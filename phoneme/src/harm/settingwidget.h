#ifndef _KARIN_SETTINGWIDGET_H
#define _KARIN_SETTINGWIDGET_H

#include <QDeclarativeView>
#include <QColor>

namespace karin
{
	class SettingWidget : public QDeclarativeView
	{
		Q_OBJECT
		public:
			explicit SettingWidget(QWidget *parent = 0);
			virtual ~SettingWidget();
			void SetVKBType(int scheme);
			void SetOrientation(int orientation);
			void SetForceFull(bool full);
			void SetKeyboardScheme(int scheme);
			void SetVKBTranslucent(bool translucent);
			void SetKeyboardOpacity(qreal opacity);
			void SetFillMode(int mode);
			void SetBackgroundColor(const QColor &color);

Q_SIGNALS:
			void setVKBType(int scheme);
			void setOrientation(int orientation);
			void setForceFull(bool full);
			void setKeyboardScheme(int scheme);
			void setVKBTranslucent(bool translucent);
			void setKeyboardOpacity(qreal opacity);
			void setFillMode(int mode);
			void setBackgroundColor(const QColor &backgroundColor);

		private:
			void Init();
			Q_DISABLE_COPY(SettingWidget)
	};
}

#endif
