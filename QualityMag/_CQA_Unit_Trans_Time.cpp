// �߼���CQA_Unit_Trans_TimeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Unit_Trans_Time.h"

IMPLEMENT_L3CLASS(CQA_Unit_Trans_Time,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Unit_Trans_Time,CL3Object)
	L3PROP_STRING(Start_Unit)
	L3PROP_STRING(End_Unit)
	L3PROP_LONG(Transport_Time)
END_L3PROPTABLE(CQA_Unit_Trans_Time)

BEGIN_L3METHODMAP(CQA_Unit_Trans_Time,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Unit_Trans_Time,CL3Object)
END_L3EVENTSINK_MAP(CQA_Unit_Trans_Time)

CQA_Unit_Trans_Time::CQA_Unit_Trans_Time(void)
{
}

CQA_Unit_Trans_Time::~CQA_Unit_Trans_Time(void)
{
}
