#ifndef _KARIN_SOFTBUTTON_H
#define _KARIN_SOFTBUTTON_H

#include "button.h"

namespace karin
{
	class SoftButton : public Button
	{
		Q_OBJECT
		public:
			explicit SoftButton(QWidget *parent = 0);
			virtual ~SoftButton();
			void SetAction(int action);
			int Action() const;
			void SetLabel(const QString &label);

Q_SIGNALS:
			void clicked(int action, bool on = false);
			void checkedChanged(int action, bool on);

			private Q_SLOTS:
				void OnClicked(bool on);
			void OnCheckedChanged(bool checked);

		private:
			int m_action;

			Q_DISABLE_COPY(SoftButton)
	};
}

#endif
