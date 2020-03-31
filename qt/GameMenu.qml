import QtQuick 2.0

Item {
    Loader {
        id: boardLoader
        asynchronous: true
        anchors.fill: parent
        onStatusChanged: {
            if(boardLoader.status === Loader.Loading)
                loadProgress.visible = true
            else if(boardLoader.status === Loader.Ready)
                loadProgress.visible = false
        }
    }


    Text {
        id: loadProgress
        anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
        text: "Loading"
        font.pointSize: 32
        font.bold: true
        color: "white"
        visible: false
    }

    Text {
        id: backButton
        anchors.right: parent.right
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20
        text: "Back"
        font.pointSize: 32
        font.bold: true
        color: "white"
        style: Text.Outline
        styleColor: "orange"
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {parent.color = "orange"}
            onExited: {parent.color = "white"}
            onClicked: {
                boardLoader.source = ""
                mainAppStackView.pop()
            }
        }
    }
    Text {
        id: loadButton
        anchors.top: backButton.bottom
        anchors.right: parent.right
        anchors.leftMargin: 20
        text: "Load"
        font.pointSize: 32
        font.bold: true
        color: "white"
        style: Text.Outline
        styleColor: "orange"
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {parent.color = "orange"}
            onExited: {parent.color = "white"}
            onClicked: {
                loadProgress.visible = true
                boardLoader.source = "Board.qml"
            }
        }
    }
    Text {
        id: debugSwitchButton
        anchors.top: loadButton.bottom
        anchors.right: parent.right
        anchors.leftMargin: 20
        text: "Debug"
        font.pointSize: 32
        font.bold: true
        color: "white"
        style: Text.Outline
        styleColor: "orange"
        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onEntered: {parent.color = "orange"}
            onExited: {parent.color = "white"}
            onClicked: {
                if(window._DEBUG_ === false)
                    window._DEBUG_ = true
                else
                    window._DEBUG_ = false
            }
        }
    }

    Rectangle {
        width: parent.width
        height: 150
        anchors{horizontalCenter: parent.horizontalCenter; bottom: parent.bottom }
    }
}
