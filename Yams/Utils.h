#pragma once

#include <Windows.h>
#include <string>

namespace Utils
{
	void FatalError(const wchar_t* msg)
	{
		MessageBox(NULL, msg, TEXT("Fatal Error !"), MB_OK | MB_ICONERROR);
		exit(-1);
	}
}
