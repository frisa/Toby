import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

GridLayout {

    property alias latitude: latitudeField.text
    property alias longitude: longitudeField.text

    columns: 2
    Label {
        text: "Hostname:"
    }
    TextField {
        id: hostNameField
        text: pcinfo.hostname
        Layout.fillWidth: true
    }
    Label {
        text: "Identifier:"
    }
    TextField {
        id: paramField1
        placeholderText: "Enter first parameter"
        text: logic.parameter1
        Layout.fillWidth: true
    }
    Label {
        text: "Name:"
    }
    TextField {
        id: paramField2
        placeholderText: "Enter second parameter"
        text: logic.parameter2
        Layout.fillWidth: true
    }
    Label {
        text: "Satelites:"
    }
    SpinBox {
        id: numberField1
        from: 0
        to: 100
        value: logic.number1
        Layout.fillWidth: true
    }
    Button {
        text: "Submit"
        width: parent.width
        Layout.columnSpan: 2
        onClicked: {
            logic.parameter1 = paramField1.text;
            logic.parameter2 = paramField2.text;
            logic.number1 = numberField1.value;
            console.log("Set Paramter 2 " + logic.parameter2);
            console.log("Set Paramter 1: " + logic.parameter1);
            console.log("Set Paramter 2 " + logic.number1);
        }
        Layout.fillWidth: true
    }
    Label {
        text: "Latitude:"
    }
    TextField {
        id: latitudeField
        text: "47.410967"
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
        text: "9.6271219"
        validator: DoubleValidator {
            bottom: -90.0
            top: 90.0
            decimals: 6
        }
        Layout.fillWidth: true
    }
    Button {
        text: "Find"
        width: parent.width
        Layout.columnSpan: 2
        onClicked: {
            console.log( latitudeField.text + " " + longitudeField.text);
        }
        Layout.fillWidth: true
    }
}