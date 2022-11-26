#include "shape_editor.h"
#include "rect_editor.h"
#include "rect_shape.h"

RectEditor::RectEditor() {}

void RectEditor::drawFunc(HDC hdc) 
{
	Rectangle(hdc, xstart, ystart, xend, yend);
}

Shape* RectEditor::shapeKind()
{
	return new RectShape;
}