#pragma once
#include <Windows.h>
#define ARGB(a, r, g, b) D3DCOLOR_ARGB(a, r, g, b)
namespace Globals {
	HWND hWnd = NULL;
	uintptr_t modBase = NULL;
	HANDLE processID = NULL;
	int killKey = VK_END;
}

namespace MenuSettings {
	bool espEnabled = false;
	bool glowEnabled = false;
	bool ItemglowEnabled = false;
	bool noRecoilEnabled = false;
	bool aimbotEnabled = false;
	int aimbotSmoothness = 3;
	bool healthbarEnabled = false;
	bool fovCircle = false;
	int aimbotFOV = 300;
	bool snaplinesEnabled = false;
	bool thirdPerson = false;

	static int Tab = 0;

	int aimbotKeyID = 0;
	const char* aimbotKeys[3] = { "Right Mouse", "Left Alt", "Left Mouse" }; // https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
}