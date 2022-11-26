#pragma once
#include "framework.h"

class Shape
{
protected:
	long xstart = 0, ystart = 0, xend = 0, yend = 0;
public:
	void Set(long x1, long y1, long x2, long y2);

	virtual Shape* Construct() = 0;
	virtual void Show(HDC) = 0;
	virtual void Gum(HDC) = 0;
};
