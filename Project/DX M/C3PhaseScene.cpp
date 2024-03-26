#include "C3PhaseScene.h"
#include"CoreInterface.h"
#include"CSKill1State.h"
#include"CSKill2State.h"
void C3PhaseScene::CreateTile()
{
    std::unique_ptr<CMapObj> pMapobj;
    float intervalx = 257.0f;
    for (int i = 0; i < 11; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-1430.0f + intervalx, 515.0f, 1.0f));
        pMapobj->SetScale(CVector3(257.0f, 753.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/3PhaseMap/Back1.png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
        intervalx += 257.0f;

    }
    intervalx = 788.0f;
    for (int i = 0; i < 3; ++i)
    {
        pMapobj = std::make_unique<CMapObj>();
        pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        pMapobj->SetPos(CVector3(-1430.0f + intervalx, -370.0f, 1.0f));
        pMapobj->SetScale(CVector3(788.0f, 160.0f, 1.0f));
        pMapobj->Create(L"../../Resourse/3PhaseMap/Back2.png", L"../../Resourse/Plane.hlsl");
        m_MapList.push_back(std::move(pMapobj));
        intervalx += 788.0f;

    }

    pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(130.0f, -170.0f, 1.0f));
    pMapobj->SetScale(CVector3(332.0f, 332.0f, 1.0f));
    pMapobj->Create(L"../../Resourse/3PhaseMap/Back3.png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));




}
void C3PhaseScene::CreateGround()
{
    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(0.0f, 102.0f, 0.0f));
    pMapobj->SetScale(CVector3(1406.0f, 643.0f, 1.0f));

    pMapobj->Create(L"../../Resourse/3PhaseMap/3Phase Back.png", L"../../Resourse/Plane.hlsl");
    m_MapList.push_back(std::move(pMapobj));


    /*   pMapobj = std::make_unique<CMapObj>();
       pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
       pMapobj->SetPos(CVector3(0.0f, 170.0f, 0.0f));
       pMapobj->SetScale(CVector3(210.0f, 186.0f, 1.0f));

       pMapobj->Create(L"../../Resourse/1PhaseMap/Back/3.png", L"../../Resourse/Plane.hlsl");
       m_MapList.push_back(std::move(pMapobj));*/







}
void C3PhaseScene::CreateHold()
{

    std::unique_ptr<CMapObj> pMapobj = std::make_unique<CMapObj>();
    pMapobj->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    pMapobj->SetPos(CVector3(0.0f, -670.0f, 0.0f));
    pMapobj->SetScale(CVector3(1406.0f, 170.0f, 1.0f));
    CVector2 rt = { pMapobj->m_vPos.x,pMapobj->m_vPos.y };
    pMapobj->SetRect(rt, pMapobj->m_vScale.x * 2.0f, (pMapobj->m_vScale.y * 2.0f) - 60.0f);
    pMapobj->Create(L"../../Resourse/3PhaseMap/3Phase foothold.png", L"../../Resourse/Plane.hlsl");
    m_FootHoldList.push_back(std::move(pMapobj));


}
void C3PhaseScene::CreateBoss()
{

    CSpriteData data;
    data.m_vPos = { 600.0f,-300.0f,0 };
    data.m_vScale = { 259,255,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PStand.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 2;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 12;
    m_pBoss->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    CVector2 rt = { m_pBoss->m_vPos.x, m_pBoss->m_vPos.y };

    m_pBoss->m_pCSpriteDataList.push_back(data);

    data;

    data.m_vScale = { 259,255,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PMove.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 2;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 12;

    m_pBoss->m_pCSpriteDataList.push_back(data);

    data;

    data.m_vScale = { 771,436,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PATTACK.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 5;
    data.m_fDelay = 0.12;
    data.MaxUvSize = 35;

    m_pBoss->m_pCSpriteDataList.push_back(data);

    data.m_vScale = {421,605,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PDie.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 6;
    data.m_fDelay = 0.15;
    data.MaxUvSize = 41;

    m_pBoss->m_pCSpriteDataList.push_back(data);


    data.m_vScale = { 388,654,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PSkill1.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 4;
    data.m_fDelay = 0.09;
    data.MaxUvSize = 26;

    m_pBoss->m_pCSpriteDataList.push_back(data);

    data.m_vScale = { 688,588,1 };
    data.FileName = L"../../Resourse/Boss/3Phase/3PSkill2.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 2;
    data.m_fDelay = 0.15;
    data.MaxUvSize = 8;

    m_pBoss->m_pCSpriteDataList.push_back(data);

    CBossSkill* input = new CBossSkill;
    input->m_pSpriteUVObj = new CSpriteUVObj;
    data.m_vScale = { 282,282,0 };
    data.iRow = 1;
    data.iCol = 7;
    data.FileName = L"../../Resourse/Boss/3Phase/RedBall.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.12;
    input->m_SustainmentTime = 20;
    input->m_pSpriteUVObj->Init();
    input->m_pSpriteUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    input->m_SpriteList.insert(std::make_pair(0, input->m_pSpriteUVObj));
    m_pBoss->m_pBossSkillList.push_back(input);

    CBossSkill* input2 = new CBossSkill;
    input2 = new CBossSkill;
    input2->m_pSpriteUVObj = new CSpriteUVObj;
    data.m_vScale = { 133,140,0 };
    data.iRow = 1;
    data.iCol = 6;
    data.FileName = L"../../Resourse/Boss/3Phase/RedHit.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.09;
    input2->m_SustainmentTime = 0.54;
    input2->m_pSpriteUVObj->Init();
    input2->m_pSpriteUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    input2->m_SpriteList.insert(std::make_pair(0, input2->m_pSpriteUVObj));
    m_pBoss->m_pBossSkillList.push_back(input2);


    CBossSkill* input3 = new CBossSkill;
    input3->m_pSpriteUVObj = new CSpriteUVObj;
    data.m_vScale = { 370,218,0 };
    data.iRow = 1;
    data.iCol = 8;
    data.FileName = L"../../Resourse/Boss/3PAttakEff.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.09;
    input3->m_SustainmentTime = 0.72;
    input3->m_pSpriteUVObj->Init();
    input3->m_pSpriteUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    input3->m_SpriteList.insert(std::make_pair(0, input3->m_pSpriteUVObj));
    m_pBoss->m_pBossSkillList.push_back(input3);





    m_pBoss->m_DeadSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/3PDie.mp3");
    m_pBoss->MaxBossHP = 800000000;
    m_pBoss->HealthPoint = m_pBoss->MaxBossHP;
    m_pBoss->Drop = true;
    m_pBoss->FSM(CFSMManager::GetInstance().Add(0));
    m_pBoss->m_pActionList[STATE_SKILL1] = (NpcState*)new CSKill1State(m_pBoss.get());
    m_pBoss->m_pActionList[STATE_SKILL2] = (NpcState*)new CSKill2State(m_pBoss.get());
    m_pBoss->MoveSpeed = 200.0;

}
void C3PhaseScene::CreateDropObj()
{
    CSpriteUVObj* Newobj = new CSpriteUVObj;
    CSpriteData data;
    

    data.m_vPos = { randstep(-1300,1300),400.0f,0 };
    data.m_vScale = { 610,1037,1 };
    data.FileName = L"../../Resourse/Dropobj/chush.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 7;
    data.iRow = 3;
    data.m_fDelay = 0.12f;
    data.MaxUvSize = 20;
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
    DropObj->m_SustainmentTime = 1.3;
    DropObj->m_HitDelayTime = 0;
    m_ObjHitSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/Damage.mp3");

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
}
bool C3PhaseScene::Init()
{
    CScene::Init();
    CreateTile();
    CreateGround();
    CreateHold();
    CreateBoss();
    CreateDropObj();
    m_pBoss->Init();
    m_pBoss->m_vPos.y -= 80.0f;
    return true;
}

bool C3PhaseScene::Frame(CPlayerObj* Target)
{
   

    CScene::Frame(Target);
    for (auto& Map : m_MapList)
    {
        Map->Frame();
    }
    DropObjTimer += g_fSecondPerFrame;
    if (DropObjTimer >= DropObjCoolDown && m_pBoss->Alive)
    {
        DropObj->m_vPos = { randstep(-1300,1300) ,m_pDropObjList[0]->m_vPos.y,1 };
        DropObj->m_RT.SetRect({ DropObj->m_vPos.x,DropObj->m_vPos.y }, DropObj->m_vScale.x*2, DropObj->m_vScale.x);
        m_ObjParticleList.push_back(*DropObj);
        DropObjTimer = 0;

    }
    m_pBoss->Frame();
    for (auto& hold : m_FootHoldList)
    {
        hold->Frame();
    }

    if (m_pBoss->m_pAction != m_pBoss->m_pActionList[STATE_DEAD])
    {

        CVector2 rt = { m_pBoss->m_vPos.x,  m_pBoss->m_vPos.y };
        m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 1.5f, m_pBoss->m_vScale.y * 1.5f);
        // m_pTexture = m_pTextureList[PState];
    }
    else
    {
        m_pBoss->Drop = false;
        CVector2 rt = { m_pBoss->m_vPos.x,  m_pBoss->m_vPos.y };
        m_pBoss->SetRect(rt, m_pBoss->m_vScale.x * 0, m_pBoss->m_vScale.y * 0);

    }

    m_pBoss->m_pBeforeAction = m_pBoss->m_pAction;

    m_pBoss->Process(Target);
   
    //위치조정 예정
#pragma region ResetPos
    if (m_pBoss->m_pBeforeAction == m_pBoss->m_pActionList[STATE_STAND])
    {
        
        if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_ATTACK])
        {
            if (m_pBoss->FaceRight)
            {
                m_pBoss->m_vPos.x += 160.0f;
            }
            else
            {
                m_pBoss->m_vPos.x -= 160.0f;
            }
            m_pBoss->m_vPos.y += 40.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_SKILL1])
        {
            m_pBoss->m_vPos.y += 380.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_DEAD])
        {
            m_pBoss->m_vPos.y += 300.0f;
        }
    }

    if (m_pBoss->m_pBeforeAction == m_pBoss->m_pActionList[STATE_TRACE])
    {
        if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_ATTACK])
        {
            if (m_pBoss->FaceRight)
            {
                m_pBoss->m_vPos.x += 160.0f;

            }
            else
            {
                m_pBoss->m_vPos.x -= 160.0f;
            }

            m_pBoss->m_vPos.y += 40.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_SKILL1])
        {
            m_pBoss->m_vPos.y += 380.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_DEAD])
        {
            m_pBoss->m_vPos.y += 300.0f;
        }
    }
    if (m_pBoss->m_pBeforeAction == m_pBoss->m_pActionList[STATE_ATTACK])
    {
        if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_ATTACK] &&m_pBoss->isflip)
        {
            if (m_pBoss->BeforeLeft)
            {
                m_pBoss->m_vPos.x += 320.0f;
                m_pBoss->isflip = false;
            }
            if (m_pBoss->BeforeRight)
            {
                m_pBoss->m_vPos.x -= 320.0f;
                m_pBoss->isflip = false;
            }

        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_TRACE])
        {
            if (m_pBoss->FaceRight)
            {
                m_pBoss->m_vPos.x -= 160.0f;
            }
            else
            {
                m_pBoss->m_vPos.x += 160.0f;
            }
            m_pBoss->m_vPos.y -= 40.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_SKILL1])
        {
            m_pBoss->m_vPos.y += 340.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_DEAD])
        {
            m_pBoss->m_vPos.y += 260.0f;
        }
     
    }
    if (m_pBoss->m_pBeforeAction == m_pBoss->m_pActionList[STATE_SKILL1])
    {
       
        if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_TRACE])
        {
            
            m_pBoss->m_vPos.y -= 380.0f;
        }
        else if (m_pBoss->m_pAction == m_pBoss->m_pActionList[STATE_DEAD])
        {
            m_pBoss->m_vPos.y -= 300.0f;
        }
    }

   
  

