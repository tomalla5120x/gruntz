#ifndef __WAP32_CGAMEAPP__
#define __WAP32_CGAMEAPP__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

namespace WAP32
{
	class CGameWnd;
	class CGameMgr;

	struct GameInfo
	{
		//size: 0x1d4

		//@offset: 0
		int size;
		//@offset: 4
		char windowClassFlags;
		//@offset: 8
		HINSTANCE hInstance;
		//@offset c
		char szCmdLine[128];
		//@offset 8c
		// used for:
		// * generating window class name <fragment>Class
		// * loading the cursor, icon, menu with the same name
		char szGameIdentifier[64];
		//@offset cc
		char szWindowName[64];
	
	//@offset: 10c
	char _padding2[0x40];

		//@offset: 14c
		char szWindowClassName[128];

		//@offset: 1cc
		int windowWidth;
		//@offset 1d0
		int windowHeight;
	};

	class CGameApp
	{
	public:
		CGameApp();
		virtual ~CGameApp();

		struct WindowClassFlags
		{
			//if set:
			// * default cursor is used
			// * window is created with menu named "Gruntz"
			// * window is created with a given width/height instead of being fullscreen (and is initially moved far away from the screen)
			// 
			static constexpr int Windowed = 0x1;

			static constexpr int DialogFrame = 0x2;
		};

		//@vftable: 0
		//vector_deleting_destructor (-> @address: 00480cf0)
		//@vftable: 4
		//@todo
		virtual bool VirtualUnknownMethod02(GameInfo* pGameInfo, WNDCLASSA* pWndClass, CREATESTRUCTA* pCreateStruct);
		//@vftable: 8
		//@todo
		virtual bool VirtualUnknownMethod03(HINSTANCE hInstance, char* szWindowName, char* szGameIdentifier, char* szCmdLine, char windowClassFlags, int windowWidth, int windowHeight);
		//@vftable: C
		//@todo
		virtual void VirtualUnknownMethod04() {}
		//@vftable: 10
		virtual void CloseResources();
		//@vftable: 14
		//@todo
		virtual void VirtualUnknownMethod06() {}
		//@vftable: 18
		//@todo
		virtual void VirtualUnknownMethod07() {}
		//@vftable: 1C
		virtual void ReportError(int errorMessageId, int errorCode);
		//@vftable: 20
		//@todo
		virtual void VirtualUnknownMethod09() {}
		//@vftable: 24
		virtual void FreeGameManager();
		//@vftable: 28
		//@todo
		virtual void VirtualUnknownMethod11() {}
		//@vftable: 2C
		virtual bool InitializeAccelerators(char* szGameIdentifier);
		//@vftable: 30
		virtual void ShowError();
		//@vftable: 34
		virtual WAP32::CGameWnd* InitializeGameWindow();
		//@vftable: 38
		virtual WAP32::CGameMgr* InitializeGameManager();
		//@vftable: 3C
		virtual void InitializeDefaultWindowClass();
		//@vftable: 40
		virtual void InitializeDefaultCreateStruct();

		//@offset: 4
		WAP32::CGameWnd* m_pGameWnd;
		//@offset: 8
		WAP32::CGameMgr* m_pGameMgr;
		//@offset: c
		HINSTANCE m_hInstance;
		//@offset: 10
		HACCEL m_hAccelerators;
		//@offset: 14 (size: 1d4)
		GameInfo m_gameInfo;
		//@offset: 1e8 (size: 28)
		WNDCLASSA m_wndClass;
		//@offset: 210
		CREATESTRUCTA m_createStruct;
		//@offset: 240
		unsigned int fieldUnknown240;
		//@offset: 244
		bool fieldUnknown244_errorRelatedFlag;
		//@offset: 248
		bool m_isError;
		//@offset: 24c
		unsigned int m_errorMessageId;
		//@offset: 250
		unsigned int m_errorCode;

	private:
		//@address: 00654bc4
		static int m_referenceCounter;

		static LRESULT CALLBACK GameWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	};

}

#endif
