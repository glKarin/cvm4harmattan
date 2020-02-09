#ifndef _KARIN_TOOLICON_H
#define _KARIN_TOOLICON_H

#include "button.h"

namespace karin
{
	class ToolIcon : public Button
	{
		Q_OBJECT
		public:
			explicit ToolIcon(QWidget *parent = 0);
			virtual ~ToolIcon();
			void SetIcon(const QString &action);
			QString Icon() const;
			void SetLabel(const QString &label);

		protected:
			void paintEvent(QPaintEvent *ev);

		private:
			QString m_icon;

			QImage m_image;

			Q_DISABLE_COPY(ToolIcon)
	};
}

#endif
