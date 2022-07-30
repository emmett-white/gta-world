#if defined _INC_rank_playercommands_inc
    #endinput
#endif
#define _INC_rank_playercommands_inc

// Variables
static
    player_AskTime[MAX_PLAYERS],
    player_ReportTime[MAX_PLAYERS];

// Commands
@Command{name: rank, rank: Rank_Player(), args: playerid, const string: params[]}
{
    SendInfoMsgF(playerid, "%s", Rank_GetRankName(Rank_GetPlayerRankID(playerid)));
    return 1;
}

@Command{name: ranks, rank: Rank_Player(), args: playerid, const string: params[]}
{
    Dialog_Show(playerid, "dialog_ranks", DIALOG_STYLE_MSGBOX,
        ""MAIN_COLOUR"gta-world: "WHITE"Rankovi",
        ""MAIN_COLOUR"[1]. "WHITE"igrac\n"MAIN_COLOUR"[2]. "WHITE"moderator\n"MAIN_COLOUR"[3]. "WHITE"administrator",
        "Izlaz", ""
    );

    return 1;
}

@Command{name: register, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (Account_Exists(playerid))
        return SendErrorMsg(playerid, "Vec imate kreiran nalog.");

    Account_PromptRegister(playerid);
    
    return 1;
}

@Command{name: changepass, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (!Account_Exists(playerid))
        return SendErrorMsg(playerid, "Nemate kreiran nalog (!register).");
    
    if (isnull(params))
        return SendSyntaxMsg(playerid, "changepass [nova lozinka]");

    if (!strcmp(params, Account_GetPassword(playerid), false))
        return SendErrorMsg(playerid, "Ne mozete istu lozinku kao staru!");

    Account_SetPassword(playerid, params, true);
    SendInfoMsgF(playerid, "Vasa nova lozinka je: "WHITE"%s", params);

    return 1;
}

@Command{name: rent, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (Rent_GetPlayerTime(playerid))
        return SendErrorMsgF(playerid, "Vec ste iznajmili vozilo (%cunrent).", CUSTOM_COMMAND_PREFIX);

    if (Rent_GetNearest(playerid) == -1)
        return SendErrorMsg(playerid, "Morate biti blizu mesta gde se iznajmljuju vozila.");

    Dialog_Show(playerid, "dialog_renttime", DIALOG_STYLE_INPUT,
        ""ORANGE"gta-world: "WHITE"Iznajmite vozilo",
        ""ORANGE"Informacija: "WHITE"Unesite na koliko minuta zelite iznajmiti vozilo (1-20) (1 minut = $3):",
        ""ORANGE"Nastavi", "Izlaz"
    );

    return 1;
}

@Command{name: buyveh, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, 1788.1427, -1693.1564, 13.4305))
        return SendErrorMsg(playerid, "Niste u auto salonu!");

    Dialog_Show(playerid, "dialog_vehicletype", DIALOG_STYLE_LIST,
        ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
        ""MAIN_COLOUR"[1]. "WHITE"Automobili\n"MAIN_COLOUR"[2]. "WHITE"Motori\n\
        "MAIN_COLOUR"[3]. "WHITE"Bicikla\n"MAIN_COLOUR"[4]. "WHITE"Avioni\n"MAIN_COLOUR"[5]. "WHITE"Helikopteri",
        ""MAIN_COLOUR"Odaberi", "Izlaz"
    );

    return 1;
}

@Command{name: vehicle, rank: Rank_Player(), args: playerid, const string: params[]}
{
    Dialog_Show(playerid, "dialog_playervehicles", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOUR"gta-world: "WHITE"Lista vozila",
        ""MAIN_COLOUR"Tip\t"MAIN_COLOUR"Marka\n\
        "MAIN_COLOUR"Automobil\t"WHITE"%s\n\
        "MAIN_COLOUR"Motor\t"WHITE"N/A\n\
        "MAIN_COLOUR"Biciklo\t"WHITE"N/A\n\
        "MAIN_COLOUR"Avion\t"WHITE"N/A\n\
        "MAIN_COLOUR"Helikopter\t"WHITE"N/A",
        ""MAIN_COLOUR"Odaberi", "Izlaz",
        Car_GetModelName(Car_GetPlayerModel(playerid))
    );

    return 1;
}

