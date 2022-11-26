#pragma once
#include "shape_editor.h"

class EllipseEditor : public ShapeEditor
{
public:
	EllipseEditor(void);
	void drawFunc(HDC);
	Shape* shapeKind();
};