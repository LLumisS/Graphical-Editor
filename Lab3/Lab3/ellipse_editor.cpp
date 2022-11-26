#include "shape_editor.h"
#include "ellipse_editor.h"
#include "ellipse_shape.h"

EllipseEditor::EllipseEditor() {}

void EllipseEditor::drawFunc(HDC hdc)
{
	Arc(hdc, xstart * 2 - xend, ystart * 2 - yend, xend, yend, 0, 0, 0, 0);
}

Shape* EllipseEditor::shapeKind()
{
	return new EllipseShape;
}