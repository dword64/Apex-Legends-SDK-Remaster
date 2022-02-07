#include "../Utilities/includes.h"
#include "../Utilities/utils.h"
#include "../SDK/Entity/BaseEntity.h"
#include "../SDK/Overlay/Rendering/Overlay.h"

//Public Release

void mainThread();

int main()
{
	FreeConsole();

	system("mapper.exe Driver.sys");

	MessageBoxA(NULL, "Start Apex please! Loader will close after injection", "Start Apex please! Loader will close after injection", NULL);

	//Initialization
	while (!Globals::hWnd)
		Globals::hWnd = FindWindow(NULL, L"Apex Legends");
		
	while (!Globals::processID)
		Globals::processID = Driver::get_process_id("r5apex.exe");
	
	while (!Globals::modBase)
		Globals::modBase = Driver::GetModuleBase(Globals::processID, "r5apex.exe");

	if (Globals::processID) {
		// create window
		if (!overlay::InitWindow())
		{
			Sleep(5000);
			return 0;
		}

		if (!overlay::DirectXInit())
		{
			Sleep(5000);
			return 0;
		}
	}

	//Main Thread
	std::thread main(mainThread);

	main.join(); //Start Main Thread


	//Kill Key
	if (GetAsyncKeyState(Globals::killKey))
	{
		for (int i = 0; i < 16000; i++)
		{
			BaseEntity pEntity(i);
			pEntity.Glow(0.f, 0.f, 0.f); //Turning off glow
		}

		overlay::DirectXShutdown();

		std::exit(0);
	}
}

void mainThread()
{
	while (!GetAsyncKeyState(Globals::killKey))
	{
		overlay::Render();
	}
}