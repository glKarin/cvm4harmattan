import QtQuick 1.1
import com.nokia.meego 1.1

Item{
	id: root;

	width: parent.width;
	height: mainlayout.height;
	clip: true;
	objectName: "karin_QML_ColorPickerWidget";
	property string text;
	property bool inverted: false;
	property int margins: 0;
	property color color: "#000000";

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
			text: root.text + ": " + root.color;
		}

		Item{
			width: parent.width;
			height: childrenRect.height;

			Item{
				id: coloritem;
				anchors.left: parent.left;
				height: slidercol.height;
				width: 80;
				clip: true;

				Column{
					anchors.centerIn: parent;
					width: parent.width;
					spacing: 10;

					Text{
						width: parent.width;
						anchors.horizontalCenter: parent.horizontalCenter;
						font.pixelSize: 24;
						color: root.inverted ? "#ffffff" : "#000000";
						elide: Text.ElideRight;
						maximumLineCount: 3;
						wrapMode: Text.WrapAnywhere;
						text: root.color;
					}
					Rectangle{
						anchors.horizontalCenter: parent.horizontalCenter;
						width: parent.width;
						height: width;
						//smooth: true;
						//radius: width / 2;
						color: root.color;
					}
				}
			}

			Column{
				id: slidercol;
				anchors.right: parent.right;
				anchors.left: coloritem.right;
				ColorElementPickerWidget{
					id: r;
					width: parent.width;
					inverted: root.inverted;
					text: "R";
					onElementValueChanged: {
						root._MakeRGB("r", elementValue);
					}
				}
				ColorElementPickerWidget{
					id: g;
					width: parent.width;
					inverted: root.inverted;
					text: "G";
					onElementValueChanged: {
						root._MakeRGB("g", elementValue);
					}
				}
				ColorElementPickerWidget{
					id: b;
					width: parent.width;
					inverted: root.inverted;
					text: "B";
					onElementValueChanged: {
						root._MakeRGB("b", elementValue);
					}
				}
			}
		}
	}

	function _MakeRGB(t, v)
	{
		var type = t[0].toLowerCase();
		var c = root.color.toString();
		c = c.substr(1);
		var ov = c.substr(type === 'r' ? 0 : (type === 'g' ? 2 : 4), 2);
		if(ov === v)
		return;
		var nc = c.substr(0, type === 'r' ? 0 : (type === 'g' ? 2 : 4)) + v + c.substr(type === 'r' ? 2 : (type === 'g' ? 4 : 6));
		if(nc === c)
		return;
		root.color = "#" + nc;
	}

	onColorChanged: {
		var c = root.color.toString();
		c = c.substr(1);
		var v = c.substr(0, 2);
		r._SetValue(parseInt(v, 16));
		v = c.substr(2, 2);
		g._SetValue(parseInt(v, 16));
		v = c.substr(4, 2);
		b._SetValue(parseInt(v, 16));
	}
}
