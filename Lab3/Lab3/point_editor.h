#pragma once
#include "shape_editor.h"

class PointEditor : public ShapeEditor
{
public:
	PointEditor(void);
	void OnMouseMove(HWND);
	void drawFunc(HDC);
	Shape* shapeKind();
};