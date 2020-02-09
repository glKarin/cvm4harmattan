import QtQuick 1.1
import com.nokia.meego 1.1

Item{
	id: root;
	property int orientationMode: 2;

	property bool inverted: true;
	property string titleText: qsTr("CVM setting");

	property int orientation: 0;
	property int fillMode: 0;
	property int vkbType: 0;
	property bool vkbTranslucent: true;
	property bool forceFull: false;
	property int keyboardScheme: 1;
	property real keyboardOpacity: 1.0;
	property color backgroundColor: "#000000";

	signal orientationSetting(int orientation);
	signal fillModeSetting(int fillMode);
	signal vkbTypeSetting(int vkbType);
	signal vkbTranslucentSetting(bool vkbTranslucent);
	signal forceFullSetting(bool forceFull);
	signal keyboardSchemeSetting(int keyboardScheme);
	signal keyboardOpacitySetting(real keyboardOpacity);
	signal backgroundColorSetting(color backgroundColor);
	signal close();
	signal quit();

	anchors.fill: parent;
	clip: true;
	objectName: "karin_QML_SettingItem";

	Rectangle{
		id: bg;
		anchors.fill: parent;
		anchors.margins: 18;
		color: root.inverted ? "#000000" : "#ffffff";
		radius: 18;
		opacity: 0.6;
	}

	Item{
		id: genericDialog;
		property int minHeight: Math.min(bg.width, bg.height);
		property int minWidth: bg.width - platformStyle.leftMargin - platformStyle.rightMargin  // ToDo: better width heuristic
		anchors.centerIn: bg;
		rotation: root.orientationMode === 1 ? -90 : 0;
		height: root.orientationMode === 1 ? minWidth : minHeight;
		width: root.orientationMode === 1 ? minHeight : minWidth;
		clip: true;

		Item {
			id: header
			height: platformStyle.titleBarHeight

			anchors.left: parent.left
			anchors.right: parent.right
			anchors.top: parent.top
			//anchors.bottom: parent.bottom

			Item {
				id: labelField

				anchors.fill:  parent

				Item {
					id: labelWrapper
					anchors.left: labelField.left
					anchors.right: closeButton.left

					anchors.bottom:  parent.bottom
					anchors.bottomMargin: platformStyle.titleBarLineMargin

					//anchors.verticalCenter: labelField.verticalCenter

					height: titleLabel.height

					Label {
						id: titleLabel
						x: platformStyle.titleBarIndent
						width: parent.width - closeButton.width
						//anchors.baseline:  parent.bottom
						font: platformStyle.titleBarFont
						color: platformStyle.commonLabelColor
						elide: platformStyle.titleElideMode
						text: root.titleText
					}

				}

				Image {
					id: closeButton
					anchors.bottom:  parent.bottom
					anchors.bottomMargin: platformStyle.titleBarLineMargin-6
					//anchors.verticalCenter: labelField.verticalCenter
					anchors.right: labelField.right

					opacity: closeButtonArea.pressed ? 0.5 : 1.0

					source: "image://theme/icon-m-common-dialog-close"

					MouseArea {
						id: closeButtonArea
						anchors.fill: parent
						onClicked:  {root.close()}
					}

				}

			}

			Rectangle {
				id: headerLine

				anchors.left: parent.left
				anchors.right: parent.right

				anchors.bottom:  header.bottom

				height: 1

				color: "#4D4D4D"
			}

		}

		Flickable{
			id: flick;
			anchors.top: header.bottom;
			anchors.horizontalCenter: parent.horizontalCenter;
			width: parent.width;
			anchors.bottom: footer.top;
			contentWidth: width;
			contentHeight: layout.height;
			clip: true;
			Column{
				id: layout;
				anchors.horizontalCenter: parent.horizontalCenter;
				width: parent.width - 48;
				spacing: 10;

				// Input method
				SelectWidget{
					id: vkbtypeselect;
					inverted: true;
					text: qsTr("MeeGo input method");
					options: [
						{
							name: qsTr("Disable"),
							value: 0,
						},
						{
							name: qsTr("Always"),
							value: 1,
						},
						{
							name: qsTr("Double click"),
							value: 2,
						},
						{
							name: qsTr("Press and hold"),
							value: 3,
						},
					]
					currentValue: root.vkbType;
					onSelected: {
						if(root.vkbType !== value)
						{
							root.vkbType = value;
							root.vkbTypeSetting(root.vkbType);
						}
					}
				}
				SwitcherWidget{
					id: vkbtranslucentswitcher;
					text: qsTr("VKB translucent");
					width: parent.width;
					checked: root.vkbTranslucent;
					onCheckedChanged: {
						if(root.vkbTranslucent !== checked)
						{
							root.vkbTranslucent = checked;
							root.vkbTranslucentSetting(root.vkbTranslucent);
						}
					}
				}

				// keyboard
				SelectWidget{
					id: keyboardschemeselect;
					inverted: true;
					text: qsTr("Keyboard scheme");
					options: [
						{
							name: qsTr("None"),
							value: 0,
						},
						{
							name: qsTr("T9"),
							value: 1,
						},
						{
							name: qsTr("T9 inverse"),
							value: 2,
						},
					]
					currentValue: root.keyboardScheme;
					onSelected: {
						if(root.keyboardScheme !== value)
						{
							root.keyboardScheme = value;
							root.keyboardSchemeSetting(root.keyboardScheme);
						}
					}
				}
				SliderWidget{
					id: keyboardopacityslider;
					enabled: root.keyboardScheme > 0;
					inverted: true;
					text: qsTr("Keyboard opacity");
					precision: 2;
					minimumValue: 0.1;
					maximumValue: 1.0;
					stepSize: 0.05;
					autoLabel: false;
					curText: parseInt(value * 100) + "%";
					minText: parseInt(minimumValue * 100) + "%";
					maxText: parseInt(maximumValue * 100) + "%";
					value: root.keyboardOpacity;
					onValueChanged /*onMove*/: {
						root.keyboardOpacity = value;
						root.keyboardOpacitySetting(root.keyboardOpacity);
					}
				}

				SelectWidget{
					id: orientationselect;
					inverted: true;
					text: qsTr("Orientation");
					options: [
						{
							name: qsTr("Automatic"),
							value: 0,
						},
						{
							name: qsTr("Portrait"),
							value: 1,
						},
						{
							name: qsTr("Landscape"),
							value: 2,
						},
					]
					currentValue: root.orientation;
					onSelected: {
						if(root.orientation !== value)
						{
							root.orientation = value;
							root.orientationSetting(root.orientation);
						}
					}
				}
				SelectWidget{
					id: fillmodeselect;
					inverted: true;
					text: qsTr("Fill mode");
					options: [
						{
							name: qsTr("Default"),
							value: 0,
						},
						{
							name: qsTr("Stretch"),
							value: 1,
						},
						{
							name: qsTr("Center"),
							value: 2,
						},
						{
							name: qsTr("Fill"),
							value: 3,
						},
						{
							name: qsTr("Full"),
							value: 4,
						},
					]
					currentValue: root.fillMode;
					onSelected: {
						if(root.fillMode !== value)
						{
							root.fillMode = value;
							root.fillModeSetting(root.fillMode);
						}
					}
				}
				SwitcherWidget{
					id: forcefullswitcher;
					text: qsTr("Full force");
					width: parent.width;
					checked: root.forceFull;
					onCheckedChanged: {
						if(root.forceFull !== checked)
						{
							root.forceFull = checked;
							root.forceFullSetting(root.forceFull);
						}
					}
				}

				ColorPickerWidget{
					id: backgroundcolorselect;
					inverted: true;
					text: qsTr("Background color");
					color: root.backgroundColor;
					onColorChanged: {
						if(root.backgroundColor !== color)
						{
							root.backgroundColor = color;
							root.backgroundColorSetting(root.backgroundColor);
						}
					}
				}
			}
		}

		ScrollDecorator{
			flickableItem: flick;
		}

		Item {
			id: footer

			anchors.bottom: parent.bottom;
			anchors.horizontalCenter: parent.horizontalCenter;
			width: parent.width
			height: childrenRect.height

			//hack to make sure, we're evaluating the correct height
			Item {
				id: lineWrapper
				width: parent.width
				height: childrenRect.height
				y: 10

				Rectangle {
					id: footerLine

					anchors.left: parent.left
					anchors.right: parent.right
					anchors.top: parent.top
					height: footer.children.length ? 1 : 0

					color: "#4D4D4D"
				}
			}

			//ugly hack to assure, that we're always evaluating the correct height
			Item {id: dummy; anchors.fill:  parent}


			Item{
				anchors.top: lineWrapper.bottom;
				anchors.horizontalCenter: parent.horizontalCenter;
				width: parent.width;
				height: childrenRect.height;
				clip: true;
				Button{
					anchors.horizontalCenter: parent.horizontalCenter;
					text: qsTr("Quit");
					onClicked: {
						root.quit();
					}
				}
			}
		}
	}
	
	Binding{
		target: theme;
		property: "inverted";
		value: root.inverted;
	}

	QtObject {
		id: platformStyle;
		property real leftMargin: 88
		property real rightMargin: 88
		property int titleBarIndent: 17
		property int titleBarHeight: 56
		property int titleBarLineMargin: 10
		property int titleElideMode: Text.ElideRight
		property color commonLabelColor: "white"
		property alias titleBarFont: __titleText.font;
		property Text __titleText: Text{
			id: __titleText;
			font.pixelSize: 32
			font.capitalization: Font.MixedCase
			font.bold: false
		}
	}

	function _SetOrientation(orientation)
	{
		if(root.orientation !== orientation)
		{
			root.orientation = orientation;
			orientationselect.currentValue = root.orientation;
		}
	}

	function _SetFillMode(fillMode)
	{
		if(root.fillMode !== fillMode)
		{
			root.fillMode = fillMode;
			fillmodeselect.currentValue = root.fillMode;
		}
	}

	function _SetVKBType(vkbType)
	{
		if(root.vkbType !== vkbType)
		{
			root.vkbType = vkbType;
			vkbtypeselect.currentValue = root.vkbType;
		}
	}

	function _SetVKBTranslucent(vkbTranslucent)
	{
		if(root.vkbTranslucent !== vkbTranslucent)
		{
			root.vkbTranslucent = vkbTranslucent;
			vkbtranslucentswitcher.checked = root.vkbTranslucent;
		}
	}

	function _SetForceFull(forceFull)
	{
		if(root.forceFull !== forceFull)
		{
			root.forceFull = forceFull;
			forcefullswitcher.checked = root.forceFull;
		}
	}

	function _SetKeyboardScheme(keyboardScheme)
	{
		if(root.keyboardScheme !== keyboardScheme)
		{
			root.keyboardScheme = keyboardScheme;
			keyboardschemeselect.currentValue = root.keyboardScheme;
		}
	}

	function _SetKeyboardOpacity(keyboardOpacity)
	{
		if(root.keyboardOpacity !== keyboardOpacity)
		{
			root.keyboardOpacity = keyboardOpacity;
			keyboardopacityslider.value = root.keyboardOpacity;
		}
	}

	function _SetBackgroundColor(backgroundColor)
	{
		if(root.backgroundColor !== backgroundColor)
		{
			root.backgroundColor = backgroundColor;
			backgroundcolorselect.color = root.backgroundColor;
		}
	}

}
