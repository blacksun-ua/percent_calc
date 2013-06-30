import QtQuick 1.1

Rectangle {
    width: 100; height: 62

    Row {
        Button {
            id: loadButton
            buttonColor: "lightgrey"
            label: "Load"
        }

        Button {
            id: saveButton
            buttonColor: "grey"
            label: "Save"
        }

        Button {
            id: exitButton
            buttonColor: "darkgrey"
            label: "Exit"

            onButtonClick: Qt.quit();
        }
    }
}
