#ifndef __UTILS_WINAPI__
#define __UTILS_WINAPI__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

namespace Utils
{
	namespace WinAPI
	{
		// returns true if there are at least minCount running processes with the given descriptor
		// the descriptor may be either an executable name or path
		// if the process handle pointer is not null, it is filled with the handle to the first matching process
		//
		// @legacy: it's a legacy method which will not work for newer Windows operating systems
		// the reason is it's based on the field th32ModuleID of PROCESSENTRY32 and MODULEENTRY32 structures
		// which are currently deprecated and are always filled with values 0 and 1 correspondingly
		// and as such it will always return FALSE.
		bool LegacyAreProcessesRunning(char* szDescriptor, int minCount, HANDLE* pOutProcessHandle);

		// checks if a file with the given path exists
		bool FileExists(char* szPath);

		// returns the letter of the CDROM drive with Gruntz CD or 0 if not found
		char GetGruntzDriveLetter();

		// tests if Gruntz CD is in any CDROM drive
		bool IsGruntzCDInAnyDrive();

		// loads the string from the resources
		// if it fails, the szDefault string is used instead
		void LoadStringDefault(HINSTANCE hInstance, unsigned int idResource, char* szBuffer, unsigned int bufferSize, char* szDefault);

		// queries the system time until the given time elapses
		void ActiveWait(unsigned int milliseconds);

		// increments the display count until the cursor is shown
		void ShowCursorForce();

		// decrements the display count until the cursor is hidden
		void HideCursorForce();
	}
}

#endif