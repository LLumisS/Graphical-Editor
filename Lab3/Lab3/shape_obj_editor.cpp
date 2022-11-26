#include "editor.h"
#include "shape.h"
#include "shape_obj_editor.h"
#include "point_shape.h"
#include "point_editor.h"
#include "line_shape.h"
#include "line_editor.h"
#include "rect_shape.h"
#include "rect_editor.h"
#include "ellipse_shape.h"
#include "ellipse_editor.h"
#include "resource.h"

ShapeObjectsEditor::ShapeObjectsEditor() {}

ShapeObjectsEditor::~ShapeObjectsEditor() {}

void ShapeObjectsEditor::StartPointEditor(HWND hWnd, ToolBar* cirillius)
{
	cirillius->OnToolMove(hWnd, ID_TOOL_POINT, IDM_POINT);
	if (pse) delete pse;
	pse = new PointEditor;
}

void ShapeObjectsEditor::StartLineEditor(HWND hWnd, ToolBar* cirillius)
{
	cirillius->OnToolMove(hWnd, ID_TOOL_LINE, IDM_LINE);;
	if (pse) delete pse;
	pse = new LineEditor;
}

void ShapeObjectsEditor::StartRectEditor(HWND hWnd, ToolBar* cirillius)
{
	cirillius->OnToolMove(hWnd, ID_TOOL_RECT, IDM_RECT);;
	if (pse) delete pse;
	pse = new RectEditor;
}

void ShapeObjectsEditor::StartEllipseEditor(HWND hWnd, ToolBar* cirillius)
{
	cirillius->OnToolMove(hWnd, ID_TOOL_ELLIPSE, IDM_ELLIPSE);;
	if (pse) delete pse;
	pse = new EllipseEditor;
}

void ShapeObjectsEditor::OnLBdown(HWND hWnd)
{
	if(pse) pse->OnLBdown(hWnd);
}

void ShapeObjectsEditor::OnLBup(HWND hWnd)
{
	if(pse) pse->OnLBup(hWnd);
}

void ShapeObjectsEditor::OnMouseMove(HWND hWnd)
{
	if(pse) pse->OnMouseMove(hWnd);
}

void ShapeObjectsEditor::OnPaint(HWND hWnd)
{
	if(pse) pse->OnPaint(hWnd);
}