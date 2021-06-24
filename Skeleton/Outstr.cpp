#include "Outstr.h"
#include <sstream>
#include <debugapi.h>
void Outstr::out(const char* str)
{
	OutputDebugStringA(str);
}

void Outstr::out(const wchar_t* str)
{
	OutputDebugStringA(str);
}

void Outstr::out(const std::string& str)
{
	OutputDebugStringA(str);
}

void Outstr::out(const std::wstring& str)
{
	OutputDebugStringA(str);
}

void Outstr::outLine(const char* str)
{
	std::ostringstream oss;
	oss << str;
	out.str();
}

void Outstr::outLine(const wchar_t* str)
{
}

void Outstr::outLine(const std::string& str)
{
}

void Outstr::outLine(const std::wstring& str)
{
}
