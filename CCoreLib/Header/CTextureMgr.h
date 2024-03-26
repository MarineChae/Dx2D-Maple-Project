#pragma once
#include"CDefine.h"
class CTexture
{

public:
	float iRow = 1;
	float iCOl = 1;
	ID3D11ShaderResourceView* m_pTextureSRV = nullptr;
	float m_DelayTime;
	
public:

	bool Apply(ID3D11DeviceContext* pImmediateContext, int iSlot) const
	{

		pImmediateContext->PSSetShaderResources(iSlot, 1, &m_pTextureSRV);
		return true;
	}
	bool LoadTextureFile(ID3D11Device* pDevice, std::wstring FileName);
	
	bool Release();


};




class CTextureMgr
{
public:
	ID3D11Device* m_pDevice ;
	ID3D11DeviceContext* m_pImmediateContext ;
	std::map < std::wstring, CTexture*> m_List;

public:

	bool Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
	const CTexture* Load(std::wstring FileName);
	const CTexture* GetPtr(std::wstring FileName);
	bool Get(std::wstring FileName,CTexture& texture);
	static CTextureMgr& GetInstance()
	{
		static CTextureMgr Texture;
		return Texture;

	}

private:
	CTextureMgr();
public:

	virtual ~CTextureMgr();


};

