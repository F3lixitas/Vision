/*
ViApplication.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file defines what happens on program execution.
*/

#include "ViApplication.h"

void ViApplication::startup() {
	_window = new ViWindow;
}

void ViApplication::runtime() {
	if (!_window) return;
	while (!_window->shouldClose()) {
		_window->proc();
	}
}

void ViApplication::shutdown() {
	if (!_window) return;
	delete _window;
}