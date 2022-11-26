#pragma once
#include "line_shape.h"
#include "ellipse_shape.h"

class LineOOShape : public LineShape, public EllipseShape
{
public:
	LineOOShape(void);
	Shape* Construct();

	std::wstring getName();
	void Draw(HDC);
	void Gum(HDC);
};