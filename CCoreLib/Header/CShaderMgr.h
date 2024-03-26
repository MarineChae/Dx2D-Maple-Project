#pragma once
#include "CDefine.h"
class CShader
{
public:

	ID3D11VertexShader* m_VertexShader = nullptr;
	ID3D11PixelShader* m_pPixelShader = nullptr;
	ID3DBlob* m_vBb = nullptr;
public:
	bool Load(ID3D11Device* pDevice, std::wstring FileName);
	bool CreatePixelShader(ID3D11Device* pDevice,std::wstring FileName);
	bool CreateVertexShader(ID3D11Device* pDevice,std::wstring FileName);
	bool Release();
	bool Apply(ID3D11DeviceContext* pImmediateContext, int iSlot) const
	{
		pImmediateContext->VSSetShader(m_VertexShader, NULL, 0); //¡§¡°Ω¶¿Ã¥ı º≥¡§
		pImmediateContext->PSSetShader(m_pPixelShader, NULL, 0); //«»ºøΩ¶¿Ã¥ı º≥¡§
		return true;
	}

};


class CShaderMgr
{


public:
		ID3D11Device* m_pDevice = nullptr;
		ID3D11DeviceContext* m_pImmediateContext = nullptr;
		std::map < std::wstring, CShader*> m_List;

public:

		bool Set(ID3D11Device* pDevice, ID3D11DeviceContext* pImmediateContext);
		const CShader* Load(std::wstring FileName);
		const CShader* GetPtr(std::wstring FileName);
		bool Get(std::wstring FileName, CShader& texture);
		static CShaderMgr& GetInstance()
		{
			static CShaderMgr Shader;
			return Shader;

		}


private:
	CShaderMgr();
public:

	virtual ~CShaderMgr();

};

