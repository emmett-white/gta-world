#if defined _INC_car_dialogs_inc
    #endinput
#endif
#define _INC_car_dialogs_inc

// Variables
// Random vehicle spawns
static const Float: vehicle_RandomBuySpawn[12][4] = {
    {1759.5939, -1710.4908, 13.0203, 294.3295},
    {1759.2819, -1705.8016, 13.0203, 296.7295},
    {1759.1412, -1701.3629, 13.0203, 297.9106},
    {1759.2610, -1696.6788, 13.0203, 294.9942},
    {1759.0881, -1692.7155, 13.0203, 296.0616},
    {1759.2135, -1687.3898, 13.0203, 297.0291},
    {1766.9198, -1687.3928, 13.0201, 59.4021},
    {1767.5460, -1691.8428, 13.0203, 59.7310},
    {1766.6316, -1696.2625, 13.0203, 61.0705},
    {1766.8854, -1700.9365, 13.0203, 58.0829},
    {1766.9420, -1705.3429, 13.0203, 61.6695},
    {1766.8438, -1710.3558, 13.0203, 58.9795}
};

// Dialogs
Dialog: dialog_vehicletype(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    new dialog_fmt_names[4096]; // I hate you.
    switch (listitem)
    {
        case 0:
        {
            for (new i = 0; i < sizeof(car_Names); ++i)
            {
                format(dialog_fmt_names, sizeof(dialog_fmt_names), "%s\n"MAIN_COLOUR"[%d]. "WHITE"%s", dialog_fmt_names, (i + 1), car_Names[i]);
                Dialog_Show(playerid, "dialog_cars", DIALOG_STYLE_LIST,
                    ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
                    dialog_fmt_names,
                    ""MAIN_COLOUR"Odaberi", "Izlaz"
                );
            }
        }
        
        case 1:
        {
            for (new i = 0; i < sizeof(vehicle_MotorcycleNames); ++i)
            {
                format(dialog_fmt_names, sizeof(dialog_fmt_names), "%s\n"MAIN_COLOUR"[%d]. "WHITE"%s", dialog_fmt_names, (i + 1), vehicle_MotorcycleNames[i]);
                Dialog_Show(playerid, "dialog_motorcycles", DIALOG_STYLE_LIST,
                    ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
                    dialog_fmt_names,
                    ""MAIN_COLOUR"Odaberi", "Izlaz"
                );
            }
        }
        
        case 2:
        {
            for (new i = 0; i < sizeof(vehicle_BikeNames); ++i)
            {
                format(dialog_fmt_names, sizeof(dialog_fmt_names), "%s\n"MAIN_COLOUR"[%d]. "WHITE"%s", dialog_fmt_names, (i + 1), vehicle_BikeNames[i]);
                Dialog_Show(playerid, "dialog_bikes", DIALOG_STYLE_LIST,
                    ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
                    dialog_fmt_names,
                    ""MAIN_COLOUR"Odaberi", "Izlaz"
                );
            }
        }
        
        case 3:
        {
            for (new i = 0; i < sizeof(vehicle_PlaneNames); ++i)
            {
                format(dialog_fmt_names, sizeof(dialog_fmt_names), "%s\n"MAIN_COLOUR"[%d]. "WHITE"%s", dialog_fmt_names, (i + 1), vehicle_PlaneNames[i]);
                Dialog_Show(playerid, "dialog_airplanes", DIALOG_STYLE_LIST,
                    ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
                    dialog_fmt_names,
                    ""MAIN_COLOUR"Odaberi", "Izlaz"
                );
            }
        }
        
        case 4:
        {
            for (new i = 0; i < sizeof(vehicle_HelicopterNames); ++i)
            {
                format(dialog_fmt_names, sizeof(dialog_fmt_names), "%s\n"MAIN_COLOUR"[%d]. "WHITE"%s", dialog_fmt_names, (i + 1), vehicle_HelicopterNames[i]);
                Dialog_Show(playerid, "dialog_helicopters", DIALOG_STYLE_LIST,
                    ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
                    dialog_fmt_names,
                    ""MAIN_COLOUR"Odaberi", "Izlaz"
                );
            }
        }
    }

    return 1;
}

