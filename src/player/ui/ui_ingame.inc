#if defined _INC_ui_ingame_inc
    #endinput
#endif
#define _INC_ui_ingame_inc

#include <YSI_Coding\y_hooks>

// Variables
static
    playerCurrentFPS[MAX_PLAYERS],
    playerCurrentDrunkLevel[MAX_PLAYERS],

    ui_InGameStatus[MAX_PLAYERS],
    ui_SpeedometerStatus[MAX_PLAYERS],
    ui_PlayersConnected,

    PlayerText: ui_InGameTextDraw[MAX_PLAYERS][15] = {PlayerText: INVALID_PLAYER_TEXT_DRAW,...},
    PlayerBar: ui_ProgressBar[MAX_PLAYERS][4] = {PlayerBar: INVALID_PLAYER_BAR_ID,...};

static stock const player_RandomMessages[][] =
{
    "DA VIDITE DISCORD SERVERA KORISTITE KOMANDU DISCORD.",
    "SKRIPTER OVOG SERVERA JE EMMETT.",
    "DRZITE NOVAC U BANCI, DA VAS NE BI POKRALI.",
    "CUVAJTE SE BANDA I MAFIJA!",
    "UKOLIKO PRIMETITE ZLOCIN, PRIJAVITE POLICIJI!",
    "UKOLIKO PRIMETITE BUG, PRIJAVITE SKRIPTERU!",
    "ZALBE NA IGRACE SALJITE KOMANDOM REPORT.",
    "UKOLIKO VAM JE POTREBNA POMOC KORISTITE KOMANDU ASK."
};

