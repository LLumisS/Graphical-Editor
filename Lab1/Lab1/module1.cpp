#include "framework.h"
#include "module1.rh"

static WCHAR* buff;
static int pos;
static WCHAR temp[4];

static INT_PTR CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM)
{
	switch (iMessage)
	{
	case WM_INITDIALOG:
		SetScrollRange(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, 1, 100, TRUE);
	case WM_HSCROLL:
		pos = GetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL);
		switch (LOWORD(wParam))
		{
		case SB_LINELEFT:
			pos--;
			break;
		case SB_LINERIGHT:
			pos++;
			break;
		case SB_THUMBPOSITION:
		case SB_THUMBTRACK:
			pos = HIWORD(wParam);
			break;
		default: break;
		}
		SetScrollPos(GetDlgItem(hDlg, IDC_SCROLLBAR1), SB_CTL, pos, TRUE);

		_itow_s(pos, temp, 10);
		SetDlgItemText(hDlg, IDC_STATIC1, temp);

		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			GetDlgItemText(hDlg, IDC_STATIC1, buff, 4);
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


int Func_MOD1(HWND hWnd, HINSTANCE hInst, WCHAR* par)
{
	buff = par;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
}