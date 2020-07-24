#pragma once
#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

class Character
{
	unsigned int charCode;
	std::string charTxt;
public:
	Character(unsigned int, const char* = nullptr);
	bool operator==(Character&) const;
	operator char const* () const;
};

#endif
