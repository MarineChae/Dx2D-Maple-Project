#include "CLobbyScene.h"
#include"CoreInterface.h"

void CLobbyScene::CreatePotal()
{
    m_pPotal = new CSpriteUVObj;
    CSpriteData data;
    data.iRow = 1;
    data.iCol = 8;
    data.m_vPos = {1200.0f,-490.0f,0.0f };
    data.m_vScale = { 89.0f,257.0f,1.0f };
    data.FileName = L"../../Resourse/potal.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pPotal->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x*0.5, data.m_vScale.y * 2.0f);
    m_pPotal->Init();
    m_pPotal->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);

    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pPotal));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size() - 1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize();
    m_SceneParticleList.push_back(info);

}
bool CLobbyScene::CheckCollide(CRect& MapObj, CRect& other)
{
   

    return  MapObj.ToRect(other);

}
void CLobbyScene::CreateBackTile()
{
    float intervalx = 0;

    std::unique_ptr<CMapObj> pMapobj;

    std::wstring fileback[] = { L"../../Resourse/Lobby/back (1).Png",
                               L"../../Resourse/Lobby/back (2).Png",
                               L"../../Resourse/Lobby/back (3).Png",
                                  L"../../Resourse/Lobby/back (4).Png" };
    intervalx = 1411.0f;
    for (int i = 0; i < 2; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-2030.0f + intervalx, -315.0f, 1.0f));
        pMapobj->SetScale(CVector3(1411.0f, 358.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/back (1).Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
        intervalx += 1411.0f;

    }
    intervalx = 1411.0f;
    for (int i = 0; i < 2; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-2030.0f + intervalx, 401.0f, 1.0f));
        pMapobj->SetScale(CVector3(1411.0f, 358.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/back (1).Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
        intervalx += 1411.0f;

    }

}
void CLobbyScene::CreateStaticObj()
{
    //왼쪽 오브젝트
    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-1300.0f, 335.0f, 1.0f));
    pMapobj->SetScale(CVector3(631.0f, 1009.0f, 1.0f));
    pMapobj->Create(L"../../Resourse/Lobby/Acc1.Png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));

    //center
    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-000.0f, 396.0f, 1.0f));
    pMapobj->SetScale(CVector3(95.0f, 365.0f, 1.0f));
    pMapobj->Create(L"../../Resourse/Lobby/Acc5.Png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));
    float intervaly = 0;

    //오른쪽 기둥
    for (int i = 0; i < 3; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(2280.0f, -1050.0f + intervaly, 1.0f));
        pMapobj->SetScale(CVector3(631.0f, 1009.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/Wall1.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
        intervaly += 504.5f;
    }
    //왼쪽 계기판
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-1100.0f, -100.0f, 1.0f));
        pMapobj->SetScale(CVector3(195.0f, 451.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/Acc2.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
    }

    //오른쪽 배전함?
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(900.0f, -205.0f, 1.0f));
        pMapobj->SetScale(CVector3(525.0f, 301.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/Acc6.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
    }

    //상단 파이프
    {


        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-331.0f, 600.0f, 1.0f));
        pMapobj->SetScale(CVector3(631.0f, 393.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/Pipe1.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));

        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(931.0f, 600.0f, 1.0f));
        pMapobj->SetScale(CVector3(631.0f, 393.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/Pipe2.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));

        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-1079.0f, 600.0f, 1.0f));
        pMapobj->SetScale(CVector3(117.0f, 392.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/PipeLeft.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));

        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(1628.0f, 600.0f, 1.0f));
        pMapobj->SetScale(CVector3(66.0f, 393.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/Lobby/PipeRight.Png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));



    }





}
void CLobbyScene::CreateFootHold()
{
    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-1700.0f, -850.0f, 0.0f));
    pMapobj->SetScale(CVector3(393.0f, 181.0f, 1.0f));
    CVector2 rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, pMapobj->m_vScale.y + 40.0f);
    pMapobj->Create(L"../../Resourse/Lobby/FootHold0.Png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    float intervalx = 0;
    std::wstring filename[] = { L"../../Resourse/Lobby/FootHold1.Png",
                               L"../../Resourse/Lobby/FootHold2.Png",
                               L"../../Resourse/Lobby/FootHold3.Png" };
    for (int i = 0; i < 6; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-1009.0f + intervalx, -850.0f, 0.0f));
        pMapobj->SetScale(CVector3(301.0f, 181.0f, 1.0f));
        CVector2 rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y };
        pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, pMapobj->m_vScale.y + 40.0f);
        pMapobj->Create(filename[i % 3], L"../../Resourse/Plane.hlsl");

        m_FootHoldList.push_back(std::move(pMapobj));
        intervalx += 599.0f;
    }


    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-000.0f, -334.0f, 1.0f));
    pMapobj->SetScale(CVector3(95.0f, 365.0f, 1.0f));
    pMapobj->Create(L"../../Resourse/Lobby/Acc4.Png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));



    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(80.0f, -334.0f, 1.0f));
    pMapobj->SetScale(CVector3(102.0f, 155.0f, 1.0f));
    pMapobj->Create(L"../../Resourse/Lobby/Acc3.Png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));
}
bool CLobbyScene::CreateMapObj()
{

    CreateBackTile();
    CreateStaticObj();
    CreateFootHold();
    CreatePotal();
    return true;

}

bool CLobbyScene::Init()
{
    CScene::Init();
    CreateMapObj();

    return true;
}

bool CLobbyScene::Frame(CPlayerObj* Target)
{
    CScene::Frame(nullptr);
    for (auto& Map : m_MapList)
    {
        Map->Frame();
    }
    for (auto& hold : m_FootHoldList)
    {
        hold->Frame();
    }
    for (auto iter = m_SceneParticleList.begin(); iter != m_SceneParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
        if (info.m_bValid == false)
        {
            info.m_bValid = true;
        }
        else
        {
            iter++;
        }

    }
    return true;
}

bool CLobbyScene::Render()
{
    CScene::Render();
    for (auto& Map : m_MapList)
    {
        Map->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        Map->Render();
    }
    for (auto& hold : m_FootHoldList)
    {
        hold->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        hold->Render();
    }
    for (auto iter = m_SceneParticleList.begin(); iter != m_SceneParticleList.end(); iter++)
    {
        CParticle& info = *iter;
        CSpriteUVObj* Obj = m_SceneSpriteList[info.iID];
        Obj->SetPos(info.m_vPos);
        Obj->SetScale(info.m_vScale);
        Obj->Move(g_fSecondPerFrame);
        Obj->Frame();
        Obj->m_pTexture;
        Obj->m_iTexIndex = info.m_iIndex;
        Obj->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        Obj->Render(0);
    }
    return true;
}

bool CLobbyScene::Release()
{
    CScene::Release();
    for (auto& Map : m_MapList)
    {
        Map->Release();
    }
    return true;
}
