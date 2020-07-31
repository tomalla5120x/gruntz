#include "cgruntzmgr.h"
#include "globals.h"
#include "../resources/resource.h"

#include <new>

Utils::MemoryPool<Pair> CGruntzMgr::memory_pool;

bool CGruntzMgr::is_font_initialized = false;
Font CGruntzMgr::font_large;
Font CGruntzMgr::font_medium;
Font CGruntzMgr::font_small;
Font CGruntzMgr::font_tiny;

CGruntzMgr::CGruntzMgr()
{
	//@address: 00482f50
	fieldUnknown02C = 0;
	fieldUnknown030_maybeSurfaceRestoreHandler = 0;
	fieldUnknown034 = 0;
	fieldUnknown038 = 0;
	fieldUnknown07C = 0;
	fieldUnknown03C = 0;
	fieldUnknown040 = 0;
	fieldUnknown044 = 0;
	fieldUnknown048 = 0;
	fieldUnknown04C = 0;
	fieldUnknown050 = 0;
	fieldUnknown064 = 0;
	fieldUnknown0C0 = 0;
	fieldUnknown054 = 0;
	fieldUnknown058 = 0;
	fieldUnknown05C = 0;
	fieldUnknown060 = 0;
	fieldUnknown068 = 0;
	fieldUnknown06C = 0;
	fieldUnknown070 = 0;
	fieldUnknown074 = 0;
	fieldUnknown078 = 0;
	fieldUnknown09C = 0;
	fieldUnknown0A0 = 0;
	fieldUnknown0A4 = 0;
	fieldUnknown0A8 = 0;
	fieldUnknown0AC = 0;
	fieldUnknown0B0 = 0;
	fieldUnknown0B4 = 0;
	fieldUnknown114 = 0;
	fieldUnknown0B8 = 1;
	fieldUnknown0C4 = 0;
	fieldUnknown0BC = 0;
	fieldUnknown080 = 0;
	fieldUnknown084 = 0;
	fieldUnknown0CC = 30;
	fieldUnknown08C = 0;
	fieldUnknown090 = 0;
	fieldUnknown088 = 16;
	fieldUnknown0F4 = 1;
	fieldUnknown0F8 = 0;
	fieldUnknown0FC = 0;

	//CGameMgr
	fieldUnknown014 = 1;
	fieldUnknown010 = 1;

	fieldUnknown100 = 1;
	fieldUnknown104 = 1;
	fieldUnknown108 = 0;
	fieldUnknown118 = 0;
	fieldUnknown130 = 0;
	fieldUnknown128 = 0;
	fieldUnknown12C = 0;
	fieldUnknown134 = 0;
	fieldUnknown10C = 1;
	fieldUnknown110 = 1;
	fieldUnknown138 = 3;
}

CGruntzMgr::~CGruntzMgr()
{
	//@address: 00483280
	UnknownClose();
}

void CGruntzMgr::ReportError(int errorMessageId, int errorCode)
{
	//@address: 0048db80
	if(m_pGameApp == nullptr)
		return;

	m_pGameApp->ReportError(errorMessageId, errorCode);
}

bool CGruntzMgr::UnknownVirtualMethod1(WAP32::CGameWnd* pGameWnd, char* szCmdLine)
{
	//@address: 00483370
	if(!memory_pool.AllocateBlock(20000))
	{
		ReportError(IDS_UNABLE_TO_INITIALIZE_THE_GAME, 1028);
		return false;
	}

	if(!CGameMgr::UnknownVirtualMethod1(pGameWnd, szCmdLine))
	{
		ReportError(IDS_UNABLE_TO_INITIALIZE_THE_GAME, 1122);
		return false;
	}

	if(!InitializeFonts())
	{
		ReportError(IDS_UNABLE_TO_INITIALIZE_THE_GAME, 1123);
		return false;
	}

	//@todo
	//until then, the method just fails gracefully:
	return false;
}

bool CGruntzMgr::InitializeFonts()
{
	//@address: 00515940
	if(is_font_initialized)
		return true;

	if(!font_large.LoadFont("large.fnt"))
		return false;
	if(!font_medium.LoadFont("medium.fnt"))
		return false;
	if(!font_small.LoadFont("small.fnt"))
		return false;
	if(!font_tiny.LoadFont("tiny.fnt"))
		return false;

	is_font_initialized = true;
	return true;
}

