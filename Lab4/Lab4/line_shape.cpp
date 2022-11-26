#include "line_shape.h"

LineShape::LineShape() {}

Shape* LineShape::Construct()
{
	return new LineShape;
}

void LineShape::Show(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}

void LineShape::Gum(HDC hdc)
{
	Show(hdc);
}