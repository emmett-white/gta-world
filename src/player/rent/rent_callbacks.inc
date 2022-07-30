#if defined _INC_rent_callbacks_inc
    #endinput
#endif
#define _INC_rent_callbacks_inc

// Callbacks
forward Rent_Load();
public Rent_Load()
{
    if (!cache_num_rows())
        return 0;

    static rows;
    cache_get_row_count(rows);

    for (new i = 0; i < rows; ++i)
    {
        cache_get_value_name_int(i, "rent_id", rent_Vehicle[i][E_RENT_VEHICLE_UNIQUE_ID]);
        cache_get_value_name_float(i, "rent_x", rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_X]);
        cache_get_value_name_float(i, "rent_y", rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Y]);
        cache_get_value_name_float(i, "rent_z", rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Z]);

        new String: str_fmt_label = String: str_format(
            "Rent - "GRAY"%d\n"ORANGE"Iznajmite vozilo komandom "LIGHTGRAY"%crent",
            i, CUSTOM_COMMAND_PREFIX
        );

        rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_LABEL] = CreateFormattedDynLabel(str_fmt_label, X11_ORANGE, rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_X], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Y], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Z], 20.00);
        rent_Vehicle[i][E_RENT_VEHICLE_CREATED] = 1;
        rent_Vehicle[i][E_RENT_VEHICLE_PICKUP] = CreateDynamicPickup(19198, 1, rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_X], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Y], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Z]);
        rent_Vehicle[i][E_RENT_VEHICLE_MAPICON] = CreateDynamicMapIcon(rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_X], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Y], rent_Vehicle[i][E_RENT_VEHICLE_PICKUP_Z], 55, 1);
    }

    return 1;
}