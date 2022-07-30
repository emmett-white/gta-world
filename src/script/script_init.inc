#if defined _INC_script_init_inc
    #endinput
#endif
#define _INC_script_init_inc

#include <YSI_Coding\y_hooks>

// Hooks
hook OnScriptInit()
{
    EnableStuntBonusForAll(0);
    DisableInteriorEnterExits();
    UsePlayerPedAnims();

    // Set the current irl time
    new __hour, __min, __sec;
    gettime(__hour, __min, __sec);
    SetWorldTime(__hour);

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// Callbacks
forward Bind_OnPlayerDisconnect(CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid);
public Bind_OnPlayerDisconnect(CallbackHandler: self, Handle: task_handle, Task: task, const orig_playerid, const playerid)
{
    if(orig_playerid == playerid)
	{
        pawn_unregister_callback(self);
        handle_release(task_handle);

        if(handle_linked(task_handle))
			task_delete(task);
    }
}

// Functions
stock BindToPlayer(Task: task, const playerid)
{
    new Handle: handle = handle_new(_:task, .tag_id = tagof(task));
		
    handle_acquire(handle);
    // pawn_register_callback(#OnPlayerDisconnect, #Bind_OnPlayerDisconnect, _, "ddd", _:handle, _:task, playerid);
    pawn_register_callback("OnPlayerDisconnect", "Bind_OnPlayerDisconnect", _, "eddd", _:handle, _:task, playerid);
    
    return _:task;
}