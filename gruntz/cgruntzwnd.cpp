#include "cgruntzwnd.h"

HWND CGruntzWnd::unknown_active_window_handle;

CGruntzWnd::~CGruntzWnd()
{
	//@address: 004945c0
	Destroy();
}

CGruntzWnd::CGruntzWnd()
{
	//@address: 00494560
	//@note: default constructor
}

