#if defined _INC_car_functions_inc
    #endinput
#endif
#define _INC_car_functions_inc

// Variables
#if defined MAX_CARS
    #undef MAX_CARS
#endif

const MAX_CARS =            400;

enum E_CAR_DATA
{
    E_CAR_UNIQUE_ID,
    E_CAR_CREATED,
    E_CAR_MODEL_ID,
    E_CAR_LOCKED,
    E_CAR_PARKED,
    E_CAR_WINDOWS,
    E_CAR_COLOUR[2],
    
    Float: E_CAR_POS_X,
    Float: E_CAR_POS_Y,
    Float: E_CAR_POS_Z,
    Float: E_CAR_POS_A,

    string: E_CAR_OWNER[MAX_PLAYER_NAME]
};

new
    car_Info[MAX_CARS][E_CAR_DATA],
    car_Model[MAX_CARS],
    car_PlayerModel[MAX_PLAYERS],
    car_PlayerLockStatus[MAX_PLAYERS],

    bool:car_PlayerDoors[MAX_PLAYERS],
    Text3D: car_Label[MAX_CARS];

// Vehicle names and IDs
new const car_Names[][] =
{
	"Landstalker", "Bravura", "Buffalo", "Perenniel",
	"Sentinel", "Manana", "Infernus", "Voodoo",
	"Cheetah", "Esperanto", "Washington", "Bobcat",
	"Premier", "Banshee", "Previon", "Stallion",
	"Romero", "Admiral", "Turismo", "Solair",
	"Glendale", "Oceanic", "Hermes", "Sabre", "ZR-350", "Walton",
	"Regina", "Comet", "Virgo", "Greenwood",
	"Blista Compact", "Mesa", "Bloodring Banger", "Rancher",
	"Super GT", "Elegant", "Nebula", "Majestic", "Buccaneer", "Fortune",
	"Cadrona", "Willard", "Feltzer", "Remington",
	"Slamvan", "Blade", "Vincent", "Bullet",
	"Clover", "Sadler", "Hustler", "Intruder",
	"Primo", "Tampa", "Sunrise", "Merit",
	"Yosemite", "Windsor", "Uranus", "Jester",
	"Sultan", "Stratum", "Elegy", "Flash", "Tahoma", "Savanna",
	"Broadway", "Tornado", "Huntley", "Stafford",
	"Emperor", "Euros", "Club", "Picador",
	"Alpha", "Phoenix"
};

new const car_IDS[] = {
    400, 401, 402, 404,
    405, 410, 411, 412,
    415, 419, 421, 422,
    426, 429, 436, 439,
    442, 445, 451, 458,
    466, 467, 474, 475,
    477, 478, 479, 480,
    491, 492, 496, 500,
    504, 505, 506, 507,
    516, 517, 518, 526,
    527, 529, 533, 534,
    535, 536, 540, 541,
    542, 543, 545, 546,
    547, 549, 550, 551,
    554, 555, 558, 559,
    560, 561, 562, 565,
    566, 567, 575, 576,
    579, 580, 585, 587,
    589, 600, 602, 603
};

new const vehicle_MotorcycleNames[][] = {
    "NRG-500", "Sanchez",
    "BF-400", "PCJ-600",
    "Quad", "FCR-900",
    "Faggio", "Wayfarer",
    "Freeway"
};

new const vehicle_BikeNames[][] = {
    "Mountain Bike", "BMX",
    "Bike"
};

new const vehicle_HelicopterNames[][] = {
    "Seasparrow", "Sparrow",
    "Maverick"
};

new const vehicle_PlaneNames[][] = {
    "Skimmer", "Rustler",
    "Beagle", "Cropduster",
    "Stuntplane", "Dodo"
};

// Functions
stock Car_GetMaxVehicles() return MAX_CARS;
stock Car_ModelSelected(const playerid, const modelid) return car_PlayerModel[playerid] = modelid;
stock Car_GetModelSelected(const playerid) return car_PlayerModel[playerid];
stock Car_GetID(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    static tmp_int;
    if (cache_num_rows())
        cache_get_value_name_int(0, "car_id", tmp_int);

    return tmp_int;
}
// stock Car_SetID(const playerid, const vehicleid) return car_PlayerID[playerid] = vehicleid;

