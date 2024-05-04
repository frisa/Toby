import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 360
    height: 360
    title: "File Browser"

    ListView{
        model: pcdata
        anchors.fill: parent
        delegate: Text {
            text: modelData
            font.pixelSize: 20
            color: "white"
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            Qt.quit();
        }
    }
}