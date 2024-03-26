#pragma once
#include"CDefine.h"
#include"CTextureMgr.h"
#include "CShaderMgr.h"


struct P_VERTEX
{

	CVector3 Pos;
	CVector2 Tex;

};
struct ConstantData
{
	CMatrix  WolrdMatrix;
	CMatrix  ViewMatrix;
	CMatrix  ProjMatrix;
};

class CDxObject
{
public:
	ID3D11Device* m_pDevice = nullptr;
	ID3D11DeviceContext* m_pImmediateContext = nullptr;
public:
	ID3D11Buffer* m_pVertexBuffer = nullptr;
	ID3D11Buffer* m_pIndexBuffer = nullptr;
	ID3D11Buffer* m_pConstantBuffer = nullptr;
	ID3D11InputLayout* m_pInputLayout = nullptr;
	const CTexture* m_pTexture = nullptr;
	const CShader* m_pShader = nullptr;
	ConstantData m_ConstantData;

public:
	virtual bool CreateVertexBuffer();
	virtual bool CreateConstantBuffer();
	virtual bool CreateInputLayout();
	virtual bool CreateIndexBuffer();
	virtual bool Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
public:
	virtual bool PreRender();
	virtual bool Render();
	virtual bool PostRender();
	virtual bool Release();
public:
	virtual ~CDxObject() {};


};

