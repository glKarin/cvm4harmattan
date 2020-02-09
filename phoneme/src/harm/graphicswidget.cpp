#include "graphicswidget.h"

#include <QDebug>
#include <QTouchEvent>

#include "macros.h"

namespace karin
{
	GraphicsWidget::GraphicsWidget(QWidget *parent)
		: QWidget(parent)
	{
		setObjectName("karin_GraphicsWidget");
		SetAcceptTouchEvents(true);
		SetIgnoreMouseEvents(false);
		setAutoFillBackground(false);
		//setAttribute(Qt::WA_OpaquePaintEvent, true);
		SetBackgroundTransparent(true);
	}

	GraphicsWidget::~GraphicsWidget()
	{
		ID_QOBJECT_DESTROY_DEBUG
	}

	void GraphicsWidget::SetBackgroundTransparent(bool on)
	{
		setStyleSheet(on ? "background-color: transparent" : "");
		setAttribute(Qt::WA_TranslucentBackground, on);
	}

	void GraphicsWidget::SetFixedSize(const QSize &size)
	{
#if 0 // for QGraphicsWidget
		setMinimumSize(size);
		setMaximumSize(size);
#endif
		setFixedSize(size);
#if 0
		resize(size);
#endif
	}

	void GraphicsWidget::SetFixedSize(int width, int height)
	{
#if 0 // for QGraphicsWidget
		setMinimumSize(width, height);
		setMaximumSize(width, height);
#endif
		setFixedSize(width, height);
#if 0
		resize(width, height);
#endif
	}

	bool GraphicsWidget::event(QEvent *ev)
	{
		if(m_acceptTouchEvents)
		{
			switch(ev->type())
			{
				case QEvent::TouchBegin:
					TouchPressEvent(static_cast<QTouchEvent *>(ev));
					ev->accept();
					return true;
				case QEvent::TouchUpdate:
					TouchMoveEvent(static_cast<QTouchEvent *>(ev));
					ev->accept();
					return true;
				case QEvent::TouchEnd:
					TouchReleaseEvent(static_cast<QTouchEvent *>(ev));
					ev->accept();
					return true;
				default:
					break;
			}
		}
		return QWidget::event(ev);
	}

	void GraphicsWidget::TouchPressEvent(QTouchEvent *ev)
	{
	}

	void GraphicsWidget::TouchMoveEvent(QTouchEvent *ev)
	{
	}

	void GraphicsWidget::TouchReleaseEvent(QTouchEvent *ev)
	{
	}

	void GraphicsWidget::resizeEvent(QResizeEvent *ev)
	{
		emit sizeChanged(ev->size());
		QWidget::resizeEvent(ev);
	}

	void GraphicsWidget::mousePressEvent(QMouseEvent *ev)
	{
		if(!m_acceptTouchEvents)
			QWidget::mousePressEvent(ev);
		else
		{
			if(m_ignoreMouseEvents)
				ev->ignore();
			else
				ev->accept();
		}
	}

	void GraphicsWidget::mouseReleaseEvent(QMouseEvent *ev)
	{
		if(!m_acceptTouchEvents)
			QWidget::mouseReleaseEvent(ev);
		else
		{
			if(m_ignoreMouseEvents)
				ev->ignore();
			else
				ev->accept();
		}
	}

	void GraphicsWidget::mouseMoveEvent(QMouseEvent *ev)
	{
		if(!m_acceptTouchEvents)
			QWidget::mouseMoveEvent(ev);
	}

	void GraphicsWidget::SetAcceptTouchEvents(bool b)
	{
		m_acceptTouchEvents = b;
		setAttribute(Qt::WA_AcceptTouchEvents, m_acceptTouchEvents);
	}

	bool GraphicsWidget::AcceptTouchEvents() const
	{
		return m_acceptTouchEvents;
	}

	bool GraphicsWidget::IgnoreMouseEvents() const
	{
		return m_ignoreMouseEvents;
	}

	void GraphicsWidget::SetIgnoreMouseEvents(bool b)
	{
		m_ignoreMouseEvents = b;
	}
}
