#ifndef __COMMON__
#define __COMMON__

#pragma warning(disable : 4996) // using deprecated CRT functions

#undef UNICODE
#undef _UNICODE
#include <afxwin.h>

#include "gruntz/globals.h"

#include <stdexcept>
class NotImplemented: public std::logic_error
{
public:
	NotImplemented(): std::logic_error("Function not yet implemented") { };
};

#endif