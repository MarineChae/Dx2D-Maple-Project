#include "CFSM.h"

CFSM* CFSMManager::GetPtr(int iIndex)
{
    auto iter = m_FSMMap.find(iIndex);
    if (iter == m_FSMMap.end())
        return NULL;

    CFSM* pPoint = (*iter).second;
    return pPoint;
}

bool CFSMManager::Init()
{
    CFSM* Point = new CFSM;
    Point->AddStateTransition(STATE_STAND, EVENT_TRACE, STATE_TRACE);
    Point->AddStateTransition(STATE_STAND, EVENT_FINDTARGET, STATE_ATTACK);

    Point->AddStateTransition(STATE_TRACE, EVENT_STOP, STATE_STAND);



    Point->AddStateTransition(STATE_ATTACK, EVENT_TRACE, STATE_TRACE);
    Point->AddStateTransition(STATE_ATTACK, EVENT_FINDTARGET, STATE_ATTACK);
    Point->AddStateTransition(STATE_TRACE, EVENT_USESKILL1, STATE_SKILL1);
    Point->AddStateTransition(STATE_TRACE, EVENT_USESKILL2, STATE_SKILL2);

    Point->AddStateTransition(STATE_SKILL1, EVENT_TRACE, STATE_TRACE);

    Point->AddStateTransition(STATE_SKILL2, EVENT_TRACE, STATE_TRACE);



    Point->AddStateTransition(STATE_STAND, EVENT_DIE, STATE_DEAD);
    Point->AddStateTransition(STATE_TRACE, EVENT_DIE, STATE_DEAD);
    Point->AddStateTransition(STATE_ATTACK, EVENT_DIE, STATE_DEAD);
    Point->AddStateTransition(STATE_SKILL1, EVENT_DIE, STATE_DEAD);
    Point->AddStateTransition(STATE_SKILL2, EVENT_DIE, STATE_DEAD);
    Point->AddStateTransition(STATE_DEAD, EVENT_SCENECHANGE, STATE_STAND);

    Point->m_Name = L"Enemy";
    m_FSMMap.insert(std::make_pair(m_iCurIndex++, Point));
    Point->m_Index = m_iCurIndex;


    return true;
}

int CFSMManager::Add(const TCHAR* FileName)
{
    TCHAR szFileName[MAX_PATH];
    TCHAR Drive[MAX_PATH];
    TCHAR Dir[MAX_PATH];
    TCHAR FName[MAX_PATH];
    TCHAR Ext[MAX_PATH];

    // 기본 유한상태기기를 사용한다.
    if (FileName == NULL)
    {
        FileName = _T("Enemy");
    }

    if (FileName)
    {
        _tsplitpath_s(FileName, Drive, Dir, FName, Ext);
        Ext[4] = 0;
        memset(szFileName, 0, sizeof(TCHAR) * MAX_PATH);
        _stprintf_s(szFileName, _T("%s%s"), FName, Ext);

        for (auto iter = m_FSMMap.begin(); iter != m_FSMMap.end(); iter++)
        {
            CFSM* pPoint = (CFSM*)(*iter).second;
            if (!_tcsicmp(pPoint->m_Name.c_str(), szFileName))
            {
                return (*iter).first;
            }
        }
    }

    CFSM* Point = new CFSM;
    // 파일에 저장되어 있는 유한상태기기를 사용한다.
   
    Point->m_Name = szFileName;
    m_FSMMap.insert(make_pair(++m_iCurIndex, Point));
    Point->m_Index = m_iCurIndex;

    return m_iCurIndex;
}

CFSMManager::CFSMManager()
{

}

CFSMManager::~CFSMManager()
{


}

void CFSM::AddStateTransition(DWORD InputState, DWORD InputEvent, DWORD OutputState)
{
    std::map<DWORD, CFinitState*>::iterator iter;
    CFinitState* state = NULL;

    iter = m_State.begin();
    while(iter != m_State.end())
    {
        state = iter->second;
        if (state->GetState() == InputState)
            break;
        iter++;

    }

    if (iter == m_State.end())
    {
        state = new CFinitState(InputState);
        m_State[state->GetState()] = state;

     }

    if (state != NULL)
    {
        state->AddTransition(InputEvent, OutputState);

    }
    



}

DWORD CFSM::GetOutPutState(DWORD InputEvent)
{
    std::map<DWORD, CFinitState*>::iterator iter;
    
    iter = m_State.find(InputEvent);

    if (iter == m_State.end())
    {
        return-1;
    }
    CFinitState* State = m_State[InputEvent];
    if (State == NULL)
    {
        return-1;
    }

    return State->OutPut(InputEvent);
}

DWORD CFSM::GetCurrentState(DWORD Output)
{
    CFinitState* crr = m_State[Output];
   
    return crr->GetState();
}

DWORD CFSM::StateTransition(DWORD dwCur, DWORD Event)
{
    DWORD Output;
    if (Output = m_State[dwCur]->OutPut(Event))
   
    return Output;
}
