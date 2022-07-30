#if defined _INC_rank_modcommands_inc
    #endinput
#endif
#define _INC_rank_modcommands_inc

// Variables
static
    rank_StaffVehicle[MAX_PLAYERS],
    rank_VehicleCreated[MAX_PLAYERS],
    
    Text3D: rank_StaffVehicleLabel[MAX_PLAYERS];

// Commands
@Command{name: veh, rank: Rank_Moderator() && Rank_Administrator(), args: playerid, const string: params[]}
{
    if (!rank_VehicleCreated[playerid])
    {
        static
            Float: x,
            Float: y,
            Float: z;
        
        GetPlayerPos(playerid, x, y, z);

        if (isnull(params) || !IsNumeric(params))
            return SendSyntaxMsg(playerid, "veh [id vozila(400-611)]");

        if (!(400 <= strval(params) <= 611))
            return SendErrorMsg(playerid, "Pogresan ID vozila!");

        rank_StaffVehicle[playerid] = CreateVehicle(strval(params), x, y, z, 0.0, random(128), random(128), 0, true);
        PutPlayerInVehicle(playerid, rank_StaffVehicle[playerid], 0);

        static fmt_label[64];
        format(fmt_label, sizeof(fmt_label), "%s - (%d)%s",
            Rank_GetRankName(Rank_GetPlayerRankID(playerid)), playerid, ReturnPlayerName(playerid)
        );
        rank_StaffVehicleLabel[playerid] = CreateDynamic3DTextLabel(fmt_label, X11_ORANGE,
            x, y, z, 30.0, .attachedvehicle = rank_StaffVehicle[playerid]
        );

        rank_VehicleCreated[playerid] = true;
        return 1;
    }

    DestroyVehicle(rank_StaffVehicle[playerid]);
    DestroyDynamic3DTextLabel(rank_StaffVehicleLabel[playerid]);
    rank_VehicleCreated[playerid] = false;

    return 1;
}

@Command{name: settime, rank: Rank_Moderator() && Rank_Administrator(), args: playerid, const string: params[]}
{
    if (isnull(params) || !IsNumeric(params))
        return SendSyntaxMsg(playerid, "settime [vreme(0-24)]");

    if (!(0 <= strval(params) <= 24))
        return SendErrorMsg(playerid, "Pogresan ID vremena.");

    SetWorldTime(strval(params));
    Rank_SendStaffMessage("%s je postavio sate na %d.", ReturnPlayerName(playerid), strval(params));

    return 1;
}

@Command{name: setweather, rank: Rank_Moderator() && Rank_Administrator(), args: playerid, const string: params[]}
{
    if (isnull(params) || !IsNumeric(params))
        return SendSyntaxMsg(playerid, "setweather [vreme(0-20)]");

    if (!(0 <= strval(params) <= 20))
        return SendErrorMsg(playerid, "Pogresan ID vremena.");

    SetWeather(strval(params));
    Rank_SendStaffMessage("%s je postavio vreme na %d.", ReturnPlayerName(playerid), strval(params));

    return 1;
}

@Command{name: bringplayer, rank: Rank_Moderator(), args: playerid, const string: params[]}
{
    if (isnull(params) || !IsNumeric(params))
        return SendSyntaxMsg(playerid, "bringplayer [target id]");

    if (!IsPlayerConnected(strval(params)))
        return 0;

    static Float: x, Float: y, Float: z;
    GetPlayerPos(playerid, x, y, z);
    SetPlayerPos(strval(params), x, y, z);

    SendInfoMsgF(playerid, "Teleportovali ste %s do sebe.", ReturnPlayerName(strval(params)));
    SendInfoMsgF(strval(params), "%s Vas je teleportovao do sebe.", ReturnPlayerName(playerid));

    return 1;
}

@Command{name: modhelp, rank: Rank_Administrator(), args: playerid, const string: params[]}
    return @Command_Call{name: mh, args: playerid, ""};

@Command{name: mh, rank: Rank_Moderator(), args: playerid, const string: params[]}
{
    Dialog_Show(playerid, "dialog_modhelp", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOUR"gta-world: "WHITE"Moderator komande",
        ""WHITE"Komanda\t"WHITE"Opis komande\n\
        "WHITE"veh\t"MAIN_COLOUR"Stvarate privremeno vozilo.\n\
        "WHITE"settime\t"MAIN_COLOUR"Podesavate vreme (sate) svima na serveru.\n\
        "WHITE"setweather\t"MAIN_COLOUR"Podesavate vreme svima na serveru.\n\
        "WHITE"bringplayer\t"MAIN_COLOUR"Teleportujete zeljenog igraca do Vas.",
        ""MAIN_COLOUR"Izlaz"
    );

    return 1;
}