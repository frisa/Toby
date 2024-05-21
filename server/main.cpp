#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "sensor.hpp"
#include <iostream>
#include "sensor.grpc.pb.h"
#include "configuration.pb.h"
#include <fstream>

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
        std::fstream output("config.pb", std::ios::out | std::ios::trunc | std::ios::binary);
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
    Sensor sensor(QString::fromStdString(config.ip()), QString::fromStdString(config.port()), QString::number(config.initlatitude()), QString::number(config.initlongitude()));
    engine.rootContext()->setContextProperty("sensor", &sensor);
    engine.connect(&sensor, &Sensor::connectionChanged, [&engine]()
                   { std::cout << "Parameters send" << std::endl; });

    const QUrl url(QStringLiteral("qrc:/qml/Sensor.qml"));
    engine.load(url);

    QObject::connect(&app, &QGuiApplication::aboutToQuit, [&config, &sensor]()
                     {
        config.set_ip(sensor.getIp().toStdString());
        config.set_port(sensor.getPort().toStdString());
        config.set_initlatitude(sensor.getLatitude().toDouble());
        config.set_initlongitude(sensor.getLongitude().toDouble());
        std::fstream output("config.pb", std::ios::out | std::ios::trunc | std::ios::binary);
        if (!config.SerializeToOstream(&output)){
            std::cerr << "Failed to write configuration file." << std::endl;
        } });
    return app.exec();
}