stock Car_Create(const playerid, const vehicleid, const modelid, const string: owner[], Float: x, Float: y, Float: z, Float: angle, const colour1, const colour2, const locked = 0)
{
    // Car_SetID(playerid, (vehicleid + 1));
    strcopy(car_Info[vehicleid][E_CAR_OWNER], owner);

    car_Info[vehicleid][E_CAR_MODEL_ID] = modelid,
    car_Info[vehicleid][E_CAR_CREATED] = 1,
    car_Info[vehicleid][E_CAR_POS_X] = x,
    car_Info[vehicleid][E_CAR_POS_Y] = y,
    car_Info[vehicleid][E_CAR_POS_Z] = z,
    car_Info[vehicleid][E_CAR_POS_A] = angle,
    car_Info[vehicleid][E_CAR_COLOUR][0] = colour1,
    car_Info[vehicleid][E_CAR_COLOUR][1] = colour2,
    car_Info[vehicleid][E_CAR_LOCKED] = locked;

    new String: str_query_insert = String: str_format(
        "INSERT INTO cars (car_id, car_model, car_name, car_owner, car_x, car_y, car_z, car_a,\
        car_colour1, car_colour2, car_windows, car_locked) \
        VALUES ('%d', '%d', '%e', '%e', '%f', '%f', '%f', '%f', '%d', '%d', '%d', '%d')",
        (vehicleid + 1),
        car_Info[vehicleid][E_CAR_MODEL_ID],
        Car_GetModelName(car_Info[vehicleid][E_CAR_MODEL_ID]),
        car_Info[vehicleid][E_CAR_OWNER],
        car_Info[vehicleid][E_CAR_POS_X],
        car_Info[vehicleid][E_CAR_POS_Y],
        car_Info[vehicleid][E_CAR_POS_Z],
        car_Info[vehicleid][E_CAR_POS_A],
        car_Info[vehicleid][E_CAR_COLOUR][0],
        car_Info[vehicleid][E_CAR_COLOUR][1],
        car_Info[vehicleid][E_CAR_WINDOWS],
        car_Info[vehicleid][E_CAR_LOCKED]
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_insert);

    new locked_status[4], String: str_fmt_label;
    if (car_Info[vehicleid][E_CAR_LOCKED])
        locked_status = "Da";
    else
        locked_status = "Ne";

    str_fmt_label = String: str_format(
        "Vlasnik vozila: "WHITE"%s\n"YELLOW"Tip: "WHITE"%s\n"YELLOW"Zakljucano: "WHITE"%s",
        ReturnPlayerName(playerid), Vehicle_GetType(modelid), locked_status
    );
    car_Model[vehicleid] = CreateVehicle(modelid, x, y, z, angle, colour1, colour2, 0);
    car_Label[vehicleid] = CreateFormattedDynLabel(str_fmt_label, X11_YELLOW, x, y, z, 30.0, .attachedvehicle = car_Model[vehicleid]);

    if (car_Info[vehicleid][E_CAR_LOCKED])
    {
        static engine, lights, alarm, doors, bonnet, boot, objective;
        GetVehicleParamsEx(car_Model[vehicleid], engine, lights, alarm, doors, bonnet, boot, objective);
        SetVehicleParamsEx(car_Model[vehicleid], engine, lights, alarm, 1, bonnet, boot, objective);
    }

    return 1;
}

stock Car_GetOwner(const vehicleid)
{
    static tmp_str[MAX_PLAYER_NAME];
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_id = '%d'", vehicleid
            )
        )
    );

    if (cache_num_rows())
        cache_get_value_name(0, "car_owner", tmp_str);

    return tmp_str;
}

stock Car_SetOwner(const vehicleid, const string: name[])
{
    strcopy(car_Info[vehicleid][E_CAR_OWNER], name);

    new String: str_query_update = String: str_format(
        "UPDATE cars SET car_owner = '%e' WHERE car_id = '%d'",
        Car_GetOwner(vehicleid), vehicleid
    );
    return mysql_tquery_s(MySQL_GetHandle(), str_query_update);
}

