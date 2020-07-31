#include "cgameapp.h"
#include <cstdio>

#include "cgamemgr.h"
#include "cgamewnd.h"

#pragma warning(disable : 4996) // using deprecated CRT functions

int WAP32::CGameApp::m_referenceCounter = 0;

WAP32::CGameApp::CGameApp()
{
	//@address: 0053d870
	m_pGameWnd = nullptr;
	m_pGameMgr = nullptr;
	m_hAccelerators = NULL;
	m_hInstance = NULL;
	fieldUnknown240 = 0;
	m_isError = false;
	m_errorMessageId = 0;
	m_errorCode = 0;

	++m_referenceCounter;
}

WAP32::CGameApp::~CGameApp()
{
	//@address: inlined
	CloseResources();
	--m_referenceCounter;
}

void WAP32::CGameApp::CloseResources()
{
	//@address: 0053dba0
	if(m_hAccelerators != NULL)
	{
		DestroyAcceleratorTable(m_hAccelerators);
		m_hAccelerators = NULL;
	}

	if(m_pGameMgr != nullptr)
	{
		delete m_pGameMgr;
		m_pGameMgr = nullptr;
	}

	if(m_pGameWnd != nullptr)
	{
		delete m_pGameWnd;
		m_pGameWnd = nullptr;
	}
}

bool WAP32::CGameApp::VirtualUnknownMethod03(HINSTANCE hInstance, char* szWindowName, char* szGameIdentifier, char* szCmdLine, char windowClassFlags, int windowWidth, int windowHeight)
{
	//@address: 0053da90
	GameInfo gameInfo;

	if(hInstance == NULL)
		return false;

	memset(&gameInfo, 0, sizeof(gameInfo));

	gameInfo.hInstance = hInstance;

	gameInfo.size = sizeof(GameInfo);
	gameInfo.windowClassFlags = windowClassFlags;
	gameInfo.windowWidth = windowWidth;
	gameInfo.windowHeight = windowHeight;

	if(szWindowName != nullptr)
	{
		//@bug: no length check
		strcpy(gameInfo.szWindowName, szWindowName);
	}

	if(szGameIdentifier != nullptr)
	{
		//@bug: no length check
		strcpy(gameInfo.szGameIdentifier, szGameIdentifier);
	}

	if(szCmdLine != nullptr)
	{
		//@bug: no length check
		strcpy(gameInfo.szCmdLine, szCmdLine);
	}

	return VirtualUnknownMethod02(&gameInfo, nullptr, nullptr);
}

bool WAP32::CGameApp::VirtualUnknownMethod02(GameInfo* pGameInfo, WNDCLASSA* pWndClass, CREATESTRUCTA* pCreateStruct)
{
	//@address: 0053d8b0
	if(m_referenceCounter > 1
		|| pGameInfo == nullptr
		|| pGameInfo->size != sizeof(GameInfo))
		return false;

	if(pWndClass != nullptr)
	{
		if(pWndClass->lpszClassName == nullptr || pWndClass->lpszClassName[0] == 0)
			return false;
	}

	fieldUnknown244_errorRelatedFlag = true;
	m_isError = false;
	m_errorMessageId = 0;
	m_errorCode = 0;

	memcpy(&m_gameInfo, pGameInfo, sizeof(GameInfo));

	HINSTANCE gameInstance = m_gameInfo.hInstance;

	if(gameInstance == NULL && pWndClass != nullptr)
		gameInstance = pWndClass->hInstance;

	if(gameInstance == NULL && pCreateStruct != nullptr)
		gameInstance = pCreateStruct->hInstance;

	if(gameInstance == NULL)
		return false;

	m_hInstance = gameInstance;

	if(m_gameInfo.szWindowClassName[0] == 0)
		sprintf(m_gameInfo.szWindowClassName, "%sClass", m_gameInfo.szGameIdentifier);

	if(m_gameInfo.szWindowName[0] == 0)
		sprintf(m_gameInfo.szWindowName, "%s", m_gameInfo.szGameIdentifier);

	if(pWndClass != nullptr)
		memcpy(&m_wndClass, pWndClass, sizeof(m_wndClass));
	else
		InitializeDefaultWindowClass();

	if(pCreateStruct != nullptr)
		memcpy(&m_createStruct, pCreateStruct, sizeof(m_createStruct));
	else
		InitializeDefaultCreateStruct();

	if(RegisterClassA(&m_wndClass) == 0)
		return false;

	InitializeAccelerators(m_gameInfo.szGameIdentifier);
	m_pGameWnd = InitializeGameWindow();

	if(m_pGameWnd == nullptr)
		return false;

	if(!m_pGameWnd->CreateAndShow(&m_createStruct, this))
	{
		delete m_pGameWnd;
		m_pGameWnd = nullptr;
		return false;
	}

	m_pGameMgr = InitializeGameManager();

	if(m_pGameMgr == nullptr)
		return false;

	if(m_pGameMgr->UnknownVirtualMethod1(m_pGameWnd, m_gameInfo.szCmdLine))
		return true;

	delete m_pGameMgr;
	m_pGameMgr = nullptr;
	return false;
}

