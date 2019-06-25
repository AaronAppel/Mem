#include "Main.h"

#include <bitset>

void PrintMainMenu();
void PrintTestMenu();

void RunTest();

void TempShiftReference() // For reference
{
	unsigned char a = 5, b = 9; // a = 5(00000101), b = 9(00001001)
	printf("a = %d, b = %d\n", a, b);
	printf("a&b = %d\n", a&b); // The result is 00000001
	printf("a|b = %d\n", a | b);  // The result is 00001101
	printf("a^b = %d\n", a^b); // The result is 00001100
	printf("~a = %d\n", a = ~a);   // The result is 11111010
	printf("b<<1 = %d\n", b << 1);  // The result is 00010010
	printf("b>>1 = %d\n", b >> 1);  // The result is 00000100

	//
	unsigned char c = 1;
	printf("c = %d\n", c);
	c |= 00000001;
	printf("c = %d\n", c);
}

void Loop()
{
	// Toggle at location
	unsigned char block = 0;
	int userChoice = -1;
	do
	{
		std::cin >> userChoice;
		block ^= 1 << userChoice;

		std::cout << std::bitset<8>(block) << std::endl;

		if (block > 254)
		{
			std::cout << "block is full" << std::endl;
		}

	} while (userChoice < 8); // quit?
}

int main()
{
	Loop();

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
   std::cout << "\n--Testing--" << std::endl;
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