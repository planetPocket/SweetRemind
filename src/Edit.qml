import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.5
Window {
    id:editor

    visible: true
    width: 400
    height: 200
    title: qsTr("Sweet Remind")
    signal sendMsg(string msg)
    onSendMsg: console.log(msg)

    Shortcut {
        sequence: StandardKey.SaveAs
        onActivated: saveDialog.open()
    }
//    Component.onCompleted: {
//        console.log(ww.tasklist)
//    }
    Connections{
        target: heditor
        onMystringChanged:{
            console.log("getform",v)
        }
    }

    Button{
        id:confirm
        x: 0
        y:0
        text: "ok"
        onClicked: {
            heditor.mystring = textArea.getText(0,textArea.length)
        }
    }
    Flickable {
        y: confirm.height
        width: parent.width
        height:  parent.height
        id: flickable
        flickableDirection: Flickable.VerticalFlick
        //            anchors.fill: parent

        TextArea.flickable: TextArea {
            //                y:20
            //                y:20 + confirm.height
            id: textArea
            textFormat: Qt.RichText
            wrapMode: TextArea.Wrap
            focus: true
            selectByMouse: true
            persistentSelection: true
            // Different styles have different padding and background
            // decorations, but since this editor is almost taking up the
            // entire window, we don't need them.
            leftPadding: 6
            rightPadding: 6
            topPadding: 0
            bottomPadding: 0
            background: null

            MouseArea {
                anchors.bottomMargin: 42
                acceptedButtons: Qt.RightButton
                anchors.fill: parent
                onClicked: contextMenu.open()
            }

            onLinkActivated: Qt.openUrlExternally(link)
        }
        ScrollBar.vertical: ScrollBar {}
    }
}
