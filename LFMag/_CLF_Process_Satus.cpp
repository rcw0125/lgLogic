// �߼���CLF_Process_SatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Process_Satus.h"

IMPLEMENT_L3CLASS(CLF_Process_Satus,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Process_Satus,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CLF_Process_Satus)

BEGIN_L3METHODMAP(CLF_Process_Satus,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Process_Satus,CL3Object)
END_L3EVENTSINK_MAP(CLF_Process_Satus)

CLF_Process_Satus::CLF_Process_Satus(void)
{
}

CLF_Process_Satus::~CLF_Process_Satus(void)
{
}
