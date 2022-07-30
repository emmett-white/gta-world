#if defined _INC_accounts_functions_inc
    #endinput
#endif
#define _INC_accounts_functions_inc

// Variables
enum
{
    SPAWN_ACCOUNT_NONE = 1,
    SPAWN_ACCOUNT_CREATED
};

new
    account_ID[MAX_PLAYERS],
    char_UniqueID[MAX_PLAYERS],
    account_Password[MAX_PLAYERS][64];

#define Account_GetUniqueID(%0) account_ID[%0]
#define Account_GetPassword(%0) account_Password[%0]
#define Char_GetUniqueID(%0) char_UniqueID[%0]

// Random spawn coordinates
static const Float: account_RandomSpawnPos[][] =
{
    {810.63520, -1340.0682, 13.5386, 37.33070},
    {1124.6071, -1427.5155, 15.7969, 350.9336},
    {585.81520, -1247.9160, 17.9521, 335.6035},
    {2025.2626, -1423.2682, 16.9922, 135.4516},
    {2509.2468, -1679.2029, 13.5469, 50.24740},
    {1457.1467, -1011.7307, 26.8438, 51.79910},
    {2017.8206, -1279.4851, 23.9820, 47.38920},
    {1935.7644, -1794.6068, 13.5469, 295.5515},
    {1371.4569, -1090.6387, 24.5459, 92.84640},
    {2298.4055, -1500.3264, 25.3047, 199.6940},
    {1178.0417, -1323.6000, 14.1005, 285.5701},
    {1757.44350, -1456.7, 13.5469, 282.4133}
};

// Functions
stock Account_Exists(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    return (!cache_num_rows() ? (0) : (1));
}

stock Account_SetUniqueID(const playerid, const id) return account_ID[playerid] = id;
stock Account_SetPassword(const playerid, const string: password[], bool: update = false)
{
    strcopy(account_Password[playerid], password);
    if (update)
    {
        new String: str_query_update = String: str_format(
            "UPDATE accounts SET account_password = '%e' WHERE account_id = '%d'",
            password, Account_GetUniqueID(playerid)
        );
        mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);
    }

    return 1;
}

stock Account_SetSpawn(const playerid, const status)
{
    new name[MAX_PLAYER_NAME];
    GetPlayerName(playerid, name);
    strreplace(name, "_", " ");

    if (status == SPAWN_ACCOUNT_NONE)
    {
        TogglePlayerSpectating(playerid, 0);
        new rand_pos = random(sizeof(account_RandomSpawnPos));
        SetSpawnInfo(playerid, 0, Char_GetSkin(playerid),
            account_RandomSpawnPos[rand_pos][0], account_RandomSpawnPos[rand_pos][1], account_RandomSpawnPos[rand_pos][2],
            account_RandomSpawnPos[rand_pos][3], 0, 0, 0, 0, 0, 0
        );
        SpawnPlayer(playerid);

        SendServerMsgF(playerid, "Dobrodosli %s na server. Vi nemate kreiran nalog.", name);
        SendServerMsg(playerid, "Da napravite nalog kucajte /registracija.");
        Dialog_Show(playerid, "dialog_notify", DIALOG_STYLE_MSGBOX,
            ""MAIN_COLOUR"gta-world: "WHITE"Obavestenje",
            ""MAIN_COLOUR"VAZNO: "WHITE"Nas server koristi drugaciji prefix za komande.\n\
            Dakle necete koristiti na primer /id nego %cid.",
            ""MAIN_COLOUR"Potvrdi", "", CUSTOM_COMMAND_PREFIX
        );

        UI_ShowInGameTextDraws(playerid);
        UI_AccountLoading(playerid);
        CancelSelectTextDraw(playerid);
    }

    else if (status == SPAWN_ACCOUNT_CREATED)
    {
        TogglePlayerSpectating(playerid, 0);
        new rand_pos = random(sizeof(account_RandomSpawnPos));
        SetSpawnInfo(playerid, 0, Char_GetSkin(playerid),
            account_RandomSpawnPos[rand_pos][0], account_RandomSpawnPos[rand_pos][1], account_RandomSpawnPos[rand_pos][2],
            account_RandomSpawnPos[rand_pos][3], 0, 0, 0, 0, 0, 0
        );
        SpawnPlayer(playerid);

        SendServerMsgF(playerid, "Dobrodosli %s nazad na server. Vas nalog je uspesno ucitan.", name);
        Dialog_Show(playerid, "dialog_notify", DIALOG_STYLE_MSGBOX,
            ""MAIN_COLOUR"gta-world: "WHITE"Obavestenje",
            ""MAIN_COLOUR"NE ZABORAVI: "WHITE"Nas server koristi drugaciji prefix za komande.\n\
            Dakle necete koristiti na primer /id nego %cid.",
            ""MAIN_COLOUR"Potvrdi", "", CUSTOM_COMMAND_PREFIX
        );

        UI_ShowInGameTextDraws(playerid);
        UI_AccountLoading(playerid);
        CancelSelectTextDraw(playerid);
    }

    return 1;
}

