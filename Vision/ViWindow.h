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
#elif defined __linux__
	#include <X11/Xlib.h>
	#include <unistd.h>
#endif

//todo : put that in a general header
#include "ViError.h"
#include "ViLabel.h"

class ViWindow {
private:
#ifdef _WIN32
	HWND _hwnd;
#elif defined __linux__
	Display* 	_display;
	Window		_window;
	GC			_windowGC, _labelGC;
	Screen*		_screen;
	int 		_screenId;
	XEvent		_event;
#endif
	ViLabel _label1;
	bool _active = false;
	ViErrorType init();
public:
	ViWindow();
	~ViWindow();

	void proc();
	bool shouldClose();
	void setText(std::wstring str);

	void onDestroy();
};

#endif