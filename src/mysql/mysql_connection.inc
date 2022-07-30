#if defined _INC_mysql_connection_inc
    #endinput
#endif
#define _INC_mysql_connection_inc

#include <YSI_Coding\y_hooks>

// Variables
new MySQL: db_handle = MYSQL_INVALID_HANDLE;
#define MySQL_GetHandle() db_handle

static const MYSQL_HOSTNAME[10] =     "localhost";
static const MYSQL_USERNAME[5] =      "root";
static const MYSQL_DATABASE[10] =     "gta_world";

// Hooks
hook OnScriptInit()
{
	new MySQLOpt: options = mysql_init_options();
    mysql_set_option(options, AUTO_RECONNECT, true);
    mysql_set_option(options, MULTI_STATEMENTS, true);
    mysql_set_option(options, POOL_SIZE, 2);

    MySQL_GetHandle() = mysql_connect(MYSQL_HOSTNAME, MYSQL_USERNAME, "", MYSQL_DATABASE, options);

    if (mysql_errno(MySQL_GetHandle()))
    {
        print("[MySQL]: Nije moguce uspostaviti konekciju sa databazom!");
        SendRconCommand("exit");
        return 1;
    }

    print("[MySQL]: Uspesna konekcija sa databazom.");
	return Y_HOOKS_CONTINUE_RETURN_1;
}

hook OnGameModeExit()
{
    if (!mysql_close(db_handle))
        print("[MySQL]: Nemoguce zavrsiti konekciju sa databazom.");

    return Y_HOOKS_CONTINUE_RETURN_1;
}

// Functions
public OnQueryError(errorid, const error[], const callback[], const query[], MySQL:handle) return 1;
stock Task: MySQL_Query(const query[]) return mysql_aquery(MySQL_GetHandle(), query, true);
stock Task: MySQL_QueryS(ConstStringTag:query) return mysql_aquery_s(MySQL_GetHandle(), query, true);