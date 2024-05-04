import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 250
    height: 300
    title: "Toby's App"
    ColumnLayout {
        anchors.fill: parent
        Label {
            horizontalAlignment: Text.AlignHCenter
            text: pcinfo.hostname
            color: "white"
            background: 
                Rectangle {
                    color: "gray"
                    border.color: "white"
                    radius: 1
                }
            Layout.fillWidth: true
        }
        RowLayout {
            height: 30
            width: parent.width
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
            height: 30
            width: parent.width
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

        Button {
            text: "Submit"
            width: parent.width
            onClicked: {
                logic.parameter1 = paramField1.text;
                console.log("Set Paramter 1: " + paramField1.text);
                logic.parameter2 = paramField2.text;
                console.log("Set Paramter 2 " + paramField2.text);
            }
            Layout.fillWidth: true
        }

        Label {
            text: "Parameters " + logic.parameter1 + " " + logic.parameter2
            color: "white"
        }
    }
}