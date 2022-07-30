#if defined _INC_rent_dialogs_inc
    #endinput
#endif
#define _INC_rent_dialogs_inc

// Variables
static tmp_int;

// Dialogs
Dialog: dialog_renttime(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    if (!(1 <= strval(inputtext) <= 20))
        return SendErrorMsg(playerid, "Ne mozete ispod jednog minuta i iznad 20 minuta!");

    tmp_int = strval(inputtext);
    Dialog_Show(playerid, "dialog_rentvehicleid", DIALOG_STYLE_LIST,
        ""ORANGE"gta-world: "WHITE"Odaberite vozilo",
        ""ORANGE"[1]. "WHITE"Landstalker\n\
        "ORANGE"[2]. "WHITE"Sentinel\n\
        "ORANGE"[3]. "WHITE"Quad\n\
        "ORANGE"[4]. "WHITE"Sabre\n\
        "ORANGE"[5]. "WHITE"ZR-350",
        ""ORANGE"Odaberi", "Izlaz"
    );

    return 1;
}

Dialog: dialog_rentvehicleid(const playerid, response, listitem, string: inputtext[])
{
    #pragma unused inputtext

    if (!response)
        return tmp_int = 0;

    switch (listitem)
    {
        case 0: Rent_Player(playerid, 400, tmp_int);
        case 1: Rent_Player(playerid, 405, tmp_int);
        case 2: Rent_Player(playerid, 471, tmp_int);
        case 3: Rent_Player(playerid, 475, tmp_int);
        case 4: Rent_Player(playerid, 477, tmp_int);
    }

    return 1;
}