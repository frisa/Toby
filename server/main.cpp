#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "sensor.hpp"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor Mockup");
    app.setWindowIcon(QIcon(":/img/sensor.png"));

    QQmlApplicationEngine engine;
    Sensor sensor;
    engine.rootContext()->setContextProperty("sensor", &sensor);

    const QUrl url(QStringLiteral("qrc:/qml/Sensor.qml"));
    engine.load(url);
    return app.exec();
}