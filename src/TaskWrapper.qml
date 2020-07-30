import QtQuick 2.0
import QtQuick.Controls 1.4
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
            heditor
            var data = {
                name: v,
                colour: color
            }
            qmlModel.append(data)
        }
        onTodolistChanged:{
            console.log('ah',list)
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
                text: name
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
//                        tt.Styled
                        tt.font.strikeout = true
                        console.log('ok')
//                        qmlModel.remove(name)
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
//                        tt.Styled
                        console.log('cacc')
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
                        qmlModel.remove(name)
                    }
                }
            }
        }
    }

}
