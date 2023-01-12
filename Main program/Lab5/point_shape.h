#pragma once
#include "shape.h"

class PointShape : virtual public Shape
{
public:
	PointShape(void);
	Shape* Construct();

	std::wstring getName();
	void Draw(HDC);
	void Gum(HDC);
};