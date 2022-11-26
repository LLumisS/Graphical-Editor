#include "cube_shape.h"

CubeShape::CubeShape(void) {}

Shape* CubeShape::Construct()
{
	return new CubeShape;
}

void CubeShape::Show(HDC hdc)
{
	long x1 = xstart, y1 = ystart, x2 = xend, y2 = yend;
	long xd = (x2 - x1) / 3, yd = (y2 - y1) / 3;

	Set(x1, y1, x2 - xd, y2 - yd);
	RectShape::Gum(hdc);

	Set(x1 + xd, y1 + yd, x2, y2);
	RectShape::Gum(hdc);

	Set(x1, y1, x1 + xd, y1 + yd);
	LineShape::Show(hdc);

	Set(x2, y2, x2 - xd, y2 - yd);
	LineShape::Show(hdc);

	Set(x1, y2 - yd, x1 + xd, y2);
	LineShape::Show(hdc);

	Set(x2 - xd, y1, x2, y1 + yd);
	LineShape::Show(hdc);

	Set(x1, y1, x2, y2);
}

void CubeShape::Gum(HDC hdc)
{
	Show(hdc);
}