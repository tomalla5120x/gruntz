#include "cgruntzmgr.h"
#include "globals.h"
#include "../resources/resource.h"
#include "../utils/winapi.h"
#include "../dx/cnetmgr.h"

#include <new>
#include <mmsystem.h>
#include <dplobby.h>

#pragma warning(disable : 4996) // using deprecated CRT functions

Utils::MemoryPool<Pair> CGruntzMgr::memory_pool;

bool CGruntzMgr::is_font_initialized = false;
Font CGruntzMgr::font_large;
Font CGruntzMgr::font_medium;
Font CGruntzMgr::font_small;
Font CGruntzMgr::font_tiny;

bool CGruntzMgr::is_high_quality_movie_enabled;
int CGruntzMgr::is_audio_disabled;
int CGruntzMgr::is_sound_disabled;
int CGruntzMgr::is_music_disabled;
int CGruntzMgr::is_fades_disabled;
int CGruntzMgr::is_direct_video_access_disabled;
int CGruntzMgr::is_joystick_disabled;
int CGruntzMgr::is_soundfonts_disabled;
int CGruntzMgr::is_triple_enabled;
int CGruntzMgr::is_hicolor_enabled;
int CGruntzMgr::is_truecolor_enabled;
int CGruntzMgr::is_emulation_enabled;

int CGruntzMgr::unknown_global_006461c4;
int CGruntzMgr::unknown_global_00646228;
int CGruntzMgr::unknown_global_006461c0;
int CGruntzMgr::unknown_global_006464c0;
int CGruntzMgr::unknown_global_00646490;
int CGruntzMgr::unknown_global_006460fc;
int CGruntzMgr::unknown_global_0064622c;
int CGruntzMgr::unknown_global_00646200;
int CGruntzMgr::unknown_global_006464b0;
int CGruntzMgr::unknown_global_006464b8;
int CGruntzMgr::unknown_global_006464b4;
int CGruntzMgr::unknown_global_006464bc;

