// 逻辑类CDeS_Process_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDeS_Process_Data.h"

IMPLEMENT_L3CLASS(CDeS_Process_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Process_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(MaterialID)
	L3PROP_DOUBLE(S_B)
	L3PROP_DOUBLE(S_A)
	L3PROP_DOUBLE(P_B)
	L3PROP_DOUBLE(P_A)
	L3PROP_DOUBLE(Mat_Consume)
	L3PROP_STRING(LanceNo)
	L3PROP_LONG(LanceAge)
	L3PROP_LONG(BlowTime)
	L3PROP_DATETIME(BlowBeginTime)
	L3PROP_DATETIME(BlowEndTime)
	L3PROP_STRING(AreaID)
END_L3PROPTABLE(CDeS_Process_Data)

BEGIN_L3METHODMAP(CDeS_Process_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Process_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Process_Data)

CDeS_Process_Data::CDeS_Process_Data(void)
{
}

CDeS_Process_Data::~CDeS_Process_Data(void)
{
}
