// 逻辑类CDeS_Base_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Base_Data.h"

IMPLEMENT_L3CLASS(CDeS_Base_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Base_Data,CL3Object)
    L3PROP_STRING(MaterialID)
	L3PROP_STRING(TAP_No)
	L3PROP_STRING(TPC_No)
	L3PROP_STRING(DeS_UnitID)
	L3PROP_STRING(RemoveSlag_UnitID)
	L3PROP_STRING(DeS_Operator)
	L3PROP_STRING(RemoveSlag_Operator)
	L3PROP_LONG(DeS_Flag)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_LONG(PreRemoveSlagTime)
	L3PROP_LONG(RemoveSlagTime)
	L3PROP_LONG(BlowTimeTotal)
	L3PROP_LONG(ProcessTime)
	L3PROP_LONG(RemoveSlagCount)
	L3PROP_DOUBLE(Gross_Weight)
	L3PROP_DOUBLE(Estimate_Weight)
	L3PROP_DOUBLE(Net_Weight)
	L3PROP_SHORT(DeSType)
	L3PROP_DOUBLE(Mat_Consume)
	L3PROP_DOUBLE(Weight_MatTank)
	L3PROP_DOUBLE(Weight_SprayTank)
	L3PROP_SHORT(Status)
	L3PROP_LONG(Destination)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Note)
	L3PROP_SHORT(Locked)
	L3PROP_SHORT(SampleApplyCount_B)
	L3PROP_SHORT(SampleApplyCount_A)
	L3PROP_STRING(Mediator)
	L3PROP_LONG(TotalTime)
END_L3PROPTABLE(CDeS_Base_Data)

BEGIN_L3METHODMAP(CDeS_Base_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Base_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Base_Data)

CDeS_Base_Data::CDeS_Base_Data(void)
{
}

CDeS_Base_Data::~CDeS_Base_Data(void)
{
}
