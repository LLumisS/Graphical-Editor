#pragma once
#include "shape.h"

class RectShape : virtual public Shape
{
public:
	RectShape(void);
	Shape* Construct();

	std::wstring getName();
	void Draw(HDC);
	void Gum(HDC);
};