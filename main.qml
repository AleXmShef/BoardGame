import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12

Window {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("Board Game")
    Item {
        id: background
        anchors.fill: parent
        Image {
            id: background_img
            anchors.fill: parent
            source: "images/main_menu_background.jpg"
        }
        GaussianBlur {
            anchors.fill: background_img
            source: background_img
            radius: 8
            samples: 16
        }
    }
    Item {
        id: menu
        anchors.fill: parent
        Rectangle {
            anchors {horizontalCenter: window.horizontalCenter; verticalCenter: window.verticalCenter}
            height: 400
            width: 600
            color: black
            opacity: 0.35
        }
    }
}
