#include "Utils.h"

bool utils::isKeyAlphaNum(unsigned char key)
{
	return key >= 0x30 && key <= 0x39 || key >= 0x41 && key <= 0x5a;
}