import QtQuick

Window {
    width: 1480
    height: 900
    visible: true
    title: qsTr("Hello World")

    Text {
        text: "Y: " + control.y
        anchors.top: parent.top
        color: "Black"
    }

    Rectangle{
        id: move
        width: 50
        height: 50
        color: "red"
        x: control.x
        y: control.y
        focus: true

        Keys.onPressed:(event) =>
                       {
                        if(event.key === Qt.Key_Left){
                               control.moveLeft()
                           }
                        if(event.key === Qt.Key_Right){
                               control.moveRight()
                           }
                        if(event.key === Qt.Key_Up){
                               control.applyThrust()
                           }

                       }
    }

}


