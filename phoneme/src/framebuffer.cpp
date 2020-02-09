/*
 * Copyright  2012 Davy Preuveneers. All Rights Reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 only, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License version 2 for more details (a copy is
 * included at /legal/license.txt).
 *
 * You should have received a copy of the GNU General Public License
 * version 2 along with this work; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#include <QtGui>
#include <QMatrix>
#include <QMutexLocker>

#ifdef _HARMATTAN
#include <QtDeclarative>

#include <QX11Info>
#include <X11/Xlib.h>
#include <X11/Xatom.h>

//for maliit inpit method
#include <maliit/inputmethod.h>
#include <maliit/namespace.h>
#include <MInputMethodState>

#include "defs.h"
#include "cvm.h"
#include "harm/vkblayer.h"
#include "harm/settingwidget.h"
#include "harm/toolicon.h"

#endif

#include "framebuffer.h"

FrameBuffer::FrameBuffer(QWidget *parent, int w, int h) :
        QWidget(parent),
        width(w),
        height(h),
        pixeldata(0)
#ifdef _HARMATTAN
		,
		m_emuScrWidth(w),
		m_emuScrHeight(h),
		m_bufferWidth(0),
		m_bufferHeight(0),
		m_fillMode(karin::FillType_Fixed),
		m_forceFull(true),
		m_vkbTranslucent(true),
		m_vkbType(karin::VKBType_Disable),
		m_keyboardScheme(karin::KeyboardScheme_None),
		m_orientation(karin::OrientationType_Auto),
		m_rotate(false),
		m_bgColor(Qt::black),
		m_vkbLayer(new karin::VKBLayer(this)),
		m_settingWidget(new karin::SettingWidget(this)),
		m_settingIcon(new karin::ToolIcon(this))
#endif
{
#ifdef Q_WS_MAEMO_5
    setAttribute(Qt::WA_Maemo5AutoOrientation, true);
    setAttribute(Qt::WA_Maemo5NonComposited);
#endif

    setAttribute(Qt::WA_OpaquePaintEvent, true);

    setFixedSize(width, height);
    connect(this, SIGNAL(refresh()), this, SLOT(repaintPixmap()));

#ifdef _HARMATTAN
	Init();
#endif
}

void FrameBuffer::update(unsigned short * surface_buffer) {
    if (surface_buffer) {
        pixeldata = surface_buffer;
    }
    emit refresh();
}

void FrameBuffer::toggleFullScreen() {
    enableStateChange();

    bool isFullScreen = windowState() & Qt::WindowFullScreen;
    if (isFullScreen) {
        showNormal();
    } else {
        showFullScreen();
    }
}

void FrameBuffer::repaintPixmap(unsigned short * surface_buffer) {
    /*if (isRotated()) {
        QImage image((uchar *)pixeldata, height, width, QImage::Format_RGB16);
        QPixmap pixmap = QPixmap::fromImage(image);

        QMatrix rm;
        rm.rotate(270);
        setPixmap(pixmap.transformed(rm));
    } else {
        QImage image((uchar *)pixeldata, width, height, QImage::Format_RGB16);
        QPixmap pixmap = QPixmap::fromImage(image);
        setPixmap(QPixmap::fromImage(image));
    }*/
    if (surface_buffer) {
        pixeldata = surface_buffer;
    }
    repaint();
}

void FrameBuffer::resizeEvent(QResizeEvent * event) {
#ifdef _HARMATTAN
	int w, h;

	QWidget::resizeEvent(event);
	w = QWidget::width();
	h = QWidget::height();
	ResetViewport(event->size(), MInputMethodState::instance()->inputMethodArea());
	m_vkbLayer->SetMinimalGeometry(0, 0, w, h);
	m_settingWidget->setGeometry(0, 0, w, h);
	m_settingIcon->move(w - m_settingIcon->width(), 0);
#else
	width = event->size().width();
	height = event->size().height();
    resetFrameBufferSize(width, height);
#endif
}

