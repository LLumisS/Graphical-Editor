#include "ellipse_shape.h"

EllipseShape::EllipseShape() {}

void EllipseShape::Show(HDC hdc)
{
	Ellipse(hdc, xstart * 2 - xend, ystart * 2 - yend, xend, yend);
}