// �߼���CAOD_Side_BlowingԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAOD_Side_Blowing.h"

IMPLEMENT_L3CLASS(CAOD_Side_Blowing,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Side_Blowing,CL3Object)
	L3PROP_STRING(Treatno)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Type)
	L3PROP_FLOAT(Flow)
	L3PROP_FLOAT(Pressure)
	L3PROP_SHORT(Type2)
	L3PROP_FLOAT(Flow2)
	L3PROP_FLOAT(Pressure2)
	L3PROP_DATETIME(Catch_Time)
	
END_L3PROPTABLE(CAOD_Side_Blowing)

BEGIN_L3METHODMAP(CAOD_Side_Blowing,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Side_Blowing,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Side_Blowing)

CAOD_Side_Blowing::CAOD_Side_Blowing(void)
{
}

CAOD_Side_Blowing::~CAOD_Side_Blowing(void)
{
}