@Command{name: weapon, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (!IsPlayerInRangeOfPoint(playerid, 2.0, 296.1837, -37.9673, 1001.5156))
        return SendErrorMsg(playerid, "Morate biti u prodavnici oruzija!");

    Dialog_Show(playerid, "dialog_buyweapon", DIALOG_STYLE_TABLIST_HEADERS,
        ""RED"gta-world: "WHITE"Prodavnica oruzija",
        ""WHITE"Ime oruzija\t"WHITE"Municija\t"WHITE"Cena\n\
        "RED"[1]. "WHITE"Desert Eagle\t"WHITE"50\t"GREEN"$2100\n\
        "RED"[2]. "WHITE"M4A1\t"WHITE"50\t"GREEN"$4350\n\
        "RED"[3]. "WHITE"AK47\t"WHITE"50\t"GREEN"$4700\n\
        "RED"[4]. "WHITE"MP5\t"WHITE"50\t"GREEN"$3100\n\
        "RED"[5]. "WHITE"Pancir\t"GRAY"NaN\t"GREEN"$800\n\
        "RED"[6]. "WHITE"Palica\t"GRAY"NaN\t"GREEN"$150\n\
        "RED"[7]. "WHITE"Noz\t"GRAY"NaN\t"GREEN"$80",
        ""RED"Kupi", "Izlaz"
    );

    return 1;
}

@Command{name: cmds, rank: Rank_Player(), args: playerid, const string: params[]}
    return @Command_Call{name: help, args: playerid, ""};
    
@Command{name: help, rank: Rank_Player(), args: playerid, const string: params[]}
{
    Dialog_Show(playerid, "dialog_playerhelp", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOUR"gta-world: "WHITE"Komande igraca",
        ""WHITE"Komanda\t"WHITE"Opis komande\n\
        "WHITE"rank\t"MAIN_COLOUR"Proveravate Vas rank.\n\
        "WHITE"ranks\t"MAIN_COLOUR"Vidite postojece rankove na serveru.\n\
        "WHITE"changepass\t"MAIN_COLOUR"Menjate lozinku Vaseg naloga.\n\
        "WHITE"rent\t"MAIN_COLOUR"Iznajmljujete vozilo (morate biti u blizini gde se iznajmljuje vozilo).\n\
        "WHITE"buyveh\t"MAIN_COLOUR"Kupujete Vase privatno vozilo (u auto salonu).\n\
        "WHITE"vehicle\t"MAIN_COLOUR"Opcije za Vase privatno vozilo.\n\
        "WHITE"weapon\t"MAIN_COLOUR"Kupovina oruzja (u gunshopu).\n\
        "WHITE"ask\t"MAIN_COLOUR"Postavljate pitanje online staff-u.\n\
        "WHITE"report\t"MAIN_COLOUR"Prijavljujete nesto online staff-u.",
        ""MAIN_COLOUR"Izlaz"
    );

    return 1;
}

@Command{name: ask, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (!Rank_StaffOnline())
        return SendErrorMsg(playerid, "Staff trenutno nije tu.");

    if (gettime() < player_AskTime[playerid])
        return SendErrorMsg(playerid, "Pitanja mozete slati svaka 2 minuta.");

    if (isnull(params) || IsNumeric(params))
        return SendSyntaxMsg(playerid, "ask [text]");

    Rank_SendStaffMessage("[ASK]: %s "GRAY"je poslao pitanje: "WHITE"%s", ReturnPlayerName(playerid), params);
    player_AskTime[playerid] = gettime() + 120;

    return 1;
}

@Command{name: report, rank: Rank_Player(), args: playerid, const string: params[]}
{
    if (!Rank_StaffOnline())
        return SendErrorMsg(playerid, "Staff trenutno nije tu.");

    if (gettime() < player_ReportTime[playerid])
        return SendErrorMsg(playerid, "Pitanja mozete slati svaka 2 minuta.");

    if (isnull(params) || IsNumeric(params))
        return SendSyntaxMsg(playerid, "report [text]");

    Rank_SendStaffMessage("[REPORT]: %s "GRAY"je poslao pitanje: "WHITE"%s", ReturnPlayerName(playerid), params);
    player_ReportTime[playerid] = gettime() + 120;

    return 1;
}