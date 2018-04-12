// �߼���CDeS_Lance_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDeS_Lance_Log.h"

IMPLEMENT_L3CLASS(CDeS_Lance_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Lance_Log,CL3Object)
    L3PROP_STRING(LanceNo)
    L3PROP_LONG(Status)
    L3PROP_LONG(LanceAge)
    L3PROP_STRING(LanceVendor)
    L3PROP_LONG(ProcessTime)
    L3PROP_DOUBLE(ProcessAmount)
    L3PROP_STRING(Note)
    L3PROP_STRING(Action)
    L3PROP_DATETIME(Time_Change)
    L3PROP_STRING(Operator)
    L3PROP_STRING(Shift)
    L3PROP_STRING(Team)
END_L3PROPTABLE(CDeS_Lance_Log)

BEGIN_L3METHODMAP(CDeS_Lance_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Lance_Log,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Lance_Log)

CDeS_Lance_Log::CDeS_Lance_Log(void)
{
}

CDeS_Lance_Log::~CDeS_Lance_Log(void)
{
}
