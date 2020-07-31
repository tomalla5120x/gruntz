#include "cgamewnd.h"

#include "cgameapp.h"

WAP32::CGameWnd* WAP32::CGameWnd::global_game_wnd = nullptr;

bool WAP32::CGameWnd::CreateAndShow(CREATESTRUCTA* pCreateStruct, WAP32::CGameApp* pGameApp)
{
	//@address: 0053d200
	if(pCreateStruct == nullptr || pGameApp == nullptr)
		return false;

	if(global_game_wnd != nullptr)
		return false;

	m_pGameApp = pGameApp;
	global_game_wnd = this;

	fieldUnknown00C = 0;

	m_hWnd = CreateWindowExA(pCreateStruct->dwExStyle, pCreateStruct->lpszClass, pCreateStruct->lpszName,
		pCreateStruct->style, pCreateStruct->x, pCreateStruct->y, pCreateStruct->cx,
		pCreateStruct->cy, pCreateStruct->hwndParent, pCreateStruct->hMenu,
		pCreateStruct->hInstance, pCreateStruct->lpCreateParams);

	if(m_hWnd == NULL)
		return false;

	ShowWindow(m_hWnd, SW_SHOWNORMAL);
	return true;
}

WAP32::CGameWnd::CGameWnd()
{
	//@address: 0053d1e0
	m_hWnd = NULL;
	fieldUnknown00C = 0;
}

WAP32::CGameWnd::~CGameWnd()
{
	//@address: inlined
	Destroy();
	global_game_wnd = nullptr;
}

void WAP32::CGameWnd::Destroy()
{
	//@address: 0053d290
	if(m_hWnd != NULL)
	{
		if(IsWindow(m_hWnd))
			DestroyWindow(m_hWnd);
		m_hWnd = NULL;
	}

	m_pGameApp = nullptr;
}

void WAP32::CGameWnd::QuitMessageLoop()
{
	//@address: 0053d770
	m_pGameApp->FreeGameManager();

	if(m_pGameApp->m_isError)
		m_pGameApp->ShowError();
	
	PostQuitMessage(0);
}