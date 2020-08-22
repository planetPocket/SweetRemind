#include "handleeditor.h"
#include "QDebug"
HandleEditor::HandleEditor(QObject *parent) : QObject(parent)
{
    connect(&m_readtimer,&QTimer::timeout,this,&HandleEditor::saveContent);
//    connect(this,&HandleEditor::activeSaved,this,&HandleEditor::saveContent);
}

HandleEditor::~HandleEditor()
{
    m_fd.flush();
    m_fd.close();
}

void HandleEditor::saveContent(){
        qDebug() << "write todo lists to file";
        for(auto d:m_tmp){
            m_fd.write(QString::number(d.id).toLatin1()
                       + " "
                       + QString::number(d.state).toLatin1()
                       + " "
                       +d.todocontent.toLatin1()
                       + "\n"
                       );
        }
        m_fd.flush();
        m_tmp.clear();
        m_readtimer.stop();
        mtimeout = false;
}

void HandleEditor::readAllRemindsFromStore()
{
    qDebug() << "read";
    m_fd.setFileName(StoreFilePath);
    if(!m_fd.open(QIODevice::ReadWrite)){
        qDebug() << "failed to open remind store file";
        qDebug() << m_fd.errorString();
        return;
    }
    QString line;
    while ((line = m_fd.readLine(1024)),!line.isEmpty()) {
        if(line == "\n"){
            continue;
        }
//        m_stringptr = line;
        auto res = line.split(" ");
        int id = res[0].toInt();
        TODO todo;
        todo.id = id;
        todo.state = STATE(res[1].toInt());
        todo.todocontent = res[2];
        m_todolist[id] = todo;
        emit mystringChanged(todo.todocontent);
        idcount = id + 1;
    }
    qDebug() << "read id:"<< idcount;
    connect(this,&HandleEditor::mystringChanged,this,&HandleEditor::handleSubmitContent);
    connect(this,&HandleEditor::activetriggerChanged,this,&HandleEditor::handleActiveChange);
}

QString HandleEditor::getString(){
    return m_stringptr;
}

void HandleEditor::setString(QString string){
    emit mystringChanged(string);
}

QString HandleEditor::getActive()
{

}

void HandleEditor::setActive(QString string)
{
    emit activetriggerChanged(string);
}

void HandleEditor::handleActiveChange(const QString &data)
{
    qDebug() << "data" << data;
}
void HandleEditor::handleSubmitContent(const QString &data)
{
    auto in = data;
    if(in.endsWith("\n")){
        qDebug() << "sd";
        in = in.chopped(1);
    }
    qDebug() << "get new todo or remind"<<in;
    TODO todo;
    todo.todocontent = in;
    todo.id = idcount++;
    todo.state = SW_AVTIVE;
    m_tmp.push_back(todo);
    mtimeout = true;
//    saveContent();
    if(mtimeout){
        m_readtimer.start(1000);
    }
}
