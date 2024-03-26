#include "CBossSkill.h"
#include"CoreInterface.h"


void CBossSkill::LoadSkill(bool face, CVector2 PlayerPos)
{

    CParticle data;
    ZeroMemory(&data, sizeof(data));
    data.m_bValid = true;
    data.iID = 0;
    data.m_vScale = m_SpriteList[data.m_iIndex]->m_vScale;
    data.m_RT.m_pPosition = PlayerPos;
    data.m_vPos = { PlayerPos.x, PlayerPos.y,0 };
    data. m_vDir = { randstep(-1,1), 1,0 };
    data.m_RT.SetRect({ data.m_RT.m_pPosition }, data.m_vScale.x , data.m_vScale.y);
    data.m_fDelay = 0.12;
    data.m_iMaxFrame = m_SpriteList[data.m_iIndex]->GetSize();
    m_ParticleList.push_back(data);





}
void CBossSkill::LoadEff( CVector2 PlayerPos)
{

    CParticle data;
    ZeroMemory(&data, sizeof(data));
    data.m_bValid = true;
    data.iID = 0;
    data.m_vScale = m_SpriteList[data.m_iIndex]->m_vScale;
    data.m_vPos = { PlayerPos.x, PlayerPos.y,0 };
    data.m_fDelay = 0.12;
    data.m_SustainmentTime = m_SpriteList[data.m_iIndex]->m_SustainmentTime;
    data.m_iMaxFrame = m_SpriteList[data.m_iIndex]->GetSize();
    m_ParticleList.push_back(data);





}
bool CBossSkill::Frame()
{
    
    for (auto iter = m_ParticleList.begin(); iter != m_ParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
       
        if (info.m_bValid == false)
        {
             iter = m_ParticleList.erase(iter);
           
     
        }
        else
        {
            CVector3 velocity = iter->m_vDir * g_fSecondPerFrame * 500.0f;
            iter->m_SustainmentTime += g_fSecondPerFrame;
            iter->m_vPos = iter->m_vPos + velocity;
            if (iter->m_vPos.x <= -Map_XSize)
            {

                iter->m_vDir.x *= -1.0f;
                iter->m_vPos.x = -Map_XSize;

            }
            if (iter->m_vPos.y <= -Map_YSize)
            {

                iter->m_vDir.y *= -1.0f;
                iter->m_vPos.y = -Map_YSize;

            }
            if (iter->m_vPos.x >= Map_XSize)
            {

                iter->m_vDir.x *= -1.0f;
                iter->m_vPos.x = Map_XSize;

            }
            if (iter->m_vPos.y >= Map_YSize)
            {

                iter->m_vDir.y *= -1.0f;
                iter->m_vPos.y = Map_YSize;

            }
            iter->m_RT.SetRect({ iter->m_vPos.x,iter->m_vPos.y }, iter->m_vScale.x*1.5,iter->m_vScale.y*1.5 );
            iter++;
        }

    }
   
    


    return true;

}

bool CBossSkill::Render(bool face, CVector3 PlayerPos)
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
        if (info.iID==0&&(info.m_iIndex >= info.m_iMaxFrame-1&& info.m_SustainmentTime <= m_SustainmentTime))
        {
            info.m_iIndex = 0;
        }
        else
        {
            
        }
    
        pBaseObj->m_iTexIndex = info.m_iIndex;
        pBaseObj->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        pBaseObj->Render(face);

    }
    return true;
}

bool CBossSkill::Release()
{
    CSpriteUVObj::Release();
    m_pSpriteUVObj->Release();
    delete m_pSpriteUVObj;
    return true;
}



