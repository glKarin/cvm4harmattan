import QtQuick 1.1
import com.nokia.meego 1.1
import "itemlist.js" as L

Item{
	id: root;
	objectName: "karin_QML_SelectWidget";
	width: parent.width;
	height: mainlayout.height;
	clip: true;

	property alias text: title.text;
	property variant options: [];
	property variant currentValue: null;
	property int currentIndex: 0;
	property int margins: 0;
	property bool inverted: false;
	signal selected(int index, variant value, bool disable);
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
		}

		ButtonColumn{
			id: col;
			width: parent.width;
			spacing: 5;
			exclusive: true;
		}
	}

	Component{
		id: checkbox;
		CheckBox{
			property int index;
			property variant value;

			width: col.width;
			onClicked: {
				currentIndex = index;
				currentValue = value;
				root.selected(index, value, false);
			}
			MouseArea{
				anchors.fill: parent;
				enabled: !parent.enabled;
				onClicked: {
					root.selected(index, value, true);
					mouse.accepted = true;
				}
			}
		}
	}

	onOptionsChanged: {
		L.Clear();
		col.children = [];

		for(var k in options)
		{
			var s = options[k];
			var item = checkbox.createObject(col);
			L.Push(item);
			item.index = k;
			item.text = s.name;
			item.value = s.value;
			if(s.enabled !== undefined)
				item.enabled = s.enabled;
			//console.log(s.text, s.value);
			/*
			item.clicked.connect(function(){
				root.selected(value);
			});
			*/
		}
		if(currentValue !== null && currentValue !== undefined) __SetCurrentChecked(currentValue);
		else __SetCurrentCheckedByIndex(currentIndex);
	}

	onCurrentValueChanged: {
		__SetCurrentChecked(currentValue);
	}

	onCurrentIndexChanged: {
		__SetCurrentCheckedByIndex(currentIndex);
	}

	function __SetCurrentChecked(v)
	{
		var items = col.children;
		for(var i = 0; i < items.length; i++)
		{
			items[i].checked = false;
		}
		for(var i = 0; i < items.length; i++)
		{
			if(items[i].value == v)
			{
				items[i].checked = true;
				break;
			}
		}
	}

	function __SetCurrentCheckedByIndex(v)
	{
		var items = col.children;
		for(var i = 0; i < items.length; i++)
		{
			items[i].checked = false;
		}
		if(v >= items.length) return;
		items[v].checked = true;
	}
}
