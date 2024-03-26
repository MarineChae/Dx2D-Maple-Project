#include "C1PhaseScene.h"
#include "CoreInterface.h"
#include"CDeadState.h"
#include"CStandState.h"

void C1PhaseScene::CreateFootHold()
{

    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(0.0f, -710.0f, 0.0f));
    pMapobj->SetScale(CVector3(1406.0f, 170.0f, 1.0f));
    CVector2 rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, pMapobj->m_vScale.y*2.0f);
    pMapobj->Create(L"../../Resourse/1PhaseMap/Back/1PhaseFootHold.png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));





    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-800.0f, -220.0f, 0.0f));
    pMapobj->SetScale(CVector3(48.0f, 83.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y +80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 20 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (1).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-602.0f,-222.0f, 0.0f));
    pMapobj->SetScale(CVector3(150.0f, 85.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 20);
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (3).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-392.0f, -217.0f, 0.0f));
    pMapobj->SetScale(CVector3(60.0f, 80.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 20 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (2).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));






    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(800.0f, -217.0f, 0.0f));
    pMapobj->SetScale(CVector3(60.0f, 80.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (2).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(590.0f, -222.0f, 0.0f));
    pMapobj->SetScale(CVector3(150.0f, 85.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f,10);
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (3).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(392.0f,-220.0f, 0.0f));
    pMapobj->SetScale(CVector3(48.0f, 83.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (1).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));







    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-900.0f, -420.0f, 0.0f));
    pMapobj->SetScale(CVector3(48.0f, 83.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y+80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f,10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (1).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-702.0f, -422.0f, 0.0f));
    pMapobj->SetScale(CVector3(150.0f, 85.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f,10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (3).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(-492.0f, -418.0f, 0.0f));
    pMapobj->SetScale(CVector3(60.0f, 80.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (2).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));





    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(492.0f, -420.0f, 0.0f));
    pMapobj->SetScale(CVector3(48.0f, 83.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (1).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(690.0f, -422.0f, 0.0f));
    pMapobj->SetScale(CVector3(150.0f, 85.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f,10 );
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (3).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(900.0f, -418.0f, 0.0f));
   
    pMapobj->SetScale(CVector3(60.0f, 80.0f, 1.0f));
    rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y + 80 };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, 10);
    pMapobj->Create(L"../../Resourse/1PhaseMap/1PHold (2).png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));




}
void C1PhaseScene::CreatePotal()
{
    m_pPotal = new CSpriteUVObj;
    CSpriteData data;
    data.iRow = 1;
    data.iCol = 7;
    data.m_vPos = { -392.0f, -20.0f, 0.0f };
    data.m_vScale = { 128.0f,122.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/InnerPortal.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pPotal->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x*2 , data.m_vScale.y * 2.0f);
    m_pPotal->Init();
    m_pPotal->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pPortalList.push_back(m_pPotal);


    m_pPotal = new CSpriteUVObj;
   
    data.iRow = 1;
    data.iCol = 7;
    data.m_vPos = { 400.0f, -20, 0.0f };
    data.m_vScale = { 128.0f,122.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/InnerPortal.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pPotal->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x * 2, data.m_vScale.y * 2.0f);
    m_pPotal->Init();
    m_pPotal->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pPortalList.push_back(m_pPotal);




}

