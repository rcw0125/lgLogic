// �߼���CVacTube_Hot_Syp_UseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CVacTube_Hot_Syp_Use.h"

IMPLEMENT_L3CLASS(CVacTube_Hot_Syp_Use,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Hot_Syp_Use,CL3Object)

	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Build_ID)
	L3PROP_STRING(Hot_Syp_ID)
	L3PROP_STRING(Refra_Fac)
	L3PROP_DATETIME(On_Time)
	L3PROP_STRING(Position)
	L3PROP_STRING(On_TeamID)
	L3PROP_LONG(On_Age)
	L3PROP_LONG(Cur_Age)
	L3PROP_LONG(Total_Age)
	L3PROP_DATETIME(OffLine_Time)
	L3PROP_STRING(Off_TeamID)
	L3PROP_STRING(Off_Reason)
	L3PROP_DOUBLE(OnLine_Len)
	L3PROP_STRING(Note)
	L3PROP_STRING(On_Operator)
	L3PROP_STRING(On_ShiftID)
	L3PROP_STRING(Off_Operator)
	L3PROP_STRING(Off_ShiftID)
	
END_L3PROPTABLE(CVacTube_Hot_Syp_Use)

BEGIN_L3METHODMAP(CVacTube_Hot_Syp_Use,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Hot_Syp_Use,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Hot_Syp_Use)

CVacTube_Hot_Syp_Use::CVacTube_Hot_Syp_Use(void)
{
}

CVacTube_Hot_Syp_Use::~CVacTube_Hot_Syp_Use(void)
{
}
