// �߼���CCalibration_SetԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCalibration_Set.h"

IMPLEMENT_L3CLASS(CCalibration_Set,CL3Object,1)

BEGIN_L3PROPTABLE(CCalibration_Set,CL3Object)
	L3PROP_STRING(Location)
	L3PROP_STRING(Location_Des)
	L3PROP_STRING(Meter)
	L3PROP_STRING(Meter_Size)
	L3PROP_STRING(Range)
	L3PROP_STRING(Precision)
	L3PROP_STRING(Factory)
	L3PROP_STRING(Measure_ID)
	L3PROP_STRING(Standard_Equ)
	L3PROP_STRING(Scale_Min)
END_L3PROPTABLE(CCalibration_Set)

BEGIN_L3METHODMAP(CCalibration_Set,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCalibration_Set,CL3Object)
END_L3EVENTSINK_MAP(CCalibration_Set)

CCalibration_Set::CCalibration_Set(void)
{
}

CCalibration_Set::~CCalibration_Set(void)
{
}
