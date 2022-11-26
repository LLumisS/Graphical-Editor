#include "shape_editor.h"
#include "point_editor.h"
#include "point_shape.h"

PointEditor::PointEditor() {}

void PointEditor::OnMouseMove(HWND hWnd) {}

void PointEditor::drawFunc(HDC hdc) {}

Shape* PointEditor::shapeKind()
{
	return new PointShape;
}