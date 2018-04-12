// �߼���CTap_Process_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Process_Data.h"

IMPLEMENT_L3CLASS(CTap_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Process_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Temp_Before_BlowAr)
	L3PROP_FLOAT(O2_Before_BlowAr)
	L3PROP_LONG(Temp_BlownAr)
	L3PROP_FLOAT(O2_BlownAr)
	L3PROP_SHORT(Blow_Mode)
	L3PROP_SHORT(Tune_Flag)
	L3PROP_LONG(BlowAr_Time)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(End_Time)
	L3PROP_FLOAT(Cold_Mat_Cunsume)
END_L3PROPTABLE(CTap_Process_Data)

BEGIN_L3METHODMAP(CTap_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Process_Data)

CTap_Process_Data::CTap_Process_Data(void)
{
}

CTap_Process_Data::~CTap_Process_Data(void)
{
}
