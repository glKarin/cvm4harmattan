#include "vkblayout.h"

#include <QDebug>

#include "softbutton.h"
#include "macros.h"
#include "defs.h"

namespace karin
{
	VKBLayout::VKBLayoutItem::VKBLayoutItem(VKBLayout *layout)
		: layout(layout),
		widget(0),
		x(0),
		y(0),
		w(0),
		h(0),
		x_anchor(0),
		y_anchor(0)
	{
	}

	VKBLayout::VKBLayoutItem::~VKBLayoutItem()
	{
		delete widget;
	}

	QLayoutItem * VKBLayout::VKBLayoutItem::AttachWidget(QLayoutItem *v)
	{
		QLayoutItem *item;

		item = widget;
		widget = v;
		return item;
	}

	void VKBLayout::VKBLayoutItem::Relayout()
	{
		QWidget *wid;
		int bx, by, bw, bh;

		if(!layout)
			return;
		if(!widget || !widget->widget())
			return;
		wid = widget->widget();
		QRect rect = layout->geometry();
		switch(x_anchor)
		{
			case Position_Base_on_Middle_Front:
				bx = rect.width() / 2 - this->x;
				break;
			case Position_Base_on_Middle_Back:
				bx = rect.width() / 2 + this->x;
				break;
			case Position_Base_on_End:
				bx = rect.width() - this->x;
				break;
			case Position_Base_on_Begin:
			default:
				bx = this->x;
				break;
		}
		switch(y_anchor)
		{
			case Position_Base_on_Middle_Front:
				by = rect.height() / 2 - this->y;
				break;
			case Position_Base_on_Middle_Back:
				by = rect.height() / 2 + this->y;
				break;
			case Position_Base_on_End:
				by = rect.height() - this->y;
				break;
			case Position_Base_on_Begin:
			default:
				by = this->y;
				break;
		}
		bw = this->w;
		bh = this->h;
		wid->setGeometry(QRect(bx, by, bw, bh));
	}

	VKBLayout::VKBLayout(QWidget *widget)
		: QLayout(widget)
	{
		setObjectName("karin_VKBLayout");
	}

	VKBLayout::~VKBLayout()
	{
		m_actions.clear();
		VKBHash_t tmp = m_btns;
		m_btns.clear();
		ID_FOREACH(VKBHash_t, tmp)
		{
			delete itor.value();
		}
		ID_QOBJECT_DESTROY_DEBUG
	}

	void VKBLayout::addItem(QLayoutItem *item)
	{
		SoftButton *btn;
		VKBLayoutItem *li;
		int action;

		btn = dynamic_cast<SoftButton *>(item->widget());
		if(btn)
		{
			action = btn->Action();
			if(!m_btns.contains(action))
			{
				m_btns[action] = new VKBLayoutItem(this);
				if(!m_actions.contains(action))

					m_actions.push_back(action);
			}
			li = m_btns[action];
			li->AttachWidget(item);
			li->Relayout();
			QLayout::invalidate();
		}
	}

	int VKBLayout::count() const
	{
		return m_btns.count();
	}

	QLayoutItem * VKBLayout::GetItem(int action) const
	{
		VKBLayoutItem *li;

		li = m_btns.value(action);
		return li ? li->widget : 0;
	}

	QLayoutItem * VKBLayout::itemAt(int index) const
	{
		VKBLayoutItem *li;

		if(index < 0 || index >= m_actions.size())
			return 0;
		li = m_btns.value(m_actions[index]);
		return li ? li->widget : 0;
	}

	QLayoutItem * VKBLayout::takeAt(int index)
	{
		VKBLayoutItem *li;
		QLayoutItem *item;
		int action;

		if(index < 0 || index >= m_actions.size())
			return 0;
		action = m_actions.takeAt(index);
		if(!m_btns.contains(action))
			return 0;
		li = m_btns.take(action);
		if(li)
			QLayout::invalidate();
		item = li ? li->AttachWidget() : 0;
		delete li;
		return item;
	}

	void VKBLayout::removeWidget(QWidget *widget)
	{
		VKBLayoutItem *li;

		ID_FOREACH(VKBHash_t, m_btns)
		{
			li = itor.value();
			if(!li || !li->widget)
				continue;
			if(li->widget->widget() == widget)
			{
				li->AttachWidget();
				delete li;
				m_actions.removeAll(itor.key());
				m_btns.erase(itor);
				delete widget;
				QLayout::invalidate();
				return;
			}
		}

		QLayout::removeWidget(widget);
	}

	QSize VKBLayout::sizeHint() const
	{
		return QSize(64, 64);
	}

	void VKBLayout::setGeometry(const QRect &r)
	{
		VKBLayoutItem *li;

		QLayout::setGeometry(r);

		ID_FOREACH(VKBHash_t, m_btns)
		{
			li = itor.value();
			if(li)
				li->Relayout();
		}
	}

	void VKBLayout::Clear()
	{
		QLayoutItem *item;
		QWidget *widget;
		VKBHash_t tmp = m_btns;

		m_actions.clear();
		m_btns.clear();
		ID_FOREACH(VKBHash_t, tmp)
		{
			item = itor.value() ? itor.value()->widget : 0;
			if(item)
			{
				widget = item->widget();
				widget->setParent(0);
				delete widget;
			}
		}
		QLayout::invalidate();
	}

	void VKBLayout::SetItemRect(QWidget *widget, int x, int y, int w, int h, unsigned char xAnchor, unsigned char yAnchor)
	{
		VKBLayoutItem *li;

		ID_FOREACH(VKBHash_t, m_btns)
		{
			li = itor.value();
			if(li && li->widget)
			{
				if(li->widget->widget() == widget)
				{
					li->x = x;
					li->y = y;
					li->w = w;
					li->h = h;
					li->x_anchor = xAnchor;
					li->y_anchor = yAnchor;
					li->Relayout();
					invalidate();
					return;
				}
			}
		}
	}
}
