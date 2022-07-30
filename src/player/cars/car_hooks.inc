#if defined _INC_car_hooks_inc
    #endinput
#endif
#define _INC_car_hooks_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnScriptInit()
{
    mysql_tquery(MySQL_GetHandle(), "SELECT * FROM cars", "Car_Load");
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText: UI_ReturnDealershipTD(playerid, 8))
    {
        Dialog_Show(playerid, "dialog_carconfirmbuy", DIALOG_STYLE_MSGBOX,
            ""MAIN_COLOUR"gta-world: "WHITE"Salon vozila",
            ""MAIN_COLOUR"VAZNO: "WHITE"Da li ste sigurni da zelite da kupite ovo vozilo?\n\
            "MAIN_COLOUR"Vozilo: "WHITE"%s\n"MAIN_COLOUR"Cena: "WHITE"$%d",
            ""MAIN_COLOUR"Kupi", "Odustani", Car_GetModelName(Car_GetModelSelected(playerid)), Car_GetModelPrice(Car_GetModelSelected(playerid))
        );
    }
    
    else if (playertextid == PlayerText: UI_ReturnDealershipTD(playerid, 9))
        UI_CreateDealershipTD(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    if (Car_GetID(playerid) != vehicleid && Car_GetLockStatus(vehicleid))
        return GameTextForPlayer(playerid, "~r~Zakljucano ~w~vozilo!", 1500, 3), ClearAnimations(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}