#if defined _INC_account_ui_inc
    #endinput
#endif
#define _INC_account_ui_inc

// Variables
static
    PlayerText: UI_Loading[MAX_PLAYERS] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerText: UI_LoginTextDraw[MAX_PLAYERS][14] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},

    account_UIUsernamePass[MAX_PLAYERS],
    account_UIPasswordPass[MAX_PLAYERS],

    player_LoginTDStatus[MAX_PLAYERS],
    player_LoadingTDStatus[MAX_PLAYERS];

// Functions
stock Account_GetUILoading(const playerid) return player_LoadingTDStatus[playerid];
stock UI_AccountLoading(const playerid)
{
    new const status = !Account_GetUILoading(playerid);

    if (!status)
    {
        PlayerTextDrawDestroy(playerid, UI_Loading[playerid]);
        
        UI_Loading[playerid] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        player_LoadingTDStatus[playerid] = false;
        return 1;
    }

    UI_Loading[playerid] = CreatePlayerTextDraw(playerid, 169.499420, 173.199981, "");
    PlayerTextDrawLetterSize(playerid, UI_Loading[playerid], 0.457999, 1.593777);
    PlayerTextDrawTextSize(playerid, UI_Loading[playerid], 714.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, UI_Loading[playerid], 1);
    PlayerTextDrawColor(playerid, UI_Loading[playerid], 545049599);
    PlayerTextDrawSetShadow(playerid, UI_Loading[playerid], 0);
    PlayerTextDrawSetOutline(playerid, UI_Loading[playerid], 1);
    PlayerTextDrawBackgroundColor(playerid, UI_Loading[playerid], 255);
    PlayerTextDrawFont(playerid, UI_Loading[playerid], 2);
    PlayerTextDrawSetProportional(playerid, UI_Loading[playerid], 1);

    player_LoadingTDStatus[playerid] = true;

    // UwU
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I   N");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I   N   G");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I   N   G   .");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I   N   G   .   .");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);
    task_await(Task: BindToPlayer(task_ms(700), playerid));
    PlayerTextDrawSetString(playerid, UI_Loading[playerid], "L   O   A   D   I   N   G   .   .   .");
    PlayerTextDrawShow(playerid, UI_Loading[playerid]);

    return 1;
}