void FrameBuffer::keyPressEvent(QKeyEvent *event) {
    unsigned short ch = 0x00;

    QString text = event->text();
#ifdef _HARMATTAN
	if (event->modifiers() & Qt::ControlModifier) {
		switch (event->key()) {
			case Qt::Key_Up:
				toggleFullScreen();
				break;
			case Qt::Key_Left:
				ch = 0x05;
				break;
			case Qt::Key_Right:
				ch = 0x06;
				break;
			case Qt::Key_Backspace:
				qApp->quit();
				break;
				// for test
			case Qt::Key_R:
				SetRotate(!m_rotate);
				break;
			case Qt::Key_B:
				static bool sb = true;
				UpdateStatusBar(sb);
				sb = !sb;
			case Qt::Key_O:
				LockOrientation((m_orientation + 1) % 3);
				break;
			case Qt::Key_F:
				SetForceFull(!m_forceFull);
				break;
			case Qt::Key_M:
				++m_fillMode;
				SetFillMode((m_fillMode + 1) % 5);
				break;
			case Qt::Key_T:
				SetVKBTranslucent(!m_vkbTranslucent);
				break;
			case Qt::Key_K:
				SetKeyboardScheme(m_keyboardScheme ^ 1);
				break;
		}
	} else {
		switch (event->key()) {
			case Qt::Key_Up:
				ch = 0x01;
				break;
			case Qt::Key_Down:
				ch = 0x02;
				break;
			case Qt::Key_Left:
				ch = 0x03;
				break;
			case Qt::Key_Right:
				ch = 0x04;
				break;
			case Qt::Key_Escape:
				qApp->quit();
				break;
			case Qt::Key_F11:
				toggleFullScreen();
				break;
		}
	}
	if (ch == 0x00 && text.length() > 0) {
		ch = text.at(0).unicode();
	}

#else
    if (text.length() > 0) {
        ch = text.at(0).unicode();
    } else {
        if (event->modifiers() & Qt::ControlModifier) {
            switch (event->key()) {
            case Qt::Key_Up:
                toggleFullScreen();
                break;
            case Qt::Key_Left:
                ch = 0x05;
                break;
            case Qt::Key_Right:
                ch = 0x06;
                break;
            }
        } else {
            switch (event->key()) {
            case Qt::Key_Up:
                ch = 0x01;
                break;
            case Qt::Key_Down:
                ch = 0x02;
                break;
            case Qt::Key_Left:
                ch = 0x03;
                break;
            case Qt::Key_Right:
                ch = 0x04;
                break;
            case Qt::Key_Escape:
                qApp->quit();
                break;
            case Qt::Key_F11:
                toggleFullScreen();
                break;
            }
        }
    }
#endif

#ifdef _HARMATTAN
	if(ch != 0x00)
		keyEvent(ch, 1);
#else
    keyEvent(ch);
#endif
}

void FrameBuffer::mousePressEvent(QMouseEvent* event) {
#ifdef _HARMATTAN
	int x, y;
	GetMouseEventCoord(&x, &y, event);
#else
    int x = event->x();
    int y = event->y();
#endif

    mouseEvent(x, y, 1);
}

void FrameBuffer::mouseMoveEvent(QMouseEvent* event) {
#ifdef _HARMATTAN
	int x, y;
	GetMouseEventCoord(&x, &y, event);
#else
    int x = event->x();
    int y = event->y();
#endif

    mouseEvent(x, y, 1);
}

void FrameBuffer::mouseReleaseEvent(QMouseEvent* event) {
#ifdef _HARMATTAN
	int x, y;
	GetMouseEventCoord(&x, &y, event);
#else
    int x = event->x();
    int y = event->y();
#endif

    mouseEvent(x, y, 0);
}

void FrameBuffer::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

#ifdef _HARMATTAN
	painter.fillRect(geometry(), m_bgColor);
