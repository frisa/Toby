import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtLocation 5.15
import QtPositioning 5.15

GridLayout {
    anchors.fill: parent
    columns: 2
    property var sensorLocation: ({latitude: sensorForm.latitude, longitude: sensorForm.longitude})
    Form {
        id: sensorForm
        Layout.alignment: Qt.AlignTop
        Layout.maximumWidth: 250
    }
    Map {
        plugin: mapPlugin
        center: QtPositioning.coordinate(sensorForm.latitude, sensorForm.longitude)
        zoomLevel: 14
        Layout.fillHeight: true
        Layout.fillWidth: true
    }
    Plugin {
        id: mapPlugin
        name: "osm"
    }
}