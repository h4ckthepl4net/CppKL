#pragma once
#ifndef CHARACTER_HANDLER_H
#define CHARACTER_HANDLER_H

#include <Windows.h>
#include <stdexcept>
#include <map>
#include "Character.h"

class CharacterHandler
{
	static std::map<unsigned char, Character*> specialChars;
public:
	static void initSpecialChars();
	static Character* getCharacterByKeyCode(unsigned char);
};

#endif