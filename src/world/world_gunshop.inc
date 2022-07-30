#if defined _INC_world_gunshop
    #endinput
#endif
#define _INC_world_gunshop

#include <YSI_Coding\y_hooks>

// Hooks
hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1297, 1362.800, -1254.699, 15.929, 0.250);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnScriptInit()
{
    new gs_ext;
    gs_ext = CreateDynamicObject(970, 1365.585815, -1250.882202, 13.082820, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1253.012817, 13.082820, 360.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1257.253295, 13.082820, 360.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1261.483642, 13.082820, -0.000000, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1265.724121, 13.082820, -0.000000, 0.000000, 89.999977, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1269.953735, 13.082820, 0.000007, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1274.194213, 13.082820, 0.000007, 0.000000, 89.999954, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1289.237670, 13.082820, 0.000015, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1293.478149, 13.082820, 0.000015, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1297.707763, 13.082820, 0.000022, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1301.948242, 13.082820, 0.000022, 0.000000, 89.999908, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1365.587646, -1304.099121, 13.082820, 0.000015, 0.000000, 179.999938, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    gs_ext = CreateDynamicObject(970, 1363.525756, -1285.007690, 13.082820, 0.000015, 0.000000, 89.999931, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gs_ext, 0, 19535, "matroadinters1", "roadinters1", 0x00000000);
    SetDynamicObjectMaterial(gs_ext, 1, 18996, "mattextures", "sampblack", 0x00000000);
    
    gs_ext = CreateDynamicObject(19121, 1363.513183, -1276.559082, 13.082811, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(19121, 1363.513183, -1282.639770, 13.082811, 0.000000, 0.000000, 0.000000, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(2321, 1367.622924, -1284.715942, 14.332811, 90.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(356, 1367.584350, -1283.595947, 14.556877, 0.000000, 0.000000, 90.000000, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(355, 1367.659301, -1284.704589, 14.546877, 0.000000, 0.000000, 95.699981, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(353, 1367.653564, -1283.682128, 14.016874, 0.000000, 0.000000, 97.299957, -1, -1, -1, 300.00, 300.00);
    gs_ext = CreateDynamicObject(353, 1367.657592, -1284.346679, 14.016874, 0.000000, 0.000000, 97.299957, -1, -1, -1, 300.00, 300.00);

    CreateDynamicPickup(19135, 1, 1367.8107, -1279.7494, 13.5469, .streamdistance = 15.0);
    CreateDynamicPickup(19135, 1, 285.7442, -40.4782, 1001.5156, .streamdistance = 15.0);
    CreateDynamicPickup(2061, 1, 296.1837, -37.9673, 1001.5156, .streamdistance = 15.0);
    
    new String: str_fmt_label = String: str_format(
        ""RED"[GUN SHOP]\n"WHITE"Da kupite oruzje kucajte \""RED"%cweapon"WHITE"\"", CUSTOM_COMMAND_PREFIX
    );

    CreateDynamic3DTextLabel(""RED"[GUN SHOP]\n"WHITE"Za ulaz pritisnite \""RED"F/ENTER"WHITE"\"", -1, 1367.8107, -1279.7494, 13.5469, .drawdistance = 15.0, .streamdistance = 15.0);
    CreateDynamic3DTextLabel(""RED"[GUN SHOP]\n"WHITE"Za izlaz pritisnite \""RED"F/ENTER"WHITE"\"", -1, 285.7442, -40.4782, 1001.5156, .drawdistance = 15.0, .streamdistance = 15.0);
    CreateFormattedDynLabel(str_fmt_label, -1, 296.1837, -37.9673, 1001.5156, .drawdistance = 8.0, .streamdistance = 8.0);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys)
{
    if (PRESSED(KEY_SECONDARY_ATTACK))
    {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, 1367.8107, -1279.7494, 13.5469))
        {
            Streamer_UpdateEx(playerid, 285.7442, -40.4782, 1001.5156, .compensatedtime = 2000);
            SetPlayerInterior(playerid, 1);
        }

        else if (IsPlayerInRangeOfPoint(playerid, 2.0, 285.7442, -40.4782, 1001.5156))
        {
            Streamer_UpdateEx(playerid, 1367.8107, -1279.7494, 13.5469, .compensatedtime = 2000);
            SetPlayerInterior(playerid, 0);
        }
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}