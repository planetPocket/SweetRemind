#ifndef HANDLEEDITOR_H
#define HANDLEEDITOR_H

#include <QObject>
#include <QString>
#include <QMap>
#include <QTimer>
#include <QFile>
#include <QList>
#include <QVariantMap>
enum STATE{
    SW_ACTIVE = 0,
    SW_FINISHED,
    SW_DELETE,
};

struct TODO{
    QString todocontent;
    int id;
    STATE state;
};

class HandleEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString m_activetrigger READ getActive WRITE setActive NOTIFY activetriggerChanged)
    Q_PROPERTY(QString mystring READ getString WRITE setString NOTIFY mystringChanged)
    Q_PROPERTY(QString m_showstr READ getShowString WRITE setShowString NOTIFY showStrChanged)
public:
    explicit HandleEditor(QObject *parent = nullptr);
    ~HandleEditor();
public:
    Q_INVOKABLE QString getString();
    Q_INVOKABLE void setString(QString string);
    Q_INVOKABLE QString getActive();
    Q_INVOKABLE void setActive(QString string);
    Q_INVOKABLE QString getShowString();
    Q_INVOKABLE void setShowString(QString string);


    void readAllRemindsFromStore();
    void saveContent();
signals:
signals:
    void mystringChanged(QString v);
    void activetriggerChanged(QString v);
    void showStrChanged(QString v);

    void activeSaved();
public slots:
    void handleSubmitContent(const QString &data);
    void handleActiveChange(const QString &data);

private:
    QString m_showstr;
    QString m_stringptr;
    //unuse
    QMap<int,TODO> m_todolist;
    QTimer m_readtimer;
    QFile m_fd;
    QString m_storefilepath = "./SweetRemind/";
    QString m_storefile = "data";
    int idcount = 0;
    QString m_activetrigger;
    bool mtimeout =false;

    QString connstr = "<-/-/->";
};

#endif // HANDLEEDITOR_H
