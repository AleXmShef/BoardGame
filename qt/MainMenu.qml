import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.14

Item {
    Item {
        id: menu
        anchors.fill: parent
        Rectangle {
            anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter; leftMargin: 340; rightMargin:340}
            height: 400
            width: 600
            color: Qt.rgba(0.6, 0.6, 0.6, 0.6)
            radius: 30
            ColumnLayout {
                anchors.fill: parent
                spacing: 4
                Text {
                    Layout.alignment: Qt.AlignCenter
                    font.pointSize: 32
                    font.bold: true
                    //anchors.fill: parent
                    text: "New Game"
                    color: "white"
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {parent.color = "orange"}
                        onExited: {parent.color = "white"}
                        onClicked: {mainAppStackView.push(board_d)}
                    }
                }
                Text {
                    Layout.alignment: Qt.AlignCenter
                    font.pointSize: 32
                    font.bold: true
                    //anchors.fill: parent
                    text: "Settings"
                    color: "white"
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {parent.color = "orange"}
                        onExited: {parent.color = "white"}
                        onClicked: {
                            mainAppStackView.push(settingsMenu)
                        }
                    }
                }
                Text {
                    Layout.alignment: Qt.AlignCenter
                    font.pointSize: 32
                    font.bold: true
                    //anchors.fill: parent
                    text: "Quit"
                    color: "white"
                    MouseArea {
                        anchors.fill: parent
                        hoverEnabled: true
                        onEntered: {parent.color = "orange"}
                        onExited: {parent.color = "white"}
                        onClicked: {Qt.quit()}
                    }
                }
            }
        }
    }
}
