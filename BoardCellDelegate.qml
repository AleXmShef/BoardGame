import QtQuick 2.0
import QtQuick.Controls 2.0

Component {
    Item {
        id: boardCellDelegate
        function cellOnClicked() {
            background_content.color = "orange"
            console.log("Cell " + _x + "," + _y + " clicked")
        }

        function cellOnEntered() {
            background_content.color = "red"
        }

        function cellOnExited() {
            background_content.color = "green"
        }


        Rectangle {
            height: board.cell_size
            width: board.cell_size
            color: "white"
            Rectangle {
                id: background_content
                height: board.cell_size - 2
                width: board.cell_size - 2
                color: "green"
                anchors {verticalCenter: parent.verticalCenter; horizontalCenter: parent.horizontalCenter}
                Text {
                    text: _x + " " + _y
                }

            }
            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onEntered: {cellOnEntered()}
                onExited: {cellOnExited()}
                onClicked: {cellOnClicked()}
            }
        }
    }
}
