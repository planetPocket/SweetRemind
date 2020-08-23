import QtQuick 2.0
import QtQuick.Controls 1.4

import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.2
Item {
    width: parent.width -20
    height: parent.height -20
    id:tasklist
    property int count:0
    property string connstr: "<-/-/->"
    property variant colors:['#D7E2E8','#0BACFF']
    property variant allheights:[20]
    Connections{
        target: heditor
        onShowStrChanged:{
//            let color = '#'+(Math.random() * 0xFFFFFF << 0).toString(16).padStart(6, '0');
            let rr = v.split(connstr);
            console.log(rr)
            let strikeoutstate = false;
            if(rr[2] === "1"){
                strikeoutstate = true;
            }
            var data = {
                list_id:rr[0],
                content: rr[1],
                colour: '',
                count:0,
                st:strikeoutstate
            }
            let findstate = false;
            for(let i = 0;i<qmlModel.count;i++)
                if(qmlModel.get(i).list_id === rr[0]){
                    // modify
                    findstate = true;
                    data.colour = colors[rr[0]%2]
                    data.count = count
                    qmlModel.set(i,data)
                    break;
                }
            if(findstate === false){
                data.count = count
                data.colour = colors[count++%2]
                qmlModel.append(data)
            }

        }
        onActivetriggerChanged:{
            console.log(v)
        }
    }
    ListModel {
         id: qmlModel
    }
    ListView {
        id: lv
        anchors.fill: parent
        model: qmlModel
        delegate: Rectangle {
            id: wrapper
            height: 20
            width: 200
            color: colour

            // content list_id st from data
            property string val:content
            property bool modifyState:false
            property int data_id:list_id
             Text {
                id:tt
                text: content
                wrapMode:Text.WrapAtWordBoundaryOrAnywhere
                width: 200
                font.strikeout: st
                Component.onCompleted: {
                    wrapper.height = height
                }

                MouseArea{
                    anchors.fill: parent
                    onDoubleClicked: {
                        if(!wrapper.modifyState){
                            wrapper.modifyState = true;
                            var component = Qt.createComponent("Modify.qml");
                            var window = component.createObject(tt);
                            window.show();
                        }
                    }
                }
            }
            Image {
                x:parent.x + 200
                y:0
                height: 20
                width: 20
                source: "/icon/confirm.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        heditor.m_activetrigger = wrapper.data_id + connstr + "finished";
                        tt.font.strikeout = true
                    }
                }
            }
            Image {
                x:parent.x + 220
                y:0
                height: 20
                width: 20
                source: "/icon/cancel.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        heditor.m_activetrigger = wrapper.data_id + connstr + "cancel";
                        tt.font.strikeout = false
                    }
                }
            }
            Image {
                x:parent.x + 240
                y:0
                height: 20
                width: 20
                source: "/icon/delete.png"
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        heditor.m_activetrigger = wrapper.data_id +connstr + "delete";
                        qmlModel.remove(content)
                    }
                }
            }
        }
    }

}
