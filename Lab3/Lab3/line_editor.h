#pragma once
#include "shape_editor.h"

class LineEditor : public ShapeEditor
{
public:
	LineEditor(void);
	void drawFunc(HDC);
	Shape* shapeKind();
};