CGruntzMgr::CGruntzMgr()
{
	//@address: 00482f50
	fieldUnknown02C = 0;
	fieldUnknown030_maybeSurfaceRestoreHandler = 0;
	fieldUnknown034 = 0;
	m_pRegistryHelper = nullptr;
	fieldUnknown07C = 0;
	fieldUnknown03C = 0;
	fieldUnknown040 = 0;
	fieldUnknown044 = 0;
	fieldUnknown048 = 0;
	fieldUnknown04C = 0;
	fieldUnknown050 = 0;
	fieldUnknown064 = 0;
	m_pDirectPlayLobby = nullptr;
	fieldUnknown054 = 0;
	fieldUnknown058 = 0;
	fieldUnknown05C = 0;
	fieldUnknown060 = 0;
	fieldUnknown068 = 0;
	fieldUnknown06C = 0;
	fieldUnknown070 = 0;
	fieldUnknown074 = 0;
	fieldUnknown078 = 0;
	m_unknownIsLobbyConnectionSettingsInitialized = false;
	m_unknownIsLobbyConnectionSettingsAttempted = false;
	fieldUnknown0A4 = 0;
	fieldUnknown0A8 = 0;
	fieldUnknown0AC = 0;
	fieldUnknown0B0 = 0;
	fieldUnknown0B4 = 0;
	fieldUnknown114 = 0;
	m_isCheckpointPrompts = 1;
	m_pDirectPlayConnection = nullptr;
	fieldUnknown0BC = 0;
	m_numRuns = 0;
	m_numMovies = 0;
	fieldUnknown0CC = 30;
	fieldUnknown08C = 0;
	fieldUnknown090 = 0;
	fieldUnknown088 = 16;
	fieldUnknown0F4 = 1;
	fieldUnknown0F8 = 0;
	fieldUnknown0FC = 0;

	//CGameMgr
	m_isMusicEnabled = 1;
	m_isSoundEnabled = 1;

	m_isVoiceEnabled = 1;
	m_isAmbientEnabled = 1;
	m_isInterlaced = 0;
	m_isEasyMode = 0;
	fieldUnknown130 = 0;
	fieldUnknown128 = 0;
	fieldUnknown12C = 0;
	fieldUnknown134 = 0;
	m_isHighDetail = 1;
	m_unknownSecondIsHighDetail = 1;
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

	srand((timeGetTime() + GetTickCount()) / 2);

	unknown_cgamemgr_global_time_related4 = 33;

	Utils::WinAPI::HideCursorForce();

	//@address: 00483471

	m_pRegistryHelper = new Utils::RegistryHelper();

	if(!m_pRegistryHelper->Open("Monolith Productions", "Gruntz", "1.0", nullptr, HKEY_LOCAL_MACHINE, nullptr))
	{
		ReportError(IDS_UNABLE_TO_INITIALIZE_THE_GAME, 1030);
		return false;
	}

	m_resolutionWidth = 640;
	m_resolutionHeight = 480;
	m_numRuns = m_pRegistryHelper->GetValueDword("Num Runs", 0);
	m_numMovies = m_pRegistryHelper->GetValueDword("Num Movies", 0);
	is_high_quality_movie_enabled = (m_pRegistryHelper->GetValueDword("Disable High Quality Movie", 0) == 0);
	is_audio_disabled = m_pRegistryHelper->GetValueDword("Disable Audio", 0);
	is_sound_disabled = m_pRegistryHelper->GetValueDword("Disable Sound", 0);
	is_music_disabled = m_pRegistryHelper->GetValueDword("Disable Music", 0);
	is_fades_disabled = m_pRegistryHelper->GetValueDword("Disable Fades", 0);
	is_direct_video_access_disabled = m_pRegistryHelper->GetValueDword("Disable Direct Video Access", 0);
	is_joystick_disabled = m_pRegistryHelper->GetValueDword("Disable Joystick", 0);
	is_soundfonts_disabled = m_pRegistryHelper->GetValueDword("Disable SoundFonts", 0);
	is_triple_enabled = m_pRegistryHelper->GetValueDword("Enable Triple", 0);
	is_hicolor_enabled = m_pRegistryHelper->GetValueDword("Enable HiColor", 0);
	is_truecolor_enabled = m_pRegistryHelper->GetValueDword("Enable TrueColor", 0);
	is_emulation_enabled = m_pRegistryHelper->GetValueDword("Enable Emulation", 0);
	m_isCheckpointPrompts = m_pRegistryHelper->GetValueDword("Checkpoint Prompts", 1);

	is_hicolor_enabled = 1;
	unknown_global_006461c4 = 0;
	unknown_global_00646228 = 0;
	unknown_global_006461c0 = 0;
	unknown_global_006464c0 = 0;
	unknown_global_00646490 = 0;
	unknown_global_006460fc = 0;
	unknown_global_0064622c = 1;
	unknown_global_00646200 = 0;
	unknown_global_006464b0 = 0;
	unknown_global_006464b8 = 0;
	unknown_global_006464b4 = 0;
	unknown_global_006464bc = 0;

	int isMusicEnabled = m_pRegistryHelper->GetValueDword("Music", m_isMusicEnabled);
	int isSoundEnabled = m_pRegistryHelper->GetValueDword("Sound", m_isSoundEnabled);
	int isVoiceEnabled = m_pRegistryHelper->GetValueDword("Voice", m_isVoiceEnabled);
	int isAmbientEnabled = m_pRegistryHelper->GetValueDword("Ambient", m_isAmbientEnabled);
	int isInterlaced = m_pRegistryHelper->GetValueDword("Interlaced", m_isInterlaced);
	int isHighDetail = m_pRegistryHelper->GetValueDword("High Detail", m_isHighDetail);
	int unknownSecondIsHighDetail = m_pRegistryHelper->GetValueDword("High Detail", m_unknownSecondIsHighDetail);
	m_isEasyMode = m_pRegistryHelper->GetValueDword("Easy Mode", m_isEasyMode);

	DecodeResolution(m_pRegistryHelper->GetValueDword("Resolution", 1), m_resolutionWidth, m_resolutionHeight);

	int musicVolume = m_pRegistryHelper->GetValueDword("Music Volume", 100);
	int soundVolume = m_pRegistryHelper->GetValueDword("Sound Volume", 60);
	int voiceVolume = m_pRegistryHelper->GetValueDword("Voice Volume", 80);
	int scrollSpeed = m_pRegistryHelper->GetValueDword("Scroll Speed", 20);

	++m_numRuns;
	m_soundVolume = soundVolume;
	m_voiceVolume = voiceVolume;
	m_scrollSpeed = scrollSpeed;

	if(is_direct_video_access_disabled)
	{
		is_fades_disabled = 1;
		is_emulation_enabled = 1;
	}

	fieldUnknown0AC = 0;
	fieldUnknown0B0 = 0;

	m_isDriveLetterLoaded = false;
	m_driveLetter = 0;
	GetGruntzDriveLetter();

	bool isNoLogo = false;
	int unknownMode = 2;

	if(szCmdLine != nullptr)
	{
		//@address: 00483822

		char szCmdLineBuffer[300];
		strcpy(szCmdLineBuffer, szCmdLine);
		strupr(szCmdLineBuffer);

		if(strstr(szCmdLineBuffer, "PLAY") != nullptr)
			unknownMode = 3;
		if(strstr(szCmdLineBuffer, "MULTI") != nullptr)
			unknownMode = 17;
		if(strstr(szCmdLineBuffer, "DEMO") != nullptr)
			unknownMode = 7;
		if(strstr(szCmdLineBuffer, "SELECT") != nullptr)
			unknownMode = 16;

		if(strstr(szCmdLineBuffer, "NOLOGO") != nullptr)
			isNoLogo = true;

		//@note: although the function is being called, for some reason it results in no further actions.
		//it was probably removed from the final version of the game.
		strstr(szCmdLineBuffer, "NOMOVIES");

		//@bug: the buffer is not initialized
		//@note: the "LOAD" parameter seems to be scrapped as well.
		char szLoadPathBuffer[128];

		if(strstr(szCmdLineBuffer, "LOAD:") != nullptr)
		{
			// initializes the szLoadPathBuffer
			// example: "LOAD:FOO_BAR+GAZ" -> "FOO BAR GAZ"

			char anotherBuffer[300];
			strcpy(anotherBuffer, szCmdLineBuffer);

			char* szLoad = strstr(anotherBuffer, "LOAD:");

			if(szLoad != nullptr && strlen(szLoad) > 5)
			{
				char* szLoadId = szLoad + 5;
				int offsetEnd = 0; // offset to either '\0' or space
				if(szLoadId[0] != ' ')
				{
					while(szLoadId[offsetEnd] != 0 && szLoadId[offsetEnd] != ' ')
						++offsetEnd;
				}
				szLoadId[offsetEnd] = 0;

				if(szLoadId[0] != 0)
				{
					for(int i=0; szLoadId[i] != 0; ++i)
					{
						if(szLoadId[i] == '_' || szLoadId[i] == '+')
							szLoadId[i] = ' ';
					}
				}

				strcpy(szLoadPathBuffer, szLoadId);
			}
		}
	}

	if(InitializeLobbyConnectionSettings())
	{
		unknownMode = 17;
		fieldUnknown0B4 = 0;
	}

	//@address: 004839e3

	//@todo
	//until then, the method just fails gracefully:
	return false;
}

