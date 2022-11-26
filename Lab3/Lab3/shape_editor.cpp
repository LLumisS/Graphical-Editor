#include "shape_editor.h"

#define MY_SHAPE_ARRAY_SIZE		106

Shape** ShapeEditor::pcshape = new Shape* [MY_SHAPE_ARRAY_SIZE] {};
int ShapeEditor::i = 0;

ShapeEditor::ShapeEditor()
{
	xstart = NULL;
	ystart = NULL;
	xend = NULL;
	yend = NULL;
}

void ShapeEditor::OnLBdown(HWND hWnd)
{
	POINT pt;

	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	xstart = pt.x;
	ystart = pt.y;
}

void ShapeEditor::OnLBup(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);

		xend = pt.x;
		yend = pt.y;

		pcshape[i] = shapeKind();
		pcshape[i]->Set(xstart, ystart, xend, yend);
		xstart = 0;
		ystart = 0;
		xend = 0;
		yend = 0;

		if (i >= 99) i = 0;
		else i++;

		InvalidateRect(hWnd, NULL, TRUE);
	}
}

void ShapeEditor::OnMouseMove(HWND hWnd)
{
	if (xstart)
	{
		POINT pt;
		HPEN hPen = CreatePen(PS_SOLID, 1, 0x00ff0000);
		HDC hdc = GetDC(hWnd);
		HPEN hPenOld = (HPEN)SelectObject(hdc, hPen);

		SetROP2(hdc, R2_NOTXORPEN);

		if (xend) drawFunc(hdc);

		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
		xend = pt.x;
		yend = pt.y;

		drawFunc(hdc);

		SelectObject(hdc, hPenOld);
		DeleteObject(hPen);
		ReleaseDC(hWnd, hdc);
	}
}

void ShapeEditor::OnPaint(HWND hWnd) 
{
	PAINTSTRUCT ps;
	HDC hdc;
	hdc = BeginPaint(hWnd, &ps);
	for (int i = 0; i < MY_SHAPE_ARRAY_SIZE; i++)
		if (pcshape[i])
			pcshape[i]->Show(hdc);
	EndPaint(hWnd, &ps);
}