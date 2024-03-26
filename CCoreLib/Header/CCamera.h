#pragma once
#include"CDefine.h"

class CCamera
{

public:
	CVector3				m_vCameraPos;
	CMatrix					m_ViewMatrix;
	CMatrix					m_OrthProjectionMatrix;
	//float					Zoom = 0.5f;
	DWORD					m_dwWindowWidth;
	DWORD					m_dwWindowHeight;

public:
	bool CreateCamera(CVector3 Pos, CVector2 Size);

public:
	bool Init();
	bool Frame();
	bool Render();
	bool Release();

};

