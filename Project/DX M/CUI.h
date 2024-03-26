#pragma once
#include"CPlaneObj.h"


struct UIDesc
{
	CVector3 UIPos;
	CVector3 UIScale;
	std::wstring TextureName;
	std::wstring ShaderName;

};

class CUI : public CPlaneObj
{
public:

	virtual bool Init() override;
	virtual bool Frame() override;
	virtual bool Render() override;
	virtual bool Release() override;

	bool CreateUI(UIDesc Desc);
};

