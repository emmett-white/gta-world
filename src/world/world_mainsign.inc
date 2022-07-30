#if defined _INC_world_mainsign_inc
    #endinput
#endif
#define _INC_world_mainsign_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1283, 1352.9375, -942.9688, 36.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1378.3594, -956.8516, 36.3672, 0.25);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnScriptInit()
{
    new gtaw_mainsign;
    gtaw_mainsign = CreateDynamicObject(18980, 1385.748535, -953.923339, 33.755142, 0.000000, 0.000000, -7.499998, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    gtaw_mainsign = CreateDynamicObject(18980, 1355.539672, -949.563476, 33.755142, 0.000000, 0.000000, -7.499998, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    gtaw_mainsign = CreateDynamicObject(18766, 1380.349121, -953.143432, 43.746234, 0.000000, 0.000000, -8.199996, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    gtaw_mainsign = CreateDynamicObject(18766, 1360.941772, -950.347106, 43.746234, 0.000000, 0.000000, -8.199996, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    gtaw_mainsign = CreateDynamicObject(18766, 1370.600097, -951.738830, 43.746234, 0.000000, 0.000000, -8.199996, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    gtaw_mainsign = CreateDynamicObject(7914, 1377.792724, -952.653869, 43.731849, -0.000000, -0.000007, 171.799972, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 18996, "mattextures", "sampblack", 0x00000000);
    SetDynamicObjectMaterialText(gtaw_mainsign, 0, "{205aab}gta {FFFFFF}world: DOBRODOSLI!", 80, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
    gtaw_mainsign = CreateDynamicObject(7914, 1377.762817, -952.861572, 43.731849, -0.000000, 0.000007, -8.199979, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterialText(gtaw_mainsign, 0, "{205aab}gta {FFFFFF}world: DOBRODOSLI!", 80, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
    gtaw_mainsign = CreateDynamicObject(7914, 1363.258422, -950.604431, 43.781845, 720.000000, 0.000000, 531.800048, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterialText(gtaw_mainsign, 0, "{205aab}SA VAMA OD\n{FFFFFF}2022. godine", 80, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);
    gtaw_mainsign = CreateDynamicObject(7914, 1363.235717, -950.763122, 43.781845, 720.000000, 0.000000, 711.800048, -1, -1, -1, 300.00, 300.00);
    SetDynamicObjectMaterial(gtaw_mainsign, 0, 19611, "microphone1", "microphone1", 0x00000000);
    SetDynamicObjectMaterialText(gtaw_mainsign, 0, "{205aab}SA VAMA OD\n{FFFFFF}2022. godine", 80, "Ariel", 20, 1, 0x00000000, 0x00000000, 1);

    gtaw_mainsign = CreateDynamicObject(1215, 1385.736206, -953.476928, 45.583881, -35.199996, 2.099998, -0.099999, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1215, 1385.716674, -954.343627, 45.632892, 324.799987, 2.099998, 179.899993, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1215, 1355.705810, -949.116577, 45.583881, -35.199996, 2.100008, -0.099994, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1215, 1355.686279, -949.983276, 45.632892, -35.200008, 2.099989, 179.899948, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1383.562988, -953.698486, 41.820823, -0.000001, 0.000007, -9.699994, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1380.586425, -953.189575, 41.820823, -0.000001, 0.000007, -9.699994, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1378.161499, -952.847900, 41.820823, -0.000001, 0.000007, -9.699994, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1375.184936, -952.338989, 41.820823, -0.000001, 0.000007, -9.699994, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1372.327880, -951.925659, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1369.339721, -951.489624, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1366.590698, -951.161010, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1363.919067, -950.771240, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1360.802856, -950.316467, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);
    gtaw_mainsign = CreateDynamicObject(1893, 1357.725341, -949.867431, 41.820823, -0.000003, 0.000022, -8.299992, -1, -1, -1, 300.00, 300.00);

    return Y_HOOKS_CONTINUE_RETURN_1;
}