#pragma once
#include"CDefine.h"
#include"CFinitState.h"

class CFSM
{
public:

	std::map<DWORD, CFinitState*>	m_State;
	std::wstring m_Name;
	std::wstring m_Path;
	int m_Index;
public:
	void AddStateTransition(DWORD InputState, DWORD InputEvent, DWORD OutputState);
	DWORD GetOutPutState(DWORD InputEvent);
	DWORD GetCurrentState(DWORD Output);
	DWORD StateTransition(DWORD dwCur, DWORD Event);


};

class CFSMManager
{

public:
	
	std::map <int, CFSM*> m_FSMMap;
	int m_iCurIndex;

public:

	bool Init();
	int Add(const TCHAR* FileName);
	CFSM* GetPtr(int iIndex);

	static CFSMManager& GetInstance()
	{
		static CFSMManager Shader;
		return Shader;

	}


private:
	CFSMManager();
public:

	virtual ~CFSMManager();


};
