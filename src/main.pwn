#include <a_samp>
#include <a_mysql>
#include <crashdetect>

#define CGEN_MEMORY 40000
#define YSI_YES_HEAP_MALLOC
#define YSI_NO_VERSION_CHECK
#define YSI_NO_MODE_CACHE
#define YSI_NO_OPTIMISATION_MESSAGE
#define Y_COMMANDS_USE_CHARS

#define FOREACH_NO_BOTS
#define FOREACH_NO_STREAMED

#include <strlib>
#include <streamer>
#include <sscanf2>
#include <PawnPlus>
#include <pp-mysql>
#include <progress2>
#include <easy-dialog>

#include <YSI_Coding\y_timers>
#include <YSI_Data\y_iterate>
#include <YSI_Coding\y_malloc>
#include <YSI_Server\y_colours>
#include <YSI_Visual\y_commands>

#include <script\script_settings>
#include <mysql\mysql_connection>
#include <player\accounts\account_main>
#include <player\characters\char_main>
#include <player\characters\systems\mute\mute_main>
#include <player\ranks\rank_main>
#include <player\ui\ui_main>
#include <vehicle\vehicle_main>
#include <player\cars\car_main>
#include <player\rent\rent_main>
#include <world\world_main>

main ()
{
	print("Gamemode loaded.");
}