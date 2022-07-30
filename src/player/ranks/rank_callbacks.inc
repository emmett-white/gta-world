#if defined _INC_rank_callbacks_inc
    #endinput
#endif
#define _INC_rank_callbacks_inc

forward OnRankCreated(const playerid);
public OnRankCreated(const playerid)
{
    rank_ID[playerid] = cache_insert_id();
    return 1;
}