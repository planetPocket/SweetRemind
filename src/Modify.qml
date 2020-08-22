import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.5
import QtQml 2.14
//import QtQuick 2.0
Window {
    id:editor

    visible: true
    width: 400
    height: 200
    title: qsTr("modify")
    signal sendMsg(string msg)
    onSendMsg: console.log(msg)
    property var pressKey: []
    Shortcut {
        sequence: StandardKey.SaveAs
        onActivated: saveDialog.open()
    }
    Component.onCompleted: {
        textArea.append(wrapper.val)
    }
    onClosing: {
        close.accepted = true;
        wrapper.modifyState = false;
    }
    Button{
        id:confirm
        x: parent.width-width
        y:0
        width: 50
        text: "Add"
        onClicked: {
            heditor.mystring = wrapper.id + " " + textArea.getText(0,textArea.length)
        }
    }
    Timer {
        id: timer_button
        interval: 500//设置定时器定时时间为500ms,默认1000ms
        repeat: false //是否重复定时,默认为false
        running: false //是否开启定时，默认是false，当为true的时候，进入此界面就开始定时
        triggeredOnStart: false // 是否开启定时就触发onTriggered，一些特殊用户可以用来设置初始值。
        onTriggered: {
            // equals EnterKey
            if(pressKey.length === 1 && pressKey.pop() === 16777220){
                heditor.mystring = wrapper.id + " " + textArea.getText(0,textArea.length)
                heditor.test = heditor.mystring
            }else{
                pressKey = []
            }

        }
        //restart ,start,stop,定时器的调用方式，顾名思义
    }
    Flickable {
        y: confirm.height
        width: parent.width
        height:  parent.height
        id: flickable
        flickableDirection: Flickable.VerticalFlick
        TextArea.flickable: TextArea {
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
            Keys.enabled: true
            Keys.onPressed: {
//                console.log(event.key)
                if(event.key === 16777220)
                    event.accepted = true;
                pressKey.push(event.key)
                if(!timer_button.running)
                    timer_button.start()
            }
            onLinkActivated: Qt.openUrlExternally(link)
        }
        ScrollBar.vertical: ScrollBar {}
    }
}
