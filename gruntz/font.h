#ifndef __GRUNTZ_FONT__
#define __GRUNTZ_FONT__

#include <atlstr.h>

class Font
{
public:
	Font();
	~Font();

	void FreeMemory();
	bool LoadFont(CString szFileName);

private:
	bool AllocateMemory(int lettersCount);

	struct Size
	{
		int width;
		int height;
	};

	//size: (? perhaps 20 bytes?)
	//@offset: 0
	bool m_isMemoryAllocated;
	//@offset: 4
	int m_lettersCount;
	//@offset: 8
	char** m_pPixelData;
	//@offset: c
	Size* m_pLettersSize;
	//@offset: 10
	int m_fontHeight;
};

#endif