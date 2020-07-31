#ifndef __UTILS_REGISTRY_WRAPPER__
#define __UTILS_REGISTRY_WRAPPER__

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

namespace Utils
{
	class RegistryHelper
	{
	public:
		__declspec(noinline)  RegistryHelper();
		~RegistryHelper();

		// opens the series of registry keys to form a path:
		// hKey -> szSubKey (optional, "Software" by defaul) -> szKeyName1 -> szKeyName2 -> szKeyName3 -> szKeyName4 (optional)
		bool Open(char* szKeyName1, char* szKeyName2, char* szKeyName3, char* szKeyName4, HKEY hKey, char* szSubKey);

		// closes all opened keys
		void Close();

		// gets the string value and saves it in the buffer
		// pValueBufferSize contains the initial buffer size and is updated to the actual value size upon return
		// returns the pointer to the value buffer or nullptr
		char* GetValueString(char* szValueName, char* szValueBuffer, unsigned int* pValueBufferSize, char* szDefault = nullptr);
		DWORD GetValueDword(char* szValueName, DWORD valueDefault);
		bool SetValueDword(char* szValueName, DWORD value);

	private:
		bool InitializeLastKey(char* szLastKey);
		bool GetRegistryKey(HKEY hKey, char* szSubKey, PHKEY phKeyResult);

		//@ofset: 0
		bool m_isInitialized;

		//@offset: 4
		HKEY m_hKey;
		//@offset: 8
		HKEY m_hKey2;
		//@offset: C
		HKEY m_hKey3;
		//@offset: 10
		HKEY m_hKey4;
		//@offset: 14
		HKEY m_hKey5;
		//@offset: 18
		HKEY m_hKey6;

		//@offset: 1C
		char m_szParam2[256];

		//@offset: 11C
		char m_szParam4[256];
	};
}

#endif