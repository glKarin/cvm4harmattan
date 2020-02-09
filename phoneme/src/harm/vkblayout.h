#ifndef _KARIN_VKBLAYOUT_H
#define _KARIN_VKBLAYOUT_H

#include <QLayout>
#include <QHash>

namespace karin
{
	class VKBLayout : public QLayout
	{
		Q_OBJECT

		public:
			explicit VKBLayout(QWidget *widget = 0);
			virtual ~VKBLayout();

			virtual void addItem(QLayoutItem *item);
			virtual int	count() const;
			virtual QLayoutItem * itemAt(int index) const;
			virtual QLayoutItem * takeAt(int index);
			virtual void removeWidget(QWidget *widget);
			virtual QSize sizeHint() const;
			virtual void setGeometry(const QRect &r);
			void SetItemRect(QWidget *widget, int x, int y, int w, int h, unsigned char xAnchor, unsigned char yAnchor);
			virtual QLayoutItem * GetItem(int action) const;
			virtual void Clear();

			protected:
			//void addChildWidget(QWidget *w);
				//virtual void Relayout(int w, int h);

		protected:
				class VKBLayoutItem
				{
					private:
						explicit VKBLayoutItem(VKBLayout *layout);
						virtual ~VKBLayoutItem();

						VKBLayout *layout;
						QLayoutItem *widget;
						int x, y, w, h;
						unsigned char x_anchor, y_anchor;

						void Relayout();
						QLayoutItem * AttachWidget(QLayoutItem *v = 0);

						friend class VKBLayout;
				};

				typedef QHash<int, VKBLayoutItem *> VKBHash_t;
				VKBHash_t m_btns;
				QList<int> m_actions;

		private:
				Q_DISABLE_COPY(VKBLayout);
	};
}

#endif
