/*
The Globals class is a "bag" for global variables for all the global variables used throughout the game.
Obviously I do not advocate for such design in any final program - it's only for the sake of the source code recreation.
*/

#ifndef __GRUNTZ_GLOBALS__
#define __GRUNTZ_GLOBALS__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>
#include <atlimage.h>
#include "../wap32/cgameapp.h"

class Globals
{
public:

	//@address: 00652560
	static int game_version[4];

	//@address: 00646544
	static bool is_spawn_mode;

	//@address: 00652570
	static HINSTANCE game_instance;

	//@address: 00646100
	//@address: 004829c0 (dynamic initializer)
	//@address: 00482a00 (dynamic destructor)
	static CWinApp game_cwinapp;

	//@address: 00652558
	static WAP32::CGameApp* gruntz_app;

	//@address: 0062a34c
	static char perhaps_an_empty_string[];
};

#endif