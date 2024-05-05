import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

GridLayout {
    anchors.fill: parent
    columns: 2

    Form{
        anchors.top: parent.top
        anchors.left: parent.left
    }

    Rectangle {
        color: "lightgreen"
        width: 200
        Layout.fillWidth: true
        Layout.fillHeight: true
    }
}