#pragma once
#pragma comment(lib, "comctl32.lib")

#include "framework.h"
#include <commctrl.h>

class ToolBar
{
private: 
	ToolBar() {}
	ToolBar(const ToolBar& root) = delete;
	ToolBar& operator = (const ToolBar&) = delete;

	HWND hwndToolBar = NULL;
	UINT previousToolID = NULL;
	UINT previousMenuID = NULL;
public:
	static ToolBar& getInstance()
	{
		static ToolBar instance;
		return instance;
	}

	void OnCreate(HWND, HINSTANCE);
	void OnSize(HWND);
	void OnNotify(HWND, WPARAM, LPARAM);
	void OnToolMove(HWND, UINT, UINT);
};