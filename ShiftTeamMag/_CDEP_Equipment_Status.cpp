// �߼���CDeS_Equipment_StatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDEP_Equipment_Status.h"

IMPLEMENT_L3CLASS(CDEP_Equipment_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Equipment_Status,CL3Object)
	L3PROP_SHORT(DePID)
    L3PROP_SHORT(Status)
	L3PROP_DATETIME(Log_Time)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CDEP_Equipment_Status)

BEGIN_L3METHODMAP(CDEP_Equipment_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Equipment_Status,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Equipment_Status)

CDEP_Equipment_Status::CDEP_Equipment_Status(void)
{
}

CDEP_Equipment_Status::~CDEP_Equipment_Status(void)
{
}
