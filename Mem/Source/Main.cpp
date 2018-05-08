#include "Main.h"

void PrintMainMenu();
void PrintTestMenu();

void RunTest();

int main()
{
#ifdef _MemTest
	// MemStartUp(4, 10);
#endif // _MemTest

	//MyGLFW* window = new MyGLFW("Mem");
	//MyImGUI* gui = new MyImGUI();
	//gui->Init(window, true);
	//gui->ShowWindow(true);

	//MemoryEditor mem_edit;
	//const int size = 100;
	//unsigned char* data = new unsigned char[size];
	//do
	//{
	//	window->CheckInput();
	//	gui->NewFrame();
	//	window->Clear();
	//	//gui->Draw();
	//	// ImGui::ShowTestWindow();
	//	mem_edit.DrawWindow("Mem", data, size);
	//	gui->Draw();
	//	ImGui::Render();
	//	window->SwapBuffers();
	//} while (!window->CloseRequested());


    //-----------------------
    /* Sample Game Memory Uses */
    // Resource manager Test_RunCase(0);


    // Scene Swaps


    // 1 frame allocations
    // - strings

    //-----------------------

    RunTest(); // temporary

    int userChoice = -1;
    do
    {
		system("cls");
        PrintMainMenu();

		std::cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			RunTest();
			break;
		}

	} while (userChoice); // quit?

    // TODO: cleanup
	// delete gui; // TODO: Fix hang after return from ~MyImGUI()
	// delete window;
	return 0;
}

void PrintMainMenu()
{
   std::cout << "--Main Menu--" << std::endl;
   std::cout << "1. Test case" << std::endl;
   std::cout << "2. Change values" << std::endl;
   std::cout << "0. Quit" << std::endl;
}

void PrintTestMenu()
{
   std::cout << "--Testing--" << std::endl;
   std::cout << "1. Test case" << std::endl;
   std::cout << "2. Reset" << std::endl;
   std::cout << "3. Clear Screen" << std::endl;
   std::cout << "0. Back" << std::endl;
}

void RunTest()
{
	int test = 0;
	do
	{
		PrintTestMenu();

		std::cin >> test;
        switch (test)
        {
        case 1:
           std::cout << "Which Case? " << std::endl;
		   std::cin >> test;
            Test_RunCase(test);
            break;
        case 2: Test_Reset(); break;
        case 3: system("cls"); break;
        }
	} while (test);
}