// 逻辑类UnitOperator源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CUnitOperator.h"

IMPLEMENT_L3CLASS(CUnitOperator,CL3Object,1)

BEGIN_L3PROPTABLE(CUnitOperator,CL3Object)
	L3PROP_SHORT(L3Index)				//主键
	L3PROP_STRING(UnitIndex)			//工序+工位
	L3PROP_STRING(Operator)			//操作人
END_L3PROPTABLE(CUnitOperator)

BEGIN_L3METHODMAP(CUnitOperator,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CUnitOperator,CL3Object)
END_L3EVENTSINK_MAP(CUnitOperator)

CUnitOperator::CUnitOperator(void)
{
}

CUnitOperator::~CUnitOperator(void)
{
}
