#include "button.h"

#include <QPainter>
#include <QFontMetrics>
#include <QDebug>

#include "macros.h"

#define FONT_METRICS_SAMPLE_CHAR 'K'

namespace karin
{
	Button::Button(QWidget *parent)
		: GraphicsWidget(parent),
		m_radius(0),
		m_border(0),
		m_checked(false),
		m_borderColor(Qt::blue),
		m_textColor(Qt::black),
		m_bgColor(Qt::white),
		m_pressedBorderColor(Qt::blue),
		m_pressedTextColor(Qt::white),
		m_pressedBgColor(Qt::blue),
		m_margin(0),
		m_paintType(Button::Button_Rect_Type),
		m_opacity(1.0)
	{
		setObjectName("karin_Button");
		Relayout();
	}

	Button::~Button()
	{
		ID_QOBJECT_DESTROY_DEBUG
	}

	void Button::DrawRectButton(QPainter &p)
	{
		QPen pen;
		QBrush brush;
		QPoint center(width() / 2, height() / 2);

		if(m_checked)
		{
			p.save();
			{
				brush = p.brush();
				brush.setStyle(Qt::SolidPattern);
				brush.setColor(m_pressedBgColor);
				p.setBrush(brush);
				//p.fillPath(m_path, brush);
				p.drawRoundedRect(m_rect, m_radius, m_radius);
			}
			p.restore();

			if(m_border > 0)
			{
				p.save();
				{
					pen = p.pen();
					pen.setWidth(m_border);
					pen.setColor(m_pressedBorderColor);
					p.setPen(pen);
					//p.drawPath(m_path);
					p.drawRoundedRect(m_rect, m_radius, m_radius);
				}
				p.restore();
			}

			if(!m_label.isEmpty())
			{
				p.save();
				{
					pen = p.pen();
					pen.setColor(m_pressedTextColor);
					p.setPen(pen);
					QFont f = p.font();
					f.setPixelSize(font().pixelSize());
					f.setBold(true);
					p.setFont(f);
					QFontMetrics m = p.fontMetrics();
					p.drawText(center - QPoint(m.width(m_label) / 2, -m.boundingRect(m_label[0]).height() / 2), m_label);
				}
				p.restore();
			}
		}
		else
		{
			p.save();
			{
				brush = p.brush();
				brush.setStyle(Qt::SolidPattern);
				brush.setColor(m_bgColor);
				p.setBrush(brush);
				//p.fillPath(m_path, brush);
				p.drawRoundedRect(m_rect, m_radius, m_radius);
			}
			p.restore();

			if(m_border > 0)
			{
				p.save();
				{
					pen = p.pen();
					pen.setWidth(m_border);
					pen.setColor(m_borderColor);
					p.setPen(pen);
					//p.drawPath(m_path);
					p.drawRoundedRect(m_rect, m_radius, m_radius);
				}
				p.restore();
			}

			if(!m_label.isEmpty())
			{
				p.save();
				{
					pen = p.pen();
					pen.setColor(m_textColor);
					p.setPen(pen);
					QFont f = p.font();
					f.setPixelSize(font().pixelSize());
					p.setFont(f);
					QFontMetrics m = p.fontMetrics();
					p.drawText(center - QPoint(m.width(m_label) / 2, -m.boundingRect(m_label[0]).height() / 2), m_label);
				}
				p.restore();
			}
		}
	}

	void Button::DrawCircleButton(QPainter &p)
	{
		QPen pen;
		QBrush brush;
		QPoint center(width() / 2, height() / 2);

		if(m_checked)
		{
			p.save();
			{
				brush = p.brush();
				brush.setStyle(Qt::SolidPattern);
				brush.setColor(m_pressedBgColor);
				p.setBrush(brush);
				p.drawEllipse(m_rect);
			}
			p.restore();

			if(m_border > 0)
			{
				p.save();
				{
					pen = p.pen();
					pen.setWidth(m_border);
					pen.setColor(m_pressedBorderColor);
					p.setPen(pen);
					p.drawEllipse(m_rect);
				}
				p.restore();
			}

			if(!m_label.isEmpty())
			{
				p.save();
				{
					pen = p.pen();
					pen.setColor(m_pressedTextColor);
					p.setPen(pen);
					QFont f = p.font();
					f.setPixelSize(font().pixelSize());
					f.setBold(true);
					p.setFont(f);
					QFontMetrics m = p.fontMetrics();
					p.drawText(center - QPoint(m.width(m_label) / 2, -m.boundingRect(m_label[0]).height() / 2), m_label);
				}
				p.restore();
			}
		}
		else
		{
			p.save();
			{
				brush = p.brush();
				brush.setStyle(Qt::SolidPattern);
				brush.setColor(m_bgColor);
				p.setBrush(brush);
				p.drawEllipse(m_rect);
			}
			p.restore();

			if(m_border > 0)
			{
				p.save();
				{
					pen = p.pen();
					pen.setWidth(m_border);
					pen.setColor(m_borderColor);
					p.setPen(pen);
					p.drawEllipse(m_rect);
				}
				p.restore();
			}

			if(!m_label.isEmpty())
			{
				p.save();
				{
					pen = p.pen();
					pen.setColor(m_textColor);
					p.setPen(pen);
					QFont f = p.font();
					f.setPixelSize(font().pixelSize());
					p.setFont(f);
					QFontMetrics m = p.fontMetrics();
					p.drawText(center - QPoint(m.width(m_label) / 2, -m.boundingRect(m_label[0]).height() / 2), m_label);
				}
				p.restore();
			}
		}
	}

	void Button::paintEvent(QPaintEvent *ev)
	{
		Q_UNUSED(ev);
		QPainter p(this);

		InitPainter(p);
		if(m_paintType == Button::Button_Circle_Type)
			DrawCircleButton(p);
		else
			DrawRectButton(p);
	}

