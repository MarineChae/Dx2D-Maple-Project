#pragma once
#include"CDevice.h"
#include"CTimer.h"
#include"CInput.h"
#include"CCamera.h"
#include"CWriter.h"

class CCore : public CDevice
{
protected:
	CTimer		 m_GameTimer;
	std::shared_ptr<CCamera> m_pMainCamera=nullptr;
	ID3D11BlendState* m_pBlendState;

public:
	virtual bool Init();
	virtual bool Frame();
	virtual bool Render();
	virtual bool Release();
	bool Run();
	bool CreateBlendState();
	


private:
	virtual bool EngineInit();
	virtual bool EngineFrame();
	virtual bool EngineRender();
	virtual bool EngineRelease();
public:
	CCore() {};
	virtual ~CCore() {};


};

