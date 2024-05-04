import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    visible: true
    width: 250
    height: 300
    title: "Toby's App"
    Column {
        anchors.fill: parent
        spacing: 10
        Label {
            text: "Hostname: " + pcinfo.hostname
            color: "white"
        }
        Row {
            Text {
                text: "Parameter 1:  "
                color: "white"
            }
            TextField {
                id: paramField1
                placeholderText: "Enter first parameter"
                text: logic.parameter1
            }
        }
        Row {
            Text {
                text: "Parameter 2:  "
                color: "white"
            }
            TextField {
                id: paramField2
                placeholderText: "Enter second parameter"
                text: logic.parameter2
            }
        }

        Button {
            text: "Submit"
            onClicked: {
                console.log("Paramter 1: " + paramField1.text);
                console.log("Paramter 2 " + paramField2.text);
            }
        }
    }
}