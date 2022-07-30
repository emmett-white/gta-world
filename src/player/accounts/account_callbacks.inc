#if defined _INC_account_callbacks_inc
    #endinput
#endif
#define _INC_account_callbacks_inc

forward OnAccountCreated(const playerid);
public OnAccountCreated(const playerid)
{
    Account_SetUniqueID(playerid, cache_insert_id());
    return 1;
}