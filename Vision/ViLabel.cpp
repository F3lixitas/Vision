/*
ViLabel.cpp
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file defines the label class, a simple text container.
*/

#include "ViLabel.h"
#include <cstring>

void ViLabel::setText(std::wstring text) {
#ifdef _WIN32
	SetWindowText(_widget.window, text.data());
#elif defined __linux__
	XFontStruct* font = XLoadQueryFont(_display, "fixed");
	XSetFont(_display, _labelGC, font->fid);

	XwcDrawString(_display,
		_widget.display,
		_widget.gc,
		0,
		10,
		text.data(), text.length());
#endif
}
