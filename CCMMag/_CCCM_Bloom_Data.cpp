// 逻辑类CCCM_Bloom_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Bloom_Data.h"

IMPLEMENT_L3CLASS(CCCM_Bloom_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Bloom_Data,CL3Object)
	L3PROP_STRING(Caster_ID)
	L3PROP_STRING(Casting_No)
	L3PROP_LONG(Casting_Heat_Cnt)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_STRING(SteelGrade)
	L3PROP_LONG(Width)
	L3PROP_LONG(Length)
	L3PROP_DOUBLE(Cal_Weight)
	L3PROP_DOUBLE(Weight)
	L3PROP_DATETIME(Cut_Time)
	L3PROP_LONG(Thickness)
END_L3PROPTABLE(CCCM_Bloom_Data)

BEGIN_L3METHODMAP(CCCM_Bloom_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Bloom_Data,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Bloom_Data)

CCCM_Bloom_Data::CCCM_Bloom_Data(void)
{
}

CCCM_Bloom_Data::~CCCM_Bloom_Data(void)
{
}
