#if defined _INC_rent_hooks_inc
    #endinput
#endif
#define _INC_rent_hooks_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnScriptInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM rent", "Rent_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    // Rent_Player(playerid, -1, 0);
    return Y_HOOKS_CONTINUE_RETURN_1;
}