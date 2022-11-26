#pragma once
#include "framework.h"

class Shape
{
protected:
	long xstart, ystart, xend, yend;
public:
	void Set(long x1, long y1, long x2, long y2);
	virtual void Show(HDC) = 0;
};