#endif

    if (pixeldata) {
#ifdef _HARMATTAN
        if (m_rotate) 
#else
        if (isRotated()) 
#endif
		{
#ifdef _HARMATTAN
            QImage image((uchar *)pixeldata, m_bufferWidth, m_bufferHeight, QImage::Format_RGB16);
#else
            QImage image((uchar *)pixeldata, height, width, QImage::Format_RGB16);
#endif
            QPixmap pixmap = QPixmap::fromImage(image);

            QMatrix rm;
            rm.rotate(270);

#ifdef _HARMATTAN
            painter.drawPixmap(m_paintRect, pixmap.transformed(rm), m_imageRect);
#else
            painter.drawPixmap(geometry(), pixmap.transformed(rm), geometry());
#endif
            buffer[pixeldata] = false;
        } else {
#ifdef _HARMATTAN
            QImage image((uchar *)pixeldata, m_bufferWidth, m_bufferHeight, QImage::Format_RGB16);
            painter.drawImage(m_paintRect, image, m_imageRect);
			//qDebug()<<m_bufferWidth<<m_bufferHeight<<m_imageRect<<m_paintRect;
#else
            QImage image((uchar *)pixeldata, width, height, QImage::Format_RGB16);
            painter.drawImage(geometry(), image, geometry());
#endif
            buffer[pixeldata] = false;
        }
    }
}

#ifdef _HARMATTAN
void FrameBuffer::focusInEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

	OpenSoftwareInputPanel();
}

void FrameBuffer::focusOutEvent(QFocusEvent *event)
{
    Q_UNUSED(event);

	CloseSoftwareInputPanel();
}

void FrameBuffer::inputMethodEvent( QInputMethodEvent* event )
{
    if (event->commitString().isEmpty()) {
        event->ignore();
        return;
    }
	const QString &commitString = event->commitString();
	foreach(const QChar &str, commitString)
		keyEvent(str.unicode(), 1);
	//event->setCommitString(QString());
	event->accept();
}

QVariant FrameBuffer::inputMethodQuery( Qt::InputMethodQuery query ) const
{
	return QWidget::inputMethodQuery(query);
}

void FrameBuffer::OpenSoftwareInputPanel()
{
	//MInputMethodState::requestSoftwareInputPanel();
    QInputContext *inputContext;
	
	inputContext = qApp->inputContext();

    if (!inputContext) {
        return;
    }

    QEvent request(QEvent::RequestSoftwareInputPanel);
    inputContext->filterEvent(&request);
}

void FrameBuffer::CloseSoftwareInputPanel()
{
	//MInputMethodState::closeSoftwareInputPanel();
    QInputContext *inputContext;
	
	inputContext = qApp->inputContext();

    if (!inputContext) {
        return;
    }

    QEvent close(QEvent::CloseSoftwareInputPanel);
    inputContext->filterEvent(&close);
    inputContext->reset();
}

void FrameBuffer::SetVirtualKeyboardTranslucency(bool value)
{
	QInputContext *ic;

	setProperty(Maliit::InputMethodQuery::translucentInputMethod, QVariant(value));

	ic = qApp->inputContext();
	if(ic)
		ic->update();
	//setFocus(Qt::MouseFocusReason);
}

void FrameBuffer::SetVirtualKeyboardSuppression(bool value)
{
	QInputContext *ic;

	setProperty(Maliit::InputMethodQuery::suppressInputMethod, QVariant(!value));

	ic = qApp->inputContext();
	if(ic)
		ic->update();
}

void FrameBuffer::OnInputMethodAreaChanged(const QRect &rect)
{
	ResetViewport(size(), rect);
	if(rect.isEmpty())
	{
		if(m_vkbType == 2 || m_vkbType == 3)
			SetVirtualKeyboardSuppression(false);
	}
}

void FrameBuffer::ResetViewport(const QSize &size, const QRect &imArea)
{
	int w, h;
	int newHeight;
	int newWidth;

    if (m_vkbTranslucent || imArea.isEmpty())
	{ // vkb is not up
		w = size.width();
		h = size.height();
    }
    // vkb is up
    else
	{
		w = size.width();
		h = size.height();
        
        newHeight = 0; // = where vkb starts - status bar
        newWidth = 0; // = where vkb starts - status bar
        if (imArea.x() == 0)
		{ // landscape
            newHeight = imArea.y() - this->y();
        }
        else if (imArea.y() == 0)
		{ // portrait
            newWidth = imArea.x() - this->x();
        }

        if (newHeight > 0)
		{  // resize to occupy area not taken  by vkb
			h = newHeight;
        }
        if (newWidth > 0)
		{  // resize to occupy area not taken  by vkb
			w = newWidth;
        }
    }

	CalePixelRect(m_emuScrWidth, m_emuScrHeight, w, h, m_fillMode, m_forceFull, m_rotate, true);
	//qDebug() <<"||||||||"<< w << h <<size << imArea;
}

