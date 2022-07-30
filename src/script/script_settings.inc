#if defined _INC_script_settings_inc
    #endinput
#endif
#define _INC_script_settings_inc

#include <script\script_init>

// Constants
const MAX_LOGIN_ATTEMPTS =      3;
const MIN_PASSWORD_LENGTH =     8;
const MAX_PASSWORD_LENGTH =     14;
const CUSTOM_COMMAND_PREFIX =   '!';

#define  MAX_REASON_LENGTH      64

// Custom colours
#define MAIN_COLOUR "{205aab}"
#define MAIN_COLOUR_HEX 0x205aabFF

// Keys
#define PRESSED(%0) (((newkeys & (%0)) == (%0)) && ((oldkeys & (%0)) != (%0)))

// PawnPlus Natives
native STREAMER_TAG_3D_TEXT_LABEL:CreateFormattedDynLabel(AmxString: text, color, Float:x, Float:y, Float:z, Float:drawdistance, attachedplayer = INVALID_PLAYER_ID, attachedvehicle = INVALID_VEHICLE_ID, testlos = 0, worldid = -1, interiorid = -1, playerid = -1, Float:streamdistance = STREAMER_3D_TEXT_LABEL_SD, STREAMER_TAG_AREA:areaid = STREAMER_TAG_AREA:-1, priority = 0) = CreateDynamic3DTextLabel;
native UpdateDyn3DTextLabelFmt(STREAMER_TAG_3D_TEXT_LABEL:id, color, AmxString: text) = UpdateDynamic3DTextLabelText;

// Messages
stock SendServerMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "gta-world: "WHITE"%s", message);

    return SendClientMessage(playerid, MAIN_COLOUR_HEX, str);
}

stock SendServerMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "gta-world: "WHITE"%s", message);

    return va_SendClientMessage(playerid, MAIN_COLOUR_HEX, va_return(str, va_start<2>));
}

stock SendErrorMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "gta-world#error: "WHITE"%s", message);
    PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);

    return SendClientMessage(playerid, X11_RED, str);
}

stock SendErrorMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "gta-world#error: "WHITE"%s", message);
    PlayerPlaySound(playerid, 1058, 0.0, 0.0, 0.0);

    return va_SendClientMessage(playerid, X11_RED, va_return(str, va_start<2>));
}

stock SendSyntaxMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "gta-world#usage: "WHITE"%c%s", CUSTOM_COMMAND_PREFIX, message);

    return SendClientMessage(playerid, X11_ORANGE, str);
}

stock SendInfoMsg(const playerid, const string: message[])
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return SendClientMessage(playerid, X11_ORANGE, str);
}

stock SendInfoMsgF(const playerid, const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return va_SendClientMessage(playerid, X11_ORANGE, va_return(str, va_start<2>));
}

stock SendInfoMsgToAllF(const string: message[], va_args<>)
{
    new str[YSI_MAX_STRING];
    format(str, sizeof str, "* %s", message);

    return va_SendClientMessageToAll(X11_ORANGE, va_return(str, va_start<1>));
}

// Macros
#define Player_ClearChat(%0,%1) for(new i; i < %1; ++i) SendClientMessage(%0,-1," ")