#pragma once
#include "shape.h"

class EllipseShape : virtual public Shape
{
public:
	EllipseShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};