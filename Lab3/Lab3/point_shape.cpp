#include "point_shape.h"
#include "framework.h"

PointShape::PointShape() {}

void PointShape::Show(HDC hdc)
{
	Rectangle(hdc, xend - 1, yend - 1, xend + 1, yend + 1);
}