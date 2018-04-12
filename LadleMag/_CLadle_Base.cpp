// 逻辑类CLadle_Base源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLadle_Base.h"

IMPLEMENT_L3CLASS(CLadle_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CLadle_Base,CL3Object)
	L3PROP_STRING(LadleID)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Refra_Facturer)
	L3PROP_STRING(Status)
	L3PROP_STRING(Ladle_Grade)
	L3PROP_LONG(Ladle_Age)
	L3PROP_LONG(New_BOF_Flag)
	L3PROP_DOUBLE(Tare_WT)
	L3PROP_LONG(LadleType)
	L3PROP_STRING(InnerID)
	L3PROP_STRING(WorkID)
	L3PROP_LONG(ComFlag)
	L3PROP_LONG(OnFireID)
	L3PROP_LONG(WorkFireID)
	L3PROP_LONG(Measure_Flag)//2009-04-13
	//Modify begin by llj 2011-04-09 增加永久层烘烤
	L3PROP_LONG(InnerFireID)
	//Modify end
END_L3PROPTABLE(CLadle_Base)

BEGIN_L3METHODMAP(CLadle_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLadle_Base,CL3Object)
END_L3EVENTSINK_MAP(CLadle_Base)

CLadle_Base::CLadle_Base(void)
{
}

CLadle_Base::~CLadle_Base(void)
{
}
