#if defined _INC_rank_dialogs_inc
    #endinput
#endif
#define _INC_rank_dialogs_inc

Dialog: dialog_buyweapon(const playerid, response, listitem, string: inputtext)
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0: GivePlayerWeapon(playerid, 24, 50), Char_TakeMoney(playerid, 2100);
        case 1: GivePlayerWeapon(playerid, 31, 50), Char_TakeMoney(playerid, 4350);
        case 2: GivePlayerWeapon(playerid, 30, 50), Char_TakeMoney(playerid, 4700);
        case 3: GivePlayerWeapon(playerid, 29, 50), Char_TakeMoney(playerid, 3100);
        case 4: SetPlayerArmour(playerid, 100.00), Char_TakeMoney(playerid, 800);
        case 5: GivePlayerWeapon(playerid, 5, 50), Char_TakeMoney(playerid, 150);
        case 6: GivePlayerWeapon(playerid, 4, 50), Char_TakeMoney(playerid, 80);
    }
    return 1;
}

Dialog: dialog_staffpanel(const playerid, response, listitem, string: inputtext)
{
    if (!response)
        return 1;

    if (Rank_GetPlayerRankID(playerid) == Rank_Moderator())
    {
        switch (listitem)
        {
            case 0: Dialog_Show(playerid, "dialog_spanelkick", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca i razlog zbog cega ga kikujete:",
                ""MAIN_COLOUR"Kikuj", "Izlaz"
            );

            case 1: Dialog_Show(playerid, "dialog_spanelmute", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca, broj minuta i razlog zbog cega ga mutirate:",
                ""MAIN_COLOUR"Mutiraj", "Izlaz"
            );

            case 2: Dialog_Show(playerid, "dialog_spaneljail", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca, broj minuta i razlog zbog cega ga zatvarate:",
                ""MAIN_COLOUR"Zatvori", "Izlaz"
            );
        }
    }

    else if (Rank_GetPlayerRankID(playerid) == Rank_Administrator())
    {
        switch (listitem)
        {
            case 0: Dialog_Show(playerid, "dialog_spanelban", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca i razlog zbog cega ga banujete:",
                ""MAIN_COLOUR"Banuj", "Izlaz"
            );

            case 1: Dialog_Show(playerid, "dialog_spanelkick", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca i razlog zbog cega ga kikujete:",
                ""MAIN_COLOUR"Kikuj", "Izlaz"
            );

            case 2: Dialog_Show(playerid, "dialog_spanelmute", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca, broj minuta i razlog zbog cega ga mutirate:",
                ""MAIN_COLOUR"Mutiraj", "Izlaz"
            );

            case 3: Dialog_Show(playerid, "dialog_spaneljail", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite ime ili id igraca, broj minuta i razlog zbog cega ga zatvarate:",
                ""MAIN_COLOUR"Zatvori", "Izlaz"
            );

            case 4: Dialog_Show(playerid, "dialog_spanelkickall", DIALOG_STYLE_MSGBOX,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Da li zelite da kikujete sve igrace sa servera?",
                ""MAIN_COLOUR"Kikuj", "Izlaz"
            );

            case 5: Dialog_Show(playerid, "dialog_spanellocksvr", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite zeljenu sifru (0 - otkljucavanje servera):",
                ""MAIN_COLOUR"Zakljucaj", "Izlaz"
            );

            case 6: Dialog_Show(playerid, "dialog_spanelsvrhost", DIALOG_STYLE_INPUT,
                ""MAIN_COLOUR"gta-world: "WHITE"Staff panel",
                ""MAIN_COLOUR"VAZNO: "WHITE"Unesite novo ime servera (hostname):",
                ""MAIN_COLOUR"Unesi", "Izlaz"
            );
        }
    }
    return 1;
}

