// �߼���CRHL_Process_SatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CRHL_Process_Status.h"

IMPLEMENT_L3CLASS(CRHL_Process_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CRHL_Process_Status,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CRHL_Process_Status)

BEGIN_L3METHODMAP(CRHL_Process_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Process_Status,CL3Object)
END_L3EVENTSINK_MAP(CRHL_Process_Status)

CRHL_Process_Status::CRHL_Process_Status(void)
{
}

CRHL_Process_Status::~CRHL_Process_Status(void)
{
}
