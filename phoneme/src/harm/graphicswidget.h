#ifndef _KARIN_GRAPHICSWIDGET_H
#define _KARIN_GRAPHICSWIDGET_H

#include <QWidget>

class QTouchEvent;

namespace karin
{
	class GraphicsWidget : public QWidget
	{
		Q_OBJECT

		public:
			explicit GraphicsWidget(QWidget *parent = 0);
			virtual ~GraphicsWidget();
			void SetFixedSize(const QSize &size);
			void SetFixedSize(int width, int height);
			void SetAcceptTouchEvents(bool b);
			bool AcceptTouchEvents() const;
			void SetBackgroundTransparent(bool on);
			bool IgnoreMouseEvents() const;
			void SetIgnoreMouseEvents(bool b);

Q_SIGNALS:
			void sizeChanged(const QSize &size);

		protected:
			virtual void resizeEvent(QResizeEvent *ev);
			virtual bool event(QEvent *ev);
			virtual void TouchPressEvent(QTouchEvent *ev);
			virtual void TouchMoveEvent(QTouchEvent *ev);
			virtual void TouchReleaseEvent(QTouchEvent *ev);
			virtual void mousePressEvent(QMouseEvent *ev);
			virtual void mouseMoveEvent(QMouseEvent *ev);
			virtual void mouseReleaseEvent(QMouseEvent *ev);

		private:
			bool m_acceptTouchEvents;
			bool m_ignoreMouseEvents;
	};
}

#endif
