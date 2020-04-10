// Prabindh Sundareson 2020
// Age of the lockdown

#include "pch.h"
#include <iostream>

static httplib::Server svr;

void pressSpace()
{
	INPUT ip;
	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwFlags = 0;
	ip.ki.wScan = 0; 
	
	ip.ki.wVk = VK_SPACE;

	ip.ki.dwExtraInfo = 0;
	SendInput(1, &ip, sizeof(INPUT));

	// Release the key
	ip.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &ip, sizeof(INPUT));
}

int main()
{
    std::cout << "Hello World!\n"; 
	svr.Post("/", [&](const auto& req, auto& res) {
		pressSpace();
		std::cout << "Received\n";
		});
	svr.listen("10.41.2.37", 8000);
}
