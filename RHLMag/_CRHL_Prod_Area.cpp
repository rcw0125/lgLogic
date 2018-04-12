// 逻辑类CRHL_Prod_Area源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CRHL_Prod_Area.h"

IMPLEMENT_L3CLASS(CRHL_Prod_Area,ProduceArea,1)

BEGIN_L3PROPTABLE(CRHL_Prod_Area,ProduceArea)
	L3PROP_LONG(Status)
	L3PROP_STRING(NextSteel)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(SteelGradeIndex)
	L3PROP_DOUBLE(Weight)
	L3PROP_DATETIME(Arrive_Time)
	L3PROP_LONG(SoftBlowTime)
	L3PROP_LONG(WiredFlag)
END_L3PROPTABLE(CRHL_Prod_Area)

BEGIN_L3METHODMAP(CRHL_Prod_Area,ProduceArea)
   L3_METHOD(CRHL_Prod_Area,"OnTimer",0,OnTimer,L3VT_BOOL,L3VTS_ULONG)
   L3_METHOD(CRHL_Prod_Area,"SetLFAreaTimer",0,SetLFAreaTimer,L3VT_BOOL,L3VTS_NONE)
   L3_METHOD(CRHL_Prod_Area,"KillLFAreaTimer",0,KillLFAreaTimer,L3VT_BOOL,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CRHL_Prod_Area,ProduceArea)
END_L3EVENTSINK_MAP(CRHL_Prod_Area)

CRHL_Prod_Area::CRHL_Prod_Area(void)
{
	m_iTimer = 0;
}

CRHL_Prod_Area::~CRHL_Prod_Area(void)
{
}
