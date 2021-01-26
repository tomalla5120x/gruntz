#ifndef __DX_NETMGR__
#define __DX_NETMGR__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

class CNetMgr: public CObject
{
public:
	//@todo: vftable, fields etc.
	//destructor: 004b5ff0
	//constructor (inlined): 004b55fe

	static void ReportError(char* szFile, int lineNumber, HRESULT hResult, HWND hWnd);

	//@address: 006c0640
	static bool is_error_log;
	//@address: 006c0644
	static bool is_error_messagebox;
	//@address: 006c0648
	static bool is_error_beep;
	//@address: 006c064c
	static bool is_error_unknown_flag;
	//@address: 006c0650
	static int error_hresult;
	//@address: 006c0654
	static int error_hresult_low;
	//@address: 006c0658
	static char error_string_code[64];
	//@address: 006c0698
	static char error_string_message[256];
};

#endif