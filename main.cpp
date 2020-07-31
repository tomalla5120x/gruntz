/*

The recreation of Monolith's 1999 puzzle game "Gruntz".

The source code is an almost one-to-one functional equivalent of the original assembly. The obvious exceptions would be
C Runtime Library and common library function calls (C standard library, MFC etc.).

Libraries/utilities used:
* Microsoft Visual C++ compiler (VC6 or earlier - based on a magic number in exception handling structures)
* WinAPI
* MFC (statically linked)
* DirectDraw
* Miles Sound System (statically linked) - playback of sound
* Smacker (dynamically linked) - part of the RAD Game Tools suite responsible for playback of videos

Annotation types:
@address - the address for a given element in the original binary ("none/helper/inline" if it was introduced by me and might have been inlined).
* addresses may be multiple if there are multiple identical definitions in the binary
@offset - offset of the field in the structure
@bug - the implementation bug in the original binary (the recreated code recreates bugs as well)
@legacy - code which may run differently on newer windows operating systems
@todo - the functions yet to be recreated
@vftable - offset of the virtual method in the virtual functions table of the object

The recreation was based on: Gruntz 1.0.1.77 (patched English version)
Executable MD5:
199d4613e4587e1d720623dc11569e4d
Executable SHA256:
ef636e84cd547efe3e835811aefa6cd20964dadb9c2b427aa13860e52b2228d4

Other notes:
* the C++ "new" operator is overloaded by MFC and throws a CMemoryException pointer. The code in the binary doesn't seem to catch it in any way
  so when out of memory happens the application simply crashes. However the pointer returned by the new operator is often compared to NULL and depending on that some
  custom error handling is employed. I've simulated a few out-of-memory situations and as I suspected the game just crashes with a CMemoryException and the
  NULL check never happens. Hard for me to tell whether it's a bug or not. Nonetheless I tried to leave the NULL checks as they were in the binary originally
  even though they may never be hit.

*/

#pragma warning(disable : 4996) // using deprecated CRT functions
#pragma comment(lib, "version.lib")

#include <cstdio>

#include "gruntz/globals.h"
#include "gruntz/dialogs/advanced_options.h"
#include "utils/winapi.h"
#include "utils/registry_helper.h"
#include "resources/resource.h"
#include "gruntz/cgruntzapp.h"
#include "commands.h"

bool GetGruntzDriveLetter_TestDrive(char driveLetter)
{
	//@address: inlined
	char drivePathBuffer[32];
	sprintf(drivePathBuffer, "%c:\\", driveLetter);

	if(GetDriveTypeA(drivePathBuffer) == DRIVE_CDROM)
	{
		char exePathBuffer[256];
		sprintf(exePathBuffer, "%c:\\GAME\\GRUNTZ.EXE", driveLetter);
		return Utils::WinAPI::FileExists(exePathBuffer);
	}

	return false;
}

// returns the letter of the CDROM drive with Gruntz CD or 0 if not found
char GetGruntzDriveLetter()
{
	//@address: 0041fff0

	//@address: 0062c1b4
	static char driveLetterEvaluated = 0;

	if(driveLetterEvaluated != 0)
		return driveLetterEvaluated;

	Utils::RegistryHelper registryHelper;
	
	if(registryHelper.Open("Monolith Productions", "Gruntz", "1.0", nullptr, HKEY_LOCAL_MACHINE, nullptr))
	{
		char valueBuffer[30];
		unsigned int valueBufferSize = sizeof(valueBuffer);
		valueBuffer[0] = 0;

		if(registryHelper.GetValueString("CdRom Drive", valueBuffer, &valueBufferSize)
			&& valueBuffer[0] > 20
			&& GetGruntzDriveLetter_TestDrive(valueBuffer[0]))
		{
			driveLetterEvaluated = valueBuffer[0];
			return valueBuffer[0];
		}
	}

	for(char driveLetter = 'A'; driveLetter <= 'Z'; ++driveLetter)
	{
		if(!GetGruntzDriveLetter_TestDrive(driveLetter))
			continue;

		driveLetterEvaluated = driveLetter;
		return driveLetter;
	}
	
	return 0;
}

// tests if Gruntz CD is in any CDROM drive
bool IsGruntzCDInAnyDrive()
{
	//@address: 0041fd60
	return(GetGruntzDriveLetter() != 0);
}

