// �߼���CCCM_Process_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Process_Data.h"

IMPLEMENT_L3CLASS(CCCM_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Process_Data,CL3Object)

	///2009-02-13 ɾ�������Ԥ��¯�š�Ԥ�����κš���Ʒ�ƺš���������������������������ע������֧����
	///������ע������֧�������������ϸ�֧�����ϸ����������ϸ�֧�������ϸ�������˦��֧���������ж�ʱ�̡�
	///���ּǺš�˦���������ϸ�֧������ˮ�������֡�©�ִ���
	///��ӻ�¯ԭ���а�����

	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CastingNo)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(TundishNo)
	L3PROP_STRING(TundishCar_Type)
	L3PROP_LONG(Casting_HeatNum)
	L3PROP_LONG(Tundish_HeatNum)
	L3PROP_DATETIME(CastingStartTime)//2008-12-26
	L3PROP_DATETIME(CastingStopTime)//2008-12-26
	L3PROP_SHORT(InjectionBar_BlowAr)
	L3PROP_DOUBLE(Weight_Return)
	L3PROP_STRING(Weight_Return_Reason)
	L3PROP_SHORT(Second_Cooling_Mode)
	L3PROP_SHORT(Second_Cooling_CurveNo)
	L3PROP_DOUBLE(Weight_Cut_Head)
	L3PROP_DOUBLE(Weight_Cut_Trail)
	L3PROP_LONG(Tundish_SlagThickness)
	L3PROP_LONG(Tundish_Bottom_Temp)
	L3PROP_LONG(Tundish_Wall_Temp)
	L3PROP_LONG(Tundish_Level_Mold)
	L3PROP_STRING(PlugBar_Control)
	L3PROP_STRING(Soft_Press_Flag_1)
	L3PROP_STRING(Soft_Press_Flag_2)
	L3PROP_STRING(Soft_Press_Flag_3)
	L3PROP_STRING(Soft_Press_Flag_4)
	L3PROP_STRING(SpeedChange)
END_L3PROPTABLE(CCCM_Process_Data)

BEGIN_L3METHODMAP(CCCM_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Process_Data)

CCCM_Process_Data::CCCM_Process_Data(void)
{
}

CCCM_Process_Data::~CCCM_Process_Data(void)
{
}
