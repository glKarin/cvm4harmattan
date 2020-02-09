#include "vkbscheme.h"

#include <QDebug>

#include "vkblayout.h"
#include "softbutton.h"
#include "macros.h"

namespace karin
{
	VKBScheme::VKBScheme(VKBLayout *layout)
		: m_layout(layout)
	{
	}

	VKBScheme::~VKBScheme()
	{
		ID_DESTROY_DEBUG(VKBScheme)
	}

	VKBLayout * VKBScheme::Layout()
	{
		return m_layout;
	}

	void VKBScheme::SetLayout(VKBLayout *layout)
	{
		if(m_layout != layout)
			m_layout = layout;
	}

	void VKBScheme::Make()
	{
		if(!m_layout)
			return;
		ClearLayout();
		MakeLayout(m_layout);
	}

	int VKBScheme::SchemeHeight() const
	{
		return -1;
	}

	int VKBScheme::SchemeWidth() const
	{
		return -1;
	}

	void VKBScheme::ClearLayout()
	{
		if(!m_layout)
			return;
		m_layout->Clear();
	}
}
