#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "sensor.hpp"
#include <iostream>
#include "sensor.grpc.pb.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor Mockup");
    app.setWindowIcon(QIcon(":/img/sensor.png"));

    QQmlApplicationEngine engine;
    Sensor sensor;
    engine.rootContext()->setContextProperty("sensor", &sensor);
    engine.connect(&sensor, &Sensor::connectionChanged, [&engine](){
        std::cout << "Connection changed" << std::endl;
    });

    const QUrl url(QStringLiteral("qrc:/qml/Sensor.qml"));
    engine.load(url);
    return app.exec();
}