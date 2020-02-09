import QtQuick 1.1
import com.nokia.meego 1.1

Item{
	id: root;

	width: parent.width;
	height: mainlayout.height;
	clip: true;
	objectName: "karin_QML_SliderWidget";
	property string text;
	property string minText: "";
	property string maxText: "";
	property string curText: "";
	property alias minimumValue: slider.minimumValue;
	property alias maximumValue: slider.maximumValue;
	property alias stepSize: slider.stepSize;
	property alias value: slider.value;
	property bool inverted: false;
	property int precision: 0;
	property bool autoLabel: true;
	property alias pressed: slider.pressed;
	property int margins: 0;

	signal move(real v);
	signal clicked;

	Column{
		id: mainlayout;
		anchors.top: parent.top;
		anchors.left: parent.left;
		anchors.right: parent.right;
		anchors.leftMargin: root.margins;
		anchors.rightMargin: root.margins;
		spacing: 8;

		Text{
			id: title;
			width: parent.width;
			anchors.horizontalCenter: parent.horizontalCenter;
			verticalAlignment: Text.AlignVCenter;
			font.pixelSize: 32;
			color: root.inverted ? "#ffffff" : "#000000";
			elide: Text.ElideRight;
			clip: true;
			text: root.text + ": " + (autoLabel ? slider.value.toFixed(root.precision) : curText);
		}

		Column{
			width: parent.width;
			Row{
				anchors.horizontalCenter: parent.horizontalCenter;
				width: parent.width - 5 * 2;
				height: 24;
				Text{
					id: minlabel;
					width: parent.width / 2;
					height: parent.height;
					horizontalAlignment: Text.AlignLeft;
					verticalAlignment: Text.AlignVCenter;
					font.pixelSize: 18;
					color: root.inverted ? "#ffffff" : "#000000";
					elide: Text.ElideRight;
					text: root.autoLabel ? slider.minimumValue : root.minText;
				}
				Text{
					id: maxlabel;
					width: parent.width / 2;
					height: parent.height;
					horizontalAlignment: Text.AlignRight;
					verticalAlignment: Text.AlignVCenter;
					font.pixelSize: 18;
					color: root.inverted ? "#ffffff" : "#000000";
					elide: Text.ElideRight;
					text: root.autoLabel ? slider.maximumValue : root.maxText;
				}
			}
			Slider{
				id: slider;
				width: parent.width;
				anchors.horizontalCenter: parent.horizontalCenter;
				minimumValue: 0;
				maximumValue: 100;
				stepSize: 1;
				value: 1;
				valueIndicatorText: value.toString();
				onValueChanged: {
					if(pressed) root.move(value);
				}
			}
		}
	}
}
