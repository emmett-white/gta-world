#if defined _INC_ui_dealership_inc
    #endinput
#endif
#define _INC_ui_dealership_inc

// Variables
static
    ui_DealershipStatus[MAX_PLAYERS],
    PlayerText: ui_DealershipTextDraw[MAX_PLAYERS][13] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...};

// Functions
stock UI_GetDealershipStatus(const playerid) return ui_DealershipStatus[playerid];
stock UI_CreateDealershipTD(const playerid)
{
    new const status = !UI_GetDealershipStatus(playerid);
    if (!status)
    {
        for (new i = 0; i < 13; ++i)
        {
            PlayerTextDrawDestroy(playerid, ui_DealershipTextDraw[playerid][i]);
            ui_DealershipTextDraw[playerid][i] = INVALID_PLAYER_TEXT_DRAW;
        }

        CancelSelectTextDraw(playerid);
        ui_DealershipStatus[playerid] = false;
        return 1;
    }

    ui_DealershipTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 260.500000, 90.911071, "LD_SPAC:WHITE");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][0], 114.000000, 247.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][0], 666397951);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][0], 0);

    ui_DealershipTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 262.200103, 93.411033, "LD_SPAC:WHITE");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][1], 114.000000, 247.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][1], 286331391);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][1], 0);

    ui_DealershipTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 317.000000, 97.911041, "SULTAN KURAC PALAC");
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][2], 0.143500, 0.871999);
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][2], 0.000000, 526.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][2], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][2], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][2], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][2], 1);

    ui_DealershipTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 269.399993, 134.466644, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][3], 99.379867, 89.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][3], 666397951);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][3], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][3], 0);

    ui_DealershipTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 263.000000, 119.533294, "");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][4], 99.000000, 116.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][4], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][4], 0x00000000);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_DealershipTextDraw[playerid][4], 560);
    PlayerTextDrawSetPreviewRot(playerid, ui_DealershipTextDraw[playerid][4], -15.00, 0.00, 45.00, 1.00);
    PlayerTextDrawSetPreviewVehCol(playerid, ui_DealershipTextDraw[playerid][4], 0, 0);

    ui_DealershipTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 319.599945, 113.888793, "Da li ste sigurni da zelite da kupite to vozilo?~n~Kliknite na 'KUPI' ukoliko ste sigurni.");
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][5], 0.135500, 0.990221);
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][5], 0.000000, 453.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][5], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][5], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][5], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][5], 1);

    ui_DealershipTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 269.500000, 229.066955, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][6], 100.000000, 22.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][6], 666397824);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][6], 0);

    ui_DealershipTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 269.500000, 256.968658, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][7], 100.000000, 22.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][7], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][7], -16777088);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][7], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][7], 0);

    ui_DealershipTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 316.399871, 233.111160, "KUPI");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][8], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][8], 0.330500, 1.382222);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][8], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][8], 0);
    PlayerTextDrawSetOutline(playerid, ui_DealershipTextDraw[playerid][8], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, ui_DealershipTextDraw[playerid][8], true);

    ui_DealershipTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 316.399871, 261.012847, "IZLAZ");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][9], 8.0, 20.0);
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][9], 0.330500, 1.382222);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][9], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][9], 0);
    PlayerTextDrawSetOutline(playerid, ui_DealershipTextDraw[playerid][9], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][9], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, ui_DealershipTextDraw[playerid][9], true);

    ui_DealershipTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 320.199981, 292.433929, "Kada kupite Vase vozilo, mozete ga pronaci na lokaciji koja ce biti oznacena na GPS-u.~n~Zelimo Vam srecnu kupovinu!");
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][10], 0.142500, 0.946666);
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][10], 0.000000, 104.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][10], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][10], 1);

    ui_DealershipTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 267.599975, 326.722473, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_DealershipTextDraw[playerid][11], 103.000000, 1.000000);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][11], 1);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][11], 666397951);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][11], 4);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][11], 0);

    ui_DealershipTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 318.100036, 329.011230, "gta-world");
    PlayerTextDrawLetterSize(playerid, ui_DealershipTextDraw[playerid][12], 0.174000, 0.822222);
    PlayerTextDrawAlignment(playerid, ui_DealershipTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, ui_DealershipTextDraw[playerid][12], 666397951);
    PlayerTextDrawSetShadow(playerid, ui_DealershipTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_DealershipTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, ui_DealershipTextDraw[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, ui_DealershipTextDraw[playerid][12], 1);

    for (new i = 0; i < 13; ++i)
        PlayerTextDrawShow(playerid, ui_DealershipTextDraw[playerid][i]);

    SelectTextDraw(playerid, X11_BLACK);
    ui_DealershipStatus[playerid] = true;

    return 1;
}

stock UI_ReturnDealershipTD(const playerid, const index) return _:ui_DealershipTextDraw[playerid][index];
stock UI_SetDealershipPrevModel(const playerid, const modelid)
{
    PlayerTextDrawSetPreviewModel(playerid, ui_DealershipTextDraw[playerid][4], modelid);
    return PlayerTextDrawShow(playerid, ui_DealershipTextDraw[playerid][4]);
}