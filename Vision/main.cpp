/*
main.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This is the entry point of the application. It shouldn't contain anything 
more than the main function and the Visual application header file.
*/

#include "ViApplication.h"

int main() {
	ViApplication app;
	app.startup();
	app.runtime();
	app.shutdown();
	return 0;
}