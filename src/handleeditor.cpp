#include "handleeditor.h"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "QDebug"
#include <QDir>
HandleEditor::HandleEditor(QObject *parent) : QObject(parent)
{
    connect(&m_readtimer,&QTimer::timeout,this,&HandleEditor::saveContent);
//    connect(this,&HandleEditor::activeSaved,this,&HandleEditor::saveContent);
}

HandleEditor::~HandleEditor()
{
    m_fd.resize(0);
    m_fd.seek(0);
    for(auto d:m_todolist){
        auto str = QString::number(d.id).toLatin1()
                + connstr.toLatin1()
                + d.todocontent.toUtf8()
                + connstr.toLatin1()
                + QString::number(d.state).toLatin1()
                + "\n";
        m_fd.write(str);
    }
    m_fd.flush();
    m_fd.close();
}

void HandleEditor::saveContent(){
        qDebug() << "write todo lists to file";
}

void HandleEditor::readAllRemindsFromStore()
{
    //read user home path
    struct passwd *pw = getpwuid(getuid());
    QString homepath = pw->pw_dir;
    if(homepath.back() != '/'){
        homepath += "/" + m_storefilepath;
    }else{
        homepath += m_storefilepath;
    }
    QDir dir;
    if(!dir.exists(homepath)){
        dir.mkdir(homepath);
    }
    auto filepath = homepath + m_storefile;

    m_fd.setFileName(filepath);
    if(!m_fd.open(QIODevice::ReadWrite)){
        qDebug() << "failed to open remind store file";
        qDebug() << m_fd.errorString();
        return;
    }
    QString line;
    while ((line = m_fd.readLine(1024)),!line.isEmpty()) {
        qDebug() << line;
        if(line == "\n"){
            continue;
        }
        line.chop(1);
        auto res = line.split(connstr);
        if(res.size() != 3){
            continue;
        }
        int id = res[0].toInt();
        TODO todo;
        todo.id = id;
        todo.state = STATE(res[2].toInt());
        todo.todocontent = res[1];
        m_todolist[id] = todo;
        QString str = QString::number(id)+ connstr + res[1] + connstr + res[2];
        emit showStrChanged(str);
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

QString HandleEditor::getShowString()
{

}

void HandleEditor::setShowString(QString string)
{

}


void HandleEditor::handleActiveChange(const QString &data)
{
    qDebug() << "active" << data;
    auto r = data.split(connstr);
    auto &todo = m_todolist[r[0].toInt()];
    if(r[1] == "finished"){
        todo.state = SW_FINISHED;
    }else if(r[1] == "cancel"){
        todo.state = SW_ACTIVE;
    }else if(r[1] == "delete"){
        //if User uses history mode,the deleted data wouldn't be deleted truely,insteads of marking as deleted.
//        s.state = SW_DELETE;
        m_todolist.remove(todo.id);

    }
    qDebug() << todo.id <<todo.state<<todo.todocontent ;
}


void HandleEditor::handleSubmitContent(const QString &data)
{
    auto in = data;
    if(in.endsWith("\n")){
        in = in.chopped(1);
    }
    qDebug() << "get new todo or remind"<<in;
    auto res = in.split(connstr);
    int id = res[0].toInt();
    qDebug() << res;
    if(id == -1){
        // new data
        qDebug() << "new data" << res << res[1];
        TODO todo;
        id = idcount++;
        todo.id = id;
        res[0] = QString::number(todo.id);
        todo.todocontent = res[1];
        todo.state = SW_ACTIVE;
        QString truestr;
        for(auto i : res){
            truestr += i + connstr;
        }
        truestr += QString::number(todo.state);
        emit showStrChanged(truestr);
        qDebug() << "new data" << truestr;
        m_todolist[id] = todo;
    }else{
        qDebug() << "modify data";
        // modify data
        TODO &todo = m_todolist[id];
        todo.todocontent = res[1];
        QString truestr;
        for(auto i : res){
            truestr += i + connstr;
        }
        truestr += QString::number(todo.state);
        emit showStrChanged(truestr);
    }
//    mtimeout = true;
//    if(mtimeout){
//        m_readtimer.start(1000);
//    }
}
