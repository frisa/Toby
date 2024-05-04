#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <pcdata.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.load(url);

    PCData pcdata;
    engine.rootContext()->setContextProperty("pcdata", &pcdata);
    return app.exec();
}