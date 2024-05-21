#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "sensor.hpp"
#include <iostream>
#include "sensor.grpc.pb.h"
#include "configuration.pb.h"
#include <fstream>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using sensor::Sensor;
using sensor::SensorRequest;
using sensor::SensorReply;

class SensorServiceImpl final : public Sensor::Service 
{
  Status callSensor(ServerContext* context, const SensorRequest* request,
                  SensorReply* reply) override {
    reply->set_latitude(0);
    reply->set_longitude(0);
    return Status::OK;
  }
};
/*
void RunServer(uint16_t port) {
  std::string server_address = absl::StrFormat("0.0.0.0:%d", port);
  SensorServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();
  ServerBuilder builder;
  // Listen on the given address without any authentication mechanism.
  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  // Register "service" as the instance through which we'll communicate with
  // clients. In this case it corresponds to an *synchronous* service.
  builder.RegisterService(&service);
  // Finally assemble the server.
  std::unique_ptr<Server> server(builder.BuildAndStart());
  std::cout << "Server listening on " << server_address << std::endl;

  // Wait for the server to shutdown. Note that some other thread must be
  // responsible for shutting down the server for this call to ever return.
  server->Wait();
}*/


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor Mockup");
    app.setWindowIcon(QIcon(":/img/sensor.png"));

    // Configuration
    SensorConfiguration config;
    std::fstream input("config.pb", std::ios::in | std::ios::binary);

    if ((!input))
    {
        std::cerr << "Unable to open/parse configuration file." << std::endl;
        config.set_name("GNSS01");
        config.set_type(SensorConfiguration_DeviceType_GNSS0);
        config.set_ip("192.168.254.1");
        config.set_port("50051");
        config.set_initlatitude(0.0);
        config.set_initlongitude(0.0);
        std::fstream output("config.pb", std::ios::out | std::ios::binary);
        if (!config.SerializeToOstream(&output))
        {
            std::cerr << "Failed to write configuration file." << std::endl;
        }
        input.close();
        input.open("config.pb", std::ios::in | std::ios::binary);
    }

    if (!config.ParseFromIstream(&input))
    {
        std::cerr << "Failed to parse configuration file." << std::endl;
    }

    QQmlApplicationEngine engine;
    SensorModel sensorModel(QString::fromStdString(config.ip()), QString::fromStdString(config.port()), QString::number(config.initlatitude()), QString::number(config.initlongitude()));
    engine.rootContext()->setContextProperty("sensor", &sensorModel);
    engine.connect(&sensorModel, &SensorModel::connectionChanged, [&engine, &sensorModel]()
                   { std::cout << "Listening on: " << sensorModel.getIp().toStdString() << std::endl; });

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