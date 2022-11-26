#include "line_shape.h"

LineShape::LineShape() {}

Shape* LineShape::Construct()
{
	return new LineShape;
}

std::wstring LineShape::getName()
{
	return L"˳��";
}

void LineShape::Draw(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}

void LineShape::Gum(HDC hdc)
{
	Draw(hdc);
}