#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QColor>
#include <QRect>
#include <QDebug>
#include <QVariantList>
#include <QObject>

#include "handleeditor.h"
int main(int argc, char *argv[])
{
    HandleEditor heditor;
//    qmlRegisterType<HandleEditor>("HandleEditorReg",1,0,"HandleEditorType");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine; const QUrl url(QStringLiteral("qrc:/main.qml"));
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("heditor",&heditor);
    engine.load(url);
    return app.exec();
}
