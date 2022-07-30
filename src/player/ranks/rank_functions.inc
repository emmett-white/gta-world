#if defined _INC_rank_functions_inc
    #endinput
#endif
#define _INC_rank_functions_inc

// Variables
new
    rank_Rank[MAX_PLAYERS],
    rank_ID[MAX_PLAYERS];

#define Rank_GetUniqueID(%0) rank_ID[%0]

enum E_RANKS_DATA
{
    E_RANK_PLAYER = 1,
    E_RANK_MODERATOR,
    E_RANK_ADMINISTRATOR
};

// Functions
stock Rank_Player() return _:E_RANK_PLAYER;
stock Rank_Moderator() return _:E_RANK_MODERATOR;
stock Rank_Administrator() return _:E_RANK_ADMINISTRATOR;
stock Rank_GetPlayerRankID(const playerid) return rank_Rank[playerid];
stock Rank_CreatePlayerRank(const targetid, const playerid = INVALID_PLAYER_ID, const string: rank[])
{
    if (Rank_GetPlayerRankID(targetid))
        return 0;
    
    new String: str_query_insert = String: str_format(
        "INSERT INTO ranks (rank_playername, rank_rankname) VALUES ('%e', '%e')",
        ReturnPlayerName(targetid), rank
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert, "OnRankCreated", "d", targetid);

    rank_Rank[targetid] = Rank_GetRankIDByName(rank);

    SendInfoMsgF(playerid, "%s sada ima rank: %s.", ReturnPlayerName(targetid), Rank_GetRankName(rank_Rank[targetid]));
    SendInfoMsgF(targetid, "Administrator %s vam je postavio rank: %s.", ReturnPlayerName(playerid), Rank_GetRankName(rank_Rank[targetid]));

    if (!strcmp(rank, "igrac", false))
        SetPlayerSkin(targetid, 0);

    else if (!strcmp(rank, "moderator", false))
        SetPlayerSkin(targetid, 299);

    else if (!strcmp(rank, "administrator", false))
        SetPlayerSkin(targetid, 294);

    return 1;
}

stock Rank_SetPlayerRank(const targetid, const playerid = INVALID_PLAYER_ID, const string: rank[])
{
    rank_Rank[targetid] = Rank_GetRankIDByName(rank);

    new String: str_query_update = String: str_format(
        "UPDATE ranks SET rank_rankname = '%e' WHERE rank_id = '%d'",
        rank, Rank_GetUniqueID(targetid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    SendInfoMsgF(playerid, "%s sada ima rank: %s.", ReturnPlayerName(targetid), Rank_GetRankName(rank_Rank[targetid]));
    SendInfoMsgF(targetid, "Administrator %s vam je postavio rank: %s.", ReturnPlayerName(playerid), Rank_GetRankName(rank_Rank[targetid]));

    if (!strcmp(rank, "igrac", false))
        Char_SetSkin(targetid, 60);

    else if (!strcmp(rank, "moderator", false))
        Char_SetSkin(targetid, 299);
        
    else if (!strcmp(rank, "administrator", false))
        Char_SetSkin(targetid, 294);

    return 1;
}

stock Rank_GetRankIDByName(const string: rank[])
{
    static tmp_int;
    if (!strcmp(rank, "igrac", false)) return tmp_int = _:E_RANK_PLAYER;
    else if (!strcmp(rank, "moderator", false)) return tmp_int = _:E_RANK_MODERATOR;
    else if (!strcmp(rank, "administrator", false)) return tmp_int = _:E_RANK_ADMINISTRATOR;

    printf("Rank_GetRankIDByName = %d", tmp_int);
    return tmp_int;
}

stock Rank_GetRankName(const rank)
{
    static tmp_str[MAX_PLAYER_NAME];
    if (rank == _:E_RANK_PLAYER) { tmp_str = "obican igrac"; }
    else if (rank == _:E_RANK_MODERATOR) { tmp_str = "moderator"; }
    else if (rank == _:E_RANK_ADMINISTRATOR) { tmp_str = "administrator"; }
    
    return tmp_str;
}

stock Rank_RadiusMessage(Float: radi, playerid, const string: string[], c1, c2, c3, c4, c5)
{
	if (IsPlayerConnected(playerid))
    {
		new
            Float: pPosX, Float: pPosY, Float: pPosZ,
		    Float: oldpPosX, Float: oldpPosY, Float: oldpPosZ,
		    Float: tmpPosX, Float: tmpPosY, Float: tmpPosZ;

		GetPlayerPos(playerid, oldpPosX, oldpPosY, oldpPosZ);
		foreach(new i: Player)
        {
            if (GetPlayerVirtualWorld(playerid) == GetPlayerVirtualWorld(i))
            {
                GetPlayerPos(i, pPosX, pPosY, pPosZ);
                
                tmpPosX = (oldpPosX -pPosX);
                tmpPosY = (oldpPosY -pPosY);
                tmpPosZ = (oldpPosZ -pPosZ);
                
                if(((tmpPosX < radi/16) && (tmpPosX > -radi/16)) && ((tmpPosY < radi/16) && (tmpPosY > -radi/16)) && ((tmpPosZ < radi/16) && (tmpPosZ > -radi/16)))
                    SendClientMessage(i, c1, string);

                else if(((tmpPosX < radi/8) && (tmpPosX > -radi/8)) && ((tmpPosY < radi/8) && (tmpPosY > -radi/8)) && ((tmpPosZ < radi/8) && (tmpPosZ > -radi/8)))
                    SendClientMessage(i, c2, string);

                else if(((tmpPosX < radi/4) && (tmpPosX > -radi/4)) && ((tmpPosY < radi/4) && (tmpPosY > -radi/4)) && ((tmpPosZ < radi/4) && (tmpPosZ > -radi/4)))
                    SendClientMessage(i, c3, string);

                else if(((tmpPosX < radi/2) && (tmpPosX > -radi/2)) && ((tmpPosY < radi/2) && (tmpPosY > -radi/2)) && ((tmpPosZ < radi/2) && (tmpPosZ > -radi/2)))
                    SendClientMessage(i, c4, string);

                else if(((tmpPosX < radi) && (tmpPosX > -radi)) && ((tmpPosY < radi) && (tmpPosY > -radi)) && ((tmpPosZ < radi) && (tmpPosZ > -radi)))
                    SendClientMessage(i, c5, string);
            }
		}
	}
    
	return 1;
}

stock Rank_SendStaffMessage(const string: message[], va_args<>)
{
    static fmt[YSI_MAX_STRING];
    format(fmt, sizeof(fmt), "* %s", message);

    foreach (new i: Player)
        if (Rank_GetPlayerRankID(i) == Rank_Moderator() || Rank_GetPlayerRankID(i) == Rank_Administrator())
            return SendClientMessage(i, X11_ORANGE, va_return(fmt, va_start<1>));

    return 0;
}

stock bool: Rank_StaffOnline()
{
    foreach (new i: Player)
        if (Rank_GetPlayerRankID(i) == Rank_Moderator() || Rank_GetPlayerRankID(i) == Rank_Administrator())
            return true;

    return false;
}

// Timer
PTASK__ FIX_StaffVehicle[1500](playerid)
{
    if ((Rank_GetPlayerRankID(playerid) == Rank_Moderator()) ||
        (Rank_GetPlayerRankID(playerid) == Rank_Administrator()) &&
        IsPlayerInAnyVehicle(playerid))
    {
        RepairVehicle(GetPlayerVehicleID(playerid));
        SetVehicleHealth(GetPlayerVehicleID(playerid), 1000.00);
    }
}