void CGruntzMgr::UnknownClose()
{
	//@address: 00485500
	if(fieldUnknown030_maybeSurfaceRestoreHandler != 0)
	{
		//@todo
		//??SetSurfaceRestoreHandler??(0);
	}

	font_large.FreeMemory();
	font_medium.FreeMemory();
	font_small.FreeMemory();
	font_tiny.FreeMemory();

	//@todo
	// saving registry values
	// releasing other structures
	//@todo

	CGameMgr::UnknownClose();
}

void CGruntzMgr::UnknownVirtualMethod3()
{
	//@todo:
}

void CGruntzMgr::UnknownVirtualMethod4()
{
	//@todo:
}

void CGruntzMgr::UnknownVirtualMethod5()
{
	//@todo:
}

UnknownClassArrays::UnknownClassArrays()
{
	//@address: 00424d50
	fieldUnknown078 = 0;
	fieldUnknown080 = 0;
	fieldUnknown07C = 0;
	fieldUnknown084 = 0;
	fieldUnknown018 = 0;
	fieldUnknown01C = 1;
	fieldUnknown020 = 64;
	fieldUnknown024 = 64;
	fieldUnknown028 = 64;
	fieldUnknown08C = 5;
	fieldUnknown090 = 5;
	fieldUnknown02C = 50;
	fieldUnknown094 = 8;
	fieldUnknown098 = 8;
	fieldUnknown0AC = 8;
	fieldUnknown0B0 = 8;
	fieldUnknown030 = 50;
	fieldUnknown0B4 = 1000;
	fieldUnknown0BC = 1000;
	fieldUnknown088 = 50;
	fieldUnknown0A8 = 50;

	fieldUnknown048 = 0;
	fieldUnknown054 = 0;
	fieldUnknown050 = 0;
	fieldUnknown058 = 0;
	fieldUnknown05C = 0;
	fieldUnknown04C = 0;

	fieldUnknown0C4 = 3000;
	fieldUnknown0CC = 3000;

	fieldUnknown13C = 0;
	fieldUnknown140 = 0;

	fieldUnknown09C = 2000;
	fieldUnknown0A0 = 2000;
	fieldUnknown0A4 = 6;
	fieldUnknown0B8 = 2000;
	fieldUnknown0C0 = 10;
	fieldUnknown0C8 = 30000;
	fieldUnknown074 = 25;
}

UnknownClassArrays::~UnknownClassArrays()
{
	//@address: 00424f10
	FreeArrays();
}

void UnknownClassArrays::FreeArrays()
{
	//@address: 00425c30
	if(unknownMemoryPoolPointers1.GetCount() > 0)
	{
		for(unsigned int i = 0; i < unknownMemoryPoolPointers1.GetCount(); ++i)
			if(unknownMemoryPoolPointers1[i] != nullptr)
				CGruntzMgr::memory_pool.Free((Pair*)unknownMemoryPoolPointers1[i]);
	}

	unknownMemoryPoolPointers1.SetSize(0);

	if(unknownMemoryPoolPointers2.GetCount() > 0)
	{
		for(unsigned int i = 0; i < unknownMemoryPoolPointers2.GetCount(); ++i)
		{
			// @note: for the second pointer array there is no check for null pointers
			CGruntzMgr::memory_pool.Free((Pair*)unknownMemoryPoolPointers2[i]);
		}
	}

	unknownMemoryPoolPointers2.SetSize(0);
	unknownDwordArray1.SetSize(0);
	unknownDwordArray2.SetSize(0);
}

UnknownClassInCGruntzMgr::UnknownClassInCGruntzMgr()
{
	//@address: 004da7c0
	fieldUnknown22C = 0;
	fieldUnknown230 = 0;
	fieldUnknown028 = 0;
	ResetFields();
}

void UnknownClassInCGruntzMgr::ResetFields()
{
	//@address: inlined
	strUnknownString004 = Globals::perhaps_an_empty_string;
	fieldUnknown000 = -1;
	fieldUnknown018 = -2;
	fieldUnknown020 = 0;
	fieldUnknown014 = 1;
	fieldUnknown008 = 0;
	fieldUnknown010 = 0;
	fieldUnknown220 = 0;
	fieldUnknown224 = 0;
	fieldUnknown228 = 15;
	fieldUnknown02C = 0;
	fieldUnknown030 = 0;
	fieldUnknown22C = 0;
	fieldUnknown230 = 0;
}

UnknownClassInCGruntzMgr::~UnknownClassInCGruntzMgr()
{
	//@address: 00483180
	ResetFields();
}