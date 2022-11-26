#pragma once
#include "shape.h"

class EllipseShape : virtual public Shape
{
public:
	EllipseShape(void);
	Shape* Construct();

	std::wstring getName();
	void Draw(HDC);
	void Gum(HDC);
};