void C1PhaseScene::CreateBackGround()
{
    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(0.0f, 102.0f, 0.0f));
    pMapobj->SetScale(CVector3(1406.0f, 643.0f, 1.0f));

    pMapobj->Create(L"../../Resourse/1PhaseMap/Back/1PhaseBack1.png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));


    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(0.0f, 170.0f, 0.0f));
    pMapobj->SetScale(CVector3(210.0f, 186.0f, 1.0f));

    pMapobj->Create(L"../../Resourse/1PhaseMap/Back/3.png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));

    m_pSwooCore = std::make_unique<CMapObj>();
    m_pSwooCore->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    m_pSwooCore->SetPos(CVector3(0.0f, 102.0f, 0.0f));
    m_pSwooCore->SetScale(CVector3(1406.0f, 643.0f, 1.0f));

    m_pSwooCore->Create(L"../../Resourse/1PhaseMap/Back/1PhaseBack2.png", L"../../Resourse/Plane.hlsl");
  
   


   
}
void C1PhaseScene::CreateBoss()
{

    CSpriteData data;
    data.m_vPos = { 0.0f,170.0f,0.0f };
    data.m_vScale = { 178.0f,254.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Back/1PhaseSwoo.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 5;
    data.iRow = 3;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 8;
    m_pBoss->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    
    m_pBoss->m_pCSpriteDataList.push_back(data);


    data.m_vPos = { 0.0f,170.0f,0.0f };
    data.m_vScale = {1522.0f,915.0f,1.0f };
    data.FileName = L"../../Resourse/Boss/1PDie.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 8;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 54;
    m_pBoss->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    
    m_pBoss->m_pCSpriteDataList.push_back(data);


    m_pBoss->m_pUVList.clear();
    m_pBoss->SetUVData(m_pBoss->m_pCSpriteDataList[0].iRow, m_pBoss->m_pCSpriteDataList[0].iCol);
    m_pBoss->m_pTexture = CTextureMgr::GetInstance().Load(m_pBoss->m_pCSpriteDataList[0].FileName);
    m_pBoss->SetScale(m_pBoss->m_pCSpriteDataList[0].m_vScale);

    CBossSkill* input = new CBossSkill;
    input->m_pSpriteUVObj = new CSpriteUVObj;
    data.iRow = 1;
    data.iCol = 6;
    data.FileName = L"../../Resourse/ball/laserAttackLoop.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12;
    input->m_pSpriteUVObj->Init();
    input->m_pSpriteUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    input->m_SpriteList.insert(std::make_pair(0, input->m_pSpriteUVObj));
    m_pBoss->m_pBossSkillList.push_back(input);


    CSpriteUVObj* m_pLazer = new CSpriteUVObj;
    data.m_vPos = { 0.0f,-470.0f,0.0f };
    data.m_vScale = { 1400.0f,59.0f,1.0f };
    data.FileName = L"../../Resourse/Boss/Lz/LZ1.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 5;
    data.iRow = 1;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 5;
    m_pLazer->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pLazer->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x, data.m_vScale.y);
    m_pLazerList.push_back(m_pLazer);

    m_pLazer = new CSpriteUVObj;
    data.m_vPos = { 0.0f,-470.0f,0.0f };
    data.m_vScale = { 1400.0f,122.0f,1.0f };
    data.FileName = L"../../Resourse/Boss/Lz/LZ2.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 6;
    data.iRow = 1;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 6;
    m_pLazer->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pLazer->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x, data.m_vScale.y);
    m_pLazerList.push_back(m_pLazer);

    m_pLazer = new CSpriteUVObj;
    data.m_vPos = { 0.0f,-470.0f,0.0f };
    data.m_vScale = { 1400.0f,115.0f,1.0f };
    data.FileName = L"../../Resourse/Boss/Lz/LZ3.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 6;
    data.iRow = 1;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 5;
    m_pLazer->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pLazer->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x, data.m_vScale.y);
    m_pLazerList.push_back(m_pLazer);





    m_pBoss->m_DeadSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/1PDie.mp3");
    m_LazerSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/Loop.mp3");
    m_pBoss->MaxBossHP = 500000000;
    m_pBoss->Drop = false;
    m_pBoss->MoveSpeed = 0.0;
    
    m_pBoss->HealthPoint = m_pBoss->MaxBossHP;
}
void C1PhaseScene::CreateParticle()
{
    m_pUVObj = new CSpriteUVObj;
    CSpriteData data;
    data.iRow = 2;
    data.iCol = 5;
    data.m_vPos = { -30.0f,580.0f,0.0f };
    data.m_vScale = { 291.0f,122.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Back/tv.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pUVObj->Init();
    m_pUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pUVObj));
    //ZeroMemory(&info, sizeof(info));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size() - 1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize() - 4;
    m_SceneParticleList.push_back(info);


    m_pUVObj = new CSpriteUVObj;
    data.iRow = 1;
    data.iCol = 5;
    data.m_vPos = { -950.0f,380.0f,0.0f };
    data.m_vScale = { 198.0f,170.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Object/LTSpawn.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pUVObj->Init();
    m_pUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pUVObj));
    //ZeroMemory(&info, sizeof(info));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size()-1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize();
    m_SceneParticleList.push_back(info);

    m_pUVObj = new CSpriteUVObj;
    data.iRow = 1;
    data.iCol = 5;
    data.m_vPos = { -1150.0f,000.0f,0.0f };
    data.m_vScale = { 207.0f,197.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Object/LBSpawn.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pUVObj->Init();
    m_pUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pUVObj));
    //ZeroMemory(&info, sizeof(info));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size() - 1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize();
    m_SceneParticleList.push_back(info);



    m_pUVObj = new CSpriteUVObj;
    data.iRow = 1;
    data.iCol = 5;
    data.m_vPos = { 950.0f,380.0f,0.0f };
    data.m_vScale = { 198.0f,170.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Object/RTSpawn.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pUVObj->Init();
    m_pUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pUVObj));
    //ZeroMemory(&info, sizeof(info));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size() - 1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize();
    m_SceneParticleList.push_back(info);

    m_pUVObj = new CSpriteUVObj;
    data.iRow = 1;
    data.iCol = 5;
    data.m_vPos = { 1150.0f,000.0f,0.0f };
    data.m_vScale = { 207.0f,197.0f,1.0f };
    data.FileName = L"../../Resourse/1PhaseMap/Object/RBSpawn.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12f;
    m_pUVObj->Init();
    m_pUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pUVObj));

    //ZeroMemory(&info, sizeof(info));
    info.m_bValid = true;
    info.iID = m_SceneSpriteList.size() - 1;
    info.m_vPos = data.m_vPos;
    info.m_vScale = data.m_vScale;
    info.m_fDelay = 0.12f;
    info.m_iMaxFrame = m_SceneSpriteList[info.iID]->GetSize();

    m_SceneParticleList.push_back(info);






}

