#include "toolicon.h"

#include <QPainter>
#include <QDebug>

#include "macros.h"

namespace karin
{
	ToolIcon::ToolIcon(QWidget *parent)
		: Button(parent)
	{
		setObjectName("karin_ToolIcon");
		SetTextColor(Qt::transparent);
		SetBorderColor(Qt::transparent);
		SetBgColor(Qt::transparent);
		SetPressedTextColor(Qt::transparent);
		SetPressedBorderColor(Qt::transparent);
		SetPressedBgColor(Qt::transparent);
	}

	ToolIcon::~ToolIcon()
	{
		ID_QOBJECT_DESTROY_DEBUG
	}

	void ToolIcon::SetIcon(const QString &icon)
	{
		bool ok;

		if(m_icon != icon)
		{
			m_icon = icon;
			ok = m_image.load(icon);
			if(!ok)
				m_icon = QString();
		}
	}

	QString ToolIcon::Icon() const
	{
		return m_icon;
	}

	void ToolIcon::SetLabel(const QString &label)
	{
		Q_UNUSED(label);
		Button::SetLabel(QString());
	}

	void ToolIcon::paintEvent(QPaintEvent *ev)
	{
		Button::paintEvent(ev);

		if(m_image.isNull())
			return;

		QPainter p(this);
		Button::InitPainter(p);
		p.drawImage(QPoint(width() / 2 - m_image.width() / 2, height() / 2 - m_image.height() / 2), m_image);
	}

}
