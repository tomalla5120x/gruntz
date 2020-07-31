#include "cgamemgr.h"

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>
#include <mmsystem.h>

#include "cgamewnd.h"

int WAP32::CGameMgr::unknown_cgamemgr_global_time;
int WAP32::CGameMgr::unknown_cgamemgr_global_time_related1;
int WAP32::CGameMgr::unknown_cgamemgr_global_time_related2;
int WAP32::CGameMgr::unknown_cgamemgr_global_time_related3;
int WAP32::CGameMgr::unknown_cgamemgr_global_time_related4;

WAP32::CGameMgr::CGameMgr()
{
	//@address: 0053dff0
	fieldUnknown010 = 1;
	fieldUnknown014 = 1;
	m_pGameWnd = nullptr;
	m_pGameApp = nullptr;
	fieldUnknown00C = 0;
	fieldUnknown01C = 0;

	UnknownMethodInitializeTime(true);
	UnknownMethodInitializeTimeGlobal();
}

void WAP32::CGameMgr::UnknownMethodInitializeTime(bool param_1)
{
	fieldUnknown020 = 0;
	fieldUnknown024 = timeGetTime();

	if(param_1)
		fieldUnknown018 = -1;
}

void WAP32::CGameMgr::UnknownMethodInitializeTimeGlobal()
{
	//@address: 0053e180
	unknown_cgamemgr_global_time = timeGetTime();
	unknown_cgamemgr_global_time_related1 = 0;
	unknown_cgamemgr_global_time_related2 = 0;
}

WAP32::CGameMgr::~CGameMgr()
{
	//@address: inlined
	UnknownClose();
}

bool WAP32::CGameMgr::UnknownVirtualMethod1(WAP32::CGameWnd* pGameWnd, char* szCmdLine)
{
	//@address: 0053e030
	if(pGameWnd == nullptr || pGameWnd->m_hWnd == NULL)
		return false;

	m_pGameWnd = pGameWnd;
	m_pGameApp = pGameWnd->m_pGameApp;
	fieldUnknown01C = 0;
	UnknownMethodInitializeTime(true);
	UnknownMethodInitializeTimeGlobal();
	unknown_cgamemgr_global_time_related3 = 100;
	unknown_cgamemgr_global_time_related4 = 100;

	return true;
}

void WAP32::CGameMgr::UnknownClose()
{
	//@address: 0053e090
	m_pGameWnd = nullptr;
	m_pGameApp = nullptr;
}