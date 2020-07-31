#pragma warning(disable : 4996) // using deprecated CRT functions

#include "registry_helper.h"
#include "../gruntz/globals.h"

Utils::RegistryHelper::RegistryHelper(): m_isInitialized(false)
{
}

bool Utils::RegistryHelper::Open(char* szKeyName1, char* szKeyName2, char* szKeyName3, char* szKeyName4, HKEY hKey, char* szSubKey)
{
	//@address: 00539420
	//@bug: no string length check
	strcpy(m_szParam2, szKeyName2);

	//@bug: no string length check
	if(szKeyName4 != nullptr)
		strcpy(m_szParam4, szKeyName4);
	else
		m_szParam4[0] = 0;

	m_hKey = hKey;

	char szSoftware[] = "Software";

	if( szSubKey == nullptr )
		szSubKey = szSoftware;

	if( !GetRegistryKey(hKey, szSubKey, &m_hKey2) 
		|| !GetRegistryKey(m_hKey2, szKeyName1, &m_hKey3)
		|| !GetRegistryKey(m_hKey3, szKeyName2, &m_hKey4)
		|| !GetRegistryKey(m_hKey4, szKeyName3, &m_hKey5) )
		return false;

	m_isInitialized = true;
	
	if( !InitializeLastKey(szKeyName4) )
	{
		//@bug: previous keys might not be closed
		m_isInitialized = false;
		return false;
	}

	return true;
}

Utils::RegistryHelper::~RegistryHelper()
{
	Close();
}

void Utils::RegistryHelper::Close()
{
	//@address: 00539540
	//@bug: previously opened keys might not be closed
	if(!m_isInitialized)
		return;

	m_isInitialized = false;

	RegCloseKey(m_hKey2);
	RegCloseKey(m_hKey3);
	RegCloseKey(m_hKey4);

	if(m_hKey5 != m_hKey6)
		RegCloseKey(m_hKey5);

	RegCloseKey(m_hKey6);
}

bool Utils::RegistryHelper::InitializeLastKey(char* szLastKey)
{
	//@address: 00539580
	if(!m_isInitialized)
		return false;

	if(szLastKey == nullptr)
	{
		// copies the last key handle
		m_hKey6 = m_hKey5;
		return true;
	}

	return GetRegistryKey(m_hKey5, szLastKey, &m_hKey6);
}

// opens or creates a registry subkey
bool Utils::RegistryHelper::GetRegistryKey(HKEY hKey, char* szSubKey, PHKEY phKeyResult)
{
	//@address: 00539860
	return RegCreateKeyExA(hKey, szSubKey, 0, Globals::perhaps_an_empty_string, 0, KEY_ALL_ACCESS, 0, phKeyResult, NULL) == ERROR_SUCCESS;
}

char* Utils::RegistryHelper::GetValueString(char* szValueName, char* szValueBuffer, unsigned int* pValueBufferSize, char* szDefault)
{
	//@address: 005396b0
	DWORD valueType;

	if(m_isInitialized
		&& szValueName != nullptr
		&& szValueBuffer != nullptr
		&& *pValueBufferSize > 0
		&& RegQueryValueExA(m_hKey6, szValueName, 0, &valueType, (LPBYTE)szValueBuffer, (LPDWORD)pValueBufferSize) == ERROR_SUCCESS
		&& valueType == REG_SZ)
	{
		return szValueBuffer;
	}

	if(szDefault == nullptr)
	{
		*pValueBufferSize = 0;
		return nullptr;
	}

	//@bug: no buffer length check
	strcpy(szValueBuffer, szDefault);
	*pValueBufferSize = strlen(szDefault);
	return szValueBuffer;
}

DWORD Utils::RegistryHelper::GetValueDword(char* szValueName, DWORD valueDefault)
{
	//@address: 005397e0
	DWORD valueType;
	DWORD valueBuffer;
	DWORD valueBufferSize = sizeof(valueBuffer);

	if(!m_isInitialized
		|| szValueName == nullptr
		|| RegQueryValueExA(m_hKey6, szValueName, 0, &valueType, (LPBYTE)&valueBuffer, &valueBufferSize) != ERROR_SUCCESS
		|| valueType != REG_DWORD)
	{
		return valueDefault;
	}

	return valueBuffer;
}

bool Utils::RegistryHelper::SetValueDword(char* szValueName, DWORD value)
{
	if(!m_isInitialized || szValueName == nullptr)
		return false;

	return(RegSetValueExA(m_hKey6, szValueName, 0, REG_DWORD, (const BYTE*)&value, sizeof(value)) == ERROR_SUCCESS);
}