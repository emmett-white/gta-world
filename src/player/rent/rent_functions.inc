#if defined _INC_rent_functions_inc
    #endinput
#endif
#define _INC_rent_functions_inc

// Variables
#if defined MAX_RENTS
    #undef MAX_RENTS
#endif
const MAX_RENTS = 50;
const RENT_PRICE_PER_MINUTE = 3;

enum E_RENT_VEHICLE_DATA
{
    E_RENT_VEHICLE_UNIQUE_ID,
    E_RENT_VEHICLE_TIME,
    E_RENT_VEHICLE_MAPICON,
    E_RENT_VEHICLE_PICKUP,
    E_RENT_VEHICLE_CREATED,
    E_RENT_VEHICLE_ID,
    
    Float: E_RENT_VEHICLE_PICKUP_X,
    Float: E_RENT_VEHICLE_PICKUP_Y,
    Float: E_RENT_VEHICLE_PICKUP_Z,

    Text3D: E_RENT_VEHICLE_PICKUP_LABEL
};

new
    rent_Vehicle[MAX_RENTS][E_RENT_VEHICLE_DATA],
    rent_Time[MAX_PLAYERS],
    rent_VehicleID[MAX_PLAYERS],

    // Timer: rent_Timer[MAX_PLAYERS],
    Text3D: rent_VehicleLabel[MAX_PLAYERS];

// Timer
TIMER__ Rent_Expired[Rent_GetPlayerTime(playerid)](playerid)
{
    Rent_Player(playerid, -1, 0);
}

// Functions
stock Rent_Create(const rentid, Float: x, Float: y, Float: z)
{
    rent_Vehicle[rentid][E_RENT_VEHICLE_CREATED] = 1;
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_X] = x;
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_Y] = y;
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_Z] = z;

    new String: str_fmt_label = String: str_format(
        "Rent - "GRAY"%d\n"ORANGE"Iznajmite vozilo komandom "LIGHTGRAY"%crent",
        rentid, CUSTOM_COMMAND_PREFIX
    );

    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_LABEL] = CreateFormattedDynLabel(str_fmt_label, X11_ORANGE, x, y, z, 20.00);
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP] = CreateDynamicPickup(19198, 1, x, y, z);
    rent_Vehicle[rentid][E_RENT_VEHICLE_MAPICON] = CreateDynamicMapIcon(x, y, z, 55, 1);

    return 1;
}

stock Rent_Delete(const playerid, const rentid)
{
    new String: str_query_delete = String: str_format(
        "DELETE FROM rent WHERE rent_id = '%d'", rentid
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_delete);

    SendServerMsgF(playerid, "Obrisali ste rent ID: %d.", rentid);

    rent_Vehicle[rentid][E_RENT_VEHICLE_CREATED] = 0;
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_X] =
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_Y] =
    rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_Z] = 0.0;

    DestroyDynamic3DTextLabel(rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP_LABEL]);
    DestroyDynamicPickup(rent_Vehicle[rentid][E_RENT_VEHICLE_PICKUP]);
    DestroyDynamicMapIcon(rent_Vehicle[rentid][E_RENT_VEHICLE_MAPICON]);

    return 1;
}

stock Rent_Player(const playerid, const vehicleid, const time)
{
    if (!time && Rent_GetPlayerTime(playerid))
    {
        SendServerMsg(playerid, "Isteklo Vam je vreme rentanog vozila.");
        DestroyVehicle(rent_VehicleID[playerid]);
        DestroyDynamic3DTextLabel(rent_VehicleLabel[playerid]);

        Rent_SetPlayerTime(playerid, 0);
        return 1;
    }

    if (Char_GetMoney(playerid) < (time * RENT_PRICE_PER_MINUTE))
        return SendErrorMsgF(playerid, "Potrebno vam je $%d.", (time * RENT_PRICE_PER_MINUTE));

    Char_TakeMoney(playerid, (time * RENT_PRICE_PER_MINUTE));
    SendServerMsgF(playerid, "Rentali ste vozilo za $%d.", (time * RENT_PRICE_PER_MINUTE));

    static
        Float: x, Float: y, Float: z,
        fmt_label[16 + MAX_PLAYER_NAME];

    format(fmt_label, sizeof(fmt_label), "Rent - %s", ReturnPlayerName(playerid));
    GetPlayerPos(playerid, x, y, z);

    Rent_SetPlayerTime(playerid, (time * 60) * 1000);
    rent_VehicleID[playerid] = CreateVehicle(vehicleid, x, y, z, 0.0, random(128), random(128), 0);
    rent_VehicleLabel[playerid] = CreateDynamic3DTextLabel(fmt_label, X11_WHITE, x, y, z, 15.0, .attachedvehicle = rent_VehicleID[playerid]);
    PutPlayerInVehicle(playerid, rent_VehicleID[playerid], 0);

    /*rent_Timer[playerid] = */
    DEFER__ Rent_Expired(playerid);

    return 1;
}

stock Rent_GetNextID()
{
    for (new i = 0; i < MAX_RENTS; ++i)
		if (!rent_Vehicle[i][E_RENT_VEHICLE_CREATED])
            return i;

	return MAX_RENTS;
}

stock Rent_GetNearest(const playerid)
{
    for (new i = 0; i < MAX_RENTS; ++i)
        if (IsPlayerInRangeOfPoint(playerid, 2.0, rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_X], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Y], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Z]))
            return i;

	return -1;
}

stock Rent_SetPlayerTime(const playerid, const time) return rent_Time[playerid] = time;
stock Rent_GetPlayerTime(const playerid) return rent_Time[playerid];