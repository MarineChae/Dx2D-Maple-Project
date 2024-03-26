#include "Sample.h"
#include"CoreInterface.h"

//temp 
int frameCount = 0;


extern float Window_Width = 1360.0f;
extern float Window_Height = 768.0f;
extern float  Map_XSize = 1833.0f;
extern float   Map_YSize =1000.0f;


bool Sample::CreatePlayer()
{
    CSpriteData data;
    PlayerSkill.m_pSpriteUVObj = new CSpriteUVObj;
    data.iRow = 4;
    data.iCol = 5;
    data.m_vPos = { 100.0f,0.0f,0.0f };
    data.m_vScale = { 100.0f,100.0f,100.0f };
    data.FileName = L"../../Resourse/PlayerCharacter/SKILLEFFECT.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.04625;
    PlayerSkill.m_pSpriteUVObj->Init();
    PlayerSkill.m_pSpriteUVObj->Load(m_pDevice, m_pImmediateContext, data);
    PlayerSkill.m_SpriteList.insert(std::make_pair(m_iTexIndex++, PlayerSkill.m_pSpriteUVObj));

    SkillEff.m_pSpriteUVObj = new CSpriteUVObj;
    data.iRow = 2;
    data.iCol = 5;
    data.m_vPos = { 100.0f,0.0f,0.0f };
    data.m_vScale = { 100.0f,100.0f,100.0f };
    data.FileName = L"../../Resourse/PlayerCharacter/SKILL1HIT.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.062;
    SkillEff.m_pSpriteUVObj->Init();
    SkillEff.m_pSpriteUVObj->Load(m_pDevice, m_pImmediateContext, data);
    SkillEff.m_SpriteList.insert(std::make_pair(0, SkillEff.m_pSpriteUVObj));

    m_UVObj = new CSpriteUVObj;

    data.iRow = 2;
    data.iCol = 5;
    data.m_vPos = { -30.0f,580.0f,0.0f };
    data.m_vScale = { 376.0f,176.0f,1.0f };
    data.FileName = L"../../Resourse/Jump.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.m_fDelay = 0.09f;
    m_UVObj->Init();
    m_UVObj->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
    m_SpriteList.insert(std::make_pair(0, m_UVObj));
    //ZeroMemory(&info, sizeof(info));

    
    

    return true;
}

bool Sample::CreateBGM()
{
    m_BGM = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/BigMachine_mission.mp3");
    m_BGM->SoundPlay(true);

   /* m_EffetSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Use.mp3");*/
   // m_EffetSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Boss/Attack1.mp3");
    SkillEff.m_EffSound = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Player/Hit.mp3");
   
    return true;
}

