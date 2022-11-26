#pragma once
#include "shape.h"

class RectShape : public Shape
{
public:
	RectShape(void);
	void Show(HDC hdc);
};