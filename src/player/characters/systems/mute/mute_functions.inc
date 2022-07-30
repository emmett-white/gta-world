#if defined _INC_mute_functions_inc
	#endinput
#endif
#define _INC_mute_functions_inc

// Variables
static mute_Time[MAX_PLAYERS];

// Functions
stock Mute_GetPlayerStatus(const playerid) return mute_Time[playerid];
stock Mute_Player(const playerid, const staffid, const time = 0, const string: reason[] = "N/A")
{
	if (!time && !Mute_GetPlayerStatus(playerid))
	{
		SendInfoMsg(playerid, "Odmutirani ste od strane staff team-a.");
		SendInfoMsgF(staffid, "Odmutirali ste %s.", ReturnPlayerName(staffid));
		Rank_SendStaffMessage("[UN-MUTE]: %s je odmutirao %s.", ReturnPlayerName(staffid), ReturnPlayerName(playerid));

		mute_Time[playerid] = 0;
		return 1;
	}

	if (!(0 <= time <= 9999))
		return SendErrorMsg(staffid, "Ne mozete ispod 0(unmute) i iznad 9999 minuta!");

	mute_Time[playerid] = time;

	SendInfoMsg(playerid, "Mutirani ste od strane "WHITE"%s "ORANGE"na %d minuta zbog: %s.", ReturnPlayerName(staffid), time, reason);
	SendInfoMsgf(staffid, "Mutirali ste igraca %s na %d minuta zbog %s.", ReturnPlayerName(playerid), time, reason);
	Rank_SendStaffMessage("[MUTE]: %s je mutirao %s na %d minuta zbog: %s.", ReturnPlayerName(staffid), ReturnPlayerName(playerid), time, reason);

	new String: str_query_update = String: str_format(
		"UPDATE characters SET char_mutetime = '%d' WHERE char_id = '%d'",
		time, Char_GetUniqueID(playerid)
	);
	mysql_tquery(MySQL_GetHandle(), str_query_update);
	return 1;
}