#pragma once
#include "editor.h"
#include "shape.h"

class ShapeEditor : public Editor
{
protected:
	static Shape** pcshape;
	static int i;
	long xstart, ystart, xend, yend;

public: 
	ShapeEditor(void);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);

	virtual void drawFunc(HDC) = 0;
	virtual Shape* shapeKind() = 0;
};