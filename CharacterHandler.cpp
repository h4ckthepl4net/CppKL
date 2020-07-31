#include "CharacterHandler.h"

std::map<unsigned char, Character*> CharacterHandler::specialChars;

static unsigned char keys[] = { VK_LBUTTON, VK_RBUTTON, VK_CANCEL, VK_MBUTTON, VK_BACK, VK_TAB, VK_CLEAR,
						VK_RETURN, VK_SHIFT, VK_CONTROL, VK_MENU, VK_PAUSE, VK_CAPITAL, VK_ESCAPE,
						VK_PRIOR, VK_NEXT, VK_END, VK_HOME, VK_LEFT, VK_UP, VK_RIGHT, VK_DOWN, VK_SELECT,
						VK_PRINT, VK_EXECUTE, VK_SNAPSHOT, VK_INSERT, VK_DELETE, VK_HELP, VK_LWIN, VK_RWIN,
						VK_APPS, VK_SLEEP, VK_NUMPAD0, VK_NUMPAD1, VK_NUMPAD2, VK_NUMPAD3, VK_NUMPAD4,
						VK_NUMPAD5, VK_NUMPAD6, VK_NUMPAD7, VK_NUMPAD8, VK_NUMPAD9,	VK_MULTIPLY, VK_ADD,
						VK_SEPARATOR, VK_SUBTRACT, VK_DECIMAL, VK_DIVIDE, VK_F1, VK_F2, VK_F3, VK_F4, VK_F5,
						VK_F6, VK_F7, VK_F8, VK_F9, VK_F10, VK_F11, VK_F12,	VK_F13, VK_F14, VK_F15, VK_F16,
						VK_F17, VK_F18, VK_F19, VK_F20, VK_F21, VK_F22, VK_F23,	VK_F24, VK_NUMLOCK, VK_SCROLL,
						VK_LSHIFT, VK_RSHIFT, VK_LCONTROL, VK_RCONTROL};
static const char* keyText[] = {"left click", "right click", "^C", "middle click", "backspace", "tab", "clear",
						"enter", "shift", "ctrl", "alt", "pause", "caps lock", "esc", "page up",
						"page down", "end", "home", "<-", "^", "->", "v", "select", "print", "execute",
						"print screen", "insert", "delete",	"help", "left Windows", "right Windows",
						"apps", "sleep", "0", "1", "2",	"3", "4", "5", "6", "7", "8", "9", "*", "+",
						".", "-", ".", "/", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10",
						"F11", "F12", "F13", "F14", "F15", "F16", "F17", "F18", "F19", "F20", "F21", "F22",
						"F23", "F24", "num lock", "scroll lock", "left shift", "right shift", "left ctrl",
						"right ctrl" };


void CharacterHandler::initSpecialChars()
{
	for (unsigned int i = 0; i < sizeof(keys); i++)
	{
		specialChars.emplace(std::make_pair(keys[i], new Character(keys[i], keyText[i])));
	}
}

Character* CharacterHandler::getCharacterByKeyCode(unsigned char keyCode)
{
	Character* ptr;
	try
	{
		ptr = specialChars.at(keyCode);
	}
	catch(std::out_of_range&)
	{
		ptr = nullptr;
	}
	return ptr;
}

