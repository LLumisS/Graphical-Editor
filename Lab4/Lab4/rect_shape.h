#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
public:
	RectShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};