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
    property variant colors:['#882313','#598131']
    Connections{
        target: heditor
        onMystringChanged:{
//            let color = '#'+(Math.random() * 0xFFFFFF << 0).toString(16).padStart(6, '0');
            let color = colors[count++%2]
            var data = {
                name: v,
                colour: color
            }
            qmlModel.append(data)
            heditor.test = "jhi"
        }
        onActivetriggerChanged:{
            console.log(v)
        }
    }
    ListModel {
         id: qmlModel
     }
    ListView {
        id: list_view
        anchors.fill: parent
        model: qmlModel
        delegate: Rectangle {
            height: 20
            width: 200
            Text {
                id:tt
                property string val:name
                text: name
                MouseArea{
                    anchors.fill: parent
                    onClicked: {
                        var component = Qt.createComponent("Modify.qml");
                        var window = component.createObject(tt);
                        window.show();
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
                        heditor.m_activetrigger = "finished";
                        tt.font.strikeout = true
                        console.log('ok')
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
                        heditor.m_activetrigger = "cancel";
                        console.log('cancel')
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
                        console.log('cancel')
                        heditor.m_activetrigger = "delete";
                        qmlModel.remove(name)
                    }
                }
            }
        }
    }

}
