/*
ViWindow.h
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This is the window class prototype file.
*/


#ifndef VI_WINDOW
#define VI_WINDOW

#ifdef _WIN32
	#include <Windows.h>
#endif

//todo : put that in a general header
#include "ViError.h"

class ViWindow {
private:
#ifdef _WIN32
	HWND _hwnd, _label;
#endif

	bool _active = false;
	ViErrorType init();
public:
	ViWindow();
	~ViWindow();

	void proc();
	bool shouldClose();

	void onDestroy();
	void setText(LPCWSTR text);
};

#endif