// Functions
stock UI_GetInGameStatus(const playerid) return ui_InGameStatus[playerid];
stock UI_CreateInGameTextDraws(const playerid)
{
    new const status = !UI_GetInGameStatus(playerid);
    if (!status)
    {
        for (new i = 0; i < sizeof(ui_InGameTextDraw[]) - 2; ++i)
        {
            PlayerTextDrawDestroy(playerid, ui_InGameTextDraw[playerid][i]);
            ui_InGameTextDraw[playerid][i] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        }

        PlayerTextDrawDestroy(playerid, ui_InGameTextDraw[playerid][14]);
        ui_InGameTextDraw[playerid][14] = PlayerText: INVALID_PLAYER_TEXT_DRAW;

        DestroyPlayerProgressBar(playerid, ui_ProgressBar[playerid][0]);
        DestroyPlayerProgressBar(playerid, ui_ProgressBar[playerid][1]);
        DestroyPlayerProgressBar(playerid, ui_ProgressBar[playerid][2]);
        ui_ProgressBar[playerid][0] = PlayerBar: INVALID_PLAYER_BAR_ID;
        ui_ProgressBar[playerid][1] = PlayerBar: INVALID_PLAYER_BAR_ID;
        ui_ProgressBar[playerid][2] = PlayerBar: INVALID_PLAYER_BAR_ID;
        ui_InGameStatus[playerid] = false;
        return 1;
    }

    ui_InGameTextDraw[playerid][0] = CreatePlayerTextDraw(playerid, 593.199707, 6.866601, "GTA~w~WORLD");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][0], 0.306499, 1.842666);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][0], 0.000000, 168.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][0], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][0], 545049599);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][0], 0);
    PlayerTextDrawSetOutline(playerid, ui_InGameTextDraw[playerid][0], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][0], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][0], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][0], 1);

    ui_InGameTextDraw[playerid][1] = CreatePlayerTextDraw(playerid, 593.199707, 19.166643, "VERSION_~w~STABLE_v1.0");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][1], 0.139500, 0.610666);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][1], 0.000000, 168.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][1], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][1], 545049599);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][1], 0);
    PlayerTextDrawSetOutline(playerid, ui_InGameTextDraw[playerid][1], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][1], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][1], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][1], 1);

    ui_InGameTextDraw[playerid][2] = CreatePlayerTextDraw(playerid, 212.100036, 429.933593, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][2], 454.000000, 118.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][2], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][2], 545049599);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][2], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][2], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][2], 4);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][2], 0);

    ui_InGameTextDraw[playerid][3] = CreatePlayerTextDraw(playerid, 169.300048, 424.222198, "");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][3], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][3], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][3], 545049599);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][3], 0x00000000);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][3], 0);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][3], 5);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][3], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_InGameTextDraw[playerid][3], 19377);
    PlayerTextDrawSetPreviewRot(playerid, ui_InGameTextDraw[playerid][3], 0.000000, 45.000000, 90.000000, 1.000000);

    ui_InGameTextDraw[playerid][4] = CreatePlayerTextDraw(playerid, 169.800079, 425.722290, "");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][4], 90.000000, 90.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][4], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][4], 255);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][4], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][4], 0x00000000);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][4], 5);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][4], 0);
    PlayerTextDrawSetPreviewModel(playerid, ui_InGameTextDraw[playerid][4], 19377);
    PlayerTextDrawSetPreviewRot(playerid, ui_InGameTextDraw[playerid][4], 0.000000, 45.000000, 90.000000, 1.000000);

    ui_InGameTextDraw[playerid][5] = CreatePlayerTextDraw(playerid, 213.900146, 431.033660, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][5], 454.000000, 118.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][5], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][5], 255);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][5], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][5], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][5], 4);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][5], 0);

    ui_InGameTextDraw[playerid][6] = CreatePlayerTextDraw(playerid, 637.100585, 431.477783, ReturnPlayerName(playerid));
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][6], 0.172499, 0.778444);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][6], 3);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][6], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][6], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][6], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][6], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][6], 1);

    ui_InGameTextDraw[playerid][7] = CreatePlayerTextDraw(playerid, 561.301635, 435.966125, "OVO JE RANDOM PORUKA JEBEM MU KRV HEHEHE");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][7], 0.158499, 0.747555);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][7], 954.000000, 0.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][7], 3);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][7], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][7], 0);
    PlayerTextDrawSetOutline(playerid, ui_InGameTextDraw[playerid][7], 1);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][7], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][7], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][7], 1);

    ui_InGameTextDraw[playerid][8] = va_CreatePlayerTextDraw(playerid, 637.700439, 438.322570, "RANK: ~y~%s", Rank_GetRankName(Rank_GetPlayerRankID(playerid)));
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][8], 0.172499, 0.788444);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][8], 3);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][8], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][8], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][8], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][8], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][8], 1);

    ui_InGameTextDraw[playerid][9] = CreatePlayerTextDraw(playerid, 566.600097, 433.833343, "LD_SPAC:white");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][9], 1.000000, 12.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][9], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][9], 545049599);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][9], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][9], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][9], 4);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][9], 0);

    ui_InGameTextDraw[playerid][10] = CreatePlayerTextDraw(playerid, 247.899810, 423.000000, "TRENUTNO IGRACA: 1/1000");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][10], 0.133999, 0.635555);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][10], 0.000000, 321.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][10], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][10], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][10], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][10], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][10], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][10], 1);

    ui_InGameTextDraw[playerid][11] = CreatePlayerTextDraw(playerid, 303.499969, 423.099945, "FPS: 200");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][11], 0.133999, 0.635555);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][11], 0.000000, 321.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][11], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][11], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][11], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][11], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][11], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][11], 1);

    ui_InGameTextDraw[playerid][12] = va_CreatePlayerTextDraw(playerid, 346.299896, 423.000000, "PING: %dms", GetPlayerPing(playerid));
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][12], 0.133999, 0.635555);
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][12], 0.000000, 321.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][12], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][12], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][12], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][12], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][12], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][12], 1);

    ui_InGameTextDraw[playerid][14] = CreatePlayerTextDraw(playerid, 615.000000, 404.000000, "");
    PlayerTextDrawTextSize(playerid, ui_InGameTextDraw[playerid][14], 22.000000, 23.000000);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][14], 1);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][14], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][14], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][14], 0x00000000);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][14], 5);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][14], 0);
    PlayerTextDrawSetSelectable(playerid, ui_InGameTextDraw[playerid][14], true);
    PlayerTextDrawSetPreviewModel(playerid, ui_InGameTextDraw[playerid][14], 1314);
    PlayerTextDrawSetPreviewRot(playerid, ui_InGameTextDraw[playerid][14], 0.000000, 0.000000, 0.000000, 1.000000);

    ui_ProgressBar[playerid][0] = CreatePlayerProgressBar(playerid, 216.00, 437.00, 67.00, 4.69, 542813183, float(GetMaxPlayers()), 0);
    ui_ProgressBar[playerid][1] = CreatePlayerProgressBar(playerid, 286.00, 437.00, 40.50, 4.69, 542813183, 100.00, 0);
    ui_ProgressBar[playerid][2] = CreatePlayerProgressBar(playerid, 329.00, 437.00, 40.50, 4.69, 542813183, 100.00, 0);

    ui_InGameStatus[playerid] = true;

    return 1;
}

