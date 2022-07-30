#if defined _INC_rank_commands_inc
    #endinput
#endif
#define _INC_rank_commands_inc

#include <YSI_Coding\y_hooks>

// Macros
#if !defined isnull
    #define isnull(%1) ((!(%1[0])) || (((%1[0]) == '\1') && (!(%1[1]))))
#endif

#define rank:
#define args_%0\32; args:
#define cmd_%0\32; cmd_
#define CMD__%0(%1) forward cmd_%0(%1); public cmd_%0(%1)
#define @Command{name:%0,%1,%2,%3} CMD__%0(%2,%3) \
    if (Rank_GetPlayerRankID(%2) < %1) return \
        SendErrorMsg(%2,"Nemate odredjeni rank za tu komandu!"); else
#define @Command_Call{name:%0,%1,%2} cmd_%0(%1,%2)

// Callbacks
hook OnPlayerCommandText(playerid, cmdtext[])
{
	if (cmdtext[0] == '/')
		return SendErrorMsg(playerid, "Nas server ne koristi prefix \"/\" za komande! Koristite \"!\".");

	new
		cmd[30],
		params[127],
		cmdfunction[64],
		result = 1;

	sscanf(cmdtext, "s[30]s[127]", cmd, params);

	for (new i, j = strlen(cmd); i < j; i++)
		cmd[i] = tolower(cmd[i]);

	format(cmdfunction, 64, "cmd_%s", cmd[1]);

	if(result == 1)
	{
		if(isnull(params))
			result = CallLocalFunction(cmdfunction, "is", playerid, "\1");

		else
			result = CallLocalFunction(cmdfunction, "is", playerid, params);
	}
	
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerText(playerid, text[])
{
	if (text[0] == '/')
		return CallLocalFunction("OnPlayerCommandText", "ds", playerid, text);

	if (text[0] == CUSTOM_COMMAND_PREFIX)
		return CallLocalFunction("OnPlayerCommandText", "ds", playerid, text);

	return Y_HOOKS_CONTINUE_RETURN_1;
}

// Commands
#include <player\ranks\rank_playercommands>
#include <player\ranks\rank_modcommands>
#include <player\ranks\rank_admincommands>