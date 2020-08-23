import QtQuick 2.14
import QtQuick.Window 2.14

import QtQuick.Controls 1.4
import QtQuick.Layouts 1.3
import QtQuick.Controls.Styles 1.2

//import HandleEditorReg 1.0
Window {
    id:ww
    visible: true
    width: 400
    height: 200
    title: qsTr("Sweet Remind")
    flags: Qt.Dialog

    property bool stickyState: true //default set always actived
    onWindowStateChanged: {
        //show 0  hide 1
        windowState.accepted = false;
        if(stickyState == true){
            // set window actived
            ww.requestActivate()
        }
    }
    Component.onCompleted: {
    }

    TaskWrapper{
        id:tw
        x:40
        y:10
        width: 200
        height: parent.height - 30
    }
    Shortcut{
        sequence: ["Ctrl+A"]
        onActivated: {
            var component = Qt.createComponent("Edit.qml");
            var window = component.createObject(ww, {"x": 100, "y": 300});
            window.show();
        }
    }
    Button{
        objectName: "sd"
        x: parent.width - width
        y: parent.height - 20
        text: "Add New"
        onClicked: {
            var component = Qt.createComponent("Edit.qml");
            var window = component.createObject(ww);
            window.show();
        }
    }
}
