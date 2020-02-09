#ifndef _KARIN_VKBSCHEME_H
#define _KARIN_VKBSCHEME_H

#include <QtGlobal>

namespace karin
{
	class VKBLayout;

	class VKBScheme
	{
		public:
			explicit VKBScheme(VKBLayout *layout = 0);
			~VKBScheme();
			VKBLayout * Layout();
			void SetLayout(VKBLayout *layout);
			void Make();
			virtual int SchemeHeight() const;
			virtual int SchemeWidth() const;

		protected:
			virtual void MakeLayout(VKBLayout *layout) = 0;

		private:
			void ClearLayout();

		private:
			VKBLayout *m_layout;

		private:
			Q_DISABLE_COPY(VKBScheme)
	};
}

#endif
