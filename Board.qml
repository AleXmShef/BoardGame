import QtQuick 2.0
import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.14

Item {
    id: board
    property int size_x: 10
    property int size_y: 10
    property int cell_size: 50
    property var arr

    function populateBoard() {
        let tarr = []
        for (let i = 0; i < board.size_y; i++) {
            for (let j = 0; j < board.size_x; j++) {
                var dict = {"_x": j, "_y": i}
                tarr.push(dict)
                boardCellModel.append(dict)
            }
        }
        board.arr = tarr
        console.log("cells: " + boardGrid.count)
    }


    BoardCellDelegate {
        id: boardCellDelegate
    }

    Rectangle {
        id: boardFrame
        width: parent.size_x * board.cell_size
        height: parent.size_y * board.cell_size
        anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
        GridView {
            interactive: false
            anchors{fill: parent; horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
            id: boardGrid
            model: BoardCellModel {
                id: boardCellModel
            }
            delegate: boardCellDelegate
            cellHeight: board.cell_size
            cellWidth: board.cell_size
            Component.onCompleted: {
                board.populateBoard()
            }
        }
    }
    Text {
        anchors.left: boardFrame.right
        anchors.verticalCenter: boardFrame.verticalCenter
        anchors.leftMargin: 20
        text: "Back"
        font.pointSize: 32
        color: "white"
        MouseArea {
            anchors.fill: parent
            onClicked: {mainAppStackView.pop()}
        }
    }
}