Dialog: dialog_cars(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    new const preview_model = car_IDS[listitem];
    UI_CreateDealershipTD(playerid);
    UI_SetDealershipPrevModel(playerid, preview_model);

    Car_ModelSelected(playerid, preview_model);
    
    return 1;
}

Dialog: dialog_carconfirmbuy(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    if (Char_GetMoney(playerid) < Car_GetModelPrice(Car_GetModelSelected(playerid)))
        return SendErrorMsg(playerid, "Nemate dovoljno novca!");

    new
        vehicleid = Car_GetNextID(),
        random_pos = random(sizeof(vehicle_RandomBuySpawn));

    Car_Create(playerid, vehicleid, Car_GetModelSelected(playerid),
        ReturnPlayerName(playerid),
        vehicle_RandomBuySpawn[random_pos][0], vehicle_RandomBuySpawn[random_pos][1], vehicle_RandomBuySpawn[random_pos][2], vehicle_RandomBuySpawn[random_pos][3],
        0, 0, 1
    );

    Char_TakeMoney(playerid, Car_GetModelPrice(Car_GetModelSelected(playerid)));
    SendInfoMsgF(playerid, "Uspesno ste kupili vozilo marke "WHITE"%s"ORANGE"!", Car_GetModelName(Car_GetModelSelected(playerid)));
    UI_CreateDealershipTD(playerid);

    return 1;
}

Dialog: dialog_playervehicles(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0:
        {
            if (!Car_PlayerExists(playerid) && !IsPlayerInVehicle(playerid, Car_GetID(Car_GetNearest(playerid))))
                return SendErrorMsg(playerid, "Nemate vozilo ili niste u svom vozilu!");

            Dialog_Show(playerid, "dialog_caroptions", DIALOG_STYLE_LIST,
                ""MAIN_COLOUR"gta-world: "WHITE"Opcije vozila",
                ""MAIN_COLOUR"> "WHITE"Informacije o vozilu\n\
                "MAIN_COLOUR"> "WHITE"Prozori %s\n\
                "MAIN_COLOUR"> "WHITE"Vrata %s\n\
                "MAIN_COLOUR"> "WHITE"Radio\n\
                "MAIN_COLOUR"> %s",
                ""MAIN_COLOUR"Odaberi", "Izlaz",
                (!Car_GetPlayerWinStatus(playerid) ? (""DARKRED"Zatvoreni") : (""GREEN"Otvoreni")),
                (!Car_GetPlayerDoorsStatus(playerid) ? (""DARKRED"Zatvorena") : (""GREEN"Otvorena")),
                (!Car_GetPlayerLockStatus(playerid) ? (""DARKRED"Zakljucaj "WHITE"vozilo") : (""GREEN"Otkljucaj "WHITE"vozilo"))
            );
        }
    }

    return 1;
}

Dialog: dialog_caroptions(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 1;

    switch (listitem)
    {
        case 0:
        {
            Dialog_Show(playerid, "dialog_carinfo", DIALOG_STYLE_MSGBOX,
                ""MAIN_COLOUR"gta-world: "WHITE"Informacije vozila",
                ""MAIN_COLOUR"Marka: "WHITE"%s\n\
                "MAIN_COLOUR"Boja: %s\n\
                "MAIN_COLOUR"Vlasnik: "WHITE"%s",
                ""MAIN_COLOUR"Izlaz", "",
                Car_GetModelName(Car_GetPlayerModel(playerid)),
                Car_GetColour(Car_GetID(playerid)),
                Car_GetOwner(Car_GetID(playerid))
            );
        }

        case 1:
        {
            new driver, passenger, backleft, backright;
            GetVehicleParamsCarWindows(GetPlayerVehicleID(playerid), driver, passenger, backleft, backright);
            Car_SetPlayerWinStatus(playerid);

            if (!Car_GetPlayerWinStatus(playerid))
                SetVehicleParamsCarWindows(GetPlayerVehicleID(playerid), 0, 0, 0, 0);
            else SetVehicleParamsCarWindows(GetPlayerVehicleID(playerid), 1, 1, 1, 1);
        }

        case 2: Car_SetPlayerDoorsStatus(playerid);
        case 4: Car_SetPlayerLockStatus(playerid);
    }

    return 1;
}