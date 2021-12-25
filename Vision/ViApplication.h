/*
ViApplication.h
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file is the base template for the program execution.
*/

#ifndef VI_APPLICATION
#define VI_APPLICATION

#include "ViWindow.h"

class ViApplication {
	ViWindow* _window;
public:
	void startup();
	void runtime();
	void shutdown();
};

#endif