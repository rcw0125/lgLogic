// �߼���CAOD_Bottom_BlowingԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAOD_Bottom_Blowing.h"

IMPLEMENT_L3CLASS(CAOD_Bottom_Blowing,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Bottom_Blowing,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_DOUBLE(Flow1)
	L3PROP_DOUBLE(Pressure1)
	L3PROP_DOUBLE(Flow2)
	L3PROP_DOUBLE(Pressure2)
	L3PROP_DOUBLE(Flow3)
	L3PROP_DOUBLE(Pressure3)
	L3PROP_DOUBLE(Flow4)
	L3PROP_DOUBLE(Pressure4)
	L3PROP_DOUBLE(Flow5)
	L3PROP_DOUBLE(Pressure5)
	L3PROP_DOUBLE(Flow6)
	L3PROP_DOUBLE(Pressure6)
	L3PROP_STRING(Gas_Type)
	L3PROP_DATETIME(Catch_Time)
	L3PROP_STRING(ObjectID)
END_L3PROPTABLE(CAOD_Bottom_Blowing)

BEGIN_L3METHODMAP(CAOD_Bottom_Blowing,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Bottom_Blowing,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Bottom_Blowing)

CAOD_Bottom_Blowing::CAOD_Bottom_Blowing(void)
{
}

CAOD_Bottom_Blowing::~CAOD_Bottom_Blowing(void)
{
}
