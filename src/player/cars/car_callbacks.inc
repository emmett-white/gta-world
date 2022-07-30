#if defined _INC_car_callbacks_inc
    #endinput
#endif
#define _INC_car_callbacks_inc

// Callbacks
forward Car_Load();
public Car_Load()
{
    if (!cache_num_rows())
        return 1;
    
    static rows;
    cache_get_row_count(rows);

    for (new i = 0; i < rows; ++i)
    {
        cache_get_value_name_int(i, "car_id", car_Info[i][E_CAR_UNIQUE_ID]);
        cache_get_value_name_int(i, "car_model", car_Info[i][E_CAR_MODEL_ID]);
        cache_get_value_name(i, "car_owner", car_Info[i][E_CAR_OWNER]);
        cache_get_value_name_float(i, "car_x", car_Info[i][E_CAR_POS_X]);
        cache_get_value_name_float(i, "car_y", car_Info[i][E_CAR_POS_Y]);
        cache_get_value_name_float(i, "car_z", car_Info[i][E_CAR_POS_Z]);
        cache_get_value_name_float(i, "car_a", car_Info[i][E_CAR_POS_A]);
        cache_get_value_name_int(i, "car_colour1", car_Info[i][E_CAR_COLOUR][0]);
        cache_get_value_name_int(i, "car_colour2", car_Info[i][E_CAR_COLOUR][1]);
        cache_get_value_name_int(i, "car_windows", car_Info[i][E_CAR_WINDOWS]);
        cache_get_value_name_int(i, "car_locked", car_Info[i][E_CAR_LOCKED]);
        
        new locked_status[4], String: str_fmt_label;
        if (car_Info[i][E_CAR_LOCKED])
            locked_status = "Da";
        else
            locked_status = "Ne";

        str_fmt_label = String: str_format(
            "Vlasnik vozila: "WHITE"%s\n"YELLOW"Tip: "WHITE"%s\n"YELLOW"Zakljucano: "WHITE"%s",
            car_Info[i][E_CAR_OWNER], Vehicle_GetType(car_Info[i][E_CAR_MODEL_ID]), locked_status
        );

        car_Model[i] = CreateVehicle(
            car_Info[i][E_CAR_MODEL_ID],
            car_Info[i][E_CAR_POS_X],
            car_Info[i][E_CAR_POS_Y],
            car_Info[i][E_CAR_POS_Z],
            car_Info[i][E_CAR_POS_A],
            car_Info[i][E_CAR_COLOUR][0],
            car_Info[i][E_CAR_COLOUR][1], 0
        );
        car_Label[i] = CreateFormattedDynLabel(
            str_fmt_label, X11_YELLOW,
            car_Info[i][E_CAR_POS_X],
            car_Info[i][E_CAR_POS_Y],
            car_Info[i][E_CAR_POS_Z], 30.0,
            .attachedvehicle = car_Model[i]
        );

        car_Info[i][E_CAR_CREATED] = 1;
    }

    return 1;
}
