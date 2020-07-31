#ifndef __WAP32_CGAMEMGR__
#define __WAP32_CGAMEMGR__

#include "cgamewnd.h"

namespace WAP32
{
	class CGameMgr
	{
	public:
		//@size: 2c

		//@todo
		CGameMgr();
		virtual ~CGameMgr();

		//@vftable: 0
		//vector deleting destructor (-> @address: 004854c0)
		//@vftable: 4
		virtual bool UnknownVirtualMethod1(WAP32::CGameWnd* pGameWnd, char* szCmdLine);
		//@vftable: 8
		virtual void UnknownClose();
		//@vftable: C
		virtual void UnknownVirtualMethod3() {}
		//@vftable: 10
		virtual void UnknownVirtualMethod4() {}
		//@vftable: 14
		virtual void UnknownVirtualMethod5() {}

		//@offset: 4
		WAP32::CGameWnd* m_pGameWnd;
		//@offset: 8
		WAP32::CGameApp* m_pGameApp;
		//@offset: c
		int fieldUnknown00C;
		//@offset: 10
		int fieldUnknown010;
		//@offset: 14
		int fieldUnknown014;
		//@offset: 18
		int fieldUnknown018;
		//@offset: 1C
		int fieldUnknown01C;
		//@offset: 20
		int fieldUnknown020;
		//@offset: 24
		int fieldUnknown024;
		//@offset: 28
		char _padding[4];

		//@address: 00654bc8
		static int unknown_cgamemgr_global_time;
		//@address: 00654bcc
		static int unknown_cgamemgr_global_time_related1;
		//@address: 00654bd0
		static int unknown_cgamemgr_global_time_related2;
		//@address: 00654bd4
		static int unknown_cgamemgr_global_time_related3;
		//@address: 00654bd8
		static int unknown_cgamemgr_global_time_related4;

	private:
		void UnknownMethodInitializeTime(bool param_1);
		void UnknownMethodInitializeTimeGlobal();
	};
}

#endif