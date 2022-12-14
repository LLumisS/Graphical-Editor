#include "my_editor.h"

MyEditor::MyEditor(void) {}
MyEditor::~MyEditor()
{
	delete pshape;
}

void MyEditor::Start(Shape *shape, HWND hWnd, ToolBar* toolBar, WPARAM toolID, WPARAM menuID)
{
	parentShape = shape;
	toolBar->OnToolMove(hWnd, toolID, menuID);
}

void MyEditor::OnLBdown(HWND hWnd)
{
	if (parentShape)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xstart = pt.x;
		ystart = pt.y;

		pshape[i] = parentShape->Construct();
		pshape[i]->Set(xstart, ystart, xend, yend);
	}
}

void MyEditor::OnLBup(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		if (i < MY_SHAPE_ARRAY_SIZE - 1) i++;
		else i = 0;

		xstart = 0, ystart = 0, xend = 0, yend = 0;

		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void MyEditor::OnMouseMove(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;
		HPEN hPen = CreatePen(PS_DOT, 1, 0);
		HDC hdc = GetDC(hWnd);
		HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

		SetROP2(hdc, R2_NOTXORPEN);

		if (xend) pshape[i]->Gum(hdc);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		pshape[i]->Set(xstart, ystart, xend, yend);
		pshape[i]->Gum(hdc);

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}

void MyEditor::OnPaint(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pshape[i])
			pshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}
