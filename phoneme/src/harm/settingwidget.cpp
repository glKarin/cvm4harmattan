#include "settingwidget.h"

#include <QApplication>
#include <QDeclarativeItem>
#include <QDebug>

#include "macros.h"

namespace karin
{
	SettingWidget::SettingWidget(QWidget *parent)
		: QDeclarativeView(parent)
	{
		setObjectName("karin_SettingWidget");
		setResizeMode(QDeclarativeView::SizeRootObjectToView);
		setSource(QUrl::fromLocalFile("qml/SettingItem.qml"));
		setAttribute(Qt::WA_TranslucentBackground, true);
		setStyleSheet("background-color: transparent");

		Init();
	}

	SettingWidget::~SettingWidget()
	{
		ID_QOBJECT_DESTROY_DEBUG
	}

	void SettingWidget::Init()
	{
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		connect(item, SIGNAL(close()), this, SLOT(close()));
		connect(item, SIGNAL(quit()), qApp, SLOT(quit()));
		connect(item, SIGNAL(orientationSetting(int)), this, SIGNAL(setOrientation(int)));
		connect(item, SIGNAL(vkbTranslucentSetting(bool)), this, SIGNAL(setVKBTranslucent(bool)));
		connect(item, SIGNAL(vkbTypeSetting(int)), this, SIGNAL(setVKBType(int)));
		connect(item, SIGNAL(keyboardSchemeSetting(int)), this, SIGNAL(setKeyboardScheme(int)));
		connect(item, SIGNAL(keyboardOpacitySetting(qreal)), this, SIGNAL(setKeyboardOpacity(qreal)));
		connect(item, SIGNAL(forceFullSetting(bool)), this, SIGNAL(setForceFull(bool)));
		connect(item, SIGNAL(fillModeSetting(int)), this, SIGNAL(setFillMode(int)));
		connect(item, SIGNAL(backgroundColorSetting(const QColor &)), this, SIGNAL(setBackgroundColor(const QColor &)));
	}

	void SettingWidget::SetVKBType(int scheme)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetVKBType", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, scheme));
	}

	void SettingWidget::SetOrientation(int orientation)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetOrientation", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, orientation));
	}

	void SettingWidget::SetForceFull(bool full)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetForceFull", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, full));
	}

	void SettingWidget::SetKeyboardScheme(int scheme)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetKeyboardScheme", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, scheme));
	}

	void SettingWidget::SetVKBTranslucent(bool translucent)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetVKBTranslucent", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, translucent));
	}

	void SettingWidget::SetKeyboardOpacity(qreal opacity)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetKeyboardOpacity", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, opacity));
	}

	void SettingWidget::SetFillMode(int mode)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetFillMode", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, mode));
	}

	void SettingWidget::SetBackgroundColor(const QColor &color)
	{
		QVariant ret;
		QDeclarativeItem *item;

		item = qobject_cast<QDeclarativeItem *>(rootObject());
		QMetaObject::invokeMethod(item, "_SetBackgroundColor", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, color));
	}
}
