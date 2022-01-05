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

void ViLabel::create(int x, int y, int width, int height, WindowHandler parent){
	ViWidget::create(x, y, width, height, parent);

#ifdef __linux__
	_widget.gc =  XCreateGC(_widget.display, _widget.window, 0, nullptr);
#endif
}

void ViLabel::setText(std::wstring text) {
#ifdef _WIN32
	SetWindowText(_widget.window, text.data());
#elif defined __linux__
	XFontStruct* font = XLoadQueryFont(_widget.display, "fixed");
	XSetFont(_widget.display, _widget.gc, font->fid);

	XChar2b* a = new XChar2b[text.length()];
	memcpy(a, text.data(), text.length());

	XTextItem16 text16 = {a, text.length(), 0};

	/*char* name = "fixed";
	char* fontName = (char *)malloc(strlen("fixed") + 3);
	memccpy(fontName, name, 0, strlen(name));
	char **missingChars;
	int missingCharsCount;
	char *stringReturn;
	XFontSet fontSet = XCreateFontSet(_widget.display, fontName, &missingChars, &missingCharsCount, &stringReturn);*/

	XDrawText16(_widget.display, _widget.window, _widget.gc, 0, 10, &text16, text.length());

	delete[] a;

	/*XwcDrawString(_widget.display,
		_widget.window,
		fontSet,
		_widget.gc,
		0,
		10,
		text.data(), text.length());*/
#endif
}
