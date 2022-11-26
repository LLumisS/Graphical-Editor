#pragma once
#pragma comment(lib, "comctl32.lib")

#include "framework.h"
#include <commctrl.h>

class ToolBar
{
protected:
	HWND hwndToolBar = NULL;
	WPARAM previousToolID = NULL;
	WPARAM previousMenuID = NULL;
public:
	ToolBar();
	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnToolMove(HWND, WPARAM, WPARAM);
};