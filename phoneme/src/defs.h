#ifndef KARIN_DEFS_H
#define KARIN_DEFS_H

#define KARIN_KEY_CODE_UNKNOW 0

#define KARIN_J2ME_COMMAND_UP 0x01
#define KARIN_J2ME_COMMAND_DOWN 0x02
#define KARIN_J2ME_COMMAND_LEFT 0x03
#define KARIN_J2ME_COMMAND_RIGHT 0x04
#define KARIN_J2ME_COMMAND_OK ((int)'\r')
#define KARIN_J2ME_COMMAND_LEFT_SOFT 0x05
#define KARIN_J2ME_COMMAND_RIGHT_SOFT 0x06
#define KARIN_J2ME_COMMAND_CALL 0x13
#define KARIN_J2ME_COMMAND_BREAK 0x12
#define KARIN_J2ME_COMMAND_1 49
#define KARIN_J2ME_COMMAND_2 50
#define KARIN_J2ME_COMMAND_3 51
#define KARIN_J2ME_COMMAND_4 52
#define KARIN_J2ME_COMMAND_5 53
#define KARIN_J2ME_COMMAND_6 54
#define KARIN_J2ME_COMMAND_7 55
#define KARIN_J2ME_COMMAND_8 56
#define KARIN_J2ME_COMMAND_9 57
#define KARIN_J2ME_COMMAND_0 48
#define KARIN_J2ME_COMMAND_STAR 42
#define KARIN_J2ME_COMMAND_POUND 35
#define KARIN_J2ME_COMMAND_MENU KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_DELETE KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_VOLUME_UP KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_VOLUME_DOWN KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_MEDIA KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_NOTE KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_CAMERA KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_INTERNET KARIN_KEY_CODE_UNKNOW
#define KARIN_J2ME_COMMAND_POWER KARIN_KEY_CODE_UNKNOW

#define DEFAULT_DEVICE_SCREEN_WIDTH 240
#define DEFAULT_DEVICE_SCREEN_HEIGHT 320

namespace karin
{
	enum FillType_e
	{
		FillType_Fixed = 0, // top-left, fixed width and height
		FillType_Stratch, // top-left, auto fill width, height
		FillType_Auto, // auto x, 0, fixed width, height
		FillType_Fill, // auto x, 0, auto fill width, height
		FillType_Full, // 0, 0, full width, height

		FillType_total,
	};
	enum OrientationType_e
	{
		OrientationType_Auto = 0,
		OrientationType_Portrait,
		OrientationType_Landscape,

		OrientationType_total,
	};
	enum VKBType_e
	{
		VKBType_Disable = 0,
		VKBType_Always,
		VKBType_TriggerDoubleClick,
		VKBType_TriggerPressHold,

		VKBType_total,
	};
	enum KeyboardScheme_e
	{
		KeyboardScheme_None = 0,
		KeyboardScheme_T9,
		KeyboardScheme_T9_Inverse,

		KeyboardScheme_total,

		KeyboardScheme_Arrow,
		KeyboardScheme_QWERTY,
	};

	typedef enum J2me_Command_Type_e
	{
		J2me_Command_Up = 0,
		J2me_Command_Down,
		J2me_Command_Left,
		J2me_Command_Right,
		J2me_Command_Ok,
		J2me_Command_Left_soft,
		J2me_Command_Right_soft,
		J2me_Command_Call,
		J2me_Command_Break,
		J2me_Command_1,
		J2me_Command_2,
		J2me_Command_3,
		J2me_Command_4,
		J2me_Command_5,
		J2me_Command_6,
		J2me_Command_7,
		J2me_Command_8,
		J2me_Command_9,
		J2me_Command_0,
		J2me_Command_Star,
		J2me_Command_Pound,
		J2me_Command_Menu,
		J2me_Command_Delete,
		J2me_Command_Volume_up,
		J2me_Command_Volume_down,
		J2me_Command_Media,
		J2me_Command_Note,
		J2me_Command_Camera,
		J2me_Command_Internet,
		J2me_Command_Power,
		J2me_Command_User,
	} J2me_Command_Type_t;

	typedef enum Position_Base_on_Type_e
	{
		Position_Base_on_Begin = 0,
		Position_Base_on_Middle_Front,
		Position_Base_on_Middle_Back,
		Position_Base_on_End,
	} Position_Base_on_Type_t;

}

#endif
