/*
main.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This is the entry point of the application. It shouldn't contain anything 
more than the main function and the Visual header file.
*/

#include "ViWindow.h"


int main() {
	
	ViWindow win;

	while (!win.shouldClose()) {
		win.proc();
//todo create a global sleep method
#ifdef _WIN32
		Sleep(1);
#endif
	}
	
	
	return 0;
}