stock Car_GetColour(const vehicleid)
{
    static
        tmp_col_1,
        tmp_col_2,
        tmp_str[4];

    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_id = '%d'", vehicleid
            )
        )
    );

    if (cache_num_rows())
    {
        cache_get_value_name_int(0, "car_colour1", tmp_col_1);
        cache_get_value_name_int(0, "car_colour2", tmp_col_2);
    }

    format(tmp_str, sizeof(tmp_str), "%d %d", tmp_col_1, tmp_col_2);
    return tmp_str;
}

stock Car_GetNextID()
{
    for (new i = 0; i < MAX_CARS; ++i)
		if (!car_Info[i][E_CAR_CREATED])
            return i;

	return MAX_CARS;
}

stock Car_GetModelName(const modelid)
{
    new tmp_str[64];
    switch (modelid)
    {
        case 400: { tmp_str = "Landstalker"; } case 603: { tmp_str = "Phoenix"; }
        case 401: { tmp_str = "Bravura"; } case 402: { tmp_str = "Buffalo"; }
        case 404: { tmp_str = "Perennial"; } case 405: { tmp_str = "Sentinel"; }
        case 410: { tmp_str = "Manana"; } case 411: { tmp_str = "Infernus"; }
        case 412: { tmp_str = "Voodoo"; } case 415: { tmp_str = "Cheetah"; }
        case 419: { tmp_str = "Esperanto"; } case 421: { tmp_str = "Washington"; }
        case 422: { tmp_str = "Bobcat"; } case 426: { tmp_str = "Premier"; }
        case 429: { tmp_str = "Banshee"; } case 436: { tmp_str = "Previon"; }
        case 439: { tmp_str = "Stallion"; } case 442: { tmp_str = "Romero"; }
        case 445: { tmp_str = "Admiral"; } case 451: { tmp_str = "Turismo"; }
        case 458: { tmp_str = "Solair"; } case 466: { tmp_str = "Glendale"; }
        case 474: { tmp_str = "Hermes"; } case 475: { tmp_str = "Sabre"; }
        case 477: { tmp_str = "ZR-350"; } case 478: { tmp_str = "Walton"; }
        case 479: { tmp_str = "Regina"; } case 480: { tmp_str = "Comet"; }
        case 491: { tmp_str = "Virgo"; } case 492: { tmp_str = "Greenwood"; }
        case 496: { tmp_str = "Blista Compact"; } case 500: { tmp_str = "Mesa"; }
        case 504: { tmp_str = "Bloodring Banger"; } case 505: { tmp_str = "Rancher Lure"; }
        case 506: { tmp_str = "Super GT"; } case 507: { tmp_str = "Elegant"; }
        case 516: { tmp_str = "Nebula"; } case 517: { tmp_str = "Majestic"; }
        case 518: { tmp_str = "Buccaneer"; } case 526: { tmp_str = "Fortune"; }
        case 527: { tmp_str = "Cadrona"; } case 529: { tmp_str = "Willard"; }
        case 533: { tmp_str = "Feltzer"; } case 534: { tmp_str = "Remington"; }
        case 535: { tmp_str = "Slamvan"; } case 536: { tmp_str = "Blade"; }
        case 540: { tmp_str = "Vincent"; } case 541: { tmp_str = "Bullet"; }
        case 542: { tmp_str = "Clover"; } case 543: { tmp_str = "Sadler"; }
        case 545: { tmp_str = "Hustler"; } case 546: { tmp_str = "Intruder"; }
        case 467: { tmp_str = "Oceanic"; } case 547: { tmp_str = "Primo"; }
        case 549: { tmp_str = "Tampa"; } case 550: { tmp_str = "Sunrise"; }
        case 551: { tmp_str = "Merit"; } case 554: { tmp_str = "Yosemite"; }
        case 555: { tmp_str = "Windsor"; } case 558: { tmp_str = "Uranus"; }
        case 559: { tmp_str = "Jester"; } case 560: { tmp_str = "Sultan"; }
        case 561: { tmp_str = "Stratum"; } case 562: { tmp_str = "Elegy"; }
        case 565: { tmp_str = "Flash"; } case 566: { tmp_str = "Tahoma"; }
        case 567: { tmp_str = "Savanna"; } case 575: { tmp_str = "Broadway"; }
        case 576: { tmp_str = "Tornado"; } case 579: { tmp_str = "Huntley"; }
        case 580: { tmp_str = "Stafford"; } case 585: { tmp_str = "Emperor"; }
        case 587: { tmp_str = "Euros"; } case 589: { tmp_str = "Club"; }
        case 600: { tmp_str = "Picador"; } case 602: { tmp_str = "Alpha"; }
        default: { tmp_str = "N/A"; }
    }

	return tmp_str;
}

