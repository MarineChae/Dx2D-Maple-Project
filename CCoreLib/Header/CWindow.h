#pragma once
#include"CDefine.h"

class CWindow 
{
public:
	HINSTANCE	m_hInstance; //컴퓨터 저장공간에서 할당된 실체를 의미한다.
	HWND		m_hWnd;
	DWORD		m_dwWindowExStyle = WS_EX_APPWINDOW;
	DWORD		m_dwWindowStyle = WS_OVERLAPPEDWINDOW;
	DWORD		m_dwWindowPosX = 0;
	DWORD		m_dwWindowPosY = 0;
	DWORD		m_dwWindowWidth;
	DWORD		m_dwWindowHeight;


public:

	bool SetRegisterClassWindow(HINSTANCE hInstance);
	bool SetWindow(const WCHAR* sztitle, DWORD dwWindowWidth = 1920 , DWORD dwWindowHeight = 1080);

public:
	
	CWindow()
	{

	}
	virtual ~CWindow()
	{

	}


};

