#if defined _INC_vehicle_hooks_inc
    #endinput
#endif
#define _INC_vehicle_hooks_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    GameTextForPlayer(playerid, "~w~Motor: ~y~2~n~~w~Svetla: ~y~Y~n~~w~Vrata: ~y~N", 2000, 3);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    // Engine status
    if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_SUBMISSION))
        Vehicle_SetEngineStatus(playerid);
    
    // Lights status
    if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_YES))
        Vehicle_SetLightsStatus(playerid);

    // Doors status
    if (IsPlayerInAnyVehicle(playerid) && PRESSED(KEY_NO))
        Vehicle_SetDoorsStatus(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}