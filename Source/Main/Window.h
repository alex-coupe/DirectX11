#pragma once
#include <Windows.h>

class Window {
public:
	Window(HINSTANCE& instance, int width, int height);
	static LRESULT CALLBACK WndProc(HWND handle, UINT msg, WPARAM wParam, LPARAM lParam);
	HWND GetHandle();
	bool Update();
	~Window();
	const int GetInitialWidth()const;
	const int GetInitialHeight()const;
private:
	HINSTANCE& m_instance;
	HWND m_handle = nullptr;
	int m_initialWidth = 0;
	int m_initialHeight = 0;
	static Window* m_pInstance;
	LRESULT CALLBACK MyWinProc(HWND, UINT, WPARAM, LPARAM);
	static constexpr wchar_t title[] = L"DirectX11 Fun";
	static constexpr wchar_t m_className[] = L"WindowClass";
	
};