void C1PhaseScene::CreateDropObj()
{
    CSpriteUVObj* Newobj = new CSpriteUVObj;
    CSpriteData data;
  

    data.m_vPos = { randstep(-1300,1300),1.0f,0 };
    data.m_vScale = { 256,576,1 };
    data.FileName = L"../../Resourse/Dropobj/ContainerObj.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 4;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 28;
    Newobj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, Newobj));

    m_pDropObjList.push_back(Newobj);
    DropObj = new CParticle;
    DropObj->m_bValid = true;
    DropObj->iID = m_SceneSpriteList.size() - 1;
    DropObj->m_iIndex = m_SceneSpriteList.size() - 1;
    DropObj->m_vScale = data.m_vScale;
    DropObj->m_fDelay = 0.12f;
    DropObj->m_iMaxFrame = data.MaxUvSize;
    DropObj->m_SustainmentTime = 1.7; 
    DropObj->m_HitDelayTime = 0;


    m_pHitEff = new CSpriteUVObj;
    data.m_vPos = { 0.0f,-470.0f,0.0f };
    data.m_vScale = { 119.0f,125.0f,1.0f };
    data.FileName = L"../../Resourse/Dropobj/ObjHitEff.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 5;
    data.iRow = 2;
    data.m_fDelay = 0.09f;
    data.MaxUvSize = 7;
    
    m_pHitEff->SpriteInfo = data;
    m_pHitEff->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pHitEff->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x, data.m_vScale.y);
    m_SceneSpriteList.insert(std::make_pair(m_iSpriteIndex++, m_pHitEff));

  
    m_ObjHitSound= CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/Damage.mp3");
}

void C1PhaseScene::CreateMapObj()
{
    CreateBackGround();
    CreateBoss();
    CreateParticle();
    CreateFootHold(); 
    CreateDropObj();
    CreatePotal();
}
bool C1PhaseScene::Init()
{
    CScene::Init();
    CreateMapObj();
    m_pBoss->Init();
    LzState = NONE;

    return true;
}

