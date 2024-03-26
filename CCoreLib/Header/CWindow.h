#pragma once
#include"CDefine.h"

class CWindow 
{
public:
	HINSTANCE	m_hInstance; //��ǻ�� ����������� �Ҵ�� ��ü�� �ǹ��Ѵ�.
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

