// �߼���CSteelBulk_Consume_RateԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CSteelBulk_Consume_Rate.h"

IMPLEMENT_L3CLASS(CSteelBulk_Consume_Rate,CL3Object,1)

BEGIN_L3PROPTABLE(CSteelBulk_Consume_Rate,CL3Object)
	L3PROP_STRING(MatCode)
	L3PROP_FLOAT(Unit_Consume)
END_L3PROPTABLE(CSteelBulk_Consume_Rate)

BEGIN_L3METHODMAP(CSteelBulk_Consume_Rate,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CSteelBulk_Consume_Rate,CL3Object)
END_L3EVENTSINK_MAP(CSteelBulk_Consume_Rate)

CSteelBulk_Consume_Rate::CSteelBulk_Consume_Rate(void)
{
}

CSteelBulk_Consume_Rate::~CSteelBulk_Consume_Rate(void)
{
}
