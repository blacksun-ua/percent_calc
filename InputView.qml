import QtQuick 1.1

Rectangle {
    property string label: ""
    property string value: ""

    width: 100; height: 60

    Column {
        anchors.centerIn: parent

        Rectangle {
            id: textBackground
            color: "yellow"
            width: 100; height: 20
            radius: 10

            Text {
                id: textLabel
                text: label
                anchors.centerIn: textBackground
            }
        }

        Rectangle {
            id: textInputBackground
            color: "lightblue"
            width: 100; height: 20
            radius: 10
            border { width: 2; color: "lightblue" }

            TextInput {
                id: editor
                anchors.centerIn: textInputBackground
                text: value
                width: 80
                opacity: 1
                //cursorVisible: true
                focus: true
                color: "#151515"; selectionColor: "green"
            }
        }
    }

    MouseArea {
        id: inputViewMouseArea
        anchors.fill: parent
    }
}
