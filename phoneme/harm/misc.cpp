#include "misc.h"

namespace karin
{
	Misc::Misc()
		: m_settings(new QSettings)
	{
	}

	Misc::~Misc()
	{
		delete m_settings;
	}

	Misc * Misc::Instance()
	{
		static Misc _misc;
		return &_misc;
	}

	const QVariantMap & Misc::DefaultSettings()
	{
		static QVariantMap _defaultSettings;
		if(_defaultSettings.isEmpty())
		{
			_defaultSettings.insert(KARIN_SETTING_SCREEN_WIDTH, 240);
			_defaultSettings.insert(KARIN_SETTING_SCREEN_HEIGHT, 320);
			_defaultSettings.insert(KARIN_SETTING_FILL_SCHEME, Misc::FillType_Fixed);
			_defaultSettings.insert(KARIN_SETTING_ORIENTATION, Misc::OrientationType_Portrait);
			_defaultSettings.insert(KARIN_SETTING_FIXED_SCREEN, false);
			_defaultSettings.insert(KARIN_SETTING_VKB_ENABLED, true);
			_defaultSettings.insert(KARIN_SETTING_VKB_TRANSLUCENT, true);
			_defaultSettings.insert(KARIN_SETTING_VKB_TYPE, Misc::VKBType_Application);
		}
		return _defaultSettings;
	}
}