bool C1PhaseScene::Frame(CPlayerObj* Target)
{
    CScene::Frame(Target);
    DropObjTimer += g_fSecondPerFrame;
    if (DropObjTimer>=DropObjCoolDown&& m_pBoss->Alive)
    { 
        DropObj->m_vPos = { randstep(-1300,1300) ,m_pDropObjList[0]->m_vPos.y,1 };
        DropObj->m_RT.SetRect({ DropObj->m_vPos.x+30,DropObj->m_vPos.y }, DropObj->m_vScale.x*0.5, DropObj->m_vScale.x);
        m_ObjParticleList.push_back(*DropObj);
        DropObjTimer = 0;
        
    }
   

    for (auto& Map : m_MapList)
    {
        Map->Frame();
    }
    for (auto& portal : m_pPortalList)
    {
        portal->Frame();
    }

    if (CInput::GetInstance().m_dwKeyState[VK_UP] == KEY_PUSH && m_pPortalList[0]->m_RT.ToRect(Target->m_RT))
    {
        Target->m_vPos = { 492.0f, -150.0f ,0};
    }
    if (CInput::GetInstance().m_dwKeyState[VK_UP] == KEY_PUSH &&m_pPortalList[1]->m_RT.ToRect(Target->m_RT))
    {
        Target->m_vPos = { -492.0f, -150.0f ,0};
    }

#pragma region Particle
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
    for (auto iter = m_ObjParticleList.begin(); iter != m_ObjParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
        if (info.m_bValid == false)
        {
            iter = m_ObjParticleList.erase(iter);
            info.m_bValid = true;
        }
        else
        {
            iter++;
        }

    }

    for (auto DropObj = m_ObjParticleList.begin(); DropObj != m_ObjParticleList.end(); DropObj++)
    {
        DropObj->m_HitDelayTime += g_fSecondPerFrame;
        if (DropObj->m_HitDelayTime >= DropObj->m_SustainmentTime)
        {
            DropObj->m_RT.m_pCenter.y = DropObj->m_RT.m_pCenter.y - (1200 * g_fSecondPerFrame);
            DropObj->m_RT.SetRect({ DropObj->m_RT.m_pCenter.x, DropObj->m_RT.m_pCenter.y }, DropObj->m_vScale.x * 0.8, DropObj->m_vScale.x * 0.8);
            if (DropObj->m_RT.ToRect(Target->m_RT))
            {
                m_ObjHitSound->EffectSoundPlay();
                DropObj->m_bValid = false;
                Target->HealthPoint -= 10000;
                DropObj->m_HitDelayTime = 0;

                info.m_bValid = true;
                info.iID = m_SceneSpriteList.size() - 1;
                info.m_vPos = { Target->m_vPos.x,Target->m_vPos.y+30,1 };
                info.m_vScale = m_SceneSpriteList[info.iID]->m_vScale;
                info.m_fDelay = 0.09f;
                info.m_SustainmentTime = 0.63;
                info.m_iMaxFrame = m_SceneSpriteList[info.iID]->SpriteInfo.MaxUvSize;
                m_ObjParticleList.push_back(info);



            }
        }

    }
#pragma endregion


    

    for (auto BossSkill : m_pBoss->m_pBossSkillList)
    {
        BossSkill->Frame();
    }

#pragma region LZstate

    if (LzState != NONE)
    {
        m_pLazerList[LzState]->Frame();
    }
    LzSkillCoolDown += g_fSecondPerFrame;
    if (LzSkillCoolDown > 15)
    {
        LzSkillCoolDown = 0;
        LzState = PRE;
    }
    if (LzState == PRE)
    {
        ChangeTime += g_fSecondPerFrame;
        if (ChangeTime >= 0.6)
        {
            LzState = LOOP;
            ChangeTime = 0;
        }
    }
    if (LzState == LOOP)
    {
        bool play;
        m_LazerSound->m_pChannel->isPlaying(&play);
        if (!play)
        {
            m_LazerSound->EffectSoundPlay();
        }
        ChangeTime += g_fSecondPerFrame;
        if (ChangeTime >= 4)
        {
            LzState = END;
            ChangeTime = 0;
        }
    }
    if (LzState == END)
    {
        bool play;
        m_LazerSound->m_pChannel->isPlaying(&play);
        if (play)
        {
            m_LazerSound->SoundStop();
        }
        ChangeTime += g_fSecondPerFrame;
        if (ChangeTime >= 0.72)
        {
            LzState = NONE;
            ChangeTime = 0;
        }
    }
    if (LzState == LOOP)
    {
        LzSkillHitDelay += g_fSecondPerFrame;
        if (m_pLazerList[LOOP]->m_RT.ToRect(Target->m_RT))
        {
            if (LzSkillHitDelay > 0.8)
            {
                Target->HealthPoint -= 30000;
                LzSkillHitDelay = 0;
            }

        }
    }

#pragma endregion

   

    if (m_pBoss->m_pAction != m_pBoss->m_pActionList[STATE_DEAD])
    {
      
    }
    else
    {
        m_pBoss->Drop = false;
        CVector2 rt = { m_pBoss->m_vPos.x,  m_pBoss->m_vPos.y };
        m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 0, m_pBoss->m_vScale.y * 0);

    }

    for (auto& hold : m_FootHoldList)
    {
     
        hold->Frame();
    }



   m_pSwooCore->Frame();
   m_pBoss->Frame();

   
   
  
  
   CVector2 rt = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };
   m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 3.0f, m_pBoss->m_vScale.y * 5.0f);

   
   if (m_pBoss->HealthPoint <= 0&& m_pBoss->Alive)
   {
       bool play;
       m_pBoss->m_DeadSound->m_pChannel->isPlaying(&play);
       if (!play)
       {
           m_pBoss->m_DeadSound->EffectSoundPlay();
       }
       m_pBoss->m_vPos.y -= 100.0f;
       m_pBoss->m_dwCurState = 1;
       m_pBoss->Alive = false;
       m_pBoss->m_pUVList.clear();
       m_pBoss->SetUVData(m_pBoss->m_pCSpriteDataList[1].iRow, m_pBoss->m_pCSpriteDataList[1].iCol);
        m_pBoss->m_pTexture = CTextureMgr::GetInstance().Load(m_pBoss->m_pCSpriteDataList[1].FileName);
       m_pBoss->SetScale(m_pBoss->m_pCSpriteDataList[1].m_vScale);
       CVector2 rt = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };
       m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 0, m_pBoss->m_vScale.y * 0);
       m_pBoss->m_iTexIndex = 0;
   }
   if (!m_pBoss->Alive&& m_pBoss->m_iTexIndex==53)
   {
       m_pBoss->m_bVaild = false;
       m_pBoss->m_iTexIndex = 0;    
       m_pBoss->m_dwCurState = 0;
       m_pBoss->Alive = false;
       m_pBoss->m_pUVList.clear();
       m_pBoss->SetUVData(m_pBoss->m_pCSpriteDataList[0].iRow, m_pBoss->m_pCSpriteDataList[0].iCol);
       m_pBoss->m_pTexture = CTextureMgr::GetInstance().Load(m_pBoss->m_pCSpriteDataList[0].FileName);
       m_pBoss->SetScale(m_pBoss->m_pCSpriteDataList[0].m_vScale);
       CVector2 rt = { m_pBoss->m_vPos.x,m_pBoss->m_vPos.y };
       m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 0, m_pBoss->m_vScale.y * 0);
   }

    return true;
}

