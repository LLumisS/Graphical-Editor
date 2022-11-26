#include "lineoo_shape.h"

LineOOShape::LineOOShape(void) {}

Shape* LineOOShape::Construct()
{
	return new LineOOShape;
}

void LineOOShape::Show(HDC hdc)
{
	long x1 = xstart, y1 = ystart, x2 = xend, y2 = yend;

	LineShape::Show(hdc);

	Set(x1, y1, x1 + 10, y1 + 10);
	EllipseShape::Show(hdc);

	Set(x2, y2, x2 + 10, y2 + 10);
	EllipseShape::Show(hdc);

	Set(x1, y1, x2, y2);
}

void LineOOShape::Gum(HDC hdc)
{
	Show(hdc);
}