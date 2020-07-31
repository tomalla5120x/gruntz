#include <new>

#include <afx.h>
#include "font.h"

Font::Font()
{
	//@address: 005799e0
	m_isMemoryAllocated = false;
	m_lettersCount = 0;
	m_pPixelData = nullptr;
	m_pLettersSize = nullptr;
}

Font::~Font()
{
	//@address: inlined
	FreeMemory();
}

void Font::FreeMemory()
{
	//@address: 00579a90
	if(!m_isMemoryAllocated)
		return;

	if(m_lettersCount > 0)
	{
		for(unsigned int i = 0; i < m_lettersCount; ++i)
		{
			delete[] m_pPixelData[i];
			m_pPixelData[i] = nullptr;
		}
	}

	delete[] m_pPixelData;
	m_pPixelData = nullptr;

	if(m_pLettersSize != nullptr)
	{
		delete[] m_pLettersSize;
		m_pLettersSize = nullptr;
	}

	m_lettersCount = 0;
	m_isMemoryAllocated = false;
}

bool Font::LoadFont(CString szFileName)
{
	//@address: 00579b10
	FreeMemory();

	/*

	Font file specification (little endian):

	struct Font
	{
		// 0x0
		uint32_t lettersCount;
		// 0x4
		Letter letters[lettersCount];
	}

	struct Letter
	{
		// 0x0
		uint32_t width;
		// 0x4
		uint32_t height;
		// 0x8
		uint8_t pixelData[width*height];
	}

	*/
	
	CFile fileFont;

	if(!fileFont.Open(szFileName, CFile::modeRead, nullptr))
		return false;

	CArchive archive(&fileFont, CArchive::load);

	//@bug: the >> operator may throw, which will cause the application to crash
	archive >> m_lettersCount;
	AllocateMemory(m_lettersCount);

	if(m_lettersCount > 0)
	{
		for(unsigned int i = 0; i < m_lettersCount; ++i)
		{
			//@bug: no checks of how much data was actually read
			archive.Read(&m_pLettersSize[i], sizeof(Size));

			m_pPixelData[i] = new char[m_pLettersSize[i].width * m_pLettersSize[i].height];
			archive.Read(m_pPixelData[i], m_pLettersSize[i].width * m_pLettersSize[i].height);
		}
	}
	
	archive.Close();
	fileFont.Close();

	int maxHeight = 0;

	if(m_lettersCount > 0)
	{
		for(unsigned int i = 0; i < m_lettersCount; ++i)
			if(m_pLettersSize[i].height > maxHeight)
				maxHeight = m_pLettersSize[i].height;
	}

	m_fontHeight = maxHeight;
	return true;
}

bool Font::AllocateMemory(int lettersCount)
{
	//@address: 00579a00
	FreeMemory();
	m_lettersCount = lettersCount;

	if(m_lettersCount < 1)
		return false;

	m_pPixelData = new char*[m_lettersCount];
	m_pLettersSize = new Size[m_lettersCount];

	//@bug: the check will always evaluate to true
	if(m_pLettersSize != nullptr)
	{
		//@note: doesn't seem to be used anywhere later
		lettersCount = m_lettersCount - 1;
	}

	if(m_lettersCount > 0)
	{
		for(unsigned int i = 0; i < m_lettersCount ; ++i)
		{
			m_pPixelData[i] = nullptr;
			m_pLettersSize[i].width = 0;
			m_pLettersSize[i].height = 0;
		}
	}

	m_fontHeight = 0;
	m_isMemoryAllocated = true;

	return true;
}