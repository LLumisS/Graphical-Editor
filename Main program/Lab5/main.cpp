﻿// Lab2.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "main.h"
#include "my_editor.h"
#include "my_table.h"

#define MAX_LOADSTRING 100

#include <commctrl.h>
#pragma comment(lib, "comctl32.lib")

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

MyEditor& cyrille = cyrille.getInstance();
ToolBar& cirillius = cirillius.getInstance();
MyTable& elcirillo = elcirillo.getInstance();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    InitCommonControls();
    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_LAB5, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LAB5));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LAB5));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_LAB5);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_LBUTTONDOWN:
        cyrille.OnLBdown(hWnd);
        break;
    case WM_LBUTTONUP:
        elcirillo.Add(cyrille.OnLBup(hWnd));
        break;
    case WM_MOUSEMOVE:
        cyrille.OnMouseMove(hWnd);
        break;
    case WM_PAINT:
        cyrille.RemoveItem(elcirillo.getRemove() - 1);
        elcirillo.setRemove(0);
        cyrille.OnPaint(hWnd, elcirillo.getSelected() - 1);
        break;

    case WM_CREATE:
        cirillius.OnCreate(hWnd, hInst);
        elcirillo.OnCreate(hWnd, hInst);
        break;
    case WM_SIZE:
        cirillius.OnSize(hWnd);
        break;
    case WM_NOTIFY:
        cirillius.OnNotify(hWnd, wParam, lParam);
        break;

    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);

            switch (wmId)
            {

            case ID_TOOL_POINT:
            case IDM_POINT:
                cyrille.Start(new PointShape, hWnd, &cirillius, ID_TOOL_POINT, IDM_POINT);
                break;

            case ID_TOOL_LINE:
            case IDM_LINE:
                cyrille.Start(new LineShape, hWnd, &cirillius, ID_TOOL_LINE, IDM_LINE);
                break;

            case ID_TOOL_RECT:
            case IDM_RECT:
                cyrille.Start(new RectShape, hWnd, &cirillius, ID_TOOL_RECT, IDM_RECT);
                break;

            case ID_TOOL_ELLIPSE:
            case IDM_ELLIPSE:
                cyrille.Start(new EllipseShape, hWnd, &cirillius, ID_TOOL_ELLIPSE, IDM_ELLIPSE);
                break;

            case ID_TOOL_LINEOO:
            case IDM_LINEOO:
                cyrille.Start(new LineOOShape, hWnd, &cirillius, ID_TOOL_LINEOO, IDM_LINEOO);
                break;

            case ID_TOOL_CUBE:
            case IDM_CUBE:
                cyrille.Start(new CubeShape, hWnd, &cirillius, ID_TOOL_CUBE, IDM_CUBE);
                break;

            case IDM_TABLE:
            case ID_TABLE:
                elcirillo.Show();
                break;

            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}