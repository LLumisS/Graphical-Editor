#pragma once
#include "shape_editor.h"

class RectEditor : public ShapeEditor
{
public:
	RectEditor(void);
	void drawFunc(HDC);
	Shape* shapeKind();
};