#if defined _INC_vehicle_functions_inc
    #endinput
#endif
#define _INC_vehicle_functions_inc

#include <YSI_Coding\y_hooks>

// Variables
static
    BitArray: BIT_VehicleEngine<MAX_PLAYERS>,
    BitArray: BIT_VehicleLights<MAX_PLAYERS>,
    BitArray: BIT_VehicleDoors<MAX_PLAYERS>;

// Hooks
// To avoid messing up engine, lights and doors status
hook OnPlayerEnterVehicle(playerid, vehicleid, ispassenger)
{
    Bit_Set(BIT_VehicleEngine, playerid, true);
    Bit_Set(BIT_VehicleLights, playerid, true);
    Bit_Set(BIT_VehicleDoors, playerid, true);

    Vehicle_SetEngineStatus(playerid);
    Vehicle_SetLightsStatus(playerid);
    Vehicle_SetDoorsStatus(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerExitVehicle(playerid, vehicleid)
{
    Bit_Set(BIT_VehicleEngine, playerid, true);
    Bit_Set(BIT_VehicleLights, playerid, true);
    Bit_Set(BIT_VehicleDoors, playerid, true);

    Vehicle_SetEngineStatus(playerid);
    Vehicle_SetLightsStatus(playerid);
    Vehicle_SetDoorsStatus(playerid);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// Functions
stock Vehicle_GetEngineStatus(const playerid) return Bit_Get(BIT_VehicleEngine, playerid);
stock Vehicle_SetEngineStatus(const playerid)
{
    new const bool: status = !Vehicle_GetEngineStatus(playerid);
    static engine, lights, alarm, doors, bonnet, boot, objective;
    
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), status, lights, alarm, doors, bonnet, boot, objective);

    if (!status)
        Bit_Set(BIT_VehicleEngine, playerid, false);
    else Bit_Let(BIT_VehicleEngine, playerid);

    return 1;
}

stock Vehicle_GetLightsStatus(const playerid) return Bit_Get(BIT_VehicleLights, playerid);
stock Vehicle_SetLightsStatus(const playerid)
{
    new const bool: status = !Vehicle_GetLightsStatus(playerid);
    static engine, lights, alarm, doors, bonnet, boot, objective;
    
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, status, alarm, doors, bonnet, boot, objective);

    if (!status)
        Bit_Set(BIT_VehicleLights, playerid, false);
    else Bit_Let(BIT_VehicleLights, playerid);

    return 1;
}

stock Vehicle_GetDoorsStatus(const playerid) return Bit_Get(BIT_VehicleDoors, playerid);
stock Vehicle_SetDoorsStatus(const playerid)
{
    new const bool: status = !Vehicle_GetDoorsStatus(playerid);
    static engine, lights, alarm, doors, bonnet, boot, objective;
    
    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, status, bonnet, boot, objective);

    if (!status)
        Bit_Set(BIT_VehicleDoors, playerid, false);
    else Bit_Let(BIT_VehicleDoors, playerid);

    return 1;
}

stock Vehicle_GetType(const modelid)
{
    static model_type[16];
    switch (modelid)
    {
        case 448, 461, 462, 463, 468, 521, 522, 581, 586: { model_type = "Motor"; }
        case 460, 476, 511, 512, 513, 519, 520, 553, 577, 592, 593: { model_type = "Avion"; }
        case 417, 425, 447, 469, 487, 488, 497, 548, 563: { model_type = "Helikopter"; }
        case 481, 509, 510: { model_type = "Biciklo"; }
        // If the vehicle type is none of the above
        default: { model_type = "Automobil"; }
    }

    return model_type;
}