stock Car_GetModelPrice(const modelid)
{
    static tmp_int;
    switch (modelid)
    {
        case 400: tmp_int = 70000; case 603: tmp_int = 920000;
        case 401: tmp_int = 45000; case 402: tmp_int = 170000;
        case 404: tmp_int = 60000; case 405: tmp_int = 55000;
        case 410: tmp_int = 30000; case 411: tmp_int = 3200000;
        case 412: tmp_int = 100000; case 415: tmp_int = 1200000;
        case 419: tmp_int = 130000; case 421: tmp_int = 70000;
        case 422: tmp_int = 110000; case 426: tmp_int = 80000;
        case 429: tmp_int = 1600000; case 436: tmp_int = 50000;
        case 439: tmp_int = 90000; case 442: tmp_int = 110000;
        case 445: tmp_int = 75000; case 451: tmp_int = 2800000;
        case 458: tmp_int = 250000; case 466: tmp_int = 120000;
        case 474: tmp_int = 115000; case 475: tmp_int = 105000;
        case 477: tmp_int = 1700000; case 478: tmp_int = 100000;
        case 479: tmp_int = 95000; case 480: tmp_int = 750000;
        case 491: tmp_int = 320000; case 492: tmp_int = 260000;
        case 496: tmp_int = 130000; case 500: tmp_int = 105000;
        case 504: tmp_int = 210000; case 505: tmp_int = 950000;
        case 506: tmp_int = 2200000; case 507: tmp_int = 205000;
        case 516: tmp_int = 80000; case 517: tmp_int = 110000;
        case 518: tmp_int = 235000; case 526: tmp_int = 100000;
        case 527: tmp_int = 125000; case 529: tmp_int = 120000;
        case 533: tmp_int = 260000; case 534: tmp_int = 1650000;
        case 535: tmp_int = 450000; case 536: tmp_int = 350000;
        case 540: tmp_int = 140000; case 541: tmp_int = 2850000;
        case 542: tmp_int = 125000; case 543: tmp_int = 430000;
        case 545: tmp_int = 750000; case 546: tmp_int = 245000;
        case 467: tmp_int = 120000; case 547: tmp_int = 230000;
        case 549: tmp_int = 315000; case 550: tmp_int = 270000;
        case 551: tmp_int = 255000; case 554: tmp_int = 620000;
        case 555: tmp_int = 520000; case 558: tmp_int = 630000;
        case 559: tmp_int = 1105000; case 560: tmp_int = 2750000;
        case 561: tmp_int = 635000; case 562: tmp_int = 990000;
        case 565: tmp_int = 810000; case 566: tmp_int = 430000;
        case 567: tmp_int = 870000; case 575: tmp_int = 210000;
        case 576: tmp_int = 315000; case 579: tmp_int = 2350000;
        case 580: tmp_int = 830000; case 585: tmp_int = 170000;
        case 587: tmp_int = 845000; case 589: tmp_int = 420000;
        case 600: tmp_int = 175000; case 602: tmp_int = 620000;
    }

    return tmp_int;
}

stock Car_GetNearest(const playerid)
{
    for (new i = 0; i < MAX_CARS; ++i)
        if (IsPlayerInRangeOfPoint(
            playerid, 5.0,
            car_Info[i][E_CAR_POS_X], car_Info[i][E_CAR_POS_Y], car_Info[i][E_CAR_POS_Z]
        )) return i;

	return -1;
}

stock Car_PlayerExists(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );
    
    return (!cache_num_rows() ? (0) : (1));
}

stock Car_GetLockStatus(const vehicleid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_id = '%d'", vehicleid
            )
        )
    );

    static tmp_int;
    if (cache_num_rows())
        cache_get_value_name_int(0, "car_locked", tmp_int);
    
    return tmp_int;
}

