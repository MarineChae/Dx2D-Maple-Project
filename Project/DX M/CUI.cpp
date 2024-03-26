#include "CUI.h"
#include"CoreInterface.h"

bool CUI::Init()
{
    CPlaneObj::Init();
    Set(CoreInterface::g_pDevice, CoreInterface::g_pImmediateContext);



    return true;
}

bool CUI::Frame()
{
    CPlaneObj::Frame();
    return false;
}

bool CUI::Render()
{
    CPlaneObj::Render();

    return false;
}

bool CUI::Release()
{
    CPlaneObj::Release();
    return false;
}

bool CUI::CreateUI(UIDesc Desc)
{
    SetPos(Desc.UIPos);
    SetScale(Desc.UIScale);
    Create(Desc.TextureName, Desc.ShaderName);
    return false;
}
