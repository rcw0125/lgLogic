// �߼���CTundish_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTundish_Base.h"

IMPLEMENT_L3CLASS(CTundish_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CTundish_Base,CL3Object)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(Refra_Pro)
	L3PROP_STRING(Status)
	L3PROP_LONG(Tundish_Age)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_STRING(TundishNO)
	L3PROP_LONG(Flag)
	L3PROP_SHORT(TundishType)
	L3PROP_STRING(VehicleID)
END_L3PROPTABLE(CTundish_Base)

BEGIN_L3METHODMAP(CTundish_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTundish_Base,CL3Object)
END_L3EVENTSINK_MAP(CTundish_Base)

CTundish_Base::CTundish_Base(void)
{
}

CTundish_Base::~CTundish_Base(void)
{
}