void: Account_PromptName(const playerid) Dialog_Show(playerid, "dialog_username", DIALOG_STYLE_INPUT,
    ""MAIN_COLOUR"gta-world: "WHITE"Korisnicko ime",
    ""MAIN_COLOUR"VAZNO: "WHITE"Unesite Vase tacno ime u prazno polje!",
    ""MAIN_COLOUR"Potvrdi", "Izlaz"
);

void: Account_PromptLogin(const playerid) Dialog_Show(playerid, "dialog_login", DIALOG_STYLE_PASSWORD,
    ""MAIN_COLOUR"gta-world: "WHITE"Prijavljivanje",
    ""MAIN_COLOUR"VAZNO: "WHITE"Imate maksimalno %d pokusaja.",
    ""MAIN_COLOUR"Potvrdi", "Izlaz", MAX_LOGIN_ATTEMPTS
);

stock Account_PromptRegister(const playerid) return Dialog_Show(playerid, "dialog_register", DIALOG_STYLE_PASSWORD,
    ""MAIN_COLOUR"gta-world: "WHITE"Kreiranje naloga",
    ""MAIN_COLOUR"VAZNO: "WHITE"Lozinka ne sme biti kraca od %d i duza od %d karaktera.",
    ""MAIN_COLOUR"Potvrdi", "Izlaz", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH
);

void: Account_IsCreated(const playerid)
{
    task_await(
        Task: MySQL_QueryS(
            String: str_format(
                "SELECT * FROM accounts WHERE account_name = '%e'", ReturnPlayerName(playerid)
            )
        )
    );

    Player_ClearChat(playerid, 60);

    if (!cache_num_rows())
    {
        UI_AccountLoading(playerid);
        task_await(Task: BindToPlayer(task_ms(2500), playerid));
        Account_SetSpawn(playerid, SPAWN_ACCOUNT_NONE);
    }
    
    else
    {
        static tmp_str[64];
        cache_get_value_name_int(0, "account_id", Account_GetUniqueID(playerid));
        cache_get_value_name(0, "account_password", tmp_str);

        new Alloc: alloc_str = malloc(64);
        msets(alloc_str, 0, tmp_str);
        Account_SetPassword(playerid, mget(alloc_str, 0));
        free(alloc_str);

        // Load character
        task_await(
            Task: MySQL_QueryS(
                String: str_format(
                    "SELECT * FROM characters WHERE char_name = '%e'", ReturnPlayerName(playerid)
                )
            )
        );

        if (cache_num_rows())
        {
            static tmp_int;
            cache_get_value_name_int(0, "char_id", Char_GetUniqueID(playerid));

            cache_get_value_name_int(0, "char_skin", tmp_int);
            Char_SetSkin(playerid, tmp_int);
            
            cache_get_value_name_int(0, "char_money", tmp_int);
            Char_GiveMoney(playerid, tmp_int);
            
            cache_get_value_name_int(0, "char_score", tmp_int);
            Char_SetScore(playerid, tmp_int);

            UI_AccountLogin(playerid);
            SelectTextDraw(playerid, MAIN_COLOUR_HEX);
        }
    }
}