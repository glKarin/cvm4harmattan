#ifndef _KARIN_VKBLAYER_H
#define _KARIN_VKBLAYER_H

#include "graphicswidget.h"

#include <QHash>

namespace karin
{
	class VKBLayout;
	class VKBScheme;

	class VKBLayer : public GraphicsWidget
	{
		Q_OBJECT

		public:
			explicit VKBLayer(QWidget *parent = 0);
			virtual ~VKBLayer();
			void SetMinimalGeometry(int x, int y, int width, int height);
			int CurrentScheme() const;

			public Q_SLOTS:
				void SendCommand(int command, bool pressed);
			void SetVKBOpacity(qreal f);
			void SetVKBScheme(int scheme);

		protected:
			virtual void resizeEvent(QResizeEvent *ev);

		private:
			void Init();

		private:
			VKBLayout *m_layout;
			VKBScheme *m_scheme;
			int m_currentScheme;

			Q_DISABLE_COPY(VKBLayer)
	};
}

#endif
