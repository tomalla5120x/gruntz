#include "cnetmgr.h"
#include "../common.h"

#include <dplay.h>

#ifdef GRUNTZ_DEBUG
bool CNetMgr::is_error_log = true;
bool CNetMgr::is_error_messagebox = true;
bool CNetMgr::is_error_beep = true;
bool CNetMgr::is_error_unknown_flag = true;
#else
bool CNetMgr::is_error_log = false;
bool CNetMgr::is_error_messagebox = false;
bool CNetMgr::is_error_beep = false;
bool CNetMgr::is_error_unknown_flag = false;
#endif

int CNetMgr::error_hresult = 0;
int CNetMgr::error_hresult_low = 0;
char CNetMgr::error_string_code[64];
char CNetMgr::error_string_message[256];

#define ERRORCASE(_hresult, _strmessage) \
case _hresult: \
	strcpy(error_string_code, #_hresult); \
	strcpy(error_string_message, _strmessage); \
	break;

void CNetMgr::ReportError(char* szFile, int lineNumber, HRESULT hResult, HWND hWnd)
{
	//@address: 00577980
	char messageBuffer[512];

	error_hresult_low = hResult & 0xFFFF;
	error_hresult = hResult;

	if(is_error_beep)
		MessageBeep(MB_ICONWARNING);

	sprintf(error_string_code, "Unknown Error Code");
	strcpy(error_string_message, "Unknown Error Message");
	strcpy(messageBuffer, Globals::perhaps_an_empty_string);

	switch(hResult)
	{
		ERRORCASE(DPERR_GENERIC, "An undefined error condition occurred.");
		ERRORCASE(DPERR_UNSUPPORTED, "The function is not available in this implementation.");
		ERRORCASE(DPERR_INVALIDPARAMS, "One or more of the parameters passed to the function are invalid.");
		ERRORCASE(DPERR_OUTOFMEMORY, "There is insufficient memory to perform the requested operation.");
		ERRORCASE(DPERR_ACCESSDENIED, "The session is full or an incorrect password was supplied.");
		ERRORCASE(DPERR_ALREADYINITIALIZED, "This object is already initialized.");
		ERRORCASE(DPERR_BUFFERTOOSMALL, "The supplied buffer is not large enough to contain the requested data.");
		ERRORCASE(DPERR_ACTIVEPLAYERS, "The requested operation cannot be performed because there are existing active players.");
		ERRORCASE(DPERR_CANTCREATEGROUP, "A new group cannot be created.");
		ERRORCASE(DPERR_CANTADDPLAYER, "The player cannot be added to the session.");
		ERRORCASE(DPERR_CANTCREATESESSION, "A new session cannot be created.");
		ERRORCASE(DPERR_CANTCREATEPLAYER, "A new player cannot be created.");
		ERRORCASE(DPERR_EXCEPTION, "An exception occurred when processing the request.");
		ERRORCASE(DPERR_CAPSNOTAVAILABLEYET, "The capabilities of the DirectPlay object have not been determined yet.");
		ERRORCASE(DPERR_INVALIDOBJECT, "The DirectPlay object pointer is invalid.");
		ERRORCASE(DPERR_INVALIDFLAGS, "The flags passed to this function are invalid.");
		ERRORCASE(DPERR_NOCAPS, "The communication link underneath DirectPlay is not capable of this function.");
		ERRORCASE(DPERR_INVALIDPLAYER, "The player ID is not recognized as a valid player ID for this game session.");
		ERRORCASE(DPERR_NOMESSAGES, "There are no messages to be received.");
		ERRORCASE(DPERR_NOCONNECTION, "No communication link was established.");
		ERRORCASE(DPERR_NOPLAYERS, "There are no active players in the session.");
		ERRORCASE(DPERR_NONAMESERVERFOUND, "No name server (host) could be found or created. A host must exist in order to create a player.");
		ERRORCASE(DPERR_SENDTOOBIG, "The message buffer passed to the IDirectPlay2::Send method is larger than allowed.");
		ERRORCASE(DPERR_NOSESSIONS, "There are no existing sessions for this game.");
		ERRORCASE(DPERR_UNAVAILABLE, "The requested function is not available at this time.");
		ERRORCASE(DPERR_TIMEOUT, "The operation could not be completed in the specified time.");
		ERRORCASE(DPERR_USERCANCEL, "The user canceled the connection process during a call to the IDirectPlay2::Open method.");
		ERRORCASE(DPERR_BUSY, "The DirectPlay message queue is full.");
		ERRORCASE(DPERR_SESSIONLOST, "The connection to the session has been lost.");
		ERRORCASE(DPERR_PLAYERLOST, "A player has lost the connection to the session.");
		ERRORCASE(DPERR_CANTCREATEPROCESS, "Can't launch the application.");
		ERRORCASE(DPERR_BUFFERTOOLARGE, "The data buffer is too large to store.");
		ERRORCASE(DPERR_UNKNOWNAPPLICATION, "An unknown application was specified.");
		ERRORCASE(DPERR_NOTLOBBIED, "Returned by IDirectPlayLobby::Connect if the application was not launched using IDirectPlayLobby::RunApplication");
		ERRORCASE(DP_OK, "No error");
		ERRORCASE(DPERR_INVALIDINTERFACE, "The interface parameter is invalid.");
		ERRORCASE(DPERR_APPNOTSTARTED, "The application has not been started yet.");
	}

	//@note: is_error_unknown_flag must have been used in the debug version of the application only and has an unknown purpose
	if(!is_error_log && !is_error_messagebox && !is_error_unknown_flag)
		return;

	if(is_error_log)
	{
		if(szFile != nullptr && lineNumber > 0)
			sprintf(messageBuffer, "%s, line %i: %s (%i) - %s\n", szFile, lineNumber, error_string_code, error_hresult_low, error_string_message);
		else
			sprintf(messageBuffer, "%s (%i) - %s\n", error_string_code, error_hresult_low, error_string_message);

		//@note: it's only my educated guess that in the debug version some kind of a log is issued here - it's not present in the binary itself
		#ifdef GRUNTZ_DEBUG
		OutputDebugStringA(messageBuffer);
		#endif
	}

	if(is_error_messagebox)
	{
		if(szFile != nullptr && lineNumber > 0)
			sprintf(messageBuffer, "%s, line %i\n\n%s (%i)\n\n%s", szFile, lineNumber, error_string_code, error_hresult_low, error_string_message);
		else
			sprintf(messageBuffer, "%s (%i)\n\n%s", error_string_code, error_hresult_low, error_string_message);

		MessageBoxA(hWnd, messageBuffer, "Net Manager", MB_ICONWARNING);
	}
}