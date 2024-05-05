import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: "Toby's App"
    menuBar: MenuBar {
        Menu {
            title: "&File"
            Action { text: "&New" }
            Action { text: "&Exit"; onTriggered: Qt.quit();
            }
        }
        Menu {
            title: "&Command"
        }
        Menu {
            title: "&Help"
        }
    }
    header: ToolBar{
        RowLayout{
            ToolButton{
                text: "Info"
            }
            ToolButton{
                text: "Locate"
            }
            ToolButton{
                text: "Bluetooth"
            }
            ToolButton{
                text: "Wlan"
            }
            ToolButton{
                text: "Exit"
                onClicked: Qt.quit();
            }
        }
    }
    footer: Label{
        text: "Done"
    }
    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: Loader {
            anchors.fill: parent
            source: "form.qml"
        }
    }
}