stock UI_ShowInGameTextDraws(const playerid)
{
    if (!UI_GetInGameStatus(playerid))
    {
        for (new i = 0; i < sizeof(ui_InGameTextDraw[]) - 2; ++i)
            PlayerTextDrawHide(playerid, ui_InGameTextDraw[playerid][i]);

        PlayerTextDrawHide(playerid, ui_InGameTextDraw[playerid][14]);
        
        HidePlayerProgressBar(playerid, ui_ProgressBar[playerid][0]);
        HidePlayerProgressBar(playerid, ui_ProgressBar[playerid][1]);
        HidePlayerProgressBar(playerid, ui_ProgressBar[playerid][2]);
        return 1;
    }

    for (new i = 0; i < sizeof(ui_InGameTextDraw[]) - 2; ++i)
        PlayerTextDrawShow(playerid, ui_InGameTextDraw[playerid][i]);

    if (Rank_GetPlayerRankID(playerid) == Rank_Moderator() || Rank_GetPlayerRankID(playerid) == Rank_Administrator())
        PlayerTextDrawShow(playerid, ui_InGameTextDraw[playerid][14]);

    ShowPlayerProgressBar(playerid, ui_ProgressBar[playerid][0]);
    ShowPlayerProgressBar(playerid, ui_ProgressBar[playerid][1]);
    ShowPlayerProgressBar(playerid, ui_ProgressBar[playerid][2]);

    return 1;
}

stock UI_GetSpeedometerStatus(const playerid) return ui_SpeedometerStatus[playerid];
stock UI_CreateSpeedometer(const playerid)
{
    new const status = !UI_GetSpeedometerStatus(playerid);

    if (!status)
    {
        PlayerTextDrawDestroy(playerid, ui_InGameTextDraw[playerid][13]);
        DestroyPlayerProgressBar(playerid, ui_ProgressBar[playerid][3]);

        ui_InGameTextDraw[playerid][13] = PlayerText: INVALID_PLAYER_TEXT_DRAW;
        ui_ProgressBar[playerid][3] = PlayerBar: INVALID_PLAYER_BAR_ID;

        ui_SpeedometerStatus[playerid] = false;
        return 1;
    }

    ui_InGameTextDraw[playerid][13] = CreatePlayerTextDraw(playerid, 287.699981, 396.000000, "200KM/H");
    PlayerTextDrawLetterSize(playerid, ui_InGameTextDraw[playerid][13], 0.206000, 0.809777);
    PlayerTextDrawAlignment(playerid, ui_InGameTextDraw[playerid][13], 2);
    PlayerTextDrawColor(playerid, ui_InGameTextDraw[playerid][13], -1);
    PlayerTextDrawSetShadow(playerid, ui_InGameTextDraw[playerid][13], 0);
    PlayerTextDrawBackgroundColor(playerid, ui_InGameTextDraw[playerid][13], 255);
    PlayerTextDrawFont(playerid, ui_InGameTextDraw[playerid][13], 1);
    PlayerTextDrawSetProportional(playerid, ui_InGameTextDraw[playerid][13], 1);

    ui_ProgressBar[playerid][3] = CreatePlayerProgressBar(playerid, 228.00, 406.00, 127.50, 6.19, -1429936641, 280.00, 0);

    PlayerTextDrawShow(playerid, ui_InGameTextDraw[playerid][13]);
    ShowPlayerProgressBar(playerid, ui_ProgressBar[playerid][3]);

    ui_SpeedometerStatus[playerid] = true;

    return 1;
}

