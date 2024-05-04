import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 320
    height: 500
    title: "Toby's App"
    ColumnLayout {
        anchors.fill: parent
        spacing: 10
        RowLayout {
            Label {
                text: "Hostname:  "
                color: "white"
            }
            TextField {
                id: hostNameField
                text: pcinfo.hostname
                Layout.fillWidth: true
            }
        }
        RowLayout {
            Label {
                text: "Parameter 1:  "
                color: "white"
            }
            TextField {
                id: paramField1
                placeholderText: "Enter first parameter"
                text: logic.parameter1
                Layout.fillWidth: true
            }
        }
        RowLayout {
            Text {
                text: "Parameter 2:  "
                color: "white"
            }
            TextField {
                id: paramField2
                placeholderText: "Enter second parameter"
                text: logic.parameter2
                Layout.fillWidth: true
            }
        }
        RowLayout {
            Text {
                text: "Number 1:  "
                color: "white"
            }
            SpinBox {
                id: numberField1
                from: 0
                to: 100
                value: logic.number1
                Layout.fillWidth: true
            }
        }

        Button {
            text: "Submit"
            width: parent.width
            onClicked: {
                logic.parameter1 = paramField1.text;
                logic.parameter2 = paramField2.text;
                logic.number1 = numberField1.value;
                logger.log = "Set Paramter 2 " + logic.parameter2;
                logger.log = "Set Paramter 1: " + logic.parameter1;
                logger.log = "Set Paramter 2 " + logic.number1;
            }
            Layout.fillWidth: true
        }

        ListView{
            model: logger
            delegate: Text {
                text: messages
                color: "yellow"
            }
        
        }

        Text {
            text: logger.log
            color: "white"
        }
    }
}