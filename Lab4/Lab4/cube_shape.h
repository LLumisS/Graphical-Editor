#pragma once
#include "line_shape.h"
#include "rect_shape.h"

class CubeShape : public LineShape, public RectShape
{
public:
	CubeShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};