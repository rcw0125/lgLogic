// �߼���CDeS_Process_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDeS_Process_Data.h"

IMPLEMENT_L3CLASS(CDeS_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Process_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(MaterialID)
	L3PROP_DOUBLE(S_B)
	L3PROP_DOUBLE(S_A)
	L3PROP_DOUBLE(P_B)
	L3PROP_DOUBLE(P_A)
	L3PROP_DOUBLE(Mat_Consume)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(LanceAge)
	L3PROP_LONG(BlowTime)
	L3PROP_DATETIME(BlowBeginTime)
	L3PROP_DATETIME(BlowEndTime)
	L3PROP_STRING(AreaID)
END_L3PROPTABLE(CDeS_Process_Data)

BEGIN_L3METHODMAP(CDeS_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Process_Data)

CDeS_Process_Data::CDeS_Process_Data(void)
{
}

CDeS_Process_Data::~CDeS_Process_Data(void)
{
}
