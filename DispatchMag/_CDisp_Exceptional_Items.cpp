// �߼���CDisp_Exceptional_ItemsԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDisp_Exceptional_Items.h"

IMPLEMENT_L3CLASS(CDisp_Exceptional_Items,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Exceptional_Items,CL3Object)
	L3PROP_STRING(IDObject)
	L3PROP_STRING(Items)
	L3PROP_STRING(BeginTime)
	L3PROP_STRING(EndTime)
	L3PROP_LONG(TimeSpan)
	L3PROP_STRING_LEN(Note,500)
	L3PROP_STRING(CreateTime)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CDisp_Exceptional_Items)

BEGIN_L3METHODMAP(CDisp_Exceptional_Items,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Exceptional_Items,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Exceptional_Items)

CDisp_Exceptional_Items::CDisp_Exceptional_Items(void)
{
}

CDisp_Exceptional_Items::~CDisp_Exceptional_Items(void)
{
}
