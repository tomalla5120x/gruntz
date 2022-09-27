#ifndef __GRUNTZ_CGRUNTZMGR__
#define __GRUNTZ_CGRUNTZMGR__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>
#include <dplobby.h>

#include "../wap32/cgamemgr.h"
#include "../utils/memory_pool.h"
#include "../utils/registry_helper.h"
#include "font.h"
#include "harry_potter.h"

struct Pair
{
	int a;
	int b;
};

class UnknownClassArrays
{
public:
	//@size: ? (@todo: perhaps 0x144? That's the largest offset referenced in the constructor)

	UnknownClassArrays();
	~UnknownClassArrays();

	void FreeArrays();

//@offset: 0
char _padding1[0x18];

	//@offset: 18
	int fieldUnknown018;
	//@offset: 1c
	int fieldUnknown01C;
	//@offset: 20
	int fieldUnknown020;
	//@offset: 24
	int fieldUnknown024;
	//@offset: 28
	int fieldUnknown028;
	//@offset: 2c
	int fieldUnknown02C;
	//@offset: 30
	int fieldUnknown030;

//@offset: 34
char _padding2[0x14];

	//@offset: 48
	int fieldUnknown048;
	//@offset: 4c
	int fieldUnknown04C;
	//@offset: 50
	int fieldUnknown050;
	//@offset: 54
	int fieldUnknown054;
	//@offset: 58
	int fieldUnknown058;
	//@offset: 5c
	int fieldUnknown05C;

//@offset: 60
char _padding3[0x14];

	//@offset: 74
	int fieldUnknown074;
	//@offset: 78
	int fieldUnknown078;
	//@offset: 7c
	int fieldUnknown07C;
	//@offset: 80
	int fieldUnknown080;
	//@offset: 84
	int fieldUnknown084;
	//@offset: 88
	int fieldUnknown088;
	//@offset: 8c
	int fieldUnknown08C;
	//@offset: 90
	int fieldUnknown090;
	//@offset: 94
	int fieldUnknown094;
	//@offset: 98
	int fieldUnknown098;
	//@offset: 9c
	int fieldUnknown09C;
	//@offset: a0
	int fieldUnknown0A0;
	//@offset: a4
	int fieldUnknown0A4;
	//@offset: a8
	int fieldUnknown0A8;
	//@offset: ac
	int fieldUnknown0AC;
	//@offset: b0
	int fieldUnknown0B0;
	//@offset: b4
	int fieldUnknown0B4;
	//@offset: b8
	int fieldUnknown0B8;
	//@offset: bc
	int fieldUnknown0BC;
	//@offset: c0
	int fieldUnknown0C0;
	//@offset: c4
	int fieldUnknown0C4;
	//@offset: c8
	int fieldUnknown0C8;
	//@offset: cc
	int fieldUnknown0CC;

//@offset: d0
char _padding4[0x0C];

	//@offset: dc (size: 0x14)
	CPtrArray unknownMemoryPoolPointers1;
	//@offset: f0
	CPtrArray unknownMemoryPoolPointers2;
	//@offset: 104
	CDWordArray unknownDwordArray1;
	//@offset: 118
	CDWordArray unknownDwordArray2;

//@offset: 12c
char _padding5[0x10];

	//@offset: 13c
	int fieldUnknown13C;
	//@offset: 140
	int fieldUnknown140;
};

class UnknownClassInCGruntzMgr
{
public:
	//@size: 0x238

	UnknownClassInCGruntzMgr();
	~UnknownClassInCGruntzMgr();

	void ResetFields();

	//@offset: 0
	int fieldUnknown000;
	//@offset: 4
	CString strUnknownString004;
	//@offset: 8
	int fieldUnknown008;

//@offset: c
char _padding1[4];

	//@offset: 10
	int fieldUnknown010;
	//@offset: 14
	int fieldUnknown014;
	//@offset: 18
	int fieldUnknown018;

//@offset: 1c
char _padding2[4];

