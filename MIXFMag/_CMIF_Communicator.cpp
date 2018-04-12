// 逻辑类CMIF_Communicator源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMIF_Communicator.h"

IMPLEMENT_L3CLASS(CMIF_Communicator,CL3Object,1)

BEGIN_L3PROPTABLE(CMIF_Communicator,CL3Object)
END_L3PROPTABLE(CMIF_Communicator)

BEGIN_L3METHODMAP(CMIF_Communicator,CL3Object)
	L3_METHOD(CMIF_Communicator,"OnMIFTemperature",0,OnMIFTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Communicator,"OnWeight",0,OnWeight,L3VT_BOOL,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Communicator,CL3Object)
END_L3EVENTSINK_MAP(CMIF_Communicator)

CMIF_Communicator::CMIF_Communicator(void)
{
}

CMIF_Communicator::~CMIF_Communicator(void)
{
}
