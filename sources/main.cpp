#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "pcinfo.h"
#include "logic.h"
#include "sensor.grpc.pb.h"
#include <grpcpp/grpcpp.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using sensor::Sensor;
using sensor::SensorReply;
using sensor::SensorRequest;

class SensorClient
{
public:
    SensorClient(std::shared_ptr<Channel> channel)
        : stub_(Sensor::NewStub(channel)) {}

    std::pair<int32_t, int32_t> CallSensor(const std::string &command)
    {
        SensorRequest request;
        request.set_command(command);
        SensorReply reply;
        ClientContext context;
        Status status = stub_->callSensor(&context, request, &reply);
        if (status.ok())
        {
            return std::pair<int32_t, int32_t>{reply.latitude(), reply.longitude()};
        }
        else
        {
            std::cout << status.error_code() << ": " << status.error_message() << std::endl;
            return std::pair<int32_t, int32_t>{0, 0};
        }
    }

private:
    std::unique_ptr<Sensor::Stub> stub_;
};

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor Monitor");
    app.setWindowIcon(QIcon(":/img/resources/world.png"));

    auto channel = grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials());
    SensorClient sensor(channel);
    std::string command("get_position");
    auto reply = sensor.CallSensor(command);
    std::cout << "Sensor received: " << reply.first << "," << reply.second << std::endl;

    QQmlApplicationEngine engine;
    PCInfo pcinfo;
    Logic logic;
    engine.rootContext()->setContextProperty("pcinfo", &pcinfo);
    engine.rootContext()->setContextProperty("logic", &logic);

    const QUrl url(QStringLiteral("qrc:/qml/components/Main.qml"));
    engine.load(url);
    return app.exec();
}