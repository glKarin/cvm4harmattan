#include "softbutton.h"

#include <QPainter>
#include <QDebug>

#include "macros.h"

namespace karin
{
	SoftButton::SoftButton(QWidget *parent)
		: Button(parent),
		m_action(0)
	{
		setObjectName("karin_SoftButton");
		SetMargin(2);
		SetBorder(2);
		SetRadius(32);
		QFont f = font();
		f.setPixelSize(24);
		setFont(f);

		connect(this, SIGNAL(clicked(bool)), this, SLOT(OnClicked(bool)));
		connect(this, SIGNAL(checkedChanged(bool)), this, SLOT(OnCheckedChanged(bool)));
	}

	SoftButton::~SoftButton()
	{
		ID_QOBJECT_DESTROY_DEBUG
	}

	void SoftButton::SetAction(int action)
	{
		if(m_action != action)
			m_action = action;
	}

	int SoftButton::Action() const
	{
		return m_action;
	}

	void SoftButton::SetLabel(const QString &label)
	{
		QString str;
		int unicode;

		if(label.startsWith("\\u"))
		{
			QStringList newLabel = label.split("\\u", QString::SkipEmptyParts);
			//qDebug()<<newLabel;
			foreach(const QString &s, newLabel)
			{
				unicode = s.toInt(0, 16);
				str.push_back(QChar(unicode));
			}
			//qDebug()<<unicode <<str ;
		}
		else
			str = label;
		Button::SetLabel(str);
	}

	void SoftButton::OnClicked(bool on)
	{
		emit clicked(m_action, on);
	}

	void SoftButton::OnCheckedChanged(bool checked)
	{
		emit checkedChanged(m_action, checked);
	}
}
