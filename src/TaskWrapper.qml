import QtQuick 2.0
Item {
    width: parent.width -20
    height: parent.height -20
    id:tasklist

    Connections{
        target: heditor
        onMystringChanged:{

            let color = '#'+(Math.random() * 0xFFFFFF << 0).toString(16).padStart(6, '0');
            var data = {name: v, colour: color}
            qmlModel.append(data)
        }
    }
    ListModel {
         id: qmlModel
     }

//    ListView {
//        anchors.fill: parent
//        clip: true
//        model:qmlModel
//    }

    ListView {
        id: list_view
        anchors.fill: parent
        model: qmlModel
//        model: cppModel
        delegate: Rectangle {
            height: 20
            width: 200
            color: colour
            Text { text: name }
        }
    }

//    Rectangle{
//        x:parent.x
//        y:parent.y
//        width: parent.width
//        height: parent.height
//        border.color:  "#404142"
//    }
//    Repeater{
//        model:(parent.height)/20
//        delegate: Rectangle{
//            x:parent.x
//            y:parent.y + 20 * (index)
//            width: parent.width
//            height: 1
//            color:  "#404142"
//            Text {
//                id: name
////                text: qsTr("" + index)
//            }
//        }
//    }
}
