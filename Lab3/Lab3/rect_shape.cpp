#include "rect_shape.h"

RectShape::RectShape() {}

void RectShape::Show(HDC hdc)
{
	HBRUSH hBrush = (HBRUSH)CreateSolidBrush(RGB(255, 255, 0));
	HBRUSH hBrushOld = (HBRUSH)SelectObject(hdc, hBrush);

	Rectangle(hdc, xstart, ystart, xend, yend);

	SelectObject(hdc, hBrushOld);
	DeleteObject(hBrush);
}