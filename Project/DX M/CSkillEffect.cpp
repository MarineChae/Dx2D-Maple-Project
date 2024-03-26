#include "CSkillEffect.h"
#include"CoreInterface.h"

void    CSkillEffect::LoadEffect(CVector2 PlayerPos)
{
    CParticle data;
    ZeroMemory(&data, sizeof(data));
    data.m_bValid = true;
    data.iID = 0;
    data.m_vScale = { 264.0f,229.0f,1.0f };
    data.m_vPos = { PlayerPos.x ,PlayerPos.y ,1 };
    data.m_fDelay = 0.062f;
    data.m_iMaxFrame = m_SpriteList[data.m_iIndex]->GetSize();
    m_ParticleList.push_back(data);
    
    m_EffSound->EffectSoundPlay();
    
}
bool CSkillEffect::Frame()
{
    for (auto iter = m_ParticleList.begin(); iter != m_ParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
        if (info.m_bValid == false)
        {
           
            
            iter = m_ParticleList.erase(iter);
            MaxSoundCount = 0;
            
        }
        else
        {
            iter++;
        }

    }

    return true;

	
}

bool CSkillEffect::Render(CVector3 PlayerPos)
{
    for (std::list<CParticle>::iterator iter = m_ParticleList.begin();
        iter != m_ParticleList.end();
        iter++)
    {

        CParticle& info = *iter;
        CSpriteUVObj* pBaseObj = m_SpriteList[info.iID];
        pBaseObj->SetPos(info.m_vPos);
               
        pBaseObj->SetScale(info.m_vScale);
        pBaseObj->Frame();
        pBaseObj->m_iTexIndex = info.m_iIndex;
        pBaseObj->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        pBaseObj->Render(0);

    }
    
	return true;
}

bool CSkillEffect::Release()
{
	return true;
}
