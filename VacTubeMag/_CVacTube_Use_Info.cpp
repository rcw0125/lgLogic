// 逻辑类CVacTube_Use_Info源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CVacTube_Use_Info.h"

IMPLEMENT_L3CLASS(CVacTube_Use_Info,CL3Object,1)

BEGIN_L3PROPTABLE(CVacTube_Use_Info,CL3Object)

	L3PROP_DATETIME(Input_Time)
	L3PROP_STRING(Install_ID)
	L3PROP_STRING(Position)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(VacTube_Code)
	L3PROP_STRING(Up_Slot_ID)
	L3PROP_STRING(Bel_Slot_ID)
	L3PROP_LONG(Up_Total_Age)
	L3PROP_LONG(Bel_Total_Age)
	L3PROP_LONG(Cir_Total_Age)
	L3PROP_LONG(Aes_Soa_On_Len)
	L3PROP_LONG(Aes_Soa_Total_Len)
	L3PROP_LONG(Aes_Soa_Total_Age)
	L3PROP_LONG(Des_Soa_On_Len)
	L3PROP_LONG(Des_Soa_Total_Len)
	L3PROP_LONG(Des_Soa_Total_Age)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_STRING(Operator)
	L3PROP_STRING(Note)

END_L3PROPTABLE(CVacTube_Use_Info)

BEGIN_L3METHODMAP(CVacTube_Use_Info,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CVacTube_Use_Info,CL3Object)
END_L3EVENTSINK_MAP(CVacTube_Use_Info)

CVacTube_Use_Info::CVacTube_Use_Info(void)
{
}

CVacTube_Use_Info::~CVacTube_Use_Info(void)
{
}
