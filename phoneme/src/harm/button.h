#ifndef _KARIN_BUTTON_H
#define _KARIN_BUTTON_H

#include "graphicswidget.h"

namespace karin
{
	class Button : public GraphicsWidget
	{
		Q_OBJECT
		public:
			enum Button_Paint_Type_e
			{
				Button_Rect_Type = 0,
				Button_Circle_Type,
			};

		public:
			explicit Button(QWidget *parent = 0);
			virtual ~Button();
			int Radius() const;
			void SetRadius(int f);
			int Border() const;
			void SetBorder(int f);
			void SetChecked(bool on);
			bool Checked() const;
			void SetTextColor(const QColor &color);
			void SetBorderColor(const QColor &color);
			void SetBgColor(const QColor &color);
			void SetPressedTextColor(const QColor &color);
			void SetPressedBorderColor(const QColor &color);
			void SetPressedBgColor(const QColor &color);
			QColor TextColor() const;
			QColor BorderColor() const;
			QColor BgColor() const;
			QColor PressedTextColor() const;
			QColor PressedBorderColor() const;
			QColor PressedBgColor() const;
			void SetLabel(const QString &label);
			QString Label() const;
			void SetPaintType(int type);
			int PaintType() const;
			void SetMargin(int m);
			int Margin() const;
			void SetOpacity(qreal m);
			qreal Opacity() const;

		protected:
			virtual void paintEvent(QPaintEvent *ev);
			virtual void TouchPressEvent(QTouchEvent *ev);
			virtual void TouchMoveEvent(QTouchEvent *ev);
			virtual void TouchReleaseEvent(QTouchEvent *ev);
			virtual void resizeEvent(QResizeEvent *ev);
			void InitPainter(QPainter &p);

			private Q_SLOTS:
				void Relayout();

		private:
			void TouchEvent(int type);
			void CaleRect();
			void CalePath();
			void DrawCircleButton(QPainter &p);
			void DrawRectButton(QPainter &p);

Q_SIGNALS:
			void clicked(bool on = false);
			void checkedChanged(bool on);

		private:
			int m_radius;
			int m_border;
			bool m_checked;
			QColor m_borderColor;
			QColor m_textColor;
			QColor m_bgColor;
			QColor m_pressedBorderColor;
			QColor m_pressedTextColor;
			QColor m_pressedBgColor;
			QString m_label;
			int m_margin;
			int m_paintType;
			qreal m_opacity;

			QRect m_rect;
			QPainterPath m_path;

			Q_DISABLE_COPY(Button)
	};
}

#endif

