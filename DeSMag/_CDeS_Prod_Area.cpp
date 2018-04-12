// 逻辑类CDeS_Prod_Area源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Prod_Area.h"

IMPLEMENT_L3CLASS(CDeS_Prod_Area,ProduceArea,1)

BEGIN_L3PROPTABLE(CDeS_Prod_Area,ProduceArea)
	L3PROP_STRING(TAP_No)
	L3PROP_STRING(TPC_No)
	L3PROP_LONG(BlowTime)
	L3PROP_DOUBLE(S)
	L3PROP_DOUBLE(Weight)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(LanceAge)
	L3PROP_DOUBLE(P)
	L3PROP_LONG(Status)
END_L3PROPTABLE(CDeS_Prod_Area)

BEGIN_L3METHODMAP(CDeS_Prod_Area,ProduceArea)
   L3_METHOD(CDeS_Prod_Area,"OnTimer",0,OnTimer,L3VT_BOOL,L3VTS_ULONG)
   L3_METHOD(CDeS_Prod_Area,"SetDeSAreaTimer",0,SetDeSAreaTimer,L3VT_BOOL,L3VTS_NONE)
   L3_METHOD(CDeS_Prod_Area,"KillDeSAreaTimer",0,KillDeSAreaTimer,L3VT_BOOL,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Prod_Area,ProduceArea)
END_L3EVENTSINK_MAP(CDeS_Prod_Area)

CDeS_Prod_Area::CDeS_Prod_Area(void)
{
	BlowTime = 0;
}

CDeS_Prod_Area::~CDeS_Prod_Area(void)
{
}