void FrameBuffer::Init()
{
	int w, h;

	w = QWidget::width();
	h = QWidget::height();
	// read global settings, not from QSettings
	m_bgColor = global_framebuffer_background_color;
	m_forceFull = global_full_framebuffer;
	m_fillMode = global_paint_scheme;
	m_vkbTranslucent = global_vkb_translucent;
	m_emuScrWidth = global_buffer_width;
	m_emuScrHeight = global_buffer_height;
	m_keyboardScheme = global_keyboard_scheme;
	m_orientation = global_orientation;
	m_rotate = isRotated();

	setWindowFlags(Qt::Window);

	// enable sofeware input method
	setAttribute(Qt::WA_InputMethodEnabled, true);
	setInputMethodHints(inputMethodHints() | Qt::ImhNoPredictiveText | Qt::ImhNoAutoUppercase);
	setFocusPolicy(Qt::StrongFocus); // trigger inputMethodQuery
	connect(MInputMethodState::instance(),
			SIGNAL(inputMethodAreaChanged(const QRect&)),
			this, SLOT(OnInputMethodAreaChanged(const QRect&)),
			Qt::UniqueConnection);

	// set initial state
	SetVirtualKeyboardTranslucency(m_vkbTranslucent);
	SetVirtualKeyboardSuppression(m_vkbType != 0);
	LockOrientation(0);
	m_settingWidget->SetVKBType(m_vkbType);
	m_settingWidget->SetOrientation(m_orientation);
	m_settingWidget->SetForceFull(m_forceFull);
	m_settingWidget->SetKeyboardScheme(m_keyboardScheme);
	m_settingWidget->SetKeyboardOpacity(1.0);
	m_settingWidget->SetVKBTranslucent(m_vkbTranslucent);
	m_settingWidget->SetFillMode(m_fillMode);
	m_settingWidget->SetBackgroundColor(m_bgColor);

	// cale initial value
	//m_forceFull = false;
	//m_rotate = false;
	CalePixelRect(m_emuScrWidth, m_emuScrHeight, width, height, m_fillMode, m_forceFull, m_rotate, true);

	m_vkbLayer->SetMinimalGeometry(0, 0, w, h);
	m_settingIcon->SetIcon("/usr/share/themes/blanco/meegotouch/icons/icon-m-toolbar-view-menu-white.png");
	m_settingWidget->setGeometry(0, 0, w, h);
	m_settingIcon->setFixedSize(64, 64);
	m_settingIcon->move(w - m_settingIcon->width(), 0);
	m_settingWidget->hide();
	m_settingIcon->stackUnder(m_settingWidget);

	connect(m_settingIcon, SIGNAL(clicked()), m_settingWidget, SLOT(show()));
	connect(m_settingWidget, SIGNAL(setOrientation(int)), this, SLOT(LockOrientation(int)));
	connect(m_settingWidget, SIGNAL(setKeyboardScheme(int)), this, SLOT(SetKeyboardScheme(int)));
	connect(m_settingWidget, SIGNAL(setVKBType(int)), this, SLOT(SetVKBType(int)));
	connect(m_settingWidget, SIGNAL(setVKBTranslucent(bool)), this, SLOT(SetVKBTranslucent(bool)));
	connect(m_settingWidget, SIGNAL(setKeyboardOpacity(qreal)), this, SLOT(SetKeyboardOpacity(qreal)));
	connect(m_settingWidget, SIGNAL(setFillMode(int)), this, SLOT(SetFillMode(int)));
	connect(m_settingWidget, SIGNAL(setForceFull(bool)), this, SLOT(SetForceFull(bool)));
	connect(m_settingWidget, SIGNAL(setBackgroundColor(const QColor &)), this, SLOT(SetBgColor(const QColor &)));
}

