import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 2.14
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.14
import game 1.0

Window {
    id: window
    visible: true
    width: 1280
    height: 720
    title: qsTr("Board Game")

    Background{

    }

    MainMenu {
        id: mainMenu
        visible: true
    }

    SettingsMenu {
        id: settingsMenu
        visible: false
    }

    Board {
        id: board_d
        visible: false
    }

    StackView {
        id: mainAppStackView
        initialItem: mainMenu
        anchors.fill: parent
    }

Component.onCompleted: {
    console.log(UIConnector.connectionTest())
}
}