bool C1PhaseScene::Render()
{
    CScene::Render();
    
 
    for (auto& Map : m_MapList)
    {
        Map->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        Map->Render();
    }
   
    if (m_pBoss->Alive)
    {
        m_pBoss->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pBoss->Render(0);
        m_pSwooCore->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pSwooCore->Render();

    }
    else
    {
        m_pSwooCore->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pSwooCore->Render();
        m_pBoss->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pBoss->Render(0);
    }
    for (auto& hold : m_FootHoldList)
    {
        hold->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        hold->Render();
    }
    for (auto& portal : m_pPortalList)
    {
        portal->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        portal->Render(0);
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


    if (m_pBoss->Alive&& LzState != NONE)
    {
        m_pLazerList[LzState]->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pLazerList[LzState]->Render(0);
    }
 
    for (auto iter = m_ObjParticleList.begin(); iter != m_ObjParticleList.end(); iter++)
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

    m_pBoss->BossHPBar.SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
    m_pBoss->BossHPBar.Render();

    return true;
}

bool C1PhaseScene::Release()
{
    CScene::Release();
    for (auto& Map : m_MapList)
    {
        Map->Release();
    }

    for (auto obj : m_SceneSpriteList)
    {
        obj.second->Release();
        delete obj.second;
    }
    m_SceneSpriteList.clear();

    return true;
}