stock UI_GetVehicleSpeed(const vehicleid)
{
    static
        Float: pos_y,
        Float: pos_x,
        Float: pos_z,
        Float: veh_speed;

    GetVehicleVelocity(vehicleid, pos_x, pos_y, pos_z);
    veh_speed = (floatsqroot((pos_x * pos_x) + (pos_y * pos_y) + (pos_z * pos_z * 2)) * 220); // 228
    
    return floatround(veh_speed, floatround_round);
}

stock UI_GetCurrentPlayers() return ui_PlayersConnected;
stock UI_UpdateRank(const playerid) return va_UpdatePlayerTextDraw(playerid, ui_InGameTextDraw[playerid][8], "RANK: ~y~%s", Rank_GetRankName(Rank_GetPlayerRankID(playerid)));
stock UI_GetPlayerFPS(const playerid)
{
    new
        level = GetPlayerDrunkLevel(playerid),
        difference = playerCurrentDrunkLevel[playerid] - level;

	if(level < 100)
		SetPlayerDrunkLevel(playerid, 2000);

	else if(playerCurrentDrunkLevel[playerid] != level)
	{
	    if((0 <= difference <= 200) && playerCurrentFPS[playerid] != difference)
	        if(playerCurrentFPS[playerid] < 0)
	            playerCurrentFPS[playerid] = 0;

		playerCurrentFPS[playerid] = difference;
		playerCurrentDrunkLevel[playerid] = level;
	}

    return playerCurrentFPS[playerid];
}

stock UI_StaffPanelClicked(const playerid) return _:ui_InGameTextDraw[playerid][14];

// Hooks
hook OnPlayerConnect(playerid)
{
    UI_CreateInGameTextDraws(playerid);

    ++ui_PlayersConnected;
    va_PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][10], "TRENUTNO IGRACA: %d/%d", UI_GetCurrentPlayers(), GetMaxPlayers());
    SetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][0], UI_GetCurrentPlayers());

    return 1;
}

hook OnPlayerDisconnect(playerid, reason)
{
    UI_CreateInGameTextDraws(playerid);

    --ui_PlayersConnected;
    va_PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][10], "TRENUTNO IGRACA: %d/%d", UI_GetCurrentPlayers(), GetMaxPlayers());
    SetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][0], UI_GetCurrentPlayers());

    return 1;
}

hook OnPlayerStateChange(playerid, newstate, oldstate)
{
    if (GetPlayerState(playerid) == PLAYER_STATE_DRIVER && !UI_GetSpeedometerStatus(playerid))
        UI_CreateSpeedometer(playerid);
    else if (GetPlayerState(playerid) == PLAYER_STATE_ONFOOT && UI_GetSpeedometerStatus(playerid))
        UI_CreateSpeedometer(playerid);

    return 1;
}

// Timers
PTASK__ timer_UpdateMessages[4000](playerid)
{
    PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][7], player_RandomMessages[random(sizeof(player_RandomMessages))]);
}

PTASK__ timer_UpdateFpsPing[1000](playerid)
{
    if (UI_GetInGameStatus(playerid))
    {
        va_PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][11], "FPS: %d", UI_GetPlayerFPS(playerid));
        va_PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][12], "PING: %dms", GetPlayerPing(playerid));

        SetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][1], UI_GetPlayerFPS(playerid));
        SetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][2], GetPlayerPing(playerid));
    }
}

PTASK__ timer_UpdateSpeed[175](playerid)
{
    if (IsPlayerInAnyVehicle(playerid))
    {
        va_PlayerTextDrawSetString(playerid, ui_InGameTextDraw[playerid][13], "%dKM/H", UI_GetVehicleSpeed(GetPlayerVehicleID(playerid)));
        
        new Float: value = GetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][3]);
        if (value <= 80.00)
            SetPlayerProgressBarColour(playerid, ui_ProgressBar[playerid][3], -1429936641);

        else if (value <= 120.00)
            SetPlayerProgressBarColour(playerid, ui_ProgressBar[playerid][3], X11_ORANGE);

        else SetPlayerProgressBarColour(playerid, ui_ProgressBar[playerid][3], 0xFF0000AA);

        SetPlayerProgressBarValue(playerid, ui_ProgressBar[playerid][3], UI_GetVehicleSpeed(GetPlayerVehicleID(playerid)));
    }
}