void FrameBuffer::CalePixelRect(int bufferWidth, int bufferHeight, int screenWidth, int screenHeight, int mode, bool forceFull, bool rotated, bool rechange)
{
	int x, y, w, h;
	int imageRectWidth, imageRectHeight;
	int newBufferWidth, newBufferHeight;
	int newScreenWidth, newScreenHeight;
	bool changed;
	float a, b, f;

	if(bufferWidth <= 0 || bufferHeight <= 0 || screenWidth <= 0 || screenHeight <= 0)
		return;

	x = 0;
	y = 0;
	changed = rechange;
	newBufferWidth = bufferWidth;
	newBufferHeight = bufferHeight;
	newScreenWidth = rotated ? screenHeight : screenWidth;
	newScreenHeight = rotated ? screenWidth : screenHeight;

	//qDebug()<<bufferWidth<<bufferHeight<<screenWidth<<screenHeight<<mode<<forceFull<<rotated<<rechange;
	if(forceFull) // QRect(0,0 854x480) QRect(0,0 854x480)
	{
		newBufferWidth = newScreenWidth;
		newBufferHeight = newScreenHeight;
		imageRectWidth = w = screenWidth;
		imageRectHeight = h = screenHeight;
	}
	else
	{
		if(mode == karin::FillType_Stratch) // stratch / top-left
		{
			a = (float)bufferWidth / (float)bufferHeight;
			b = (float)newScreenWidth / (float)newScreenHeight;
			f = a < b ? ((float)newScreenHeight / (float)bufferHeight) : ((float)newScreenWidth / (float)bufferWidth);
			//qDebug()<<f<<a<<b;
			w = (int)floor(bufferWidth * f);
			h = (int)floor(bufferHeight * f);
			imageRectWidth = rotated ? bufferHeight : bufferWidth;
			imageRectHeight = rotated ? bufferWidth : bufferHeight;
			if(rotated)
				qSwap(w, h);
		}
		else if(mode == karin::FillType_Fill) // stratch / center
		{
			a = (float)bufferWidth / (float)bufferHeight;
			b = (float)newScreenWidth / (float)newScreenHeight;
			f = a < b ? ((float)newScreenHeight / (float)bufferHeight) : ((float)newScreenWidth / (float)bufferWidth);
			//qDebug()<<f<<a<<b;
			w = (int)floor(bufferWidth * f);
			h = (int)floor(bufferHeight * f);
			imageRectWidth = rotated ? bufferHeight : bufferWidth;
			imageRectHeight = rotated ? bufferWidth : bufferHeight;
			if(rotated)
				qSwap(w, h);
			x = screenWidth / 2 - w / 2;
			y = screenHeight / 2 - h / 2;
		}
		else if(mode == karin::FillType_Full) // fill / top-left
		{
			imageRectWidth = rotated ? bufferHeight : bufferWidth;
			imageRectHeight = rotated ? bufferWidth : bufferHeight;
			w = screenWidth;
			h = screenHeight;
		}
		else if(mode == karin::FillType_Auto) // fixed size / center
		{
			imageRectWidth = w = rotated ? bufferHeight : bufferWidth;
			imageRectHeight = h = rotated ? bufferWidth : bufferHeight;
			x = screenWidth / 2 - imageRectWidth / 2;
			y = screenHeight / 2 - imageRectHeight / 2;
		}
		else
		{
			imageRectWidth = w = rotated ? bufferHeight : bufferWidth;
			imageRectHeight = h = rotated ? bufferWidth : bufferHeight;
			if(rotated)
				y = screenHeight - bufferWidth;
		}
	}

	// set widget size
	if(rechange || width != screenWidth || height != screenHeight)
	{
		width = screenWidth;
		height = screenHeight;
		changed = true;
	}
	// set framebuffer size
	if(rechange || m_bufferWidth != newBufferWidth || m_bufferHeight != newBufferHeight)
	{
		m_bufferWidth = newBufferWidth;
		m_bufferHeight = newBufferHeight;
		if(pixeldata && buffer.contains(pixeldata))
			buffer[pixeldata] = false;
		pixeldata = 0; // Must seset to NULL, otherwise pixel data is invalid when repaint. Because resetFrameBufferSize() will call FrameBuffer::update(), but the current pixel data pointer is invalid in Qt, and CVM realloc a new memory data.
		resetFrameBufferSize(m_bufferWidth, m_bufferHeight);
		changed = true;
	}
	//qDebug() << m_bufferWidth << m_bufferHeight<<width<<height;

	if(!changed)
		return;

	m_imageRect.setWidth(imageRectWidth);
	m_imageRect.setHeight(imageRectHeight);

	m_paintRect.setX(x);
	m_paintRect.setY(y);
	m_paintRect.setWidth(w);
	m_paintRect.setHeight(h);

	//qDebug() << m_paintRect <<m_imageRect<<forceFull;
	//qDebug()<<"----------------";

	repaint(); // update
}

