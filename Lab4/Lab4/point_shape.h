#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
	PointShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};