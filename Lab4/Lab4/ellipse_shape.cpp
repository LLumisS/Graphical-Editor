#include "ellipse_shape.h"

EllipseShape::EllipseShape() {}

Shape* EllipseShape::Construct()
{
	return new EllipseShape;
}

void EllipseShape::Show(HDC hdc)
{
	Ellipse(hdc, xstart * 2 - xend, ystart * 2 - yend, xend, yend);
}

void EllipseShape::Gum(HDC hdc)
{
	Show(hdc);
}