void FrameBuffer::keyReleaseEvent(QKeyEvent *event) {
	unsigned short ch = 0x00;

	QString text = event->text();
	if (event->modifiers() & Qt::ControlModifier) {
		switch (event->key()) {
			case Qt::Key_Left:
				ch = 0x05;
				break;
			case Qt::Key_Right:
				ch = 0x06;
				break;
		}
	} else {
		switch (event->key()) {
			case Qt::Key_Up:
				ch = 0x01;
				break;
			case Qt::Key_Down:
				ch = 0x02;
				break;
			case Qt::Key_Left:
				ch = 0x03;
				break;
			case Qt::Key_Right:
				ch = 0x04;
				break;
		}
	}

	if (ch == 0x00 && text.length() > 0) {
		ch = text.at(0).unicode();
	}

	if(ch != 0x00)
		keyEvent(ch, 0);
}

void FrameBuffer::SetOrientation(int angle)
{
	Display *display;
	WId wid;

	display = QX11Info::display();

	if (!display)
		return;

	wid = winId();
	if(wid == 0)
		return;

	//qDebug() << angle;
	Atom orientationAngleAtom = XInternAtom(display, "_MEEGOTOUCH_ORIENTATION_ANGLE", False);

	XChangeProperty(display, wid, orientationAngleAtom, XA_CARDINAL, 32,
			PropModeReplace, (unsigned char*)&angle, 1);

	MInputMethodState::instance()->setActiveWindowOrientationAngle(M::OrientationAngle(angle));
}

void FrameBuffer::LockOrientation(int type)
{
	if(type == 1)
	{
		m_rotate = true;
		SetOrientation(270);
		setAttribute(Qt::WA_LockPortraitOrientation, true);
	}
	else if(type == 2)
	{
		m_rotate = false;
		SetOrientation(0);
		setAttribute(Qt::WA_LockLandscapeOrientation, true);
	}
	else
	{
		setAttribute(Qt::WA_AutoOrientation, true);
	}
	UpdatePaintData(true, true);
}

void FrameBuffer::SetRotate(bool r)
{
	if(m_rotate != r)
	{
		m_rotate = r;
		UpdatePaintData(true, true);
	}
}

void FrameBuffer::SetVKBTranslucent(bool t)
{
	if(m_vkbTranslucent != t)
	{
		m_vkbTranslucent = t;
		SetVirtualKeyboardTranslucency(m_vkbTranslucent);
		UpdatePaintData(true, true);
	}
}

void FrameBuffer::SetKeyboardOpacity(qreal t)
{
	m_vkbLayer->SetVKBOpacity(t);
}

void FrameBuffer::UpdateStatusBar(bool statusBar)
{
	unsigned long data[4] = {0};

	if (statusBar) {
		//QRectF statusBarGeometry = statusBar->geometry();
		QRectF mappedStatusBarGeometry(0, 0, size().width(), 36);
		data[0] = mappedStatusBarGeometry.x();
		data[1] = mappedStatusBarGeometry.y();
		data[2] = mappedStatusBarGeometry.width();
		data[3] = mappedStatusBarGeometry.height();
	}

	//qDebug() <<statusBar << data[0] <<data[1] <<data[2]<<data[3];

	Display *dpy = QX11Info::display();

	Atom a = XInternAtom(dpy, "_MEEGOTOUCH_MSTATUSBAR_GEOMETRY", False);
	WId w = winId();
	if (!statusBar)
		XDeleteProperty(dpy, w, a);
	else
		XChangeProperty(dpy, w, a, XA_CARDINAL, 32, PropModeReplace,
				(unsigned char*)data, 4);
}

void FrameBuffer::UpdatePaintData(bool force, bool repaintThis)
{
	ResetViewport(size(), MInputMethodState::instance()->inputMethodArea());
	//CalePixelRect(m_emuScrWidth, m_emuScrHeight, width, height, m_fillMode, m_forceFull, m_rotate, force);
	if(repaintThis)
		repaintPixmap();
}

