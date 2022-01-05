/*
ViWindow.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This is the window class definition file.
*/
#include "ViWindow.h"
#include "ViKeys.h"
#include <cstring>
#include <stdio.h>


ViWindow* window = nullptr;
bool altDown = false;

ViWindow::ViWindow() {
	init();
}

ViWindow::~ViWindow() {
#ifdef _WIN32
	if(_hwnd) ::DestroyWindow(_hwnd);
#elif defined __linux__
	XDestroyWindow(_display, _window);
	XFree(_screen);
	XFlush(_display);
#endif
}

#ifdef _WIN32
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
	switch (msg) {
	case WM_CREATE:
		break;
	case WM_DESTROY:
		window->onDestroy();
		::PostQuitMessage(0);
		break;
	case WM_SYSKEYDOWN:
		altDown = true;
	case WM_KEYDOWN:
		if (altDown && wparam == VI_A_AZERTY) window->onDestroy();
		break;
	default:
		return ::DefWindowProc(hwnd, msg, wparam, lparam);
	}
	return 0;
}
#elif defined __linux__
void WndProc(XEvent event){
	switch (event.type){
	case KeyPress:
		if (altDown && event.xkey.keycode == VI_A_AZERTY) window->onDestroy();
		if (event.xkey.keycode == VI_ALT_AZERTY) altDown = true;
		break;
	case KeyRelease:
		if (event.xkey.keycode == VI_ALT_AZERTY) altDown = false;
	default:
		break;
	}
}
#endif

ViErrorType ViWindow::init() {
#ifdef _WIN32
	WNDCLASSEX wc;
	wc.cbClsExtra = 0;
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	wc.lpszClassName = L"Vision";
	wc.lpszMenuName = L"";
	wc.lpfnWndProc = WndProc;

	if(!::RegisterClassEx(&wc)) return VI_WINDOW_CREATION_FAILURE;
	
	_hwnd = ::CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, L"Vision", L"Vision", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 720, 480, nullptr, nullptr, nullptr, nullptr);

	if (!_hwnd) return VI_WINDOW_CREATION_FAILURE;
	//SetWindowLong(_hwnd, GWL_STYLE, 0);

	_label1.create(10, 10, 100, 50, {_hwnd});
	_label1.setText(L"Hello");

	::ShowWindow(_hwnd, SW_SHOW);
	::UpdateWindow(_hwnd);


#elif defined __linux__
	_display = XOpenDisplay(nullptr);

	if(!_display) return VI_WINDOW_CREATION_FAILURE;

	_screen = DefaultScreenOfDisplay(_display);
	_screenId = DefaultScreen(_display);

	/*Main window creation*/
	_window = XCreateSimpleWindow(_display, RootWindowOfScreen(_screen), 
		0, 0, 720, 480, 0, 
		BlackPixel(_display, _screenId), WhitePixel(_display, _screenId));
	
	XSelectInput(_display, _window, KeyPressMask|KeyReleaseMask|StructureNotifyMask|ExposureMask);
	

	/*Simple label creation*/
	_label1.create(10, 10, 100, 50, {_window, _display});
	
	XMapRaised(_display, _window);
	
#endif

	_active = true;
	if (!window) window = this;

	return VI_SUCCESS;
}

void ViWindow::proc() {
#ifdef _WIN32
	altDown = false;
	MSG message;
	while (::PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
		TranslateMessage(&message);
		DispatchMessageW(&message);
	}
#elif defined __linux__
	XNextEvent(_display, &_event);
	WndProc(_event);
	_label1.setText(L"Hello");
	
#endif
}

void ViWindow::onDestroy() {
	_active = false;
}

bool ViWindow::shouldClose() {
	return !_active;
}
