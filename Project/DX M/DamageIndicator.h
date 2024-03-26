#pragma once
#include"CPlaneObj.h"
#include<list>
class DamageIndicator 
{
	std::vector<shared_ptr<CPlaneObj>> DamageList;
	std::list<shared_ptr<CPlaneObj>> PrintDamageList;
public:

	float lifeTime;
	bool IsVaild = false;


public:
	virtual bool Init();
	virtual bool Frame(int damage, float XPos, float YPos);
	virtual bool Render();
	virtual bool Release();






};

