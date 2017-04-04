import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    id: mainWindow
    visible: true
    width: 640
    height: 480
    title: qsTr("Gauss - Jordan elimination method")

    Canvas {
        id: mycanvas
        width: mainWindow.width
        height: mainWindow.height

        property real height_pct: 0.35
        property real width_pct: 0.7

        onPaint: {
            var ctx = getContext("2d");
            ctx.fillStyle = "#03A9F4";
            ctx.beginPath();
            ctx.moveTo(mainWindow.width * width_pct, 0);
            ctx.lineTo(mainWindow.width, 0);
            ctx.lineTo(mainWindow.width,mainWindow.height * height_pct);
            ctx.closePath();
            ctx.shadowColor = "#000000";
            ctx.shadowOffsetX = -2;
            ctx.shadowOffsetY = 2;
            ctx.shadowBlur = 5.0;
            ctx.fill();
        }
    }

    Column {
        width: mainWindow.width
        height: mainWindow.height

        TextArea {
            id: results
            readOnly: true
            width: mainWindow.width * 0.7
            height: mainWindow.height * 0.5 - arithmetic_subtitle.height - arithmetic_wrapper.height
            wrapMode: TextEdit.WrapAnywhere
        }
        Label {
            id: arithmetic_subtitle
            text: "Arithmetic:"
            color: "#03A9F4"
            font.pixelSize: 22
            font.bold: true
        }

        Row {
            id: arithmetic_wrapper
            Label {
                text: "Standard"
                anchors.verticalCenter: parent.verticalCenter
            }
            Switch {
                id: arithmetic
                checked: false
            }
            Label {
                text: "Interval"
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        TextArea {
            id: factors
            width: mainWindow.width * 0.9
            height: mainWindow.height * 0.5 - compute.height - 20
            anchors.horizontalCenter: parent.horizontalCenter
            wrapMode: TextEdit.WrapAnywhere
        }

        Button {
            id: compute
            text: "Compute"
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }
    }
}
