#include "CScene.h"
#include"CoreInterface.h"

bool CScene::Init()
{
    m_pMapObj = std::make_unique<CMapObj>();
    m_pMapObj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    m_pMapObj->SetPos({ 0,0,0 });
    m_pMapObj->SetScale({ Map_XSize, Map_YSize,1 });
    m_pMapObj->Create(BackGroundFile, L"../../Resourse/Plane.hlsl");

        

    return true;
}

bool CScene::Frame(CPlayerObj* Target)
{
    m_pMapObj->Frame();
    return true;
}

bool CScene::Render()
{
    m_pMapObj->SetMatrix(nullptr,&CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
    m_pMapObj->Render();
    return true;
}

bool CScene::Release()
{
    m_pMapObj->Release();
    return true;
}

void CScene::SetMatrix(CMatrix* WolrdMatrix, CMatrix* ViewMatrix, CMatrix* ProjMatrix)
{
    
}
