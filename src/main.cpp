#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include "pcinfo.h"
#include "logic.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("PCData Example");
    app.setWindowIcon(QIcon(":/img/world.png"));

    QQmlApplicationEngine engine;

    PCInfo pcinfo;
    Logic logic;
    engine.rootContext()->setContextProperty("pcinfo", &pcinfo);
    engine.rootContext()->setContextProperty("logic", &logic);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.load(url);
    return app.exec();
}