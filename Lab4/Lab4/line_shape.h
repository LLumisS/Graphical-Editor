#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
	LineShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};