void FrameBuffer::GetMouseEventCoord(int *x, int *y, const QMouseEvent *event)
{
	int mx, my;
	float f, fh;

	mx = event->x();
	my = event->y();
	if(m_forceFull)
	{
		if(m_rotate)
		{
			*x = height - my;
			*y = mx;
		}
		else
		{
			*x = mx;
			*y = my;
		}
	}
	else
	{
		if(m_fillMode == karin::FillType_Stratch) // stratch / top-left
		{
			f = (float)m_bufferWidth / (float)(m_rotate ? m_paintRect.height() : m_paintRect.width());
			if(m_rotate)
			{
				*x = (int)qRound((height - my) * f);
				*y = (int)qRound(mx * f);
			}
			else
			{
				*x = (int)qRound(mx * f);
				*y = (int)qRound(my * f);
			}
		}
		else if(m_fillMode == karin::FillType_Fill) // stratch / center
		{
			f = (float)m_bufferWidth / (float)(m_rotate ? m_paintRect.height() : m_paintRect.width());
			if(m_rotate)
			{
				*x = (int)qRound((height - my - m_paintRect.y()) * f);
				*y = (int)qRound((mx - m_paintRect.x()) * f);
			}
			else
			{
				*x = (int)qRound((mx - m_paintRect.x()) * f);
				*y = (int)qRound((my - m_paintRect.y()) * f);
			}
		}
		else if(m_fillMode == karin::FillType_Full) // fill / top-left
		{
			f = (float)(m_bufferWidth) / (float)(m_rotate ? m_paintRect.height() : m_paintRect.width());
			fh = (float)m_bufferHeight / (float)(m_rotate ? m_paintRect.width() : m_paintRect.height());
			if(m_rotate)
			{
				*x = (int)qRound((height - my) * f);
				*y = (int)qRound(mx * fh);
			}
			else
			{
				*x = (int)qRound(mx * f);
				*y = (int)qRound(my * fh);
			}
		}
		else if(m_fillMode == karin::FillType_Auto) // fixed size / center
		{
			if(m_rotate)
			{
				*x = height - my - m_paintRect.y();
				*y = mx - m_paintRect.x();
			}
			else
			{
				*x = mx - m_paintRect.x();
				*y = my - m_paintRect.y();
			}
		}
		else
		{
			if(m_rotate)
			{
				*x = height - my;
				*y = mx;
			}
			else
			{
				*x = mx;
				*y = my;
			}
		}
	}
}

void FrameBuffer::SetKeyboardScheme(int e)
{
	if(m_keyboardScheme != e)
	{
		m_keyboardScheme = e;
		m_vkbLayer->SetVKBScheme(m_keyboardScheme);
	}
}

void FrameBuffer::SetVKBType(int type)
{
	if(m_vkbType != type)
	{
		m_vkbType = type;
		SetVirtualKeyboardSuppression(m_vkbType != 0);
		UpdatePaintData(true, true);
	}
}

void FrameBuffer::mouseDoubleClickEvent(QMouseEvent *ev)
{
	if(m_vkbType == 2)
		ToggleSoftwareInputPanel();
	QWidget::mouseDoubleClickEvent(ev);
}

void FrameBuffer::ToggleSoftwareInputPanel()
{
	QRect imArea = MInputMethodState::instance()->inputMethodArea();
	if(imArea.isEmpty())
	{
		SetVirtualKeyboardSuppression(true);
		OpenSoftwareInputPanel();
	}
	else
	{
		CloseSoftwareInputPanel();
		SetVirtualKeyboardSuppression(false);
	}
}

void FrameBuffer::SetForceFull(bool f)
{
	if(m_forceFull != f)
	{
		m_forceFull = f;
		UpdatePaintData(true, true);
	}
}

void FrameBuffer::SetFillMode(int e)
{
	if(m_fillMode != e)
	{
		m_fillMode = e;
		UpdatePaintData(true, true);
	}
}

void FrameBuffer::SetBgColor(const QColor &e)
{
	if(m_bgColor != e)
	{
		m_bgColor = e;
		update();
	}
}

#endif
