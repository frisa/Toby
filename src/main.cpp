#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <pcdata.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl::fromLocalFile("/Users/jan/Repository/Toby/qml/main.qml"));

    PCData pcdata;
    engine.rootContext()->setContextProperty("pcdata", &pcdata);
    return app.exec();
}