	//@offset: 20
	int fieldUnknown020;

//@offset: 24
char _padding3[4];

	//@offset: 28
	int fieldUnknown028;
	//@offset: 2c
	int fieldUnknown02C;
	//@offset: 30
	int fieldUnknown030;

//@offset: 34
char _padding4[4];

	//@offset: 38
	UnknownClassArrays unknownObjectArrays;

//@offset: 17c
char _padding9[0xA4];

	//@offset: 220
	int fieldUnknown220;
	//@offset: 224
	int fieldUnknown224;
	//@offset: 228
	int fieldUnknown228;
	//@offset: 22c
	int fieldUnknown22C;
	//@offset: 230
	int fieldUnknown230;

//@ofset: 234
char _padding5[4];
};

class CGruntzMgr: public WAP32::CGameMgr
{
public:
	//@size: a30
	CGruntzMgr();
	virtual ~CGruntzMgr();

	//@vftable: 0
	//vector deleting destructor (-> @address: 00483250)
	//@vftable: 4
	virtual bool UnknownVirtualMethod1(WAP32::CGameWnd* pGameWnd, char* szCmdLine) override;
	//@vftable: 8
	virtual void UnknownClose() override;
	//@vftable: C
	virtual void UnknownVirtualMethod3() override;
	//@vftable: 10
	virtual void UnknownVirtualMethod4() override;
	//@vftable: 14
	virtual void UnknownVirtualMethod5() override;

	void ReportError(int errorMessageId, int errorCode);

	//@offset: 0
	//CGameMgr base

	//@offset: 2c
	int fieldUnknown02C; // @todo: pointer to the current game state (an object derived from CState class)
	//@offset: 30
	UnknownClassCGruntzMgrHarryPotter* fieldUnknown030_maybeSurfaceRestoreHandler;
	//@offset: 34
	int fieldUnknown034;
	//@offset: 38
	Utils::RegistryHelper* m_pRegistryHelper;
	//@offset: 3c
	int fieldUnknown03C;
	//@offset: 40
	int fieldUnknown040;
	//@offset: 44
	int fieldUnknown044;
	//@offset: 48
	int fieldUnknown048;
	//@offset: 4c
	int fieldUnknown04C;
	//@offset: 50
	int fieldUnknown050;
	//@offset: 54
	int fieldUnknown054;
	//@offset: 58
	int fieldUnknown058;
	//@offset: 5c
	int fieldUnknown05C;
	//@offset: 60
	int fieldUnknown060;
	//@offset: 64
	int fieldUnknown064;
	//@offset: 68
	int fieldUnknown068;
	//@offset: 6c
	int fieldUnknown06C;
	//@offset: 70
	int fieldUnknown070;
	//@offset: 74
	int fieldUnknown074;
	//@offset: 78
	int fieldUnknown078;
	//@offset: 7c
	int fieldUnknown07C;
	//@offset: 80
	int m_numRuns;
	//@offset: 84
	int m_numMovies;
	//@offset: 88
	int fieldUnknown088;
	//@offset: 8c
	int fieldUnknown08C;
	//@offset: 90
	int fieldUnknown090;
	//@offset: 94
	int m_resolutionWidth;
	//@offset: 98
	int m_resolutionHeight;
	//@offset: 9c
	bool m_unknownIsLobbyConnectionSettingsInitialized;
	//@offset: a0
	bool m_unknownIsLobbyConnectionSettingsAttempted;
	//@offset: a4
	int fieldUnknown0A4;
	//@offset: a8
	int fieldUnknown0A8;
	//@offset: ac
	int fieldUnknown0AC;
	//@offset: b0
	int fieldUnknown0B0;
	//@offset: b4
	int fieldUnknown0B4;
	//@offset: b8
	int m_isCheckpointPrompts;
	//@offset: bc
	int fieldUnknown0BC;
	//@offset: c0
	LPDIRECTPLAYLOBBYA m_pDirectPlayLobby;
	//@offset: c4
	DPLCONNECTION* m_pDirectPlayConnection;
	//@offset: c8
	CString strUnknownString0C8;
	//@offset: cc
	int fieldUnknown0CC;
	//@offset: d0
	char m_driveLetter;
	//@offset: d4
	bool m_isDriveLetterLoaded;
	//@offset: d8
	CPtrArray aUnknownPtrArray0D8;
	//@offset: ec
	CString strUnknownString0EC;
	//@offset: f0
	CString strUnknownString0F0;
	//@offset: f4
	int fieldUnknown0F4;
	//@offset: f8
	int fieldUnknown0F8;
	//@offset: fc
	int fieldUnknown0FC;
	//@offset: 100
	int m_isVoiceEnabled;
	//@offset: 104
	int m_isAmbientEnabled;
	//@offset: 108
	int m_isInterlaced;
	//@offset: 10c
	int m_isHighDetail;
	//@offset: 110
	int m_unknownSecondIsHighDetail;
	//@offset: 114
	int fieldUnknown114;
	//@offset: 118
	int m_isEasyMode;
	//@offset: 11c
	int m_soundVolume;
	//@offset: 120
	int m_voiceVolume;
	//@offset: 124
	int m_scrollSpeed;
	//@offset: 128
	int fieldUnknown128;
	//@offset: 12c
	int fieldUnknown12C;
	//@offset: 130
	int fieldUnknown130;
	//@offset: 134
	int fieldUnknown134;
	//@offset: 138
	int fieldUnknown138;

//@offset: 13c
char _padding4[0x14];

