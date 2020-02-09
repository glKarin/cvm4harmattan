import QtQuick 1.1
import com.nokia.meego 1.1

Item{
	id: root;
	width: parent.width;
	height: 48;
	clip: true;
	objectName: "karin_QML_SwitchWidget";

	property alias text: title.text;
	property alias checked: switcher.checked;
	property int margins: 0;

	Row{
		anchors.fill: parent;
		anchors.leftMargin: root.margins;
		anchors.rightMargin: root.margins;
		spacing: 8;
		Text{
			id: title;
			anchors.verticalCenter: parent.verticalCenter;
			width: parent.width - switcher.width - parent.spacing;
			height: parent.height;
			verticalAlignment: Text.AlignVCenter;
			font.pixelSize: 32;
			color: "#ffffff";
			elide: Text.ElideRight;
			clip: true;
		}
		Switch{
			id: switcher;
			anchors.verticalCenter: parent.verticalCenter;
			// checked: 
			// onCheckedChanged:{ }
			MouseArea{
				anchors.fill: parent;
				enabled: !root.enabled;
			}
		}
	}
}
