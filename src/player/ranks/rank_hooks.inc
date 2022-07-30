#if defined _INC_rank_hooks_inc
    #endinput
#endif
#define _INC_rank_hooks_inc

#include <YSI_Coding\y_hooks>

hook OnPlayerConnect(playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM ranks WHERE rank_playername = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
    {
        static tmp_str[MAX_PLAYER_NAME];
        cache_get_value_name_int(0, "rank_id", Rank_GetUniqueID(playerid));
        cache_get_value_name(0, "rank_rankname", tmp_str);
        Rank_SetPlayerRank(playerid, .rank = tmp_str);
    }
    
    else Rank_CreatePlayerRank(playerid, .rank = "igrac");

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerText(playerid, text[])
{
    if (text[0] == '!')
        return 0;
    
    if (Mute_GetPlayerStatus(playerid))
        return SendErrorMsgF(playerid, "Mutirani ste jos %d minuta.", Mute_GetPlayerStatus(playerid)), 0;

    new tmp_str[128];
    if (Rank_GetPlayerRankID(playerid) == Rank_Player())
        format(tmp_str, sizeof(tmp_str), "Igrac %s(%d): "WHITE"%s", ReturnPlayerName(playerid), playerid, text);
    
    else if (Rank_GetPlayerRankID(playerid) == Rank_Moderator())
        format(tmp_str, sizeof(tmp_str), ""YELLOW"Moderator "WHITE"%s(%d): "WHITE"%s", ReturnPlayerName(playerid), playerid, text);

    else
        format(tmp_str, sizeof(tmp_str), ""BLACK"Administrator "WHITE"%s(%d): "WHITE"%s", ReturnPlayerName(playerid), playerid, text);

    Rank_RadiusMessage(20.0, playerid, tmp_str, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE, X11_WHITE);

    return Y_HOOKS_BREAK_RETURN_0;
}

// Staff panel (clickable preview model textdraw)
hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_NO) && (Rank_GetPlayerRankID(playerid) == Rank_Moderator() || Rank_GetPlayerRankID(playerid) == Rank_Administrator()))
        SelectTextDraw(playerid, X11_WHITE);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText: UI_StaffPanelClicked(playerid))
    {
        Dialog_Show(playerid, "dialog_staffpanel", DIALOG_STYLE_LIST,
            ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
            (Rank_GetPlayerRankID(playerid) == Rank_Moderator()) ? ("Kikuj igraca\nMutiraj igraca\nZatvori igraca") :
            (Rank_GetPlayerRankID(playerid) == Rank_Administrator()) ? ("Banuj igraca\nKikuj igraca\nMutiraj igraca\n\
                Zatvori igraca\nKikuj sve igrace\nZakljucaj server\nPromeni ime servera") : (""),
            ""MAIN_COLOUR"Odaberi", "Izlaz"
        );
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}