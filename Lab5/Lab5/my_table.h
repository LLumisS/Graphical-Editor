#pragma once
#include "framework.h"
#include "resource1.h"
#include <fstream>
#include <string>
#include <codecvt>
//#include <locale>

class MyTable
{
private:
	MyTable() {}
	MyTable(const MyTable& root) = delete;
	MyTable& operator = (const MyTable&) = delete;

	static HWND hWndTable;
	static HWND hWndParent;

	static LPCSTR path;
	static int selectedItem;
public:
	static MyTable& getInstance()
	{
		static MyTable instance;
		return instance;
	}
	static HWND getTable();
	static HWND getParent();

	static void setItem(int);
	static int getItem();

	void OnCreate(HWND, HINSTANCE);
	void Show();
	void Add(std::wstring);
};