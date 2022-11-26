#pragma once
#include "shape.h"

class LineShape : public Shape
{
public:
	LineShape(void);
	void Show(HDC hdc);
};