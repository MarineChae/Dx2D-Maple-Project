#include "C5thSkill.h"
#include"CoreInterface.h"


void C5thSkill::LoadSkill(bool face, CVector2 PlayerPos)
{

  
  
}

bool C5thSkill::Init()
{
    m_pSkillUVObj = new CSpriteUVObj;
    CSpriteData data;
    data.iRow = 1;
    data.iCol = 6;
    data.m_vPos = { 0,0, 1 };
    data.m_vScale = { 853.0f,652.0f,1.0f };
    data.FileName = L"../../Resourse/howling/5th1.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.06f;
    data.MaxUvSize = 6;
    m_pSkillUVObj->SpriteInfo = data;
    m_pSkillUVObj->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x * 2, data.m_vScale.y * 2.0f);
    m_pSkillUVObj->Init();
    m_pSkillUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pSpriteUVObj.push_back(m_pSkillUVObj);

    m_pSkillUVObj = new CSpriteUVObj;

    data.iRow = 4;
    data.iCol = 7;
    data.m_vPos = { 0,0, 1 };
    data.m_vScale = { 822.0f,663.0f,1.0f };
    data.FileName = L"../../Resourse/howling/5th2.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.06f;
    data.MaxUvSize = 26;
    m_pSkillUVObj->SpriteInfo = data;
    m_pSkillUVObj->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x * 2, data.m_vScale.y * 2.0f);
    m_pSkillUVObj->Init();
    m_pSkillUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pSpriteUVObj.push_back(m_pSkillUVObj);


    m_pSkillUVObj = new CSpriteUVObj;
    
    data.iRow = 3;
    data.iCol = 7;
    data.m_vPos = {0,0, 1 };
    data.m_vScale = { 2283.0f,1173.0f,1.0f };
    data.FileName = L"../../Resourse/howling/5th3.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.06f;
    data.MaxUvSize = 18;
    m_pSkillUVObj->SpriteInfo = data;
    m_pSkillUVObj->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x * 2, data.m_vScale.y * 2.0f);
    m_pSkillUVObj->Init();
    m_pSkillUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pSpriteUVObj.push_back(m_pSkillUVObj);


    m_pSkillUVObj = new CSpriteUVObj;
   
    data.iRow = 3;
    data.iCol = 7;
    data.m_vPos = { 0,0, 1 };
    data.m_vScale = { 2256.0f,1032.0f,1.0f };
    data.FileName = L"../../Resourse/howling/5th4.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.06f;
    data.MaxUvSize = 19;
    m_pSkillUVObj->SpriteInfo = data;
    m_pSkillUVObj->SetRect({ data.m_vPos.x,data.m_vPos.y }, data.m_vScale.x * 2, data.m_vScale.y * 2.0f);
    m_pSkillUVObj->Init();
    m_pSkillUVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_pSpriteUVObj.push_back(m_pSkillUVObj);

    
    CSound* input = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/5th/5thPre.mp3");
    m_SoundList.push_back(input);
    input = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/5th/5thLoop.mp3");
    m_SoundList.push_back(input);

    input = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/5th/5thUse.mp3");
    m_SoundList.push_back(input);


    return true;
}

bool C5thSkill::Frame(CBoss* boss, CPlayableCharacter* player, std::vector<std::shared_ptr<DamageIndicator>> Indicator)
{
    if (SkillCollDown <= 0)
    {
        SkillCollDown = 0;
        Isok = true;
    }
    else
    {
        SkillCollDown -= g_fSecondPerFrame;
    }

    if (IsUse)
    {
        if (m_pSpriteUVObj[m_Index]->SpriteInfo.MaxUvSize-1 <= m_pSpriteUVObj[m_Index]->m_iTexIndex)
        {
           
           
            m_pSpriteUVObj[m_Index]->Frame();
            m_pSpriteUVObj[m_Index]->m_iTexIndex = 0;
            m_Index++;
            if (m_Index > 3)
            {
                m_Index = 0;
                IsUse = false;
                player->IsAttack = false;
            }
        }
        else
        {
            m_pSpriteUVObj[m_Index]->Frame();
        }

        if (boss->m_bVaild)
        {
            if (m_Index == 1)
            {
                if (m_pSpriteUVObj[m_Index]->m_RT.ToRect(boss->m_RT))
                {
                    m_HitDelay += g_fSecondPerFrame;

                    if (m_HitDelay > 0.1)
                    {
                        m_HitSound->EffectSoundPlay();
                        boss->HealthPoint -= SKillDamage;
                        m_HitDelay -= 0.1;
                        float yInterval = 30;
                        for (auto& DamageLine : Indicator)
                        {
                            if (!DamageLine->IsVaild)
                            {
                                DamageLine->Frame(SKillDamage, boss->m_vPos.x + 125, boss->m_vPos.y+20 + yInterval);
                                DamageLine->IsVaild = true;
                                break;
                            }
                            yInterval += 30;
                        }

                    }

                }
            }
            else
            {
                if (m_pSpriteUVObj[m_Index]->m_RT.ToRect(boss->m_RT))
                {
                    m_HitDelay += g_fSecondPerFrame;

                    if (m_HitDelay > 0.05)
                    {
                        m_HitSound->EffectSoundPlay();
                        boss->HealthPoint -= SKillDamage;
                        m_HitDelay -= 0.05;
                        float yInterval = 30;
                        for (auto& DamageLine : Indicator)
                        {
                            if (!DamageLine->IsVaild)
                            {
                                DamageLine->Frame(SKillDamage, boss->m_vPos.x+125, boss->m_vPos.y + 20 + yInterval);
                                DamageLine->IsVaild = true;
                                break;
                            }
                            yInterval += 30;
                        }

                    }

                }
            }
            

        }
        bool playing;
        if (m_Index == 3)
        {
            m_SoundList[2]->m_pChannel->isPlaying(&playing);
            if (!playing)
            {
                m_SoundList[2]->EffectSoundPlay();
            }
        }
        else
        {
            m_SoundList[m_Index]->m_pChannel->isPlaying(&playing);
            if (!playing)
            {
                m_SoundList[m_Index]->EffectSoundPlay();
            }
        }
       
    }



    return true;

}

bool C5thSkill::Render(bool face, CVector3 PlayerPos)
{
    
    if (IsUse)
    {
        m_pSpriteUVObj[0]->m_vPos = { PlayerPos.x,PlayerPos.y,1 };
        m_pSpriteUVObj[1]->m_vPos = { PlayerPos.x,PlayerPos.y,1 };
        m_pSpriteUVObj[2]->m_vPos = { PlayerPos.x,PlayerPos.y,1 };
        m_pSpriteUVObj[3]->m_vPos = { PlayerPos.x,PlayerPos.y,1 };
        m_pSpriteUVObj[m_Index]->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        m_pSpriteUVObj[m_Index]->Render(face);
    }
    return true;
}

bool C5thSkill::Release()
{
   


    return true;
}



