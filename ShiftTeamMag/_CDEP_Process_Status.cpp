// �߼���CDEP_Process_StatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDEP_Process_Status.h"

IMPLEMENT_L3CLASS(CDEP_Process_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Process_Status,CL3Object)
	L3PROP_STRING(IronLadle)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_SHORT(Step)
	L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CDEP_Process_Status)

BEGIN_L3METHODMAP(CDEP_Process_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Process_Status,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Process_Status)

CDEP_Process_Status::CDEP_Process_Status(void)
{
}

CDEP_Process_Status::~CDEP_Process_Status(void)
{
}
