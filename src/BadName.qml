import QtQuick 2.0
import Qt3D.Input 2.14


Rectangle {
    property  alias mouseArea :mouseArea
    width: 360
    height: 360
    MouseArea {
        id :mouseArea
        anchors.fill:  parent
    }

    Text {
        anchors.centerIn: parent
        text: "hi"
    }
}
