// 逻辑类UnitTimeInfo源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CUnitTimeInfo.h"

IMPLEMENT_L3CLASS(CUnitTimeInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CUnitTimeInfo,CL3Object)
	L3PROP_SHORT(L3Index)				//主键
	L3PROP_STRING(UnitIndex)			//工序+工位
	L3PROP_STRING(ShiftType)			//换班类型
	L3PROP_SHORT(ShiftID)				//班次
	L3PROP_STRING(UnitTypeID)			//工序
	L3PROP_STRING(UnitTypeIDDesc)		//工序描述
	L3PROP_STRING(UnitID)				//工位
	L3PROP_STRING(UnitIDDesc)			//工位描述
	L3PROP_DATETIME(BeginProcessTime)	//开始时刻
	L3PROP_DATETIME(EndProcessTime)		//结束时刻
END_L3PROPTABLE(CUnitTimeInfo)

BEGIN_L3METHODMAP(CUnitTimeInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CUnitTimeInfo,CL3Object)
END_L3EVENTSINK_MAP(CUnitTimeInfo)

CUnitTimeInfo::CUnitTimeInfo(void)
{
}

CUnitTimeInfo::~CUnitTimeInfo(void)
{
}
