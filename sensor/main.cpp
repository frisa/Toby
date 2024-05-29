#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "sensor.hpp"
#include <iostream>
#include "sensor.grpc.pb.h"
#include "configuration.pb.h"
#include <fstream>
#include <filesystem>
#include <thread>
#include <future>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using sensor::Sensor;
using sensor::SensorReply;
using sensor::SensorRequest;

class SensorServiceImpl final : public Sensor::Service
{
    Status callSensor(ServerContext *context, const SensorRequest *request,
                      SensorReply *reply) override
    {
        reply->set_latitude(43.000000);
        reply->set_longitude(-75.000000);
        std::cout << "Received request from " << context->peer() << std::endl;
        return Status::OK;
    }
};

void RunServer(const std::string &ip, const uint16_t port)
{
    std::string server_address = absl::StrFormat("%s:%d", ip.c_str(), port);
    SensorServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    ServerBuilder builder;

    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Sensor listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor");
    app.setWindowIcon(QIcon(":/img/sensor.png"));

    // Configuration
    SensorConfiguration config;
    std::filesystem::path applicationPath = std::filesystem::canonical(argv[0]);
    std::filesystem::path configPath = applicationPath.parent_path() / "config.pb";
    std::fstream input(configPath, std::ios::in | std::ios::binary);
    std::cout << "Reading configuration file." << configPath << std::endl;
    if (!input)
    {
        std::cerr << "Unable to open/parse configuration file. Making default: " << configPath << std::endl;
        config.set_name("GNSS01");
        config.set_type(SensorConfiguration_DeviceType_GNSS0);
        config.set_ip("127.0.0.1");
        config.set_port("50051");
        config.set_initlatitude(43.000000);
        config.set_initlongitude(-75.000000);
        std::fstream output(configPath, std::ios::out | std::ios::binary);
        if (!config.SerializeToOstream(&output))
        {
            std::cerr << "Failed to write configuration file." << std::endl;
        }
        input.close();
        input.open(configPath, std::ios::in | std::ios::binary);
    }

    if (!config.ParseFromIstream(&input))
    {
        std::cerr << "Failed to parse configuration file." << std::endl;
    }
    QQmlApplicationEngine engine;
    SensorModel sensorModel(QString::fromStdString(config.ip()), QString::fromStdString(config.port()), QString::number(config.initlatitude()), QString::number(config.initlongitude()));
    engine.rootContext()->setContextProperty("sensor", &sensorModel);
    std::future<void> serverFuture;
    engine.connect(&sensorModel, &SensorModel::connectionChanged, [&sensorModel, &serverFuture]()
                   {  
                        serverFuture = std::async(std::launch::async, [&sensorModel]()
                        {
                            RunServer(sensorModel.getIp().toStdString(), sensorModel.getPort().toUShort());
                        });
                   });
    const QUrl url(QStringLiteral("qrc:/qml/Sensor.qml"));
    engine.load(url);

    QObject::connect(&app, &QGuiApplication::aboutToQuit, [&config, &sensorModel]()
                     {
        config.set_ip(sensorModel.getIp().toStdString());
        config.set_port(sensorModel.getPort().toStdString());
        config.set_initlatitude(sensorModel.getLatitude().toDouble());
        config.set_initlongitude(sensorModel.getLongitude().toDouble());
        std::fstream output("config.pb", std::ios::out | std::ios::binary);
        if (!config.SerializeToOstream(&output)){
            std::cerr << "Failed to write configuration file." << std::endl;
        } });
    return app.exec();
}