#include "point_shape.h"
#include "framework.h"

PointShape::PointShape() {}

Shape* PointShape::Construct()
{
	return new PointShape;
}

std::wstring PointShape::getName()
{
	xstart = 0;
	ystart = 0;
	return L"Крапка";
}

void PointShape::Draw(HDC hdc)
{
	Rectangle(hdc, xend - 1, yend - 1, xend + 1, yend + 1);
}

void PointShape::Gum(HDC hdc) {}