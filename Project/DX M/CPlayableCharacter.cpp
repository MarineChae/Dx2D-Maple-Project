#include "CPlayableCharacter.h"
#include"CoreInterface.h"


bool CPlayableCharacter::Init()
{
    HealthPoint = MaxPlayerHP;
    PlayerMP = MaxPlayerMP;
    CSpriteData data;
    data.m_vPos = { -600,-400,0 };
    data.m_vScale = { 46,68,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/PStand.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 3;
    data.iRow = 1;
    data.m_fDelay = 0.5f;
   
    Load(CoreInterface::g_pDevice, CoreInterface:: g_pImmediateContext, data);
    CVector2 rt = {m_vPos.x,m_vPos.y };
   SetRect(rt,m_vScale.x * 2.0f, m_vScale.y * 2.0f);
   m_pCSpriteDataList.push_back(data);


    data.m_vScale = { 46,68,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/PWalk.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 4;
    data.iRow = 1;
    data.m_fDelay = 0.18f;
    m_pCSpriteDataList.push_back(data);

    data.m_vScale = { 46,68,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/PJump.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 1;
    data.iRow = 1;
    data.m_fDelay = 0.18f;
    m_pCSpriteDataList.push_back(data);

    data.m_vScale = { 65,41,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/PProne.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 1;
    data.iRow = 1;
    data.m_fDelay = 0.45f;
    m_pCSpriteDataList.push_back(data);

    data.m_vScale = { 65,65,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/PNormalAttack.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 2;
    data.iRow = 1;
    data.m_fDelay = 0.5f;
   m_pCSpriteDataList.push_back(data);

    data.m_vScale = { 78,67,1 };
    data.FileName = L"../../Resourse/PlayerCharacter/SKILL1.png";
    data.ShaderName = L"../../Resourse/Plane.hlsl";
    data.iCol = 5;
    data.iRow = 2;
    data.m_fDelay = 0.065;
   m_pCSpriteDataList.push_back(data);

   data.m_vScale = { 39,61,1 };
   data.FileName = L"../../Resourse/PlayerCharacter/DEAD.png";
   data.ShaderName = L"../../Resourse/Plane.hlsl";
   data.iCol = 1;
   data.iRow = 1;
   data.m_fDelay = 0.065;
   m_pCSpriteDataList.push_back(data);

   PlayerHPBar.Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
   PlayerHPBar.SetPos({ 20, -700.0f, 1 });
   PlayerHPBar.SetScale({ 171,13,1 });
   PlayerHPBar.Create(L"../../Resourse/mainBarhplayer.png", L"../../Resourse/Plane.hlsl");


   PlayerMPBar.Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
   PlayerMPBar.SetPos({ 20, -740.0f, 1 });
   PlayerMPBar.SetScale({ 171,13,1 });
   PlayerMPBar.Create(L"../../Resourse/mainBarmplayer.png", L"../../Resourse/Plane.hlsl");
 
    return true;
}

bool CPlayableCharacter::Frame()
{
    CVector2 rt = { m_vPos.x,m_vPos.y };
    SetRect(rt, m_vScale.x * 2.0f, m_vScale.y * 2.0f);
    CPlaneObj::Frame();

  
    if (CInput::GetInstance().m_dwKeyState['A'] >= KEY_HOLD && IsAttack == false&& IsDead == false)
    {
        ChangeState(PSTATE_SKILL1);
        IsAttack = true;
        m_AccumulatedTime = 0;
       

    }

    m_AccumulatedTime += g_fSecondPerFrame;

    if (m_AccumulatedTime >= m_pCSpriteDataList[PState].m_fDelay)
    {
        m_iTexIndex++;
        if (m_iTexIndex >= m_pUVList.size())
        {
            if (PState==PSTATE_SKILL1|| PState == PSTATE_ATTACK|| PState == PSTATE_DEAD)
            {
               if(IsDead == false)ChangeState(PSTATE_STAND);
                IsAttack = false;
            }
            m_iTexIndex = 0;
            m_AccumulatedTime = 0;
        }
        m_AccumulatedTime -= m_pCSpriteDataList[PState].m_fDelay;
    }



    float tmep = static_cast<float> (HealthPoint) / MaxPlayerHP;
    PlayerHPBar.Frame();
    PlayerHPBar.SetScale({ 171 * tmep,13,1 });
    float movebar =(171 * tmep);
    PlayerHPBar.SetPos({ -158 + movebar , -700.0f, 1});

    float tempMP = static_cast<float> (PlayerMP) / MaxPlayerMP;
    PlayerMPBar.Frame();
    PlayerMPBar.SetScale({ 171 * tempMP,13,1 });
    float moveMPbar = (171 * tempMP);
    PlayerMPBar.SetPos({ -158 + moveMPbar , -727.0f, 1 });

    return true;

}

bool CPlayableCharacter::Render(bool face)
{
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




    PostRender();

    std::wstring msg = L"[PLAYER HP] :";

    msg += std::to_wstring(HealthPoint);
    msg += L"[PLAYER DEATHCOUNT";
    msg += std::to_wstring(DeathCount);

    CWriter::GetInstance().AddText(msg, 500,700, D2D1::ColorF(0, 1, 1, 1));

    return true;

}



void CPlayableCharacter::Move(double fSecond)
{
    if (HealthPoint <= 0 && IsDead == false)
    {
        IsDead = true;
        ChangeState(PSTATE_DEAD);
        DeathCount--;
    }
    if (IsDead == false)
    {


    if (CInput::GetInstance().m_dwKeyState[VK_LEFT] ==KEY_NONE
        && CInput::GetInstance().m_dwKeyState[VK_RIGHT] == KEY_NONE && IsTurnDelay == false)
    {
        MoveSpeed = 0;
    }
    if (MaxSpeed <= MoveSpeed&&IsTurnDelay==false)
    {
        MoveSpeed = MaxSpeed;
    }
    if (MinSpeed >= MoveSpeed && IsTurnDelay == false)
    {
        MoveSpeed = MinSpeed;
    }
    if (Jump == false && Drop == false) BeforePos = m_vPos;

    if (m_bVaild == false)
    {
        return;
    }
    if (CInput::GetInstance().m_dwKeyState[VK_UP] >= KEY_PUSH && Drop == false && Jump == false)
    {

    }
    if (CInput::GetInstance().m_dwKeyState[VK_LEFT] >= KEY_HOLD &&
        CInput::GetInstance().m_dwKeyState[VK_RIGHT] == KEY_NONE)
    {
        IsMove = true;
        if (PState < PSTATE_WALK && Drop == false && Jump == false && IsAttack == false)
        {
            ChangeState(PSTATE_WALK);
        }


        if (IsAttack == false)
        {
            FaceLeft = true;
            FaceRight = false;
        }
        if (MinSpeed <= MoveSpeed && PState != PSTATE_PRONE)
        {
            if (Drop == false && Jump == false && IsTurnDelay == false && IsAttack == false)
                MoveSpeed -= 1600.0f * fSecond;
            else if (IsAttack == true)
                MoveSpeed -= 0;

            else if (IsAttack == true && Drop == true && Jump == true)
                MoveSpeed -= 200 * fSecond;

            else if (IsTurnDelay == false)
                MoveSpeed -= 410.0f * fSecond;
            if (IsAttack == true && Drop == false && Jump == false)
                MoveSpeed = 0;
        }
    
           

        m_vVertexList[0].Tex = { 0.0f,0.0f };
        m_vVertexList[1].Tex = { 1.0f,0.0f };
        m_vVertexList[2].Tex = { 0.0f,1.0f };
        m_vVertexList[3].Tex = m_vVertexList[2].Tex;
        m_vVertexList[4].Tex = m_vVertexList[1].Tex;
        m_vVertexList[5].Tex = { 1.0f,1.0f };

        m_pImmediateContext->UpdateSubresource(m_pVertexBuffer, 0, nullptr, &m_vVertexList.at(0), 0, 0);

    }
    /* else if (CInput::GetInstance().m_dwKeyState[VK_LEFT] >= KEY_HOLD &&
         CInput::GetInstance().m_dwKeyState[VK_RIGHT] != KEY_NONE)
     {

         if (PState != PSTATE_STAND && PState != PSTATE_JUMP)
             ChangeState(PSTATE_STAND);

     }*/


    if (CInput::GetInstance().m_dwKeyState[VK_LEFT] == KEY_UP && Drop == false && Jump == false && IsAttack == false)
    {

        ChangeState(PSTATE_STAND);

        MoveSpeed = 0;
    }
    if (CInput::GetInstance().m_dwKeyState[VK_RIGHT] >= KEY_HOLD &&
        CInput::GetInstance().m_dwKeyState[VK_LEFT] == KEY_NONE)
    {
        IsMove = true;
        if (PState < PSTATE_WALK && Drop == false && Jump == false && IsAttack == false)
        {
            ChangeState(PSTATE_WALK);
        }

        if (IsAttack == false)
        {
            FaceRight = true;
            FaceLeft = false;
        }

        if (MaxSpeed >= MoveSpeed && PState != PSTATE_PRONE)
        {


            if (Drop == false && Jump == false && IsTurnDelay == false && IsAttack == false)
                MoveSpeed += 1600.0f * fSecond;
            else if (IsAttack == true)
                MoveSpeed += 0;
            
            else if (IsAttack == true && Drop == true && Jump == true)
                MoveSpeed += 200 * fSecond;

            else if (IsTurnDelay == false)
                MoveSpeed += 410.0f * fSecond;
            if (IsAttack == true && Drop == false && Jump == false)
                MoveSpeed = 0;
        }



        m_vVertexList[0].Tex = { 1.0f,0.0f };
        m_vVertexList[1].Tex = { 0.0f,0.0f };
        m_vVertexList[2].Tex = { 1.0f,1.0f };
        m_vVertexList[3].Tex = m_vVertexList[2].Tex;
        m_vVertexList[4].Tex = m_vVertexList[1].Tex;
        m_vVertexList[5].Tex = { 0.0f,1.0f };


        m_pImmediateContext->UpdateSubresource(m_pVertexBuffer, 0, nullptr, &m_vVertexList.at(0), 0, 0);


    }
  
    if (CInput::GetInstance().m_dwKeyState[VK_RIGHT] == KEY_UP && Drop == false && Jump == false && IsAttack == false)
    {
        ChangeState(PSTATE_STAND);

        MoveSpeed = 0;

    }
    if (CInput::GetInstance().m_dwKeyState[VK_SPACE] >= KEY_HOLD &&
        Jump == false && Drop == false && PState != PSTATE_PRONE&& IsAttack == false)
    {
       if(IsAttack == false)
        ChangeState(PSTATE_JUMP);                      

        Jump = true;
       

    }
   
    if (CInput::GetInstance().m_dwKeyState[VK_DOWN] == KEY_PUSH && PState != PSTATE_JUMP && IsAttack == false)
    {
        MoveSpeed = 0;
        m_vPos.y -= 28.0f;


    }
    if (CInput::GetInstance().m_dwKeyState[VK_DOWN] == KEY_HOLD && PState != PSTATE_JUMP && IsAttack == false)
    {
        MoveSpeed = 0;
        ChangeState(PSTATE_PRONE);

    }
    if (CInput::GetInstance().m_dwKeyState[VK_DOWN] == KEY_UP && PState != PSTATE_JUMP && IsAttack == false)
    {
        MoveSpeed = 0;
        m_vPos.y += 28.0f;
        ChangeState(PSTATE_STAND);

    }
   
    /*if (CInput::GetInstance().m_dwKeyState[VK_SPACE] == KEY_HOLD && PState != STATE_PRONE)
    {
        if (Drop == false && Jump == false)
        {
            ChangeState(STATE_JUMP);
            Jump = true;

        }

    }*/
   
    if (Jump == true)
    {
        m_vPos.y += 600.0f * fSecond;
        if (m_vPos.y - BeforePos.y > fabs(200.0f) || m_vPos.y >= (Map_YSize)-(m_vScale.y))
        {
            Jump = false;
            Drop = true;
     
        }

    }
    if (Drop == true )
    {
        
        if (MaxDropSpeed >= DropSpeed)
        {
            DropSpeed += 3500.0f * fSecond;
        }
        m_vPos.y -= DropSpeed * fSecond;
        if (IsAttack == false)
        ChangeState(PSTATE_JUMP);
        BeforeDrop = true;
    }
    else
    {
        if (BeforeDrop == true &&IsTurnDelay==true)
        {
            if (FaceRight)
                MoveSpeed = MaxSpeed;
            else
                MoveSpeed = MinSpeed;
            IsTurnDelay = false;
        }
       
        
        
        DropSpeed = 0.0f;
        if (BeforeDrop && CInput::GetInstance().m_dwKeyState[VK_SPACE] != KEY_HOLD && IsAttack == false)
        {
            PState = PSTATE_STAND;
            m_pUVList.clear();
            SetUVData(m_pCSpriteDataList[PState].iRow, m_pCSpriteDataList[PState].iCol);
            m_pTexture = CTextureMgr::GetInstance().Load(m_pCSpriteDataList[PState].FileName);
            m_iTexIndex = 0;
            BeforeDrop = false;

        }
        
            

        
    }

    m_vPos.x += MoveSpeed * fSecond;
    if (m_vPos.x <= -(Map_XSize)+(m_vScale.x))
    {

        m_vPos.x = -(Map_XSize)+(m_vScale.x);

    }
    if (m_vPos.y <= -(Map_YSize)+(m_vScale.y))
    {

        m_vPos.y = -(Map_YSize)+(m_vScale.y);

    }
    if (m_vPos.x >= (Map_XSize)-(m_vScale.x))
    {

        m_vPos.x = (Map_XSize)-(m_vScale.x);

    }
    if (m_vPos.y >= (Map_YSize)-(m_vScale.y))
    {

        m_vPos.y = (Map_YSize)-(m_vScale.y);

    }

    /*  CVector3 velocity = m_vDirection * fSecond * 500.0f;
      m_vPos = m_vPos + velocity;*/


    }
    else
    {
    if (CInput::GetInstance().m_dwKeyState[VK_RETURN])
    {
        IsDead = false;
        HealthPoint = 60000;
        MoveSpeed = 0;
        m_vPos = { -600,-400 ,0 };
        ChangeState(PSTATE_STAND);

    }
     }


}

void CPlayableCharacter::ChangeState(PlayerState State)
{
    PState = State;
    m_pUVList.clear();
    SetUVData(m_pCSpriteDataList[State].iRow, m_pCSpriteDataList[State].iCol);
    m_pTexture = CTextureMgr::GetInstance().Load(m_pCSpriteDataList[State].FileName);
    SetScale(m_pCSpriteDataList[State].m_vScale);
    CVector2 rt = { m_vPos.x,m_vPos.y };
    SetRect(rt, m_vScale.x * 2.0f,m_vScale.y * 2.0f);
    
    m_iTexIndex = 0;
}
