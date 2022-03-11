/*
ViWidget.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file defines the widget abstract class.
*/

#include "ViWidget.h"

void ViWidget::create(int x, int y, int width, int height, WindowHandler parent) {
#ifdef _WIN32
	_widget.window = CreateWindow(L"static", L"ST_U",
		WS_CHILD | WS_VISIBLE | WS_TABSTOP,
		x, y, width, height,
		parent.window, nullptr,
		(HINSTANCE)GetWindowLong(parent.window, GWLP_HINSTANCE), NULL);
#elif defined __linux__
	_widget.display = parent.display;
	int screenId = DefaultScreen(parent.display);
	_widget.window = XCreateSimpleWindow(parent.display, parent.window,
		x, y, width, height, 1,
		BlackPixel(parent.display, screenId), WhitePixel(parent.display, screenId));
	XSelectInput(_widget.display, _widget.window, KeyPressMask | KeyReleaseMask | StructureNotifyMask | ExposureMask);
	XMapWindow(_widget.display, _widget.window);
#endif
	_X = x;
	_Y = y;
	_width = width;
	_height = height;
}

void ViWidget::show(bool t) {
#ifdef _WIN32
	if(t)
		::ShowWindow(_widget.window, SW_SHOW);
	else
		::ShowWindow(_widget.window, SW_HIDE);
#elif defined __linux__
	
#endif
}

void ViWidget::clear(){
#ifdef _WIN32
	
#elif defined __linux__
	XClearWindow(_widget.display, _widget.window);
#endif
}

ViWidget::~ViWidget(){
#ifdef __linux__
	XDestroyWindow(_widget.display, _widget.window);
#endif
}
