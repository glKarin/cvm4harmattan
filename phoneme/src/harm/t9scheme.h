#ifndef _KARIN_T9SCHEME_H
#define _KARIN_T9SCHEME_H

#include "vkbscheme.h"

namespace karin
{
	class T9Scheme : public VKBScheme
	{
		public:
			explicit T9Scheme(VKBLayout *layout);
			virtual ~T9Scheme();
			virtual int SchemeHeight() const;

		protected:
			virtual void MakeLayout(VKBLayout *layout);

		private:
			Q_DISABLE_COPY(T9Scheme)
	};

	class T9InverseScheme : public VKBScheme
	{
		public:
			explicit T9InverseScheme(VKBLayout *layout);
			virtual ~T9InverseScheme();
			virtual int SchemeHeight() const;

		protected:
			virtual void MakeLayout(VKBLayout *layout);

		private:
			Q_DISABLE_COPY(T9InverseScheme)
	};
}

#endif
