// 逻辑类CQA_Caster_Std_Proc源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_Caster_Std_Proc.h"

IMPLEMENT_L3CLASS(CQA_Caster_Std_Proc,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Caster_Std_Proc,CL3Object)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(Mold_Cold_Base)
	L3PROP_STRING(Mold_Shake_Base)
	L3PROP_STRING(Sec_Cold_Base)
	L3PROP_DOUBLE(Elec_Mix_Current)
	L3PROP_DOUBLE(Elec_Mix_Freq)
	L3PROP_LONG(ASTC_Flag)
	L3PROP_LONG(Cut_Coefficient)
	L3PROP_LONG(Cut_Head_Max)
	L3PROP_LONG(Cut_Head_Min)
	L3PROP_LONG(Cut_Trail_Max)
	L3PROP_LONG(Cut_Trail_Min)
	L3PROP_LONG(DifSteel_Cut_Length_Max)
	L3PROP_LONG(DifSteel_Cut_Length_Min)
	L3PROP_LONG(Mark_Cut_Length_Max)
	L3PROP_LONG(Mark_Cut_Length_Min)
	L3PROP_STRING(Bloom_Finish_Base)
	L3PROP_STRING(Slab_Check_Base)
	L3PROP_STRING(Tundish_Water_Type)
	L3PROP_DOUBLE(Tundish_Weight_Min)
	L3PROP_STRING(Protect_Slag_Base)
	L3PROP_DOUBLE(Blow_Ar_Max)
	L3PROP_DOUBLE(Blow_Ar_Min)
	L3PROP_DOUBLE(Ladle_Blow_Ar_Max)
	L3PROP_DOUBLE(Ladle_Blow_Ar_Min)
	L3PROP_DOUBLE(Change_Time_Min)
	L3PROP_DOUBLE(Hold_Steel_Time_Max)
	L3PROP_DOUBLE(Stay_Steel_Time_Max)
	L3PROP_DOUBLE(Liquid_Temp)
	L3PROP_STRING(Slow_Cold_Base)
	L3PROP_STRING(Tundish_Speed_Base)
	L3PROP_STRING(Bloom_Low_Base)

END_L3PROPTABLE(CQA_Caster_Std_Proc)

BEGIN_L3METHODMAP(CQA_Caster_Std_Proc,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Caster_Std_Proc,CL3Object)
END_L3EVENTSINK_MAP(CQA_Caster_Std_Proc)

CQA_Caster_Std_Proc::CQA_Caster_Std_Proc(void)
{
}

CQA_Caster_Std_Proc::~CQA_Caster_Std_Proc(void)
{
}
