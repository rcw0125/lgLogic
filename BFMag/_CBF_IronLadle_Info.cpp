// �߼���CBF_IronLadle_InfoԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBF_IronLadle_Info.h"

IMPLEMENT_L3CLASS(CBF_IronLadle_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CBF_IronLadle_Info,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(TPC_No)
	L3PROP_STRING(GroupNo)
	L3PROP_LONG(Order_No)
	L3PROP_DATETIME(ModifyTime)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CBF_IronLadle_Info)

BEGIN_L3METHODMAP(CBF_IronLadle_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBF_IronLadle_Info,CL3Object)
END_L3EVENTSINK_MAP(CBF_IronLadle_Info)

CBF_IronLadle_Info::CBF_IronLadle_Info(void)
{
}

CBF_IronLadle_Info::~CBF_IronLadle_Info(void)
{
}