stock Account_UILoginFailed(const playerid) return (Account_GetUIUsername(playerid) && Account_GetUIPassword(playerid)) ? (1) : (0);
stock Account_UIUsernamePass(const playerid, const value) return account_UIUsernamePass[playerid] = value;
stock Account_UIPasswordPass(const playerid, const value) return account_UIPasswordPass[playerid] = value;
stock Account_GetUIUsername(const playerid) return account_UIUsernamePass[playerid];
stock Account_GetUIPassword(const playerid) return account_UIPasswordPass[playerid];
stock Account_GetUILogin(const playerid) return player_LoginTDStatus[playerid];
stock Account_UILoginClicked(const playerid, const index) return _:UI_LoginTextDraw[playerid][index];
stock UI_AccountLogin(const playerid)
{
    new const status = !Account_GetUILogin(playerid);

    if (!status)
    {
        for (new i = 0; i < sizeof(UI_LoginTextDraw[]); ++i)
        {
            PlayerTextDrawDestroy(playerid, UI_LoginTextDraw[playerid][i]);
            UI_LoginTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        player_LoginTDStatus[playerid] = false;
        return 1;
    }

    UI_LoginTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 251.000000, 110.822204, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][0], 136.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][0], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][0], 144);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][0], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][0], 4);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][0], 0);

    UI_LoginTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 251.000000, 110.822204, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][1], 136.000000, 230.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][1], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][1], 144);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][1], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][1], 4);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][1], 0);

    UI_LoginTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 318.200012, 112.944389, "GTA WORLD - ~w~PRIJAVLJIVANJE");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][2], 0.164000, 0.735111);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][2], 0.000000, 423.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][2], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][2], 545049599);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][2], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][2], 1);

    UI_LoginTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 319.300079, 132.655487, "Imate tri pokusaja da se prijavite.~n~Ukoliko omasite sva tri puta, bicete~n~automatski ~r~kikovani ~w~sa servera.");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][3], 0.138500, 0.735111);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][3], 0.000000, 423.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][3], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][3], -1);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][3], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][3], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][3], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][3], 1);

    UI_LoginTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 255.500000, 162.532562, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][4], 126.150032, 19.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][4], -112);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][4], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][4], 4);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][4], 0);

    UI_LoginTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 255.500000, 186.934051, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][5], 126.150032, 19.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][5], -112);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][5], 0);

    UI_LoginTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 281.500000, 211.200729, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][6], 75.000000, 18.520011);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][6], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][6], 545049376);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][6], 4);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][6], 0);

    UI_LoginTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 316.900024, 168.844421, "UNESITE VASE IME");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][7], 0.190499, 0.741333);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][7], 8.0, 485.0);
    // PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][7], 0.000000, 485.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][7], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][7], 255);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][7], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][7], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][7], 1);
    PlayerTextDrawSetSelectable(playerid, UI_LoginTextDraw[playerid][7], true);

    UI_LoginTextDraw[playerid][8] = CreatePlayerTextDraw(playerid, 316.500000, 193.345916, "Unesite vasu lozinku");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][8], 0.190499, 0.741333);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][8], 8.0, 485.0);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][8], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][8], 255);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][8], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][8], 1);
    PlayerTextDrawSetSelectable(playerid, UI_LoginTextDraw[playerid][8], true);

    UI_LoginTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 319.400024, 216.755523, "PRIJAVI SE");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][9], 0.190499, 0.741333);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][9], 8.0, 485.0);
    // PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][9], 0.000000, 485.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][9], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][9], -2139062017);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][9], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][9], 1);
    PlayerTextDrawSetSelectable(playerid, UI_LoginTextDraw[playerid][9], true);

    UI_LoginTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 233.500000, 260.155609, "");
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][10], 75.000000, 70.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][10], 1);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][10], 0x00000000);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][10], 5);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][10], 0);
    PlayerTextDrawSetPreviewModel(playerid, UI_LoginTextDraw[playerid][10], 217);
    PlayerTextDrawSetPreviewRot(playerid, UI_LoginTextDraw[playerid][10], -15.000000, 0.000000, 25.000000, 1.000000);

    UI_LoginTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 270.399963, 254.711151, "Administrator");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][11], 0.092999, 0.735110);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][11], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][11], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][11], 1);

    UI_LoginTextDraw[playerid][12] = CreatePlayerTextDraw(playerid, 330.400024, 265.911163, "KAZE: Ukoliko ne unesete vase tacno ime i lozinku iz treceg pokusaja, staff team ce biti~n~obavesten o pokusaju ~r~''upada''~w~");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][12], 0.125000, 0.591999);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][12], 0.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][12], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][12], 1);

    UI_LoginTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 353.600250, 286.900177, "na_tudji_nalog!");
    PlayerTextDrawLetterSize(playerid, UI_LoginTextDraw[playerid][13], 0.117000, 0.598221);
    PlayerTextDrawTextSize(playerid, UI_LoginTextDraw[playerid][13], 0.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, UI_LoginTextDraw[playerid][13], 2);
    PlayerTextDrawColor(playerid, UI_LoginTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, UI_LoginTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, UI_LoginTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, UI_LoginTextDraw[playerid][13], 2);
    PlayerTextDrawSetProportional(playerid, UI_LoginTextDraw[playerid][13], 1);

    for (new i = 0; i < sizeof(UI_LoginTextDraw[]); ++i)
        PlayerTextDrawShow(playerid, UI_LoginTextDraw[playerid][i]);

    player_LoginTDStatus[playerid] = true;

    return 1;
}