#pragma once
#include "framework.h"
#include "shape_editor.h"
#include "tool_bar.h"

class ShapeObjectsEditor
{
protected:
	ShapeEditor *pse = NULL;
public:
	ShapeObjectsEditor(void);
	~ShapeObjectsEditor();
	void StartPointEditor(HWND, ToolBar*);
	void StartLineEditor(HWND, ToolBar*);
	void StartRectEditor(HWND, ToolBar*);
	void StartEllipseEditor(HWND, ToolBar*);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};
