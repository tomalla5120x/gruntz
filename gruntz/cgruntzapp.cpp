#include "cgruntzapp.h"
#include "cgruntzmgr.h"
#include "cgruntzwnd.h"

#include "../resources/resource.h"
#include "../utils/winapi.h"

#pragma warning(disable : 4996) // using deprecated CRT functions

char CGruntzApp::error_dialog_message[256];

CGruntzApp::~CGruntzApp()
{
	//@address: 004807d0
	CloseResources();
}

bool CGruntzApp::VirtualUnknownMethod03(HINSTANCE hInstance, char* szWindowName, char* szGameIdentifier, char* szCmdLine, char windowClassFlags, int windowWidth, int windowHeight)
{
	//@address: 00480850
	return CGameApp::VirtualUnknownMethod03(hInstance, szWindowName, szGameIdentifier, szCmdLine, windowClassFlags, windowWidth, windowHeight);
}

WAP32::CGameMgr* CGruntzApp::InitializeGameManager()
{
	//@address: 00480940
	return new CGruntzMgr;
}

WAP32::CGameWnd* CGruntzApp::InitializeGameWindow()
{
	//@address: 004808c0
	return new CGruntzWnd;
}

void CGruntzApp::ShowError()
{
	//@address: 004809e0
	int errorMessageId = m_errorMessageId;
	if(errorMessageId == 0)
		errorMessageId = IDS_UNABLE_TO_CONTINUE_THE_GAME;

	char szCodePostfix[32];
	szCodePostfix[0] = 0;

	if(m_errorCode > 0)
		sprintf(szCodePostfix, " (%i)", m_errorCode);

	if(LoadStringA(m_hInstance, errorMessageId, error_dialog_message, 250) == 0)
		Utils::WinAPI::LoadStringDefault(m_hInstance, IDS_UNABLE_TO_CONTINUE_THE_GAME, error_dialog_message, 250, "Unable to continue game.");

	strcat(error_dialog_message, szCodePostfix);

	Utils::WinAPI::ShowCursorForce();
	DialogBoxParamA(m_hInstance, "ERROR", NULL, &ErrorDialogProc, 0);
}

INT_PTR CALLBACK CGruntzApp::ErrorDialogProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//@address: 00480b90
	CGruntzWnd::unknown_active_window_handle = hWnd;

	if(message == WM_INITDIALOG)
	{
		SetDlgItemTextA(hWnd, IDC_ERROR_TEXT, error_dialog_message);
		return TRUE;
	}

	if(message != WM_COMMAND)
		return FALSE;

	if(wParam == IDOK || wParam == IDCANCEL)
	{
		EndDialog(hWnd, 0);
		return TRUE;
	}

	return FALSE;
}