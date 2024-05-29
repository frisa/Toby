import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow{
    visible: true 
    width: 200
    height: 200
    title: "Sensor"
    GridLayout {
        columns: 2
        Image {
            id: image
            source: "qrc:/img/sensor.png"
            Layout.columnSpan: 2
            Layout.preferredWidth: 40
            Layout.preferredHeight: 40
            fillMode: Image.PreserveAspectFit
        }
        Label {
            text: "IP2:"
        }
        TextField {
            id: ipField
            placeholderText: "Enter sensor IP"
            text: sensor.ip
            Layout.fillWidth: true
        }
        Label {
            text: "Port:"
        }
        TextField {
            id: portField
            placeholderText: "Enter sensor port"
            text: sensor.port
            Layout.fillWidth: true
        }
        Label {
            text: "Latitude:"
        }
        TextField {
            id: latitudeField
            text: sensor.latitude
            validator: DoubleValidator {
                bottom: -90.0
                top: 90.0
                decimals: 6
            }
            Layout.fillWidth: true
        }
        Label {
            text: "Longitude:"
        }
        TextField {
            id: longitudeField
            text: sensor.longitude
            validator: DoubleValidator {
                bottom: -90.0
                top: 90.0
                decimals: 6
            }
            Layout.fillWidth: true
        }
        Button {
            text: "Listen"
            width: parent.width
            Layout.columnSpan: 2
            onClicked: {
                sensor.Longitude = longitudeField.text;
                sensor.Latitude = latitudeField.text;
                sensor.Send();
            }
            Layout.fillWidth: true
        }      
    }
}