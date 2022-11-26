#pragma once
#include "line_shape.h"
#include "ellipse_shape.h"

class LineOOShape : public LineShape, public EllipseShape
{
public:
	LineOOShape(void);
	Shape* Construct();

	void Show(HDC hdc);
	void Gum(HDC hdc);
};