#pragma endregion

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
            DropObj->m_RT.m_pCenter.y = DropObj->m_RT.m_pCenter.y - (8000 * g_fSecondPerFrame);
            DropObj->m_RT.SetRect({ DropObj->m_RT.m_pCenter.x, DropObj->m_RT.m_pCenter.y }, DropObj->m_vScale.x * 1.5, DropObj->m_vScale.x * 1.5);
            if (DropObj->m_RT.ToRect(Target->m_RT))
            {
                m_ObjHitSound->EffectSoundPlay();
                DropObj->m_bValid = false;
                Target->HealthPoint -= 45000;
                DropObj->m_HitDelayTime = 0;
                info.m_bValid = true;
                info.iID = m_SceneSpriteList.size() - 1;
                info.m_vPos = { Target->m_vPos.x,Target->m_vPos.y + 30,1 };
                info.m_vScale = m_SceneSpriteList[info.iID]->m_vScale;
                info.m_fDelay = 0.09f;
                info.m_SustainmentTime = 0.63;
                info.m_iMaxFrame = m_SceneSpriteList[info.iID]->SpriteInfo.MaxUvSize;
                m_ObjParticleList.push_back(info);

            }
        }

    }
    for (auto BossSkill : m_pBoss->m_pBossSkillList)
    {
        BossSkill->Frame();
    }


    for (auto& BossSkill : m_pBoss->m_pBossSkillList[0]->m_ParticleList)
    {
        m_pBoss->m_pBossSkillList[0]->m_AccumulatedTime += g_fSecondPerFrame;
        if (BossSkill.m_RT.ToRect(Target->m_RT))
        {

            if (m_pBoss->m_pBossSkillList[0]->m_AccumulatedTime > m_pBoss->m_pBossSkillList[0]->m_Delay)
            {
                m_pBoss->m_pBossSkillList[1]->LoadEff({ Target->m_vPos.x,Target->m_vPos.y });
                Target->HealthPoint -= m_pBoss->m_pBossSkillList[0]->SKillDamage;
                m_pBoss->m_pBossSkillList[0]->m_AccumulatedTime = 0;
            }

        }
    }

    return true;
}

bool C3PhaseScene::Render()
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

    m_pBoss->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
    m_pBoss->Render(m_pBoss->FaceRight);

    for (auto BossSkill : m_pBoss->m_pBossSkillList)
    {
        BossSkill->Render(0, m_pBoss->m_vPos);
    }
    m_pBoss->BossHPBar.SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
    m_pBoss->BossHPBar.Render();
    return true;
}

bool C3PhaseScene::Release()
{
    CScene::Release();
    for (auto& Map : m_MapList)
    {
        Map->Release();
    }
    return true;
}
