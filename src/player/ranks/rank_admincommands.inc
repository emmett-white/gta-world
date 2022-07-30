#if defined _INC_rank_admincommands_inc
    #endinput
#endif
#define _INC_rank_admincommands_inc

@Command{name: setrank, rank: Rank_Administrator(), args: playerid, const string: params[]}
{
    static
        targetid,
        rank_name[MAX_PLAYER_NAME];

    if (sscanf(params, "rs[25]", targetid, rank_name))
        return SendSyntaxMsg(playerid, "setrank [id igraca] [ime ranka (!ranks)]");

    Rank_SetPlayerRank(targetid, playerid, rank_name);

    return 1;
}

@Command{name: createrent, rank: Rank_Administrator(), args: playerid, const string: params[]}
{
    new
        String: str_query_insert,
        Float: x, Float: y, Float: z,
        i = Rent_GetNextID();

    GetPlayerPos(playerid, x, y, z);
    Rent_Create(i, x, y, z);

    str_query_insert = String: str_format(
        "INSERT INTO rent (rent_id, rent_x, rent_y, rent_z) VALUES ('%d', '%f', '%f', '%f')",
        (i + 1), x, y, z
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_insert);
    SendInfoMsgF(playerid, "Kreirali ste rent ID %d.", (i + 1));

    return 1;
}

@Command{name: deleterent, rank: Rank_Administrator(), args: playerid, const string: params[]}
{
    new rentid = Rent_GetNearest(playerid);
    if (rentid == -1)
        return SendErrorMsg(playerid, "Morate biti blizu renta!");

    Rent_Delete(playerid, rentid);

    return 1;
}

@Command{name: xyz, rank: Rank_Administrator(), args: playerid, const string: params[]}
{
    new Float: x, Float: y, Float: z;
    if (sscanf(params, "fff", x, y, z))
        return SendSyntaxMsg(playerid, "xyz [x] [y] [z]");

    SetPlayerPos(playerid, x, y, z);

    return 1;
}

@Command{name: ahelp, rank: Rank_Administrator(), args: playerid, const string: params[]}
    return @Command_Call{name: ah, args: playerid, ""};

@Command{name: ah, rank: Rank_Administrator(), args: playerid, const string: params[]}
{
    Dialog_Show(playerid, "dialog_adminhelp", DIALOG_STYLE_TABLIST_HEADERS,
        ""MAIN_COLOUR"gta-world: "WHITE"Admin komande",
        ""WHITE"Komanda\t"WHITE"Opis komande\n\
        "WHITE"setrank\t"MAIN_COLOUR"Postavlja rank (player, moderator, administrator) odredjenom igracu.\n\
        "WHITE"createrent\t"MAIN_COLOUR"Kreira rent na Vasoj trenutnoj lokaciji.\n\
        "WHITE"deleterent\t"MAIN_COLOUR"Brise Vama najblizi rent.\n\
        "WHITE"xyz\t"MAIN_COLOUR"Mogucnost postavljanja Vase pozicije na odredjene koordinate.",
        ""MAIN_COLOUR"Izlaz"
    );

    return 1;
}