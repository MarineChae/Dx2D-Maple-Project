#include "CBoss.h"
#include"CoreInterface.h"
#include"CStandState.h"
#include"CTraceState.h"
#include"CAttackState.h"
#include"CDeadState.h"
#include"CSKill1State.h"
#include"CSKill2State.h"
void CBoss::Process(CPlayerObj* obj)
{
    if (m_bVaild == false)
    {
        return ;
    }
    m_pAction->Process(obj);
}

void CBoss::FSM(int Index)
{
    m_pFSM = CFSMManager::GetInstance().GetPtr(Index);
    m_pActionList[STATE_STAND] = (NpcState*)new CStandState(this);
    m_pActionList[STATE_TRACE]= (NpcState*)new CTraceState(this);
    m_pActionList[STATE_ATTACK] = (NpcState*)new CAttackState(this);
    m_pActionList[STATE_DEAD] = (NpcState*)new CDeadState(this);
    //m_pActionList[STATE_SKILL1] = (NpcState*)new CSKill1State(this);
    //m_pActionList[STATE_SKILL2] = (NpcState*)new CSKill2State(this);
    m_pAction = m_pActionList[STATE_STAND];
    m_dwCurState = STATE_STAND;
}

void CBoss::SetTransition(DWORD Event)
{
    
        m_dwCurState = m_pFSM->StateTransition(m_dwCurState, Event);
        m_pAction = m_pActionList[m_dwCurState];
        m_iTexIndex = 0;
        m_pUVList.clear();
        SetUVData(m_pCSpriteDataList[m_dwCurState].iRow, m_pCSpriteDataList[m_dwCurState].iCol);
        m_pTexture = CTextureMgr::GetInstance().Load(m_pCSpriteDataList[m_dwCurState].FileName);
        SetScale(m_pCSpriteDataList[m_dwCurState].m_vScale);
        CVector2 rt = { m_vPos.x,m_vPos.y };
        SetRect(rt, m_vScale.x * 2.0f, m_vScale.y * 2.0f);
   
   

}

bool CBoss::Init()
{
    BossHPBar.Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
    BossHPBar.SetPos({ 0,100,1 });
    BossHPBar.SetScale({ 100,10,1 });
    BossHPBar.Create(L"../../Resourse/HPBar.png", L"../../Resourse/Plane.hlsl");
    m_AttackSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/Attack1.mp3");
    m_SkillSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/BossSound/Skill2.mp3");

   

    return true;
}

bool CBoss::Frame()
{
    if (m_bVaild == false)
    {
        return false;
    }
    CPlaneObj::Frame();

    
 

    m_AccumulatedTime += g_fSecondPerFrame;

    if (m_AccumulatedTime >= m_pCSpriteDataList[m_dwCurState].m_fDelay)
    {
        m_iTexIndex++;
        if (m_iTexIndex >= m_pCSpriteDataList[m_dwCurState].MaxUvSize)
        {
           
            IsDelay = false;
            AfterDelay = 0;
            m_iTexIndex = 0;
            m_AccumulatedTime = 0;
        }
        m_AccumulatedTime -= m_pCSpriteDataList[m_dwCurState].m_fDelay;
    }


   // float tmep = static_cast<float> (HealthPoint) / MaxBossHP;
   // BossHPBar.Frame();
   // BossHPBar.SetScale({ 100 * tmep,10,1 });
   // BossHPBar.SetPos({ m_vPos.x,m_vPos.y + 140,1 });


    float tmep = static_cast<float> (HealthPoint) / MaxBossHP;
    BossHPBar.Frame();
    BossHPBar.SetScale({ 1015 * tmep,13,1 });
    float movebar = (1015 * tmep);
    BossHPBar.SetPos({ -1030 + movebar , 715.0f, 1 });
    return true;

}

void CBoss::Move(CVector2 vTarget)
{
    if (m_bVaild == false)
    {
        return;
    }
    if (Drop == true)
    {

        if (MaxDropSpeed >= DropSpeed)
        {
            DropSpeed += 1500.0f * g_fSecondPerFrame;
        }
        m_vPos.y -= DropSpeed * g_fSecondPerFrame;

    }


    CVector3 tg(vTarget.x, vTarget.y, 0);
    tg *= g_fSecondPerFrame* MoveSpeed;
    m_vPos = m_vPos + tg ;


}

bool CBoss::Render(bool face)
{
    if (m_bVaild == false)
    {
        return false;
    }
    PreRender();
   
    CUVRect uv = m_pUVList[m_iTexIndex];
    if (face)
    {
        m_vVertexList[0].Tex.x = uv.m_Max.x;
        m_vVertexList[0].Tex.y = uv.m_Min.y;
        m_vVertexList[1].Tex = uv.m_Min;
        m_vVertexList[2].Tex = uv.m_Max;
        m_vVertexList[3].Tex = m_vVertexList[2].Tex;
        m_vVertexList[4].Tex = m_vVertexList[1].Tex;
        m_vVertexList[5].Tex.x = uv.m_Min.x;
        m_vVertexList[5].Tex.y = uv.m_Max.y;
    
    }
    else
    {
        m_vVertexList[0].Tex = uv.m_Min;
        m_vVertexList[1].Tex.x = uv.m_Max.x;
        m_vVertexList[1].Tex.y = uv.m_Min.y;
    
        m_vVertexList[2].Tex.x = uv.m_Min.x;
        m_vVertexList[2].Tex.y = uv.m_Max.y;
    
    
        m_vVertexList[3].Tex = m_vVertexList[2].Tex;
        m_vVertexList[4].Tex = m_vVertexList[1].Tex;
    
        m_vVertexList[5].Tex = uv.m_Max;
    }
    m_pImmediateContext->UpdateSubresource(m_pVertexBuffer, 0, nullptr, &m_vVertexList.at(0), 0, 0);
    
    std::wstring msg = L"[BOSS HP : ]";
    msg += std::to_wstring(HealthPoint);


    CWriter::GetInstance().AddText(msg, 50, 110, D2D1::ColorF(0, 1, 1, 1));
    

    PostRender();


    return true;

}

