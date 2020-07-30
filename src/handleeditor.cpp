#include "handleeditor.h"
#include "QDebug"
HandleEditor::HandleEditor(QObject *parent) : QObject(parent)
{
    connect(this,&HandleEditor::mystringChanged,this,&HandleEditor::handleSubmitContent);

}

QString HandleEditor::getString(){
    return m_stringptr;
}

void HandleEditor::setString(QString string){
    m_stringptr = string;
    emit mystringChanged(string);
}

QList<QString> HandleEditor::getTodolist()
{

}

void HandleEditor::setTodolist(QList<QString> string)
{

}

void HandleEditor::handleSubmitContent(const QString &in)
{
    qDebug() << "get new todo or remind"<<in;
    m_todolist[m_todolist.size()].todocontent = in;
    m_todolisttest.push_back(in);
}
