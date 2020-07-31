#ifndef __WAP32_CGAMEWND__
#define __WAP32_CGAMEWND__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

namespace WAP32
{
	class CGameApp;

	class CGameWnd
	{
	public:
		//@size: 0x10
		CGameWnd();
		virtual ~CGameWnd();

		bool CreateAndShow(CREATESTRUCTA* pCreateStruct, WAP32::CGameApp* pGameApp);
		void Destroy();

		//@todo (virtual methods)
		//@address: 005ea344 (vftable)
		//@offset: 4
		virtual void UnknownVirtualMethod02() {}
		//@offset: 8
		virtual void UnknownVirtualMethod03() {}
		//@offset: c
		virtual void UnknownVirtualMethod04() {}
		//@offset: 10
		virtual void UnknownVirtualMethod05() {}
		//@offset: 14
		virtual void UnknownVirtualMethod06() {}
		//@offset: 18
		virtual void UnknownVirtualMethod07() {}
		//@offset: 1c
		virtual void UnknownVirtualMethod08() {}
		//@offset: 20
		virtual void UnknownVirtualMethod09() {}
		//@offset: 24
		virtual void UnknownVirtualMethod10() {}
		//@offset: 28
		virtual void UnknownVirtualMethod11() {}
		//@offset: 2c
		virtual void UnknownVirtualMethod12() {}
		//@offset: 30
		virtual void UnknownVirtualMethod13() {}
		//@offset: 34
		virtual void QuitMessageLoop();
		//@offset: 38
		virtual void UnknownVirtualMethod15() {}
		//@offset: 3c
		virtual void UnknownVirtualMethod16() {}
		//@offset: 40
		virtual void UnknownVirtualMethod17() {}
		//@offset: 44
		virtual void UnknownVirtualMethod18() {}
		//@offset: 48
		virtual void UnknownVirtualMethod19() {}
		//@offset: 4c
		virtual void UnknownVirtualMethod20() {}
		//@offset: 50
		virtual void UnknownVirtualMethod21() {}
		//@offset: 54
		virtual void UnknownVirtualMethod22() {}

		//@offset: 4
		HWND m_hWnd;
		//@offset: 8
		CGameApp* m_pGameApp;
		//@offset: c
		int fieldUnknown00C;

		//@address: 00654bc0
		static CGameWnd* global_game_wnd;
	};
}

#endif