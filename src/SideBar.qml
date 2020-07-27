import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
Item {
    width: parent.width
    height: parent.height
    // need parent passing x position infomation
//    Rectangle{
//        x:parent.x
//        y:parent.y
//        width: parent.width
//        height: parent.height
//        border.color:  "#404142"
//        MouseArea {
//            anchors.fill: parent
//            onClicked: {
//                console.log("Clicked")
//            }
//        }
//    }
    Repeater{
        model:[
            {'value':'note','color':'#008000'},
            {'value':'todo','color':'#008080'},
            {'value':'unk','color':'#808000'},
            ]
        delegate: Button{
            x:parent.x
            y:parent.y + 20 * (index)
            width: parent.width
            height: 20
//            color: modelData.color
//            border.color:  "#404142"
            Text {
                id: name
                text: qsTr("" + modelData.value)
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    console.log("1 bold line",index)
                    parent.tasklist.n.text = qsTr('www')
                }
            }
        }
    }

}
