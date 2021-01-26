#pragma warning(disable : 4996) // using deprecated CRT functions

#include "winapi.h"
#include <cstring>
#include <tlhelp32.h>
#include <mmsystem.h>

#include "registry_helper.h"

using namespace Utils::WinAPI;

char* path_separator = "\\";

typedef HANDLE (WINAPI *PFCreateToolhelp32Snapshot)(DWORD dwFlags, DWORD th32ProcessID);
typedef BOOL (WINAPI *PFProcess32First)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
typedef BOOL (WINAPI *PFProcess32Next)(HANDLE hSnapshot, LPPROCESSENTRY32 lppe);
typedef BOOL (WINAPI *PFModule32First)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);
typedef BOOL (WINAPI *PFModule32Next)(HANDLE hSnapshot, LPMODULEENTRY32 lpme);

namespace
{
	// searches all modules of the process for the module with a specified module id
	// if found the module entry passed to the function is filled with module data and the function returns true
	//
	// @legacy: on newer windows operating systems the function will never find any matching modules, since
	// the passed module id will never match any module id in the process (these fields are deprecated)
	bool LegacyFindModule(DWORD processId, DWORD moduleId, PMODULEENTRY32 pOutFoundModuleEntry, DWORD moduleEntrySize)
	{
		//@address: 00519170
		MODULEENTRY32 moduleEntry32;
		memset(&moduleEntry32, 0, sizeof(moduleEntry32));
		moduleEntry32.dwSize = sizeof(moduleEntry32);

		HMODULE hModuleKernel32 = GetModuleHandleA("KERNEL32.DLL");
		if(hModuleKernel32 == NULL)
			return false;

		PFCreateToolhelp32Snapshot pfCreateToolhelp32Snapshot = (PFCreateToolhelp32Snapshot)GetProcAddress(hModuleKernel32, "CreateToolhelp32Snapshot");
		if(pfCreateToolhelp32Snapshot == NULL)
			return false;

		PFModule32First pfModule32First = (PFModule32First)GetProcAddress(hModuleKernel32, "Module32First");
		if(pfModule32First == NULL)
			return false;

		PFModule32Next pfModule32Next = (PFModule32Next)GetProcAddress(hModuleKernel32, "Module32Next");
		if(pfModule32Next == NULL)
			return false;

		HANDLE hSnapshot = pfCreateToolhelp32Snapshot(TH32CS_SNAPMODULE, processId);
		if(hSnapshot == INVALID_HANDLE_VALUE)
			return false;

		bool moduleFound = false;

		if(pfModule32First(hSnapshot, &moduleEntry32))
		{
			do
			{
				if(moduleEntry32.th32ModuleID == moduleId)
				{
					moduleFound = true;
					memcpy(pOutFoundModuleEntry, &moduleEntry32, moduleEntrySize);
					break;
				}
			} while(pfModule32Next(hSnapshot, &moduleEntry32));
		}

		CloseHandle(hSnapshot);
		return moduleFound;
	}

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
}

bool Utils::WinAPI::LegacyAreProcessesRunning(char* szDescriptor, int minCount, HANDLE* pOutProcessHandle)
{
	//@address: 00518ef0
	if(szDescriptor == nullptr || szDescriptor[0] == 0)
		return false;

	if(pOutProcessHandle != nullptr)
		*pOutProcessHandle = 0;

	bool hasPathSeparator = (strstr(szDescriptor, path_separator) != nullptr);

	HMODULE hModuleKernel32 = GetModuleHandleA("KERNEL32.DLL");
	if(hModuleKernel32 == NULL)
		return false;

	PFCreateToolhelp32Snapshot pfCreateToolhelp32Snapshot = (PFCreateToolhelp32Snapshot)GetProcAddress(hModuleKernel32, "CreateToolhelp32Snapshot");
	if (pfCreateToolhelp32Snapshot == NULL)
		return false;
	
	PFProcess32First pfProcess32First = (PFProcess32First)GetProcAddress(hModuleKernel32, "Process32First");
	if (pfProcess32First == NULL)
		return false;

	PFProcess32Next pfProcess32Next = (PFProcess32Next)GetProcAddress(hModuleKernel32, "Process32Next");
	if (pfProcess32Next == NULL)
		return false;

	HANDLE hSnapshot = pfCreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if(hSnapshot == INVALID_HANDLE_VALUE)
		return false;

	PROCESSENTRY32 processEntry32;
	memset(&processEntry32, 0, sizeof(processEntry32));
	processEntry32.dwSize = sizeof(processEntry32);

	if(pfProcess32First(hSnapshot, &processEntry32))
	{
		MODULEENTRY32 moduleEntry32;
		memset(&moduleEntry32, 0, sizeof(moduleEntry32));
		moduleEntry32.dwSize = sizeof(moduleEntry32);

		int matchesFound = 0;
		
		do
		{
			if(LegacyFindModule(processEntry32.th32ProcessID, processEntry32.th32ModuleID, &moduleEntry32, sizeof(moduleEntry32)))
			{
				if(hasPathSeparator && _stricmp(szDescriptor, moduleEntry32.szExePath) == 0
					|| !hasPathSeparator && _stricmp(szDescriptor, moduleEntry32.szModule) == 0)
				{
					++matchesFound;
					if(matchesFound == 1 && pOutProcessHandle != nullptr)
						*pOutProcessHandle = OpenProcess(PROCESS_QUERY_INFORMATION, false, moduleEntry32.th32ProcessID);

					if(matchesFound >= minCount)
					{
						// @bug: possible leak - if the function returns true, the snapshot handle is never closed
						return true;
					}
				}
			}
		} while(pfProcess32Next(hSnapshot, &processEntry32));
	}

	CloseHandle(hSnapshot);
	return false;
}

bool Utils::WinAPI::FileExists(char* szPath)
{
	//@address: 0041fd80
	//@address: 00518bd0
	if(szPath == nullptr || szPath[0] == 0)
		return false;

	OFSTRUCT ofStruct;
	return(OpenFile(szPath, &ofStruct, OF_EXIST) != HFILE_ERROR);
}

char Utils::WinAPI::GetGruntzDriveLetter()
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
bool Utils::WinAPI::IsGruntzCDInAnyDrive()
{
	//@address: 0041fd60
	return(Utils::WinAPI::GetGruntzDriveLetter() != 0);
}

void Utils::WinAPI::LoadStringDefault(HINSTANCE hInstance, unsigned int idResource, char* szBuffer, unsigned int bufferSize, char* szDefault)
{
	//@address: none
	if(LoadStringA(hInstance, idResource, szBuffer, bufferSize) == 0)
		strcpy(szBuffer, szDefault);
}

void Utils::WinAPI::ActiveWait(unsigned int milliseconds)
{
	//@address: 0053e2c0
	unsigned int timeEnd = timeGetTime() + milliseconds;
	while(timeGetTime() < timeEnd);
}

void Utils::WinAPI::ShowCursorForce()
{
	//@address: none
	while(ShowCursor(TRUE) < 0);
}

void Utils::WinAPI::HideCursorForce()
{
	//@address: none
	while(ShowCursor(FALSE) >= 0);
}