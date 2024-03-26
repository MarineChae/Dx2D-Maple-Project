#include "DamageIndicator.h"
#include "CoreInterface.h"
bool DamageIndicator::Init()
{

    std::wstring No[10] = {
        L"../../Resourse/DamageSkin/Damage (1).png",
        L"../../Resourse/DamageSkin/Damage (2).png",
        L"../../Resourse/DamageSkin/Damage (3).png",
        L"../../Resourse/DamageSkin/Damage (4).png",
        L"../../Resourse/DamageSkin/Damage (5).png",
        L"../../Resourse/DamageSkin/Damage (6).png",
        L"../../Resourse/DamageSkin/Damage (7).png",
        L"../../Resourse/DamageSkin/Damage (8).png",
        L"../../Resourse/DamageSkin/Damage (9).png",
        L"../../Resourse/DamageSkin/Damage (10).png"
    };

    for (int i = 0 ; i < 10 ; ++i)
    {
        std::shared_ptr<CPlaneObj> No0 = std::make_shared<CPlaneObj>();
        No0->Init();
        No0->Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);
        No0->SetPos(CVector3(1, 1, 1));
        No0->SetScale(CVector3(28, 36, 1));
        No0->Create(No[i], L"../../Resourse/Plane.hlsl");
        DamageList.push_back(No0);
    }



    return true;
}

bool DamageIndicator::Frame(int damage, float XPos,float YPos)
{
    float interval = -50;
    int i = 0;
    if (damage > 0)
    {
        int Temp = damage;
        while (Temp > 0)
        {
            int damageNum = Temp % 10;
            Temp /= 10;
            PrintDamageList.push_back(DamageList[damageNum]);
            DamageList[damageNum]->SetPos(CVector3(XPos + interval * i++, YPos, 0.5));
        }
    }

    for (auto& damage : DamageList)
    {
        damage->Frame();

    }

    return true;
}

bool DamageIndicator::Render()
{
    lifeTime += g_fSecondPerFrame;
    if (lifeTime >= 1.0f)
    {
        lifeTime = 0;
        IsVaild = false;
        PrintDamageList.clear();
    }

    for (auto iter = PrintDamageList.rbegin(); iter != PrintDamageList.rend();++iter)
    {
        iter->get()->SetMatrix(nullptr, &CoreInterface::g_pMainCamera->m_ViewMatrix, &CoreInterface::g_pMainCamera->m_OrthProjectionMatrix);
        iter->get()->Render();
    }



    return true;
}

bool DamageIndicator::Release()
{
    return false;
}