	//@offset: 150
	UnknownClassInCGruntzMgr aUnknownObjs[4];

	//@address: 00646498
	//@address: 00482ec0 (dynamic initializer)
	//@address: 00482f10 (dynamic destructor)
	static Utils::MemoryPool<Pair> memory_pool;

	//@address: 0064fa18
	//@address: 005156e0 (dynamic initializer)
	//@address: 00515720 (dynamic destructor)
	static Font font_large;
	//@address: 0064fa40
	static Font font_medium;
	//@address: 0064fa58
	static Font font_small;
	//@address: 0064f9b0
	static Font font_tiny;

	//@address: 0064652c
	static bool is_high_quality_movie_enabled;
	//@address: 0064650c
	static int is_audio_disabled;
	//@address: 00646514
	static int is_sound_disabled;
	//@address: 00646518
	static int is_music_disabled;
	//@address: 0064651c
	static int is_fades_disabled;
	//@address: 00646528
	static int is_direct_video_access_disabled;
	//@address: 00646520
	static int is_joystick_disabled;
	//@address: 00646524
	static int is_soundfonts_disabled;
	//@address: 00646530
	static int is_triple_enabled;
	//@address: 00646534
	static int is_hicolor_enabled;
	//@address: 00646538
	static int is_truecolor_enabled;
	//@address: 0064653c
	static int is_emulation_enabled;

	//@address: 006461c4
	static int unknown_global_006461c4;
	//@address: 00646228
	static int unknown_global_00646228;
	//@address: 006461c0
	static int unknown_global_006461c0;
	//@address: 006464c0
	static int unknown_global_006464c0;
	//@address: 00646490
	static int unknown_global_00646490;
	//@address: 006460fc
	static int unknown_global_006460fc;
	//@address: 0064622c
	static int unknown_global_0064622c;
	//@address: 00646200
	static int unknown_global_00646200;
	//@address: 006464b0
	static int unknown_global_006464b0;
	//@address: 006464b8
	static int unknown_global_006464b8;
	//@address: 006464b4
	static int unknown_global_006464b4;
	//@address: 006464bc
	static int unknown_global_006464bc;

private:
	//@address: 0064fa6c
	static bool is_font_initialized;

	bool InitializeFonts();
	void DecodeResolution(int resolution, int& width, int& height);
	char GetGruntzDriveLetter();

	bool InitializeLobbyConnectionSettings();
};

#endif