bool CGruntzMgr::InitializeLobbyConnectionSettings()
{
	//@address: 0048ebc0
	if(m_unknownIsLobbyConnectionSettingsAttempted)
		return m_unknownIsLobbyConnectionSettingsInitialized;

	m_unknownIsLobbyConnectionSettingsAttempted = true;
	m_unknownIsLobbyConnectionSettingsInitialized = false;

	if(m_pDirectPlayLobby != nullptr)
	{
		m_pDirectPlayLobby->Release();
		m_pDirectPlayLobby = nullptr;
	}

	HRESULT hResult = DirectPlayLobbyCreateA(NULL, &m_pDirectPlayLobby, NULL, NULL, 0);

	if(hResult != DP_OK)
	{
		CNetMgr::ReportError(__FILE__, __LINE__, hResult, m_pGameWnd->m_hWnd);
		return false;
	}

	if(m_pDirectPlayLobby == nullptr)
		return false;
	
	if(m_pDirectPlayConnection != nullptr)
	{
		delete m_pDirectPlayConnection;
		m_pDirectPlayConnection = nullptr;
	}

	DWORD connectionStructSize = 0;
	hResult = m_pDirectPlayLobby->GetConnectionSettings(0, NULL, &connectionStructSize);

	if(hResult != DP_OK && hResult != DPERR_BUFFERTOOSMALL)
	{
		CNetMgr::ReportError(__FILE__, __LINE__, hResult, m_pGameWnd->m_hWnd);
		m_pDirectPlayLobby->Release();
		m_pDirectPlayLobby = nullptr;
		return false;
	}

	m_pDirectPlayConnection = (DPLCONNECTION*) new char[connectionStructSize];

	if(m_pDirectPlayConnection != nullptr)
	{
		hResult = m_pDirectPlayLobby->GetConnectionSettings(0, m_pDirectPlayConnection, &connectionStructSize);

		if(hResult == DP_OK)
		{
			m_unknownIsLobbyConnectionSettingsInitialized = true;
			return true;
		}

		CNetMgr::ReportError(__FILE__, __LINE__, hResult, m_pGameWnd->m_hWnd);
	}

	m_pDirectPlayLobby->Release();
	m_pDirectPlayLobby = nullptr;

	return false;
}

char CGruntzMgr::GetGruntzDriveLetter()
{
	//@address: 0048f990
	if(m_isDriveLetterLoaded)
		return m_driveLetter;
	
	m_driveLetter = Utils::WinAPI::GetGruntzDriveLetter();
	m_isDriveLetterLoaded = true;
	return m_driveLetter;
}

void CGruntzMgr::DecodeResolution(int resolution, int& width, int& height)
{
	//@address: inlined
	if(resolution == 3)
	{
		width = 1024;
		height = 768;
	}
	else if(resolution == 2)
	{
		width = 800;
		height = 600;
	}
	else
	{
		width = 640;
		height = 480;
	}
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