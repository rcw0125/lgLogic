// �߼���CBase_Operator_IDԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Operator_ID.h"

IMPLEMENT_L3CLASS(CBase_Operator_ID,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Operator_ID,CL3Object)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Operator_Name)
END_L3PROPTABLE(CBase_Operator_ID)

BEGIN_L3METHODMAP(CBase_Operator_ID,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Operator_ID,CL3Object)
END_L3EVENTSINK_MAP(CBase_Operator_ID)

CBase_Operator_ID::CBase_Operator_ID(void)
{
}

CBase_Operator_ID::~CBase_Operator_ID(void)
{
}
