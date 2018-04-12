// �߼���CVacTube_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CVacTube_Use.h"

IMPLEMENT_L3CLASS(CVacTube_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Use,CL3Object)
	
	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Install_ID)
	L3PROP_STRING(VacTube_Code)
	L3PROP_STRING(Position)
	L3PROP_STRING(Up_Slot_ID)
	L3PROP_STRING(Bel_Slot_ID)
	L3PROP_LONG(Up_Total_Age)
	L3PROP_LONG(Bel_Total_Age)
	L3PROP_LONG(Cir_Total_Age)
	L3PROP_LONG(Aes_Soa_Total_Len)
	L3PROP_LONG(Aes_Soa_Total_Age)
	L3PROP_LONG(Des_Soa_Total_Len)
	L3PROP_LONG(Des_Soa_Total_Age)
	L3PROP_DATETIME(On_Line_Time)
	L3PROP_STRING(Crane_TeamID)
	L3PROP_DATETIME(Off_Line_Time)
	L3PROP_STRING(Off_Line_Reason)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)
END_L3PROPTABLE(CVacTube_Use)

BEGIN_L3METHODMAP(CVacTube_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Use,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Use)

CVacTube_Use::CVacTube_Use(void)
{
}

CVacTube_Use::~CVacTube_Use(void)
{
}
