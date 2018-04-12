// 逻辑类CBloom_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBloom_Data.h"

IMPLEMENT_L3CLASS(CBloom_Data,Material,1)

BEGIN_L3PROPTABLE(CBloom_Data,Material)
	L3PROP_STRING(CasterID)
	L3PROP_STRING(Casting_No)
	L3PROP_LONG(Casting_Heat_Cnt)
	L3PROP_STRING(Pre_SteelGradeIndex)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Cut_SteelGradeIndex)
	L3PROP_STRING(Final_SteelGradeIndex)
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_STRING(Cur_Section_ID)
	L3PROP_STRING(Cur_Pile_ID)
	L3PROP_STRING(Cur_Layer_ID)
	L3PROP_LONG(Cur_Seq_ID)
	L3PROP_STRING(Cur_Bay_ID)
	L3PROP_STRING(Destination)
	L3PROP_LONG(Hot_Send_Flag)
	L3PROP_LONG(Process_Type)
	L3PROP_STRING(Plan_Ord_ID)
	L3PROP_DATETIME(Produce_Date)
	L3PROP_LONG(Finish_Flag)
	L3PROP_DATETIME(FinishedTime)
	L3PROP_LONG(Bloom_Count)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_LONG(Right_Count)
	L3PROP_DOUBLE(Right_Weight)
	L3PROP_DOUBLE(Waster_Count)
	L3PROP_DOUBLE(Waster_Weight)
	L3PROP_DOUBLE(Waster_Count1)
	L3PROP_DOUBLE(Waster_Weight1)
	L3PROP_STRING(Waster_Reason1)
	L3PROP_DOUBLE(Waster_Count2)
	L3PROP_DOUBLE(Waster_Weight2)
	L3PROP_STRING(Waster_Reason2)
	L3PROP_DOUBLE(Waster_Count3)
	L3PROP_DOUBLE(Waster_Weight3)
	L3PROP_STRING(Waster_Reason3)
	L3PROP_LONG(Wrong_Count)
	L3PROP_DOUBLE(Wrong_Weight)
	L3PROP_LONG(Wrong_Count1)
	L3PROP_DOUBLE(Wrong_Weight1)
	L3PROP_STRING(Wrong_Reason1)
	L3PROP_LONG(Wrong_Count2)
	L3PROP_DOUBLE(Wrong_Weight2)
	L3PROP_STRING(Wrong_Reason2)
	L3PROP_LONG(Wrong_Count3)
	L3PROP_DOUBLE(Wrong_Weight3)
	L3PROP_STRING(Wrong_Reason3)
	L3PROP_STRING(SufaceDefactDes)
	L3PROP_STRING(Reason)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Test_Roll_Count)//2008-12-31 tangyi
	L3PROP_DOUBLE(Test_Roll_Weight)
	L3PROP_LONG(Back_Flag)
	L3PROP_DATETIME(Back_Date)
	//2009-08-06 tangyi
	L3PROP_LONG(Add_Bloom_Count)
	L3PROP_LONG(Div_Bloom_Count)
	L3PROP_LONG(Plan_Bloom_Count)
	L3PROP_STRING(Add_Div_HeatID)


	L3PROP_STRING(Add_HeatID1)
	L3PROP_STRING(Add_HeatID2)
	L3PROP_LONG(Add_Bloom_Count2)
END_L3PROPTABLE(CBloom_Data)

BEGIN_L3METHODMAP(CBloom_Data,Material)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBloom_Data,Material)
END_L3EVENTSINK_MAP(CBloom_Data)

CBloom_Data::CBloom_Data(void)
{
}

CBloom_Data::~CBloom_Data(void)
{
}
