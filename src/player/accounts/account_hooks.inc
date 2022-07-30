#if defined _INC_accounts_hooks_inc
    #endinput
#endif
#define _INC_accounts_hooks_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnPlayerConnect(playerid)
{
    // TogglePlayerSpectating(playerid, 1);
    Account_IsCreated(playerid);

    if (!strcmp(ReturnPlayerName(playerid), "Emmett_White", true))
    {
        new Text3D: tmp_rank_label = Create3DTextLabel("[Owner & Developer]", X11_BLACK, 10.0, 20.0, 30.0, 25.0, 0);
        Attach3DTextLabelToPlayer(tmp_rank_label, playerid, 0.0, 0.0, 0.3);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerRequestClass(playerid, classid)
{
    TogglePlayerSpectating(playerid, 1);
    return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnPlayerClickPlayerTD(playerid, PlayerText:playertextid)
{
    if (playertextid == PlayerText: Account_UILoginClicked(playerid, 7))
        Account_PromptName(playerid);

    else if (playertextid == PlayerText: Account_UILoginClicked(playerid, 8))
        Account_PromptLogin(playerid);

    else if (playertextid == PlayerText: Account_UILoginClicked(playerid, 9))
    {
        if (!Account_UILoginFailed(playerid))
            return SendErrorMsg(playerid, "Niste popunili sva polja!");

        UI_AccountLogin(playerid);
        UI_AccountLoading(playerid);
        task_await(Task: BindToPlayer(task_ms(2500), playerid));
        Account_SetSpawn(playerid, SPAWN_ACCOUNT_CREATED);
    }

    return Y_HOOKS_CONTINUE_RETURN_1;
}