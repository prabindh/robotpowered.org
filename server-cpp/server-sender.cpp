// wiolink-server.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

static httplib::Server svr;

void pressSpace()
{
	INPUT ip;
	std::vector<INPUT> ips;

	ip.type = INPUT_KEYBOARD;
	ip.ki.time = 0;
	ip.ki.dwFlags = 0;
	ip.ki.wScan = 0; 
	ip.ki.dwExtraInfo = 0;

	ip.ki.wVk = VK_SPACE;

	ips.push_back(ip);
	// Release the key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	ips.push_back(ip);

	SendInput(ips.size(), &ips[0], sizeof(INPUT));
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
