#include "t9scheme.h"

#include <QDebug>

#include "vkblayout.h"
#include "vkblayer.h"
#include "softbutton.h"
#include "defs.h"
#include "macros.h"

#define BW (80)
#define BS (0)
#define VB_W(x) ((x) * BW)
#define VB_S(x) ((x) * BS)

#define VB_FONT_SIZE 32
#define VB_TEXT_COLOR 0x0000ff
#define VB_PRESSED_TEXT_COLOR 0xffffff
#define VB_COLOR 0xffffff
#define VB_PRESSED_COLOR 0x0000ff

namespace karin
{
	T9Scheme::T9Scheme(VKBLayout *layout)
		: VKBScheme(layout)
	{
	}

	T9Scheme::~T9Scheme()
	{
		ID_DESTROY_DEBUG(T9Scheme)
	}

	void T9Scheme::MakeLayout(VKBLayout *layout)
	{
		VKBLayer *layer;
		const QString Labels[] = {
			"U", "D", "L", "D", "F",
			"Left", "Right", "Call", "Break",
			"1", "2", "3",
			"4", "5", "6",
			"7", "8", "9",
			"*", "0", "#",
		};
		typedef struct J2meCommand_e
		{
			int command;
			int x, y, w, h;
			int x_rule, y_rule;
			const char *label;
			int font_size;
			int color, pressed_color;
			int text_color, pressed_text_color;
		} J2meCommand_t;
		const J2meCommand_t Command_Init_Data[] = {
			// up down
			{
				KARIN_J2ME_COMMAND_UP,
				VB_W(1) + VB_S(1), VB_W(3.5) + VB_S(2.5), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u2b06"/*"↑"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_DOWN,
				VB_W(1) + VB_S(1), VB_W(1.5) + VB_S(0.5), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u2b07"/*"↓"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// left right
			{
				KARIN_J2ME_COMMAND_LEFT,
				VB_W(0) + VB_S(0), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u2b05"/*"←"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_RIGHT,
				VB_W(2) + VB_S(2), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u27a1"/*"→"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// ok
			{
				KARIN_J2ME_COMMAND_OK,
				VB_W(1) + VB_S(1), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u2622"/*"⚪"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// left/right soft
			{
				KARIN_J2ME_COMMAND_LEFT_SOFT,
				VB_W(0) + VB_S(0), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u25c0"/*"Left"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_RIGHT_SOFT,
				VB_W(2) + VB_S(2), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u25b6"/*"Right"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// call break
			{
				KARIN_J2ME_COMMAND_CALL,
				VB_W(0) + VB_S(0), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u2706"/*"Call"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_BREAK,
				VB_W(2) + VB_S(2), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"\\u260f"/*"Break"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 1 2 3
			{
				KARIN_J2ME_COMMAND_1,
				VB_W(3) + VB_S(2), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"1", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_2,
				VB_W(2) + VB_S(1), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"2", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_3,
				VB_W(1) + VB_S(0), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"3", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 4 5 6
			{
				KARIN_J2ME_COMMAND_4,
				VB_W(3) + VB_S(2), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"4", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_5,
				VB_W(2) + VB_S(1), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"5", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_6,
				VB_W(1) + VB_S(0), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"6", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 7 8 9
			{
				KARIN_J2ME_COMMAND_7,
				VB_W(3) + VB_S(2), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"7", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_8,
				VB_W(2) + VB_S(1), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"8", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_9,
				VB_W(1) + VB_S(0), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"9", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// * 0 #
			{
				KARIN_J2ME_COMMAND_STAR,
				VB_W(3) + VB_S(2), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"*", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_0,
				VB_W(2) + VB_S(1), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"0", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_POUND,
				VB_W(1) + VB_S(0), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"#", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
		};
		SoftButton *b;
		const J2meCommand_t *j;

		layer = dynamic_cast<VKBLayer *>(layout->parentWidget());
		for(int i = 0; i <= J2me_Command_Pound; i++)
		{
			j = Command_Init_Data + i;
			b = new SoftButton(layout->parentWidget());
			b->SetAction(j->command);
			b->SetLabel(j->label);
			b->SetTextColor(j->text_color);
			b->SetPressedTextColor(j->pressed_text_color);
			b->SetBorderColor(j->text_color);
			b->SetPressedBorderColor(j->pressed_text_color);
			b->SetBgColor(j->color);
			b->SetPressedBgColor(j->pressed_color);
			QFont font = b->font();
			font.setPixelSize(j->font_size);
			b->setFont(font);
			b->SetPaintType(SoftButton::Button_Circle_Type);
			layout->addWidget(b);
			layout->SetItemRect(b, j->x, j->y, j->w, j->h, j->x_rule, j->y_rule);
			if(layer)
			{
				QObject::connect(b, SIGNAL(checkedChanged(int, bool)), layer, SLOT(SendCommand(int, bool)));
			}
		}
	}

	int T9Scheme::SchemeHeight() const
	{
		return VB_W(4);
	}
}

namespace karin
{
	T9InverseScheme::T9InverseScheme(VKBLayout *layout)
		: VKBScheme(layout)
	{
	}

	T9InverseScheme::~T9InverseScheme()
	{
		ID_DESTROY_DEBUG(T9InverseScheme)
	}

	void T9InverseScheme::MakeLayout(VKBLayout *layout)
	{
		VKBLayer *layer;
		const QString Labels[] = {
			"U", "D", "L", "D", "F",
			"Left", "Right", "Call", "Break",
			"1", "2", "3",
			"4", "5", "6",
			"7", "8", "9",
			"*", "0", "#",
		};
		typedef struct J2meCommand_e
		{
			int command;
			int x, y, w, h;
			int x_rule, y_rule;
			const char *label;
			int font_size;
			int color, pressed_color;
			int text_color, pressed_text_color;
		} J2meCommand_t;
		const J2meCommand_t Command_Init_Data[] = {
			// up down
			{
				KARIN_J2ME_COMMAND_UP,
				VB_W(2) + VB_S(1), VB_W(3.5) + VB_S(2.5), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u2b06"/*"↑"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_DOWN,
				VB_W(2) + VB_S(1), VB_W(1.5) + VB_S(0.5), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u2b07"/*"↓"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// left right
			{
				KARIN_J2ME_COMMAND_LEFT,
				VB_W(3) + VB_S(2), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u2b05"/*"←"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_RIGHT,
				VB_W(1) + VB_S(0), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u27a1"/*"→"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// ok
			{
				KARIN_J2ME_COMMAND_OK,
				VB_W(2) + VB_S(1), VB_W(2.5) + VB_S(1.5), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u2622"/*"⚪"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// left/right soft
			{
				KARIN_J2ME_COMMAND_LEFT_SOFT,
				VB_W(3) + VB_S(2), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u25c0"/*"Left"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_RIGHT_SOFT,
				VB_W(1) + VB_S(0), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u25b6"/*"Right"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// call break
			{
				KARIN_J2ME_COMMAND_CALL,
				VB_W(3) + VB_S(2), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u2706"/*"Call"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_BREAK,
				VB_W(1) + VB_S(0), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_End, Position_Base_on_End,
				"\\u260f"/*"Break"*/, VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 1 2 3
			{
				KARIN_J2ME_COMMAND_1,
				VB_W(0) + VB_S(0), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"1", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_2,
				VB_W(1) + VB_S(1), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"2", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_3,
				VB_W(2) + VB_S(2), VB_W(4) + VB_S(3), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"3", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 4 5 6
			{
				KARIN_J2ME_COMMAND_4,
				VB_W(0) + VB_S(0), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"4", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_5,
				VB_W(1) + VB_S(1), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"5", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_6,
				VB_W(2) + VB_S(2), VB_W(3) + VB_S(2), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"6", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// 7 8 9
			{
				KARIN_J2ME_COMMAND_7,
				VB_W(0) + VB_S(0), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"7", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_8,
				VB_W(1) + VB_S(1), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"8", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_9,
				VB_W(2) + VB_S(2), VB_W(2) + VB_S(1), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"9", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			// * 0 #
			{
				KARIN_J2ME_COMMAND_STAR,
				VB_W(0) + VB_S(0), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"*", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_0,
				VB_W(1) + VB_S(1), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"0", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
			{
				KARIN_J2ME_COMMAND_POUND,
				VB_W(2) + VB_S(2), VB_W(1) + VB_S(0), VB_W(1), VB_W(1),
				Position_Base_on_Begin, Position_Base_on_End,
				"#", VB_FONT_SIZE,
				VB_COLOR, VB_PRESSED_COLOR, VB_TEXT_COLOR, VB_PRESSED_TEXT_COLOR,
			},
		};
		SoftButton *b;
		const J2meCommand_t *j;

		layer = dynamic_cast<VKBLayer *>(layout->parentWidget());
		for(int i = 0; i <= J2me_Command_Pound; i++)
		{
			j = Command_Init_Data + i;
			b = new SoftButton(layout->parentWidget());
			b->SetAction(j->command);
			b->SetLabel(j->label);
			b->SetTextColor(j->text_color);
			b->SetPressedTextColor(j->pressed_text_color);
			b->SetBorderColor(j->text_color);
			b->SetPressedBorderColor(j->pressed_text_color);
			b->SetBgColor(j->color);
			b->SetPressedBgColor(j->pressed_color);
			QFont font = b->font();
			font.setPixelSize(j->font_size);
			b->setFont(font);
			b->SetPaintType(SoftButton::Button_Circle_Type);
			layout->addWidget(b);
			layout->SetItemRect(b, j->x, j->y, j->w, j->h, j->x_rule, j->y_rule);
			if(layer)
			{
				QObject::connect(b, SIGNAL(checkedChanged(int, bool)), layer, SLOT(SendCommand(int, bool)));
			}
		}
	}

	int T9InverseScheme::SchemeHeight() const
	{
		return VB_W(4);
	}
}
