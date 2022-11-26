#pragma once
#include "shape.h"

class EllipseShape : public Shape
{
public:
	EllipseShape(void);
	void Show(HDC hdc);
};