#pragma once
#ifndef LOOP_KEY_LOGGER_H
#define LOOP_KEY_LOGGER_H

#include <Windows.h>
#include <ostream>
#include "CharacterHandler.h"
#include "Character.h"
#include "Utils.h"

namespace loopKeyLogger {
	void log(std::ostream&);
}

#endif