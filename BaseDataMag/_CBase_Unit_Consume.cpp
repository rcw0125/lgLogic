// �߼���CBase_Unit_ConsumeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Unit_Consume.h"

IMPLEMENT_L3CLASS(CBase_Unit_Consume,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Unit_Consume,CL3Object)
	L3PROP_STRING(SteelType)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(Ele_Code)
	L3PROP_STRING(Ele_Des)
	L3PROP_FLOAT(Unit_Consume)
END_L3PROPTABLE(CBase_Unit_Consume)

BEGIN_L3METHODMAP(CBase_Unit_Consume,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Unit_Consume,CL3Object)
END_L3EVENTSINK_MAP(CBase_Unit_Consume)

CBase_Unit_Consume::CBase_Unit_Consume(void)
{
}

CBase_Unit_Consume::~CBase_Unit_Consume(void)
{
}
