#include "globals.h"

CWinApp Globals::game_cwinapp("Gruntz");
int Globals::game_version[4] = {0, 0, 0, 0};
bool Globals::is_spawn_mode = false;
HINSTANCE Globals::game_instance;
WAP32::CGameApp* Globals::gruntz_app;
char Globals::perhaps_an_empty_string[] = "";