// checks for the absence of the Gruntz CD in the CDROM drive
// either waits for the CD to be insterted or asks if the user wants to run the game in the spawn mode
// returns false if the prompts were cancelled
bool StartUpPrompt(HWND hParentWindow)
{
	//@address: 0041f9c0
	if(IsGruntzCDInAnyDrive())
	{
		Globals::is_spawn_mode = false;
		return true;
	}

	char currentDirectoryBuffer[256];
	if(GetCurrentDirectoryA(255, currentDirectoryBuffer) == 0)
		return false;

	CString strGruntzRezPath;
	CString strGruntzRez("Gruntz.REZ");
	strGruntzRezPath.Format("%s\\%s", currentDirectoryBuffer, strGruntzRez.GetBuffer());

	char szGruntzBuffer[64];

	//@bug: game_instance handle is zero-initialized at this point
	if(Utils::WinAPI::FileExists(strGruntzRezPath.GetBuffer()))
	{
		// there is a file "Gruntz.REZ" in the current directory
		char szPromptBuffer[128];

		Utils::WinAPI::LoadStringDefault(Globals::game_instance, IDS_GRUNTZ_CDROM_NOT_FOUND_RUN_IN_SPAWN_MODE, szPromptBuffer, 124, "Gruntz CD-ROM not found. Run in Spawn Mode?");
		Utils::WinAPI::LoadStringDefault(Globals::game_instance, IDS_GRUNTZ, szGruntzBuffer, 62, "Gruntz");

		if(MessageBoxA(hParentWindow, szPromptBuffer, szGruntzBuffer, MB_ICONWARNING | MB_YESNO) == IDYES)
		{
			Globals::is_spawn_mode = true;
			return true;
		}

		return false;
	}

	Globals::is_spawn_mode = false;

	for(;;)
	{
		Utils::WinAPI::LoadStringDefault(Globals::game_instance, IDS_GRUNTZ, szGruntzBuffer, 62, "Gruntz");

		if(MessageBoxA(hParentWindow, "Please insert the game CD-ROM into the drive.", szGruntzBuffer, MB_ICONWARNING | MB_OKCANCEL) != IDOK)
			return false;

		CWaitCursor waitCursor;

		if(IsGruntzCDInAnyDrive())
			return true;
			
		Sleep(1000);

		if(IsGruntzCDInAnyDrive())
			return true;
	}
}

void InitializeVersionInfo(char* szModuleName)
{
	//@address: inlined

	//@bug: assumption that the binary always has valid version data
	int fileVersionInfoSize = GetFileVersionInfoSizeA(szModuleName, nullptr);
	char* pFileVersionInfoData = new char[fileVersionInfoSize];

	GetFileVersionInfoA(szModuleName, 0, fileVersionInfoSize, pFileVersionInfoData);

	char* szFileVersionBuffer;
	unsigned int fileVersionBufferSize;
	// reading the file version string, for example: "1, 0, 1, 77"
	// 040904B0 is a lang-codepage combination: 0x0409 means U.S. English and 0x04B0 means Unicode
	VerQueryValueA(pFileVersionInfoData, "\\StringFileInfo\\040904B0\\FileVersion", (LPVOID*)&szFileVersionBuffer, &fileVersionBufferSize);
	sscanf(szFileVersionBuffer, "%d, %d, %d, %d", &Globals::game_version[0], &Globals::game_version[1], &Globals::game_version[2], &Globals::game_version[3]);

	delete[] pFileVersionInfoData;
}

bool ManageAdvancedOptions(char* lpCmdLine)
{
	//@address: inlined
	Utils::WinAPI::ActiveWait(100);

	bool advancedOptions = false;

	if((GetAsyncKeyState(VK_CONTROL) & 0x8000) != 0)
		advancedOptions = true;
	if((GetAsyncKeyState(VK_SHIFT) & 0x8000) != 0)
		advancedOptions = true;
	if((GetAsyncKeyState(VK_HOME) & 0x8000) != 0)
		advancedOptions = true;

	if(lpCmdLine != nullptr)
	{
		if(strstr(lpCmdLine, "advanced") != nullptr)
			advancedOptions = true;
		if(strstr(lpCmdLine, "optionz") != nullptr)
			advancedOptions = true;
		if(strstr(lpCmdLine, "ADVANCED") != nullptr)
			advancedOptions = true;
		if(strstr(lpCmdLine, "OPTIONZ") != nullptr)
			advancedOptions = true;
		if(strstr(lpCmdLine, "ADV") != nullptr)
			advancedOptions = true;
		if(strstr(lpCmdLine, "adv") != nullptr)
			advancedOptions = true;
	}

	if(!advancedOptions)
		return true;
	return GruntzDialogs::ShowAdvancedOptions();
}

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	//@address: 0051ca70
	char szModuleName[254];

	if(GetModuleFileNameA(NULL, szModuleName, sizeof(szModuleName)) > 0
		&& Utils::WinAPI::LegacyAreProcessesRunning(szModuleName, 2, nullptr))
	{
		HWND hGruntzWindow = FindWindowA("GruntzClass", "Gruntz");

		if(hGruntzWindow == NULL)
			return 0;
		
		if(IsIconic(hGruntzWindow))
			SendMessageA(hGruntzWindow, WM_SYSCOMMAND, SC_RESTORE, 0);

		if(lpCmdLine == nullptr || strstr(lpCmdLine, "LOBBYLAUNCH") == nullptr)
			return 0;

		PostMessageA(hGruntzWindow, WM_COMMAND, Commands::LobbyLaunch, 0);
		return 0;
	}

	//@bug: moduleName may not be initialized
	InitializeVersionInfo(szModuleName);

	if(!StartUpPrompt(NULL))
		return 0;
	
	Globals::gruntz_app = new CGruntzApp();
	Globals::game_instance = hInstance;

	int exitValue = 0;

	if(ManageAdvancedOptions(lpCmdLine)
		&& Globals::gruntz_app->VirtualUnknownMethod03(Globals::game_instance, "Gruntz", "Gruntz", lpCmdLine, 0, 0x80000000, 0x80000000))
	{
		//@todo: commented out until the message loop is recreated
		//exitValue = Globals::gruntz_app->VirtualUnknownMethod07();
	}

	//@todo: to be removed
	MessageBoxA(NULL, "Recreation has advanced only this far - the message loop has been skipped and the aplication will terminate.", "Gruntz", MB_ICONINFORMATION | MB_OK);

	delete Globals::gruntz_app;
	return exitValue;
}