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
#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <QWidget>
#include <QLabel>
#include <QKeyEvent>
#include <QMutex>
#include <QMutexLocker>
#include <QMap>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _HARMATTAN
void resetFrameBufferSize(int w, int h);
void keyEvent(unsigned ch);
void mouseEvent(int x, int y, int pressed);
void enableStateChange();
bool isRotated();
#else
namespace karin
{
	class VKBLayer;
	class SettingWidget;
	class ToolIcon;
}
#endif

typedef QMap<unsigned short *,bool> Buffer;

class FrameBuffer : public QWidget
{
    Q_OBJECT

public:
    FrameBuffer(QWidget *parent = 0, int w = 480, int h = 640);
    void update(unsigned short * surface_buffer = (unsigned short *)0);
    void toggleFullScreen();
    Buffer buffer;

    void repaintPixmap(unsigned short * surface_buffer);
public slots:
    void repaintPixmap() {
        repaintPixmap(0);
    }

signals:
    void refresh();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

#ifdef _HARMATTAN
    virtual void mouseDoubleClickEvent(QMouseEvent *);
    virtual void keyReleaseEvent(QKeyEvent *event);
	virtual void focusInEvent(QFocusEvent *event);
	virtual void focusOutEvent(QFocusEvent *event);
	virtual void inputMethodEvent( QInputMethodEvent* event );
	virtual QVariant inputMethodQuery( Qt::InputMethodQuery query ) const;

	private Q_SLOTS:
		void OnInputMethodAreaChanged(const QRect &rect);

private:
	void OpenSoftwareInputPanel();
	void CloseSoftwareInputPanel();
	void ToggleSoftwareInputPanel();
	void SetVirtualKeyboardTranslucency(bool value);
	void SetVirtualKeyboardSuppression(bool value);
	void ResetViewport(const QSize &size, const QRect &imArea);
	void Init();
	void CalePixelRect(int bufferWidth, int bufferHeight, int screenWidth, int screenHeight, int mode = 0, bool force = false, bool rotated = false, bool rechange = false);
	void SetOrientation(int angle = 0);
	void UpdateStatusBar(bool statusBar);
	void UpdatePaintData(bool force = true, bool repaintThis = false);
	void GetMouseEventCoord(int *x, int *y, const QMouseEvent *event);

	private Q_SLOTS:
	void LockOrientation(int type = 0);
	void SetRotate(bool r);
	void SetVKBTranslucent(bool t);
	void SetVKBType(int type);
	void SetKeyboardOpacity(qreal t);
	void SetKeyboardScheme(int e);
	void SetForceFull(bool f);
	void SetFillMode(int e);
	void SetBgColor(const QColor &e);
#endif

private:
    int width;
    int height;
    unsigned short *pixeldata;
#ifdef _HARMATTAN
	// emulate device screen size
	int m_emuScrWidth;
	int m_emuScrHeight;
	// real emulate device screen size
	int m_bufferWidth;
	int m_bufferHeight;
	int m_fillMode;
	bool m_forceFull;
	bool m_vkbTranslucent;
	int m_vkbType;
	int m_keyboardScheme;
	int m_orientation;
	bool m_rotate;
	QColor m_bgColor;

	karin::VKBLayer *m_vkbLayer;
	karin::SettingWidget *m_settingWidget;
	karin::ToolIcon *m_settingIcon;
	QRect m_imageRect; // image size
	QRect m_paintRect; // paint geometry
#endif
};

#endif
