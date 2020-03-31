import QtQuick 2.0
import QtQuick 2.0
import QtQuick.Window 2.14
import QtQuick.Controls 2.0
import QtGraphicalEffects 1.12
import QtQuick.Layouts 1.14
import game 1.0

Item {
    id: board
    anchors.fill: parent
    property int size_x: 50
    property int size_y: 50
    property int cell_size: 30
    property int cell_size_min: 60
    property int cell_size_max: 500
    property bool isLoaded: false
    property var arr
    property var state: {"invoking_cell": "empty", "target_cell": "empty"}
    property real transformScale: 1
    property real transformOriginX: 0
    property real transformOriginY: 0
    transform: Scale {origin.x: transformOriginX; origin.y: transformOriginY; xScale: transformScale; yScale: transformScale}
    function populateBoard() {
        let tarr = UIConnector.initBoard(size_x, size_y, 10)
        for (let i = 0; i < board.size_y; i++) {
            for (let j = 0; j < board.size_x; j++) {
                var dict = {"_x": j, "_y": i, "_terrain_type": tarr[i][j]["terrain_unit"], "_pongo_type": tarr[i][j]["board_unit"]}
                boardCellModel.append(dict)
            }
        }
        board.arr = tarr
        console.log("cells: " + boardGrid.count)
    }

    Connections {
        target: UIConnector
        onBoardChanged: {
            updateBoard()
        }
    }

    function updateBoard() {
        var cells = UIConnector.getUpdatedCells()
        cells.forEach(cell => {
                          var index = (cell["x"] + cell["y"]*board.size_x)
                          //var index = (cell["x"] + (board.size_y - cell["y"] - 1)*board.size_x)
                          var mcell = boardCellModel.get(index)
                          mcell._terrain_type = cell["terrain_unit"]["name"]
                          mcell._pongo_type = cell["board_unit"]["name"]
                          var bcell = boardGrid.itemAtIndex(index)
                          bcell.isSelected = false
                      }
                    )
    }

    function sendAction() {
        UIConnector.action(board.state)
        var index = (board.state["invoking_cell"]["x"] + board.state["invoking_cell"]["y"]*board.size_x)
        var bcell = boardGrid.itemAtIndex(index)
        bcell.isSelected = false
        board.state = {"invoking_cell": "empty", "target_cell": "empty"}
    }

    Rectangle {
        id: boardFrame
        width: parent.size_x * board.cell_size
        height: parent.size_y * board.cell_size
        anchors {horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
        //transform: Rotation {origin.x: window.width / 2; origin.y: window.height/2; angle: 20}    //ROFL
        GridView {
            BoardCellDelegate {
                id: boardCellDelegate
            }
            interactive: false
            anchors{fill: parent; horizontalCenter: parent.horizontalCenter; verticalCenter: parent.verticalCenter}
            id: boardGrid
            model: BoardCellModel {
                id: boardCellModel
            }
            delegate: boardCellDelegate
            cellHeight: board.cell_size
            cellWidth: board.cell_size
        }
    }
    MouseArea {
        anchors.fill: parent
        drag.filterChildren: true
        drag.target: boardFrame
        drag.axis: Drag.XAndYAxis
        propagateComposedEvents: true
        onClicked: {mouse.accepted = false}
        onPressed: {boardFrame.anchors.horizontalCenter = undefined; boardFrame.anchors.verticalCenter = undefined}
        onWheel: {
            board.transformOriginX = mouseX
            board.transformOriginY = mouseY
            board.transformScale += wheel.angleDelta.y/200
        }

    }
    Component.onCompleted: {
        isLoaded = true
        board.populateBoard()
    }
}
