#include "shape_editor.h"
#include "line_editor.h"
#include "line_shape.h"

LineEditor::LineEditor() {}

void LineEditor::drawFunc(HDC hdc)
{
	MoveToEx(hdc, xstart, ystart, NULL);
	LineTo(hdc, xend, yend);
}

Shape* LineEditor::shapeKind()
{
	return new LineShape;
}