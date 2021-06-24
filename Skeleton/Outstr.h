#pragma once
#include <wchar.h>
#include <string>
class Outstr
{
public:
	static void out(const char* str);
	static void out(const wchar_t* str);
	static void out(const std::string& str);
	static void out(const std::wstring& str);
	static void outLine(const char* str);
	static void outLine(const wchar_t* str);
	static void outLine(const std::string& str);
	static void outLine(const std::wstring& str);

};

