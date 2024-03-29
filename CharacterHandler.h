#pragma once
#ifndef CHARACTER_HANDLER_H
#define CHARACTER_HANDLER_H


#include <Windows.h>
#include <map>
#include <unordered_map>
#include <string>

class CharacterHandler
{
	static std::map<char, std::string> specialChars;
	static void initSpecialChars()
	{
		char chars[] = {VK_LBUTTON, VK_RBUTTON, VK_CANCEL, VK_MBUTTON, VK_BACK, VK_TAB, VK_CLEAR,
						VK_RETURN, VK_SHIFT, VK_CONTROL, VK_MENU, VK_PAUSE, VK_CAPITAL, VK_ESCAPE,
						VK_SPACE, VK_PRIOR, VK_NEXT, VK_END, VK_HOME, VK_LEFT, VK_UP, VK_RIGHT,
						VK_DOWN, VK_SELECT, VK_PRINT, VK_EXECUTE, VK_SNAPSHOT, VK_INSERT, VK_DELETE,
						VK_HELP, VK_LWIN, VK_RWIN, VK_APPS, VK_SLEEP, VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2,
						VK_NUMPAD3, VK_NUMPAD4, VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9,
						VK_MULTIPLY, VK_ADD, VK_SEPARATOR, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE,
						VK_F1, VK_F2, VK_F3, VK_F4, VK_F5, VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12,
						VK_F13, VK_F14, VK_F15, VK_F16, VK_F17, VK_F18, VK_F19, VK_F20, VK_F21, VK_F22, VK_F23,
						VK_F24};
	}
};

#endif