#include "Character.h"

Character::Character(unsigned int charCode, const char* charTxt) : charCode(charCode) {
	if(!charTxt) {
		this->charTxt += static_cast<char>(charCode);
	} else
	{
		this->charTxt += "**";
		this->charTxt += charTxt;
		this->charTxt += "**";
	}
}
bool Character::operator==(Character& right) const {
	return this->charCode == right.charCode;
}
Character::operator char const* () const {
	return this->charTxt.c_str();
}