#ifndef _KARIN_MISC_H
#define _KARIN_MISC_H

#include <QSettings>

#define KARIN_SETTING_SCREEN_WIDTH "cvm/width"
#define KARIN_SETTING_SCREEN_HEIGHT "cvm/height"
#define KARIN_SETTING_FIXED_SCREEN "cvm/fixed_screen"
#define KARIN_SETTING_FILL_SCHEME "frontend/fill_scheme"
#define KARIN_SETTING_ORIENTATION "frontend/orientation"
#define KARIN_SETTING_VKB_ENABLED "frontend/vkb_ebabled"
#define KARIN_SETTING_VKB_TYPE "frontend/vkb_type"
#define KARIN_SETTING_VKB_TRANSLUCENT "frontend/vkb_translucent"

namespace karin
{
	class Misc
	{
		public:
			enum FillType_e
			{
				FillType_Fixed = 0, // top-left, fixed width and height
				FillType_Stratch, // top-left, auto fill width, height
				FillType_Auto, // auto x, 0, fixed width, height
				FillType_Fill, // auto x, 0, auto fill width, height
				FillType_Full, // 0, 0, full width, height
			};
			enum OrientationType_e
			{
				OrientationType_Auto = 0,
				OrientationType_Portrait,
				OrientationType_Landscape,
			};
			enum VKBType_e
			{
				VKBType_System = 0,
				VKBType_Application,
			};

		public:
			virtual ~Misc();
			static Misc * Instance();
			template <class T> T GetSetting(const QString &key);
			template <class T> void SetSetting(const QString &key, const T &value);
			template <class T> T GetSetting(const QString &key, const T &defValue);

		private:
			QSettings *m_settings;

		private:
			explicit Misc();
			static const QVariantMap & DefaultSettings();
			Q_DISABLE_COPY(Misc)
	};

	template <class T> 
		T Misc::GetSetting(const QString &key)
		{
			T r = T();
			const QVariantMap &DS = DefaultSettings();

			if(!DS.contains(key))
				return r;
			QVariant v = m_settings->value(key, DS[key]);
			if(v.canConvert<T>())
				r = v.value<T>();

			return r;
		}

	template <class T>
		void Misc::SetSetting(const QString &key, const T &value)
		{
			const QVariantMap &DS = DefaultSettings();
			if(!DS.contains(key))
				return;

			m_settings->value(key, QVariant(value));
		}

	template <class T> 
		T Misc::GetSetting(const QString &key, const T &defValue)
		{
			T r = T();
			const QVariantMap &DS = DefaultSettings();

			QVariant v = m_settings->value(key, DS.contains(key) ? DS[key] : defValue);
			if(v.canConvert<T>())
				r = v.value<T>();

			return r;
		}

}

#endif
