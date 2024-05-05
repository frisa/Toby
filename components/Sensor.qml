import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtLocation 5.15
import QtPositioning 5.15

GridLayout {
    anchors.fill: parent
    columns: 2

    Form {
        anchors.top: parent.top
        anchors.left: parent.left
        Layout.maximumWidth: 250
    }
    Map {
        plugin: mapPlugin
        center: QtPositioning.coordinate(51.5074, -0.1278)
        zoomLevel: 14
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
    Plugin {
        id: mapPlugin
        name: "osm"
    }
}