	void Button::InitPainter(QPainter &p)
	{
		p.setOpacity(m_opacity);
		p.setRenderHint(QPainter::Antialiasing, true);
		p.setClipping(true);
		// p.setRenderHint(QPainter::TextAntialiasing, true);
	}

	void Button::TouchPressEvent(QTouchEvent *ev)
	{
		TouchEvent(1);
	}

	void Button::TouchMoveEvent(QTouchEvent *ev)
	{
		//TouchEvent(-1);
	}

	void Button::TouchReleaseEvent(QTouchEvent *ev)
	{
		TouchEvent(0);
	}

	void Button::TouchEvent(int type)
	{
		SetChecked(type == 1);
		emit clicked(type == 1);
		//repaint();
		update();
	}

	int Button::Radius() const
	{
		return m_radius;
	}

	void Button::SetRadius(int f)
	{
		int radius;
		
		radius = qMin(qMin(width() / 2, height() / 2), m_radius < 0 ? qMin(width(), height()) / 2 : m_radius);

		if(m_radius != radius)
		{
			m_radius = radius;
			CalePath();
		}
	}

	int Button::Border() const
	{
		return m_border;
	}

	void Button::SetBorder(int f)
	{
		if(m_border != f)
		{
			m_border = f;
			CaleRect();
			CalePath();
		}
	}

	void Button::CaleRect()
	{
		//const int _Margin = m_border;
		const int _Margin = m_margin;
		QRect r = rect();

		if(_Margin == 0)
		{
			m_rect = r;
			return;
		}

		m_rect.setX(r.left() + m_margin);
		m_rect.setY(r.top() + m_margin);
		m_rect.setWidth(r.width() - m_margin * 2);
		m_rect.setHeight(r.height() - m_margin * 2);

		if(!m_rect.isValid())
			m_rect = r;
	}

	void Button::CalePath()
	{
		QPainterPath path;
		
		path.moveTo(m_rect.topRight() - QPointF(m_radius, 0));
		path.lineTo(m_rect.topLeft() + QPointF(m_radius, 0));
		// TL
		path.quadTo(m_rect.topLeft(), m_rect.topLeft() + QPointF(0, m_radius));
		path.lineTo(m_rect.bottomLeft() + QPointF(0, -m_radius));
		// BL
		path.quadTo(m_rect.bottomLeft(), m_rect.bottomLeft() + QPointF(m_radius, 0));
		path.lineTo(m_rect.bottomRight() - QPointF(m_radius, 0));
		// BR
		path.quadTo(m_rect.bottomRight(), m_rect.bottomRight() + QPointF(0, -m_radius));
		path.lineTo(m_rect.topRight() + QPointF(0, m_radius));
		// TR
		path.quadTo(m_rect.topRight(), m_rect.topRight() + QPointF(-m_radius, 0));

		m_path = path;
	}

	void Button::Relayout()
	{
		CaleRect();
		CalePath();
	}

	void Button::resizeEvent(QResizeEvent *ev)
	{
		GraphicsWidget::resizeEvent(ev);
		Relayout();
	}

	void Button::SetChecked(bool on)
	{
		if(m_checked != on)
		{
			m_checked = on;
			emit checkedChanged(m_checked);
		}
	}

	bool Button::Checked() const
	{
		return m_checked;
	}

	void Button::SetTextColor(const QColor &color)
	{
		if(m_textColor != color)
		{
			m_textColor = color;
			repaint();
		}
	}

	void Button::SetBorderColor(const QColor &color)
	{
		if(m_borderColor != color)
		{
			m_borderColor = color;
			repaint();
		}
	}

	void Button::SetBgColor(const QColor &color)
	{
		if(m_bgColor != color)
		{
			m_bgColor = color;
			repaint();
		}
	}

	void Button::SetPressedTextColor(const QColor &color)
	{
		if(m_pressedTextColor != color)
		{
			m_pressedTextColor = color;
			repaint();
		}
	}

	void Button::SetPressedBorderColor(const QColor &color)
	{
		if(m_pressedBorderColor != color)
		{
			m_pressedBorderColor = color;
			repaint();
		}
	}

	void Button::SetPressedBgColor(const QColor &color)
	{
		if(m_pressedBgColor != color)
		{
			m_pressedBgColor = color;
			repaint();
		}
	}

	QColor Button::TextColor() const
	{
		return m_textColor;
	}

	QColor Button::BorderColor() const
	{
		return m_borderColor;
	}

	QColor Button::BgColor() const
	{
		return m_bgColor;
	}

	QColor Button::PressedTextColor() const
	{
		return m_pressedTextColor;
	}

	QColor Button::PressedBorderColor() const
	{
		return m_borderColor;
	}

	QColor Button::PressedBgColor() const
	{
		return m_pressedBgColor;
	}

	void Button::SetLabel(const QString &label)
	{
		if(m_label != label)
		{
			m_label = label;
			repaint();
		}
	}

	QString Button::Label() const
	{
		return m_label;
	}

	void Button::SetPaintType(int type)
	{
		if(m_paintType != type)
		{
			m_paintType = type;
			repaint();
		}
	}

	int Button::PaintType() const
	{
		return m_paintType;
	}

	void Button::SetMargin(int m)
	{
		if(m_margin != m)
		{
			m_margin = m;
			repaint();
		}
	}

	int Button::Margin() const
	{
		return m_margin;
	}

	void Button::SetOpacity(qreal m)
	{
		if(m_opacity != m)
		{
			m_opacity = m;
			repaint();
		}
	}

	qreal Button::Opacity() const
	{
		return m_opacity;
	}
}
