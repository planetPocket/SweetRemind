#ifndef HANDLEEDITOR_H
#define HANDLEEDITOR_H

#include <QObject>
#include <QString>
#include <qmap.h>
struct TODO{
    QString todocontent;
};

class HandleEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString mystring READ getString WRITE setString NOTIFY mystringChanged)
    Q_PROPERTY(QList<QString> m_todolisttest READ getTodolist WRITE setTodolist NOTIFY todolistChanged)
public:
    explicit HandleEditor(QObject *parent = nullptr);

public:
    Q_INVOKABLE QString getString();
    Q_INVOKABLE void setString(QString string);
    Q_INVOKABLE QList<QString> getTodolist();
    Q_INVOKABLE void setTodolist(QList<QString> string);
signals:
signals:
    void mystringChanged(QString v);
    void todolistChanged(QList<QString> list);
public slots:
    void handleSubmitContent(const QString &in);

private:
    QString m_stringptr;
    QList<QString> m_todolisttest;
    QMap<int,TODO> m_todolist;
    int m_todosize;
};

#endif // HANDLEEDITOR_H
