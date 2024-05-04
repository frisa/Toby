#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QIcon>
#include <pcdata.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    app.setApplicationName("PCData Example");
    app.setWindowIcon(QIcon(":/img/world.png"));

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    engine.load(url);

    PCData pcdata;
    engine.rootContext()->setContextProperty("pcdata", &pcdata);
    return app.exec();
}