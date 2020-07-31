#include "Utils.h"

bool utils::is_alpha_num_key(unsigned char key)
{
	constexpr auto VK_0 = 0x30, VK_9 = 0x39, VK_A = 0x41, VK_Z = 0x5A;
	return key >= VK_0 && key <= VK_9 || key >= VK_A && key <= VK_Z;
}

bool utils::is_modifier_key(unsigned char)
{
	return false;
}
