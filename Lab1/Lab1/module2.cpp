#include "framework.h"
#include "module2.rh"

static INT_PTR CALLBACK Work2(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, 1);
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, 0);
			return (INT_PTR)TRUE;
		}
		break;
	default: break;
	}
	return (INT_PTR)FALSE;
}


int Func_MOD2(HWND hWnd, HINSTANCE hInst)
{
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, Work2);
}