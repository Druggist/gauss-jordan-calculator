#include "gaussjordan.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlEngine>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QScopedPointer<GaussJordan> solver(new GaussJordan);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("solver", solver.data());
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    return app.exec();
}
