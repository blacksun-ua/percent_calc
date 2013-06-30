import QtQuick 1.1


Rectangle {
    width: 360
    height: 360

    Row {
        id: inputMenu
        anchors { left: parent.left }
        //spacing: parent.width/8

        InputView {
            id: percent
            label: "percent:"
            value: "20"
        }

        InputView {
            id: cash
            label: "cash:"
            value: "50000"
        }

        InputView {
            id: period
            label: "period:"
            value: "12"
        }
    }

    Text {
        id: calcResult
        anchors { top: inputMenu.bottom; }
        text: "Hello World"
    }

//    MouseArea {
//        anchors.fill: parent
//        onClicked: {
//            Qt.quit();
//        }
//    }

    Button {
        id: quitButton
        anchors { top: calcResult.bottom }
        label: "Quit"
        onButtonClick: { Qt.quit(); }
    }


}

