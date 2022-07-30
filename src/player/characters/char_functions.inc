#if defined _INC_char_functions_inc
    #endinput
#endif
#define _INC_char_functions_inc

// Variables
static
    char_Skin[MAX_PLAYERS],
    char_Money[MAX_PLAYERS],
    char_Score[MAX_PLAYERS];

// Functions
stock Char_GetSkin(const character) return char_Skin[character];
stock Char_SetSkin(const character, const id)
{
    char_Skin[character] = id;
    SetPlayerSkin(character, Char_GetSkin(character));

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_skin = '%d' WHERE char_id = '%d'",
        Char_GetSkin(character), Char_GetUniqueID(character)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Char_GetMoney(const character) return char_Money[character];
stock Char_GiveMoney(const character, const value)
{
    char_Money[character] += value;
    GivePlayerMoney(character, value);

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_money = '%d' WHERE char_id = '%d'",
        Char_GetMoney(character), Char_GetUniqueID(character)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Char_TakeMoney(const character, const value)
{
    char_Money[character] -= value;
    GivePlayerMoney(character, -value);

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_money = '%d' WHERE char_id = '%d'",
        Char_GetMoney(character), Char_GetUniqueID(character)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}

stock Char_GetScore(const character) return char_Score[character];
stock Char_SetScore(const character, const value)
{
    char_Score[character] = value;
    SetPlayerScore(character, Char_GetScore(character));

    new String: str_query_update = String: str_format(
        "UPDATE characters SET char_score = '%d' WHERE char_id = '%d'",
        Char_GetScore(character), Char_GetUniqueID(character)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_update);

    return 1;
}