stock Car_GetPlayerLockStatus(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    if (cache_num_rows())
        cache_get_value_name_int(0, "car_locked", car_PlayerLockStatus[playerid]);

    return car_PlayerLockStatus[playerid];
}

stock Car_SetPlayerLockStatus(const playerid)
{
    if (!IsPlayerInVehicle(playerid, car_Model[(Car_GetID(playerid) - 1)]))
        return SendErrorMsg(playerid, "Morate biti u Vasem vozilu!");

    new const status = !Car_GetPlayerLockStatus(playerid);
    new
        String: str_query_update,
        fmt_str_label[128],

        engine, lights, alarm, doors, bonnet, boot, objective;

    GetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, doors, bonnet, boot, objective);
    SetVehicleParamsEx(GetPlayerVehicleID(playerid), engine, lights, alarm, 0, bonnet, boot, objective);

    if (!status)
    {
        format(fmt_str_label, sizeof(fmt_str_label),
            "Vlasnik vozila: "WHITE"%s\n"YELLOW"Tip: "WHITE"%s\n"YELLOW"Zakljucano: "WHITE"Ne",
            Car_GetOwner(Car_GetID(playerid)), Vehicle_GetType(GetVehicleModel(GetPlayerVehicleID(playerid)))
        );
        UpdateDynamic3DTextLabelText(car_Label[(Car_GetID(playerid) - 1)], X11_YELLOW, fmt_str_label);

        str_query_update = String: str_format(
            "UPDATE cars SET car_locked = '0' WHERE car_owner = '%e'", ReturnPlayerName(playerid)
        );
        mysql_tquery_s(MySQL_GetHandle(), str_query_update);

        car_PlayerLockStatus[playerid] = 0;
        return 1;
    }

    format(fmt_str_label, sizeof(fmt_str_label),
        "Vlasnik vozila: "WHITE"%s\n"YELLOW"Tip: "WHITE"%s\n"YELLOW"Zakljucano: "WHITE"Da",
        Car_GetOwner(Car_GetID(playerid)), Vehicle_GetType(GetVehicleModel(GetPlayerVehicleID(playerid)))
    );
    UpdateDynamic3DTextLabelText(car_Label[(Car_GetID(playerid) - 1)], X11_YELLOW, fmt_str_label);

    str_query_update = String: str_format(
        "UPDATE cars SET car_locked = '1' WHERE car_owner = '%e'", ReturnPlayerName(playerid)
    );
    mysql_tquery_s(MySQL_GetHandle(), str_query_update);

    car_PlayerLockStatus[playerid] = 1;

    return 1;
}

stock Car_GetPlayerModel(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    static tmp_int;
    if (cache_num_rows())
        cache_get_value_name_int(0, "car_model", tmp_int);

    return tmp_int;
}

stock Car_GetPlayerWinStatus(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM cars WHERE car_owner = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    static tmp_int;
    if (cache_num_rows())
        cache_get_value_name_int(0, "car_windows", tmp_int);

    return tmp_int;
}

stock Car_SetPlayerWinStatus(const playerid)
{
    new
        const status = !Car_GetPlayerWinStatus(playerid),
        String: str_query_update = String: str_format(
            "UPDATE cars SET car_windows = '%d' WHERE car_id = '%d'",
            status, Car_GetID(Car_GetNearest(playerid))
        );

    return mysql_tquery_s(MySQL_GetHandle(), str_query_update);
}

stock Car_GetPlayerDoorsStatus(const playerid) return car_PlayerDoors[playerid];
stock Car_SetPlayerDoorsStatus(const playerid)
{
    new const bool: status = !Car_GetPlayerDoorsStatus(playerid);
    new driver, passenger, backleft, backright;
    
    if (!status)
    {
        car_PlayerDoors[playerid] = false;

        GetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, passenger, backleft, backright);
        SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), 0, 0, 0, 0);
        return 1;
    }

    car_PlayerDoors[playerid] = true;

    GetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), driver, passenger, backleft, backright);
    SetVehicleParamsCarDoors(GetPlayerVehicleID(playerid), 1, 1, 1, 1);

    return 1;
}