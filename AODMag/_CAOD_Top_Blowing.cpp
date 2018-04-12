// �߼���CAOD_Top_BlowingԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAOD_Top_Blowing.h"

IMPLEMENT_L3CLASS(CAOD_Top_Blowing,CL3Object,1)

BEGIN_L3PROPTABLE(CAOD_Top_Blowing,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)

	
	L3PROP_FLOAT(Position)
	L3PROP_SHORT(Air_Type)
	L3PROP_FLOAT(Air_Flow)
	L3PROP_FLOAT(Air_Pressure)
	L3PROP_SHORT(Inwater_Temp)
	L3PROP_FLOAT(Inwater_Flow)
	L3PROP_SHORT(Outwater_Temp)
	L3PROP_FLOAT(Outwater_Flow)
	L3PROP_DATETIME(Catch_Time)

END_L3PROPTABLE(CAOD_Top_Blowing)

BEGIN_L3METHODMAP(CAOD_Top_Blowing,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Top_Blowing,CL3Object)
END_L3EVENTSINK_MAP(CAOD_Top_Blowing)

CAOD_Top_Blowing::CAOD_Top_Blowing(void)
{
}

CAOD_Top_Blowing::~CAOD_Top_Blowing(void)
{
}
