#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "pcinfo.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("Sensor Monitor");
    app.setWindowIcon(QIcon(":/img/resources/world.png"));

    QQmlApplicationEngine engine;

    PCInfo pcinfo;
    Logic logic;
    engine.rootContext()->setContextProperty("pcinfo", &pcinfo);
    engine.rootContext()->setContextProperty("logic", &logic);

    const QUrl url(QStringLiteral("qrc:/qml/components/Main.qml"));
    engine.load(url);
    return app.exec();
}