bool Sample::Init()
{
    srand(time(NULL));
    CFSMManager::GetInstance().Init();
    CreateBGM();



    m_pLobbyScene = std::make_shared<CLobbyScene>();
    m_pLobbyScene->Init();

    m_p1PhaseScene = std::make_shared<C1PhaseScene>();
   

    m_p2PhaseScene = std::make_shared<C2PhaseScene>();
  
  
    m_p3PhaseScene = std::make_shared<C3PhaseScene>();
    m_p1PhaseScene->Init();
    m_p2PhaseScene->Init();
    m_p3PhaseScene->Init();

    {
        std::shared_ptr<CUI> PlayerState = std::make_shared<CUI>();
        PlayerState->Init();
        UIDesc desc;
        desc.TextureName = L"../../Resourse/mainBar.png";
        desc.ShaderName = L"../../Resourse/Plane.hlsl";
        desc.UIPos = CVector3(0, -698, 1);
        desc.UIScale = CVector3(204, 70, 1);
        PlayerState->CreateUI(desc);
        m_pUIList.push_back(PlayerState);

        std::shared_ptr<CUI> QuickSlot = std::make_shared<CUI>();
        QuickSlot->Init();
        desc.TextureName = L"../../Resourse/StatusBar2quickSlot.png";
        desc.UIPos = CVector3(1215.0f, -675.0f, 1);
        desc.UIScale = CVector3(145, 93, 1);
        QuickSlot->CreateUI(desc);
        m_pUIList.push_back(QuickSlot);


        std::shared_ptr<CUI> QuickSlot1 = std::make_shared<CUI>();
        QuickSlot1->Init();
        desc.TextureName = L"../../Resourse/fist.png";
        desc.UIPos = CVector3(1115.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlot1->CreateUI(desc);
        m_pUIList.push_back(QuickSlot1);

        std::shared_ptr<CUI> QuickSlot2 = std::make_shared<CUI>();
        QuickSlot2->Init();
        desc.TextureName = L"../../Resourse/Howling.png";
        desc.UIPos = CVector3(1180.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlot2->CreateUI(desc);
        m_pUIList.push_back(QuickSlot2);


        std::shared_ptr<CUI> QuickSlot3 = std::make_shared<CUI>();
        QuickSlot3->Init();
        desc.TextureName = L"../../Resourse/powerelixer.png";
        desc.UIPos = CVector3(1250.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlot3->CreateUI(desc);
        m_pUIList.push_back(QuickSlot3);

        std::shared_ptr<CUI> QuickSlotA = std::make_shared<CUI>();
        QuickSlotA->Init();
        desc.TextureName = L"../../Resourse/A.png";
        desc.UIPos = CVector3(1115.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlotA->CreateUI(desc);
        m_pUIList.push_back(QuickSlotA);

        std::shared_ptr<CUI> QuickSlot11 = std::make_shared<CUI>();
        QuickSlot11->Init();
        desc.TextureName = L"../../Resourse/no1.png";
        desc.UIPos = CVector3(1250.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlot11->CreateUI(desc);
        m_pUIList.push_back(QuickSlot11);

        std::shared_ptr<CUI> QuickSlotQ = std::make_shared<CUI>();
        QuickSlotQ->Init();
        desc.TextureName = L"../../Resourse/Q.png";
        desc.UIPos = CVector3(1180.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        QuickSlotQ->CreateUI(desc);
        m_pUIList.push_back(QuickSlotQ);

        std::shared_ptr<CUI> BossState = std::make_shared<CUI>();
        BossState->Init();
        desc.TextureName = L"../../Resourse/backgrnd.png";
        desc.UIPos = CVector3(-1040.0f, 731.0f, 1);
        desc.UIScale = CVector3(37, 37, 1);
        BossState->CreateUI(desc);
        m_pUIList.push_back(BossState);

        std::shared_ptr<CUI> BossPortrait = std::make_shared<CUI>();
        BossPortrait->Init();
        desc.TextureName = L"../../Resourse/Mob.8240098.png";
        desc.UIPos = CVector3(-1040.0f, 731.0f, 1);
        desc.UIScale = CVector3(27, 27, 1);
        BossPortrait->CreateUI(desc);
        m_pUIList.push_back(BossPortrait);


        std::shared_ptr<CUI> BossState1 = std::make_shared<CUI>();
        BossState1->Init();
        desc.TextureName = L"../../Resourse/backgrnd1.png";
        desc.UIPos = CVector3(-1003.0f, 715.0f, 1);
        desc.UIScale = CVector3(3, 20, 1);
        BossState1->CreateUI(desc);
        m_pUIList.push_back(BossState1);

        std::shared_ptr<CUI> BossState2 = std::make_shared<CUI>();
        BossState2->Init();
        desc.TextureName = L"../../Resourse/backgrnd3.png";
        desc.UIPos = CVector3(0.0f, 715.0f, 1);
        desc.UIScale = CVector3(1000, 20, 1);
        BossState2->CreateUI(desc);
        m_pUIList.push_back(BossState2);

        std::shared_ptr<CUI> BossState3 = std::make_shared<CUI>();
        BossState3->Init();
        desc.TextureName = L"../../Resourse/backgrnd4.png";
        desc.UIPos = CVector3(1003.0f, 715.0f, 1);
        desc.UIScale = CVector3(3, 20, 1);
        BossState3->CreateUI(desc);
        m_pUIList.push_back(BossState3);

        std::shared_ptr<CUI> DeathCount = std::make_shared<CUI>();
        DeathCount->Init();
        desc.TextureName = L"../../Resourse/DeathCount.png";
        desc.UIPos = CVector3(0, 660.0f, 1);
        desc.UIScale = CVector3(166, 42, 1);
        DeathCount->CreateUI(desc);
        m_pUIList.push_back(DeathCount);

        DisableSkillUI = std::make_shared<CUI>();
        DisableSkillUI->Init();
        desc.TextureName = L"../../Resourse/HowlingDIsable.png";
        desc.UIPos = CVector3(1180.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        DisableSkillUI->CreateUI(desc);
       

        DisableElixer = std::make_shared<CUI>();
        DisableElixer->Init();
        desc.TextureName = L"../../Resourse/powerelixerDisable.png";
        desc.UIPos = CVector3(1250.0f, -644.0f, 1);
        desc.UIScale = CVector3(30, 30, 1);
        DisableElixer->CreateUI(desc);


        float xInterval = 60;
        for (int i = 0; i < 5; ++i)
        {
            std::shared_ptr<CSpriteUVObj> Sprite = std::make_shared<CSpriteUVObj>();
            CSpriteData data;
            data.m_vPos = { -125 + xInterval * i,680.0f,0 };
            data.m_vScale = { 54,60,1 };
            data.FileName = L"../../Resourse/DeathCountSkull.png";
            data.ShaderName = L"../../Resourse/Plane.hlsl";
            data.iCol = 5;
            data.iRow = 3;
            data.m_fDelay = 0.1f;

            Sprite->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
            SpriteUI.push_back(Sprite);




        }
    }
   
    // to do : change lobby
    m_PresentScene = m_pLobbyScene.get();
   
    m_PresentScene->m_pBoss->m_bVaild = false;
    CreatePlayer();
    m_pPlayer->Init();
    howling.Init();
    m_pPlayer->HealthPoint = 60000;
    PlayerSkill.Init();
    m_lDamageIndicator.reserve(10);
    for (int i = 0; i < 10; ++i)
    {
        std::shared_ptr<DamageIndicator> list = make_shared<DamageIndicator>();
        list->Init();
        m_lDamageIndicator.push_back(list);
    }
   

    return true;


}
bool Sample::Frame()
{
    DisableSkillUI->Frame();
    DisableElixer->Frame();
    for (auto& UI : m_pUIList)
    {
        UI->Frame();
    }

    std::wstring msg = L"[ELIXER CoolDown : ";
    msg += std::to_wstring(PotionCoolDown);
    msg += L"초] ";
    CWriter::GetInstance().AddText(msg, 100, 700, D2D1::ColorF(0.3215, 0.751, 0.1235, 1));
    msg = L"[Skill CoolDown : ";
    msg += std::to_wstring(howling.SkillCollDown);
    msg += L"초] ";
    CWriter::GetInstance().AddText(msg, 900, 700, D2D1::ColorF(0.3215, 0.751, 0.1235, 1));
   
   
    if (IsClear)
    {
        std::wstring msg = L"[ClearTime : ";
        msg += std::to_wstring(minute);
        msg += L"분 ";
        msg += std::to_wstring(ClearTime);
        msg += L"초] ";
        CWriter::GetInstance().AddText(msg, 600, 300, D2D1::ColorF(0.3215, 0.751, 0.1235, 1));
       
    }
    else
    {

        if (ClearTime >= 60.0)
        {
            ClearTime -= 60;
            
            minute+=1;
        }
      
      
    }
   
    CoreInterface::g_pMainCamera->m_vCameraPos = m_pPlayer->m_vPos;
   // CoreInterface::g_pMainCamera->m_vCameraPos.y -= 300.0f;
#pragma region ChangeScene
    if (CInput::GetInstance().m_dwKeyState[VK_UP] == KEY_PUSH
        &&m_pLobbyScene.get()->CheckCollide(m_pLobbyScene.get()->m_pPotal->m_RT,m_pPlayer.get()->m_RT))
    {
        ClearTime = 0;
        IsClear = false;
        m_PresentScene->m_pBoss->HealthPoint = m_PresentScene->m_pBoss->MaxBossHP;
        m_PresentScene = m_p1PhaseScene.get();
        m_BGM->SoundStop();
        m_PresentScene->m_pBoss->Alive = true;
        m_PresentScene->m_pBoss->m_bVaild = true;
        m_BGM = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Gravity Core.mp3");
        m_BGM->SoundPlay(true);
        
        Map_XSize = 1406.0;
        Map_YSize = 743.0f;
        m_pPlayer->m_vPos = { -600,-400,0 };
        m_PresentScene->m_pBoss->m_vPos = { 0.0f,170.0f,0.0f };
       


    }
 
       
     if ((m_PresentScene->m_pBoss->m_bVaild == false && m_PresentScene == m_p3PhaseScene.get())||m_pPlayer->DeathCount==0)
     {
         m_PresentScene->m_pBoss->HealthPoint = m_PresentScene->m_pBoss->MaxBossHP;
         m_BGM->SoundStop();
         m_BGM = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/BigMachine_mission.mp3");
         m_BGM->SoundPlay(true);
         Map_XSize = 1833.0f;
         Map_YSize = 1000.0f;
         m_pPlayer->m_vPos = { -600,-400,0 };
         m_PresentScene->m_pBoss->m_vPos = { 600,-300,0 };
         
         m_PresentScene = m_pLobbyScene.get();
         if (m_pPlayer->DeathCount>0)
         {
             IsClear = true;
             m_pPlayer->HealthPoint = 60000;
             m_pPlayer->DeathCount = 5;

         }
         else
         {
             IsClear = false;
             m_pPlayer->HealthPoint = 60000;
             m_pPlayer->DeathCount = 5;
         }
         SpriteUI.clear();
         float xInterval = 60;
         for (int i = 0; i < 5; ++i)
         {
             std::shared_ptr<CSpriteUVObj> Sprite = std::make_shared<CSpriteUVObj>();
             CSpriteData data;
             data.m_vPos = { -125 + xInterval * i,680.0f,0 };
             data.m_vScale = { 54,60,1 };
             data.FileName = L"../../Resourse/DeathCountSkull.png";
             data.ShaderName = L"../../Resourse/Plane.hlsl";
             data.iCol = 5;
             data.iRow = 3;
             data.m_fDelay = 0.1f;

             Sprite->Load(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext, data);
             SpriteUI.push_back(Sprite);

         }

     }
     
     else if (m_PresentScene->m_pBoss->m_bVaild == false && m_PresentScene == m_p1PhaseScene.get())
     {
         m_PresentScene->m_pBoss->HealthPoint = m_PresentScene->m_pBoss->MaxBossHP;
         m_PresentScene = m_p2PhaseScene.get();
         m_BGM->SoundStop();
     
         m_PresentScene->m_pBoss->m_bVaild = true;
       
         m_BGM = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Gravity Lord.mp3");
         m_BGM->SoundPlay(true);
         m_pPlayer->m_vPos = { -600,-400,0 };
         m_PresentScene->m_pBoss->m_vPos = { 600,-300,0 };
        


     }
     else if (m_PresentScene->m_pBoss->m_bVaild == false && m_PresentScene == m_p2PhaseScene.get())
     {
         m_PresentScene->m_pBoss->HealthPoint = m_PresentScene->m_pBoss->MaxBossHP;
         m_PresentScene = m_p3PhaseScene.get();
         m_BGM->SoundStop();
    
         m_PresentScene->m_pBoss->m_bVaild = true;
        
         m_BGM = CSoundMgr::GetInstance().Load(L"../../Resourse/Sound/Gravity Lord Rise.mp3");
         m_BGM->SoundPlay(true);
         m_pPlayer->m_vPos = { -600,-400,0 };
         m_PresentScene->m_pBoss->m_vPos = { 600,-100,0 };

        


     }
    
 
    if (CInput::GetInstance().m_dwKeyState[VK_CONTROL] == KEY_PUSH)
    {
       
    }
#pragma endregion

    if (m_PresentScene != m_pLobbyScene.get())
    {
        ClearTime += g_fSecondPerFrame;
    }

    m_PresentScene->Frame(m_pPlayer.get());

    if (PotionCoolDown > 0)
    {
        PotionCoolDown -= g_fSecondPerFrame;
    }
    else
    {
        PotionCoolDown = 0;
    
    }
   
    if (CInput::GetInstance().m_dwKeyState['1'] == KEY_PUSH && PotionCoolDown<=0)
    {
        PotionCoolDown = 5;
        m_pPlayer->HealthPoint = m_pPlayer->MaxPlayerHP;
        m_pPlayer->PlayerMP = m_pPlayer->MaxPlayerMP;
    }

    if (CInput::GetInstance().m_dwKeyState['Q'] >= KEY_HOLD && m_pPlayer->IsAttack == false && m_pPlayer->IsDead == false&& howling.Isok && m_pPlayer->PlayerMP >= PlayerSkill.UseMp)
    {
        m_pPlayer->IsAttack = true;
        howling.IsUse = true;
        howling.Isok = false;
        howling.SkillCollDown = 30;
        m_pPlayer->PlayerMP -= howling.UseMP;
    }

    if (CInput::GetInstance().m_dwKeyState['A'] >= KEY_HOLD && m_pPlayer->IsAttack == false && m_pPlayer->IsDead == false && m_pPlayer->PlayerMP>=PlayerSkill.UseMp)
    {
        bool play;
        SkillEff.m_EffSound->m_pChannel->isPlaying(&play);
        if (play)
        {
            SkillEff.m_EffSound->m_pChannel->stop();
        }


        PlayerSkill.LoadSkill(m_pPlayer->FaceRight, { m_pPlayer->m_vPos.x,m_pPlayer->m_vPos.y });
        PlayerSkill.m_UseSound->EffectSoundPlay();
        m_pPlayer->PlayerMP -= PlayerSkill.UseMp;

    }
    if (m_PresentScene->m_pBoss->UseSkill1 == true)
    {

        m_PresentScene->m_pBoss->m_pBossSkillList[0]->LoadSkill(0, { m_PresentScene->m_pBoss->m_vPos.x, m_PresentScene->m_pBoss->m_vPos.y+200 });
        m_PresentScene->m_pBoss->UseSkill1 = false;

    }
    
    
    if ((m_pPlayer->Drop == true || m_pPlayer->Jump == true) && CInput::GetInstance().m_dwKeyState[VK_SPACE] == KEY_PUSH
        && m_pPlayer->IsTurnDelay==false)
    {
        m_pPlayer->m_JumpSound->EffectSoundPlay();
        if (m_pPlayer->FaceRight)
        {
            CParticle info;
            info.m_bValid = true;
            info.iID = m_SpriteList.size() - 1;
            info.m_vPos = { m_pPlayer->m_vPos.x-240,m_pPlayer->m_vPos.y ,1};
            info.m_vScale = { 376.0f,176.0f,1.0f };
            info.m_fDelay = 0.09f;
             info.m_iMaxFrame = m_SpriteList[info.iID]->GetSize() - 2;
            m_ParticleList.push_back(info);
            m_pPlayer->MoveSpeed += 1000;
            isRight = true;
        }
        else
        {
            CParticle info;
            info.m_bValid = true;
            info.iID = m_SpriteList.size() - 1;
            info.m_vPos = { m_pPlayer->m_vPos.x + 240,m_pPlayer->m_vPos.y ,1 };
            info.m_vScale = { 376.0f,176.0f,1.0f };
            info.m_fDelay = 0.09f;
            info.m_iMaxFrame = m_SpriteList[info.iID]->GetSize() - 2;
            m_ParticleList.push_back(info);
            m_pPlayer->MoveSpeed += -1000;
            isRight = false;
        }
          
            m_pPlayer->IsTurnDelay = true;
    }
   

  
    m_pPlayer->Move(g_fSecondPerFrame);
    m_pPlayer->Frame();
    
    
    PlayerSkill.Frame();
    SkillEff.Frame();

    howling.Frame(m_PresentScene->m_pBoss.get(),m_pPlayer.get(), m_lDamageIndicator);

    for (auto iter = m_ParticleList.begin(); iter != m_ParticleList.end(); )
    {
        CParticle& info = *iter;
        info.Frame();
        if (info.m_bValid == false)
        {
            iter = m_ParticleList.erase(iter);
            info.m_bValid = true;
        }
        else
        {
            iter++;
        }

    }
#pragma region PlayerOnBlock



    if (m_pPlayer->Drop != false || m_pPlayer->Jump != true)
    {
        bool OnBolck = false;
        if (OnBolck == false)
        {
            for (auto& rt : m_PresentScene->m_FootHoldList)
            {
                if (m_pPlayer->m_RT.ToRectFootHold(rt->m_RT))
                {
                    m_pPlayer->Drop = false;
                    OnBolck = true;
                    break;
                }
                 else
                {
                    m_pPlayer->Drop = true;
                }

            }
        }


    }
#pragma endregion
#pragma region BossOnBlock
    if (m_PresentScene->m_pBoss->Drop != false || m_PresentScene->m_pBoss->Jump != true)
    {
        bool OnBolck = false;
      
        if (OnBolck == false)
        {
            for (auto& rt : m_PresentScene->m_FootHoldList)
            {
                if (m_PresentScene->m_pBoss->m_RT.ToRectFootHold(rt->m_RT))
                {
                    m_PresentScene->m_pBoss->Drop = false;
                    OnBolck = true;
                    break;
                }
                else
                {
                    m_PresentScene->m_pBoss->Drop = true;
                }

            }
        }


    }

#pragma endregion
#pragma region PlayerAttack To Boss

    float yInterval = 30;

    if (m_PresentScene->m_pBoss->m_bVaild)
    {
        for (auto& Skill : PlayerSkill.m_ParticleList)
        {
            if (Skill.m_RT.ToRect(m_PresentScene->m_pBoss->m_RT))
            {
                PlayerSkill.m_AccumulatedTime += g_fSecondPerFrame;
                SkillEff.m_AccumulatedTime += g_fSecondPerFrame;
                if (PlayerSkill.m_AccumulatedTime> PlayerSkill.m_Delay && PlayerSkill.MaxSoundCount <6)
                {
                   
                    if (SkillEff.m_AccumulatedTime > SkillEff.m_Delay)
                    {
                        SkillEff.LoadEffect({ m_PresentScene->m_pBoss->m_vPos.x, m_PresentScene->m_pBoss->m_vPos.y });
                        for (auto& DamageLine : m_lDamageIndicator)
                        {
                            if (!DamageLine->IsVaild)
                            {
                                DamageLine->Frame(PlayerSkill.SKillDamage, m_PresentScene->m_pBoss->m_vPos.x+125, m_PresentScene->m_pBoss->m_vPos.y + 20 +yInterval);
                                DamageLine->IsVaild = true;
                                break;
                            }
                            yInterval += 30;
                        }

                        SkillEff.m_AccumulatedTime=0;
                        PlayerSkill.MaxSoundCount++;
                    }

                    m_PresentScene->m_pBoss->HealthPoint -= PlayerSkill.SKillDamage;
                    PlayerSkill.m_AccumulatedTime -= PlayerSkill.m_Delay;
                   
                    /*if (m_pBoss->HealthPoint <= 0)
                    {
                        m_pBoss->m_bVaild = false;
                    }*/
                   
                   
                }
                
            }

        }
    }

#pragma endregion   

    


    while (m_pPlayer->DeathCount != SpriteUI.size())
    {
        SpriteUI.pop_back();
    }

    for (auto& sprite : SpriteUI)
    {
        sprite->Frame();
    }
   

    return true;
}
bool Sample::Render()
{
   
    
     m_PresentScene->Render();
    
    
     m_pPlayer->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
     m_pPlayer->Render(m_pPlayer->FaceRight);
     howling.Render(m_pPlayer->FaceRight, m_pPlayer->m_vPos);
    
     PlayerSkill.Render(m_pPlayer->FaceRight,m_pPlayer->m_vPos);
     SkillEff.Render(m_PresentScene->m_pBoss->m_vPos);
    
     for (auto iter = m_ParticleList.begin(); iter != m_ParticleList.end(); iter++)
     {
         CParticle& info = *iter;
         CSpriteUVObj* Obj = m_SpriteList[info.iID];
         Obj->SetPos(info.m_vPos);
         Obj->SetScale(info.m_vScale);
         Obj->Move(g_fSecondPerFrame);
         Obj->Frame();
         Obj->m_pTexture;
         Obj->m_iTexIndex = info.m_iIndex;
         Obj->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
         Obj->Render(isRight);
     }
    
   
    
     m_pPlayer->PlayerHPBar.SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
     m_pPlayer->PlayerHPBar.Render();
     m_pPlayer->PlayerMPBar.SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
     m_pPlayer->PlayerMPBar.Render();


  
    for (auto& UI : m_pUIList)
    {
        UI->SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        UI->Render();
    }

    for (auto& sprite : SpriteUI)
    {
        sprite->SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        sprite->Render(0);
    }
    if (howling.SkillCollDown > 0)
    {
        DisableSkillUI->SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        DisableSkillUI->Render();
    }
    if (PotionCoolDown > 0)
    {
        DisableElixer->SetMatrix(nullptr, nullptr, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        DisableElixer->Render();
    }
  

    for (int i = 0; i <m_lDamageIndicator.size() ; ++i)
    {
        if (m_lDamageIndicator[i]->IsVaild)
        {
            m_lDamageIndicator[i]->Render();
            
        }
  
    }

    return true;

}
bool Sample::Release()
{
    m_PresentScene->Release();
  
 
    return true;
}



GAME_PLAY(L"타이틀이름", Window_Width, Window_Height);
