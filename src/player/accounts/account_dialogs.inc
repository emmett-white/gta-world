#if defined _INC_account_dialogs_inc
    #endinput
#endif
#define _INC_account_dialogs_inc

// Variables
static
    account_MaxUsernameAttempts[MAX_PLAYERS],
    account_MaxLoginAttempts[MAX_PLAYERS];

// Dialogs
Dialog: dialog_username(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return Kick(playerid);

    if (!strcmp(inputtext, ReturnPlayerName(playerid), false))
    {
        PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 7), ReturnPlayerName(playerid));
        Account_UIUsernamePass(playerid, 1);
    }
   
    else
    {
        if (account_MaxUsernameAttempts[playerid] == MAX_LOGIN_ATTEMPTS)
            return Kick(playerid);

        ++account_MaxUsernameAttempts[playerid];
        
        SendErrorMsgF(playerid, "%d/%d neuspeli pokusaj.", account_MaxUsernameAttempts[playerid], MAX_LOGIN_ATTEMPTS);
        Account_UIUsernamePass(playerid, 0);
    }

    return 1;
}

Dialog: dialog_login(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return Kick(playerid);

    if (!strcmp(inputtext, Account_GetPassword(playerid), false))
    {
        switch(strlen(inputtext))
        {
            case 4: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]");
            case 5: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]");
            case 6: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]");
            case 7: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]");
            case 8: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]");
            case 9: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]");
            case 10: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]]");
            case 11: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]]]");
            case 12: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]]]]");
            case 13: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]]]]]");
            case 14: PlayerTextDrawSetString(playerid, PlayerText: Account_UILoginClicked(playerid, 8), "]]]]]]]]]]]]]]");
        }

        // these are not literally clickable textdraws but ok
        PlayerTextDrawColor(playerid, PlayerText: Account_UILoginClicked(playerid, 9), 0xFFFFFFAA);
        PlayerTextDrawColor(playerid, PlayerText: Account_UILoginClicked(playerid, 6), 0x205aab90);
        PlayerTextDrawShow(playerid, PlayerText: Account_UILoginClicked(playerid, 9));
        PlayerTextDrawShow(playerid, PlayerText: Account_UILoginClicked(playerid, 6));

        Account_UIPasswordPass(playerid, 1);
    }

    else
    {
        if (account_MaxLoginAttempts[playerid] == MAX_LOGIN_ATTEMPTS)
            return Kick(playerid);

        ++account_MaxLoginAttempts[playerid];
        
        SendErrorMsgF(playerid, "%d/%d neuspeli pokusaj.", account_MaxLoginAttempts[playerid], MAX_LOGIN_ATTEMPTS);
        Account_UIPasswordPass(playerid, 0);
    }

    return 1;
}

Dialog: dialog_register(const playerid, response, listitem, string: inputtext[])
{
    if (!response)
        return 0;

    if (!(MIN_PASSWORD_LENGTH <= strlen(inputtext) <= MAX_PASSWORD_LENGTH))
        return SendErrorMsg(playerid, "Predugacka ili prekratka lozinka."), Account_PromptRegister(playerid);

    Account_SetPassword(playerid, inputtext);

    new String: str_query_insert_acc = String: str_format(
        "INSERT INTO accounts (account_name, account_password) VALUES ('%e', '%e')",
        ReturnPlayerName(playerid), Account_GetPassword(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert_acc, "OnAccountCreated", "d", playerid);

    new String: str_query_insert_char = String: str_format(
        "INSERT INTO characters (char_name, char_money, char_skin) VALUES ('%e', '1000', '60')",
        ReturnPlayerName(playerid)
    );
    mysql_tquery_s(MySQL: MySQL_GetHandle(), str_query_insert_char, "OnCharacterCreated", "d", playerid);

    return 1;
}