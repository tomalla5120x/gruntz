#ifndef __GRUNTZ_CGRUNTZWND__
#define __GRUNTZ_CGRUNTZWND__

#include "../wap32/cgamewnd.h"

class CGruntzWnd: public WAP32::CGameWnd
{
public:
	//@size: 0x10 (same as the base)
	CGruntzWnd();
	virtual ~CGruntzWnd();

	//@vftable: 0
	//vector deleting destructor (-> @address: 00494590)
	//@todo: vftable

	//@address: 006464d4
	static HWND unknown_active_window_handle;
};

#endif
