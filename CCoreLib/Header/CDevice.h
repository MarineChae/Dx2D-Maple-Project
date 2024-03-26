#pragma once
#include "CWindow.h"
class CDevice :public CWindow
{
public:
	IDXGISwapChain*			 m_pSwapChain = nullptr;
	ID3D11Device*			 m_pDevice = nullptr;
	ID3D11DeviceContext*	 m_pImmediateContext = nullptr;
	ID3D11RenderTargetView*  m_pRenderTargetView;
	D3D_FEATURE_LEVEL		 m_pFeatureLevels = D3D_FEATURE_LEVEL_11_0;
	D3D_DRIVER_TYPE          m_DriverType = D3D_DRIVER_TYPE_HARDWARE;
	IDXGIFactory*			 m_pFactory=nullptr;
	D3D11_VIEWPORT			 m_ViewPort;

public:
	bool CreateDevice();
	bool CreateFactory();
	bool CreateSwapChain();
	bool SetRenderTarGetView();
	bool SetViewPort();

public:
	bool Init();
	bool Frame();
	
	bool PreRender();
	bool PostRender();
	bool Render();
	bool Release();

};

