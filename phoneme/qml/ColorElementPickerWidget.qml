import QtQuick 1.1
import com.nokia.meego 1.1

Item{
	id: root;
	property int value: 0;
	property string elementValue: root._ToString(value);
	property string text: "";
	property bool inverted: false;
	height: childrenRect.height;
	objectName: "karin_QML_ColorElementPickerWidget";

	Text{
		id: title;
		anchors.left: parent.left;
		width: 32;
		height: sliderbar.height;
		horizontalAlignment: Text.AlignHCenter;
		verticalAlignment: Text.AlignVCenter;
		font.pixelSize: 24;
		color: root.inverted ? "#ffffff" : "#000000";
		elide: Text.ElideRight;
		font.bold: true;
		clip: true;
		text: root.text;
	}

	Column{
		id: sliderbar;
		anchors.left: title.right;
		anchors.right: parent.right;

		Text{
			anchors.horizontalCenter: parent.horizontalCenter;
			width: parent.width;
			height: 18;
			horizontalAlignment: Text.AlignHCenter;
			verticalAlignment: Text.AlignBottom;
			font.pixelSize: 18;
			color: root.inverted ? "#ffffff" : "#000000";
			elide: Text.ElideRight;
			clip: true;
			text: root.value;
		}
		Row{
			anchors.horizontalCenter: parent.horizontalCenter;
			width: parent.width;
			height: slider.height;
			Text{
				id: minlabel;
				//width: 32;
				height: parent.height;
				//horizontalAlignment: Text.AlignHCenter;
				verticalAlignment: Text.AlignVCenter;
				font.pixelSize: 18;
				color: root.inverted ? "#ffffff" : "#000000";
				elide: Text.ElideRight;
				text: slider.minimumValue;
			}
			Slider{
				id: slider;
				width: parent.width - minlabel.width - maxlabel.width;
				minimumValue: 0;
				maximumValue: 255;
				stepSize: 1;
				value: 0;
				valueIndicatorText: value.toString();
				onValueChanged: {
					{
						root.value = value;
						//root.elementValue = root._ToString(value);
					}
				}
			}
			Text{
				id: maxlabel;
				//width: 32;
				height: parent.height;
				//horizontalAlignment: Text.AlignHCenter;
				verticalAlignment: Text.AlignVCenter;
				font.pixelSize: 18;
				color: root.inverted ? "#ffffff" : "#000000";
				elide: Text.ElideRight;
				text: slider.maximumValue;
			}
		}
	}

	function _ToString(value)
	{
		var e = value.toString(16).toUpperCase();
		if(e.length === 1)
		e = "0" + e;
		return e;
	}

	function _SetValue(v)
	{
		root.value = v;
		//root.elementValue = _ToString(root.value);
		slider.value = root.value;
	}
}
