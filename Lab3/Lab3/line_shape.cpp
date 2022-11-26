#include "line_shape.h"

LineShape::LineShape() {}

void LineShape::Show(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}