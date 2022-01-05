/*
ViWidget.h
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file declares the widget abstract class.
*/

#ifndef VI_WIDGET
#define VI_WIDGET

#ifdef _WIN32
	#include <Windows.h>
#elif defined __linux__
	#include <X11/Xlib.h>
#endif

typedef struct WindowHandler {
#ifdef _WIN32
	HWND window;
#elif defined __linux__
	Window		window;
	Display*	display;
	GC			gc;
#endif
}WindowHandler;

class ViWidget {
protected:
	int _X, _Y, _width, _height;
	WindowHandler _widget;
public:
	virtual void create(int x, int y, int width, int height, WindowHandler parent);
	void show(bool t);

	~ViWidget();
};

#endif