WAP32::CGameMgr* WAP32::CGameApp::InitializeGameManager()
{
	//@address: 0053dea0
	return new CGameMgr;
}

WAP32::CGameWnd* WAP32::CGameApp::InitializeGameWindow()
{
	//@address: 0053de40
	return new CGameWnd;
}

bool WAP32::CGameApp::InitializeAccelerators(char* szGameIdentifier)
{
	//@address: 0053df00
	if(szGameIdentifier == nullptr || szGameIdentifier[0] == 0)
		return false;

	if(m_hAccelerators != NULL)
	{
		DestroyAcceleratorTable(m_hAccelerators);
		m_hAccelerators = NULL;
	}

	m_hAccelerators = LoadAcceleratorsA(m_hInstance, szGameIdentifier);
	return(m_hAccelerators != NULL);
}

void WAP32::CGameApp::InitializeDefaultCreateStruct()
{
	//@address: 0053dd30
	memset(&m_createStruct, 0, sizeof(m_createStruct));

	HMENU hMenu = NULL;
	if(m_gameInfo.windowClassFlags & WindowClassFlags::Windowed)
		hMenu = LoadMenuA(m_hInstance, m_gameInfo.szGameIdentifier);

	int x, y, cx, cy;

	if(m_gameInfo.windowClassFlags & WindowClassFlags::Windowed)
	{
		x = y = 0x80000000;
		cx = m_gameInfo.windowWidth;
		cy = m_gameInfo.windowHeight;
	}
	else
	{
		x = y = 0;
		cx = GetSystemMetrics(SM_CXSCREEN);
		cy = GetSystemMetrics(SM_CYSCREEN);
	}

	int style, dwExStyle;

	if(m_gameInfo.windowClassFlags & WindowClassFlags::Windowed)
	{
		style = WS_CAPTION | WS_SYSMENU | WS_THICKFRAME | WS_GROUP | WS_TABSTOP;
		dwExStyle = WS_EX_APPWINDOW;
		
		if(m_gameInfo.windowClassFlags & WindowClassFlags::DialogFrame)
			style = WS_BORDER | WS_DLGFRAME | WS_SYSMENU | WS_GROUP;
	}
	else
	{
		style = WS_POPUP | WS_SYSMENU;
		dwExStyle = WS_EX_APPWINDOW | WS_EX_TOPMOST;
	}

	m_createStruct.style = style;
	m_createStruct.hInstance = m_hInstance;
	m_createStruct.hMenu = hMenu;
	m_createStruct.y = y;
	m_createStruct.cx = cx;
	m_createStruct.lpCreateParams = NULL;
	m_createStruct.hwndParent = NULL;
	m_createStruct.x = x;
	m_createStruct.cy = cy;
	m_createStruct.lpszName = m_gameInfo.szWindowName;
	m_createStruct.lpszClass = m_gameInfo.szWindowClassName;
	m_createStruct.dwExStyle = dwExStyle;
}

void WAP32::CGameApp::InitializeDefaultWindowClass()
{
	//@address: 0053dc90
	memset(&m_wndClass, 0, sizeof(m_wndClass));

	HCURSOR hCursor = LoadCursorA(m_hInstance, m_gameInfo.szGameIdentifier);

	if(m_gameInfo.windowClassFlags & WindowClassFlags::Windowed)
		hCursor = LoadCursorA(NULL, IDC_ARROW);

	m_wndClass.style = CS_DBLCLKS;
	m_wndClass.lpfnWndProc = &GameWindowProc;
	m_wndClass.cbClsExtra = 0;
	m_wndClass.cbWndExtra = 0;
	m_wndClass.hInstance = m_hInstance;
	m_wndClass.hIcon = LoadIconA(m_hInstance, m_gameInfo.szGameIdentifier);
	m_wndClass.hCursor = hCursor;
	m_wndClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	m_wndClass.lpszMenuName = nullptr;
	m_wndClass.lpszClassName = m_gameInfo.szWindowClassName;
}

LRESULT CALLBACK WAP32::CGameApp::GameWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	//@address: 0053d2d0
	//@todo
	return 0;
}

// sets the error to be reported on window close and send the close message
void WAP32::CGameApp::ReportError(int errorMessageId, int errorCode)
{
	//@address: 0053df90
	if(m_isError)
		return;

	m_isError = true;

	if(m_pGameWnd != nullptr && m_pGameWnd->fieldUnknown00C == 0)
		PostMessageA(m_pGameWnd->m_hWnd, WM_CLOSE, 0, 0);

	fieldUnknown244_errorRelatedFlag = 0;
	m_errorMessageId = errorMessageId;
	m_errorCode = errorCode;
}

void WAP32::CGameApp::FreeGameManager()
{
	//@address: 0053df70
	if(m_pGameMgr != nullptr)
	{
		delete m_pGameMgr;
		m_pGameMgr = nullptr;
	}
}

void WAP32::CGameApp::ShowError()
{
	//@address: 00480cd0
	//@note: to be overriden by the derived class
	return;
}