Dialog: dialog_spanelkick(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    static
        targetid,
        reason[MAX_REASON_LENGTH];

    if (sscanf(inputtext, "rs["#MAX_REASON_LENGTH"]", targetid, reason))
        return SendErrorMsg(playerid, "Niste uneli ispravan format.");

    if (Rank_GetPlayerRankID(targetid) == Rank_Administrator() && Rank_GetPlayerRankID(playerid) == Rank_Moderator())
        return SendErrorMsg(playerid, "Ne mozete kikovati administratora.");

    if (Rank_GetPlayerRankID(targetid) == Rank_Moderator() && Rank_GetPlayerRankID(playerid) == Rank_Moderator())
        return SendErrorMsg(playerid, "Ne mozete kikovati moderatora.");

    GameTextForPlayer(targetid, "~r~KICKED", 3000, 3);
    Rank_SendStaffMessage("[KICK]: %s je kikovao %s | Razlog: %s", ReturnPlayerName(playerid), ReturnPlayerName(targetid), reason);
    SendInfoMsgToAllF("%s je napustio server | Kikovan", ReturnPlayerName(targetid));

    task_await(Task: BindToPlayer(task_ms(1000), targetid));
    Kick(targetid);
    return 1;
}

Dialog: dialog_spanelban(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    static
        targetid,
        reason[MAX_REASON_LENGTH];

    if (sscanf(inputtext, "rs["#MAX_REASON_LENGTH"]", targetid, reason))
        return SendErrorMsg(playerid, "Niste uneli ispravan format.");

    if (Rank_GetPlayerRankID(targetid) == Rank_Administrator() && Rank_GetPlayerRankID(playerid) == Rank_Moderator())
        return SendErrorMsg(playerid, "Ne mozete banovati administratora.");

    if (Rank_GetPlayerRankID(targetid) == Rank_Moderator() && Rank_GetPlayerRankID(playerid) == Rank_Moderator())
        return SendErrorMsg(playerid, "Ne mozete banovati moderatora.");

    GameTextForPlayer(targetid, "~r~BANNED", 3000, 3);
    Rank_SendStaffMessage("[BAN]: %s je banovao %s | Razlog: %s", ReturnPlayerName(playerid), ReturnPlayerName(targetid), reason);
    SendInfoMsgToAllF("%s je napustio server | Banovan", ReturnPlayerName(targetid));
    
    task_await(Task: BindToPlayer(task_ms(1000), targetid));
    Ban(targetid);
    return 1;
}

Dialog: dialog_spanelkickall(const playerid, response, listitem, string: inputtext)
{
    if (!response)
        return 1;

    foreach (new i: Player)
    {
        if (i == playerid)
            return 0;

        GameTextForPlayer(i, "~r~KICKED", 3000, 3);
        Kick(i);
    }
    return 1;
}

Dialog: dialog_spanellocksvr(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    static password[12];
    if (sscanf(inputtext, "s[12]", password))
        return SendErrorMsg(playerid, "Niste uneli ispravan format.");

    if (!strcmp(password, "0", true))
    {
        SendRconCommand("password 0");
        Rank_SendStaffMessage("[PASSWORD]: %s je otkljucao server.", ReturnPlayerName(playerid));
    }

    else
    {
        if (!(3 <= strlen(password) <= 12))
            return SendErrorMsg(playerid, "Lozinka mora sadrzati najmanje 3 i najvise 12 karaktera!");

        new fmt_str[21];
        format(fmt_str, sizeof(fmt_str), "password %s", password);
        SendRconCommand(fmt_str);

        Rank_SendStaffMessage("[PASSWORD]: %s je zakljucao server.", ReturnPlayerName(playerid));
    }
    return 1;
}

Dialog: dialog_spanelsvrhost(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    static hostname[64];
    if (sscanf(inputtext, "s[64]", hostname))
        return SendErrorMsg(playerid, "Niste uneli ispravan format.");

    if (strlen(hostname) > 64)
        return SendErrorMsg(playerid, "Hostname ne sme sadrzati vise od 64 karaktera!");

    new fmt_str[64];
    format(fmt_str, sizeof(fmt_str), "hostname %s", hostname);
    SendRconCommand(fmt_str);

    Rank_SendStaffMessage("[HOSTNAME]: %s je promenio ime servera.", ReturnPlayerName(playerid));
    return 1;
}