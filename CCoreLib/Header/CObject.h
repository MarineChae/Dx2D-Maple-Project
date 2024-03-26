#pragma once
#include"CDefine.h"
#include"CDxObject.h"


class CObject : public CDxObject
{
public:

	CRect m_RT;

public:

	void SetRect(CVector2 p, float width, float height);


public:
	CMatrix m_WolrdMatrix;
	CMatrix m_ViewMatrix;
	CMatrix m_ProjMatrix;

public:
	float m_TexAccumulatedTime=0.0f;
	
public:
	CVector3 m_vPos;
	CVector3 m_vScale;
	CVector3 m_vRotate;
	std::vector<P_VERTEX> m_vVertexList;
	virtual bool SetPos(CVector3 Pos);
	virtual void SetScale(CVector3 Pos);
	virtual void Move(double fSecond) {};

public:
	
	//virtual bool Create(std::wstring FileName, std::wstring ShaderFileName,float Delay);
	virtual bool Create(std::wstring FileName, std::wstring ShaderFileName);
	virtual void SetMatrix(CMatrix* WolrdMatrix , CMatrix* ViewMatrix, CMatrix* ProjMatrix);
	
	
public:


	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();

public:
	CObject()
	{
		m_vPos = CVector3(0, 0, 0);
		m_vScale = CVector3(1, 1, 1);
		m_vRotate = CVector3(0, 0, 0);
	}

};

