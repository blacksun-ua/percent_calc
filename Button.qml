import QtQuick 1.1

Rectangle {
    id: button

    property int buttonWidth: 70
    property int buttonHeight: 30

    property string label

    property color textColor: buttonLabel.color
    property color onHoverColor: "darkblue"
    property color borderColor: "transparent"
    property color buttonColor: "lightblue"

    property real lableSize: 14

    radius: 6
    smooth: true
    border { width: 2; color: borderColor }
    width: buttonWidth; height: buttonHeight

    Text {
        id: buttonLabel
        anchors.centerIn: parent
        text: label
        color: "#DCDCCC"
        font.pointSize: lableSize
    }

    signal buttonClick()

    MouseArea {
        id: buttonMouseArea
        anchors.fill: parent
        onClicked: buttonClick()

        hoverEnabled: true
        onEntered: { parent.border.color = onHoverColor; parent.color = "green" }
        onExited:  { parent.border.color = borderColor; parent.color = buttonColor }
    }

    color: buttonMouseArea.pressed ? Qt.darker(buttonColor, 1.5) : buttonColor
    Behavior on color { ColorAnimation { duration: 55 } }

    scale: buttonMouseArea.pressed ? 1.1 : 1.0
    Behavior on scale { NumberAnimation { duration: 55 } }
}
