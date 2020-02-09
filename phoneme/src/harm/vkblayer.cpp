#include "vkblayer.h"

#include <QResizeEvent>
#include <QDebug>

#include "vkblayout.h"
#include "t9scheme.h"
#include "cvm.h"
#include "button.h"
#include "macros.h"
#include "defs.h"

namespace karin
{
	VKBLayer::VKBLayer(QWidget *parent)
		: GraphicsWidget(parent),
		m_layout(new VKBLayout(this)),
		m_scheme(0),
		m_currentScheme(KeyboardScheme_None)
	{
		setObjectName("karin_VKBLayer");
		SetIgnoreMouseEvents(true);
		setLayout(m_layout);
		//m_layout->Relayout(width(), height());
		
		Init();
	}

	VKBLayer::~VKBLayer()
	{
		delete m_scheme;
		ID_QOBJECT_DESTROY_DEBUG
	}

	void VKBLayer::resizeEvent(QResizeEvent *ev)
	{
		GraphicsWidget::resizeEvent(ev);
		/*
		QSize s = ev->size();
		m_layout->Relayout(s.width(), s.height());
		*/
	}

	void VKBLayer::Init()
	{
		SetVKBScheme(KeyboardScheme_T9_Inverse);
	}

	void VKBLayer::SetVKBScheme(int scheme)
	{
		QWidget *parent;

		if(m_currentScheme == scheme)
			return;

		hide();
		m_currentScheme = scheme;
		if(scheme != KeyboardScheme_None)
		{
			if(m_scheme)
			{
				m_layout->Clear();
				delete m_scheme;
				m_scheme = 0;
			}
			if(scheme == KeyboardScheme_T9_Inverse)
				m_scheme = new T9InverseScheme(0);
			else
				m_scheme = new T9Scheme(0);
			m_scheme->SetLayout(m_layout);
			m_scheme->Make();
			parent = parentWidget();
			if(parent)
				SetMinimalGeometry(0, 0, parent->width(), parent->height());
			setVisible(true);
		}
	}

	void VKBLayer::SendCommand(int command, bool pressed)
	{
		keyEvent(command, pressed ? 1 : 0);
	}

	void VKBLayer::SetMinimalGeometry(int posx, int posy, int width, int height)
	{
		int x, y, w, h;

		w = m_scheme ? m_scheme->SchemeWidth() : width;
		h = m_scheme ? m_scheme->SchemeHeight() : 0;
		w = w < 0 ? width : w;
		h = h < 0 ? height : h;
		x = posx;
		y = height - h + posy;
		setGeometry(x, y, w, h);
	}

	void VKBLayer::SetVKBOpacity(qreal f)
	{
		int count;
		Button *btn;
		bool hasHide;

		hasHide = !isVisible();
		if(!hasHide)
			setVisible(false);
		count = m_layout->count();
		for(int i = 0; i < count; i++)
		{
			btn = dynamic_cast<Button *>(m_layout->itemAt(i)->widget());
			if(btn)
				btn->SetOpacity(f);
		}
		if(!hasHide)
			setVisible(true);
	}

	int VKBLayer::CurrentScheme() const
	{
		return m_currentScheme;
	}
}
