#include "CSkill.h"
#include"CoreInterface.h"


void CSkill::LoadSkill(bool face,CVector2 PlayerPos)
{
    
    CParticle data;
    ZeroMemory(&data, sizeof(data));
    data.m_bValid = true;
    data.iID =0;
    data.m_vScale = { 702.0f,353.0f,1.0f };
    data.m_RT.m_pPosition = PlayerPos;
    if (face)
    {
        data.m_RT.m_pPosition.x = PlayerPos.x + 400.0f;
       
    }
    else
    {
        data.m_RT.m_pPosition.x = PlayerPos.x - 400.0f;
       
    };

    data.m_RT.SetRect({ data.m_RT.m_pPosition }, data.m_vScale.x-300.0f, data.m_vScale.y);
    data.m_fDelay = 0.04625;
    data.m_iMaxFrame = m_SpriteList[data.m_iIndex]->GetSize() - 4;
    m_ParticleList.push_back(data);


   

  
}

bool CSkill::Init()
{
    CSpriteUVObj::Init();


    return false;
}

bool CSkill::Frame()
{
    for (auto iter = m_ParticleList.begin(); iter != m_ParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
        if (info.m_bValid == false)
        {
            iter = m_ParticleList.erase(iter);
            m_AccumulatedTime = 0;
            MaxSoundCount = 0;
        }
        else
        {
            iter++;
        }

    }


    return true;

}

bool CSkill::Render(bool face,CVector3 PlayerPos)
{
    for (std::list<CParticle>::iterator iter = m_ParticleList.begin();
        iter != m_ParticleList.end();
        iter++)
    {

        CParticle& info = *iter;
        CSpriteUVObj* pBaseObj = m_SpriteList[info.iID];
        pBaseObj->SetPos(PlayerPos);
        if (face)
        {
            pBaseObj->m_vPos.x = PlayerPos.x + 400.0f;
        }
        else
        {
            pBaseObj->m_vPos.x = PlayerPos.x - 400.0f;
        };
        pBaseObj->SetScale(info.m_vScale);
        pBaseObj->Frame();
        pBaseObj->m_iTexIndex = info.m_iIndex;
        pBaseObj->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        pBaseObj->Render(face);

    }

    return true;
}

bool CSkill::Release()
{
    CSpriteUVObj::Release();
    m_pSpriteUVObj->Release();
    delete m_pSpriteUVObj;
    return true;
}



