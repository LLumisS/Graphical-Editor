#pragma once
#include "shape.h"

class LineShape : virtual public Shape
{
public:
	LineShape(void);
	Shape* Construct();

	std::wstring getName();
	void Draw(HDC);
	void Gum(HDC);
};