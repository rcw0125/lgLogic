// �߼���CAOD_Prod_AreaԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAOD_Prod_Area.h"

IMPLEMENT_L3CLASS(CAOD_Prod_Area,ProduceArea,1)

BEGIN_L3PROPTABLE(CAOD_Prod_Area,ProduceArea)
	L3PROP_LONG(Status)
	L3PROP_STRING(NextSteel)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DOUBLE(Weight)
	L3PROP_DATETIME(Arrive_Time)
	/*L3PROP_LONG(SoftBlowTime)
	L3PROP_LONG(WiredFlag)*/
END_L3PROPTABLE(CAOD_Prod_Area)

BEGIN_L3METHODMAP(CAOD_Prod_Area,ProduceArea)
   L3_METHOD(CAOD_Prod_Area,"OnTimer",0,OnTimer,L3VT_BOOL,L3VTS_ULONG)
   L3_METHOD(CAOD_Prod_Area,"SetLFAreaTimer",0,SetLFAreaTimer,L3VT_BOOL,L3VTS_NONE)
   L3_METHOD(CAOD_Prod_Area,"KillLFAreaTimer",0,KillLFAreaTimer,L3VT_BOOL,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAOD_Prod_Area,ProduceArea)
END_L3EVENTSINK_MAP(CAOD_Prod_Area)

CAOD_Prod_Area::CAOD_Prod_Area(void)
{
	m_iTimer = 0;
}

CAOD_Prod_Area::~CAOD_Prod_Area(void)
{
}
