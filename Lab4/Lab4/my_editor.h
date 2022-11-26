#pragma once
#include "shape.h"
#include "point_shape.h"
#include "line_shape.h"
#include "rect_shape.h"
#include "ellipse_shape.h"
#include "lineoo_shape.h"
#include "cube_shape.h"
#include "tool_bar.h"

#define MY_SHAPE_ARRAY_SIZE		106

class MyEditor
{
private:
	Shape** pshape = new Shape * [MY_SHAPE_ARRAY_SIZE] {};;
	int i = 0;
	Shape* parentShape = NULL;
	long xstart = 0, ystart = 0, xend = 0, yend = 0;
public:
	MyEditor(void);
	~MyEditor();
	void Start(Shape*, HWND, ToolBar*, WPARAM, WPARAM);
	void OnLBdown(HWND);
	void OnLBup(HWND);
	void OnMouseMove(HWND);
	void OnPaint(HWND);
};