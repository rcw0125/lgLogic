// �߼���CCCM_Tundish_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Tundish_Data.h"

IMPLEMENT_L3CLASS(CCCM_Tundish_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Tundish_Data,CL3Object)

	///2009-02-13 ɾ���а���������ʡ��а���������ء��а�����ǽ���а�����ǽ���ҡ�
	///�а�����ǽ���ʡ�Ԥ��С��ʼʱ�̡�Ԥ���л�ʼʱ�̡�Ԥ�ȴ��ʼʱ�̡�Ԥ�Ƚ���ʱ�̡�
	///Ԥ�Ƚ����а��������¶ȡ�Ԥ�Ƚ�������ʽˮ���¶ȡ�����ʽˮ���ͺš�����ʽˮ�ڲ��ء�
	///�����ͺš��������ء��а��Ǳ�š��а��Ǳ�š��а�����Ʒ���а����ڷϡ��а����Ǽ����ơ��а����Ǽ�����
	///���ӣ����ο�ʼʱ�̡����ν���ʱ�̡��а���������

	L3PROP_STRING(TundishNo)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(TundishID)
	L3PROP_STRING(Tundish_CarID)
	L3PROP_STRING(First_HeatID)
	L3PROP_STRING(Last_HeatID)
	L3PROP_LONG(HeatCount)
	L3PROP_STRING(Fender_Slag_Usage_Case)
	L3PROP_STRING(Cover_Factory)
	L3PROP_STRING(Reason_Holt_Casting)
	L3PROP_DOUBLE(Remain_Steel_Weight)
	L3PROP_DATETIME(Casting_Start_Time)
	L3PROP_DATETIME(Casting_Stop_Time)	
	L3PROP_STRING(WorkID)

END_L3PROPTABLE(CCCM_Tundish_Data)

BEGIN_L3METHODMAP(CCCM_Tundish_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Tundish_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Tundish_Data)

CCCM_Tundish_Data::CCCM_Tundish_Data(void)
{
}

CCCM_Tundish_Data::~CCCM_Tundish_Data(void)
{
}
