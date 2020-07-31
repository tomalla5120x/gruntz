#ifndef __GRUNTZ_CGRUNTZAPP__
#define __GRUNTZ_CGRUNTZAPP__

#include "../wap32/cgameapp.h"

class CGruntzApp: public WAP32::CGameApp
{
public:
	//@vftable: 0
	//vector_deleting_destructor (-> @address: 004807a0)

	virtual ~CGruntzApp();

	//@todo
	virtual bool VirtualUnknownMethod03(HINSTANCE hInstance, char* szWindowName, char* szGameIdentifier, char* szCmdLine, char windowClassFlags, int windowWidth, int windowHeight) override;
	//@todo
	virtual void VirtualUnknownMethod11() override {}
	virtual void ShowError() override;
	//@todo
	virtual WAP32::CGameWnd* InitializeGameWindow() override;
	//@todo
	virtual WAP32::CGameMgr* InitializeGameManager() override;

private:
	//@address: 00645df8
	static char error_dialog_message[256];
	static INT_PTR CALLBACK ErrorDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif