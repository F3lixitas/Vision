/*
ViLabel.h
---------------------------------------------------------------------------
(c) Felix Riedel aka F3lixitas, 2021
This file is not to be used or modified without the author's permission.
To get permission, contact at felixriedel24@gmail.com
---------------------------------------------------------------------------
This file declares the label class, a simple text container.
*/

#ifndef VI_LABEL
#define VI_LABEL

#include "ViWidget.h"
#include <string>

class ViLabel : public ViWidget {

public:
	void create(int x, int y, int width, int height, WindowHandler parent);
	void setText(std::wstring text);
};


#endif