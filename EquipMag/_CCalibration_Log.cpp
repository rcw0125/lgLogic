// �߼���CCalibration_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCalibration_Log.h"

IMPLEMENT_L3CLASS(CCalibration_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CCalibration_Log,CL3Object)
	L3PROP_STRING(LogID)
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
	L3PROP_DATETIME(Check_Date)
	L3PROP_DATETIME(Create_Time)
	L3PROP_STRING(Operator)
	L3PROP_DATETIME(Auditing_Time)
	L3PROP_STRING(Assessor)
	L3PROP_STRING(Result)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CCalibration_Log)

BEGIN_L3METHODMAP(CCalibration_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCalibration_Log,CL3Object)
END_L3EVENTSINK_MAP(CCalibration_Log)

CCalibration_Log::CCalibration_Log(void)
{
}

CCalibration_Log::~CCalibration_Log(void)
{
}
