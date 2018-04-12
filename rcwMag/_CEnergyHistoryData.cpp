// 逻辑类CEnergyHistoryData源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEnergyHistoryData.h"

IMPLEMENT_L3CLASS(CEnergyHistoryData,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergyHistoryData,CL3Object)
	L3PROP_STRING(TagName)
	L3PROP_LONG(TagType)
	L3PROP_DOUBLE(TagValue)
	L3PROP_DATETIME(Catch_Time)
END_L3PROPTABLE(CEnergyHistoryData)

BEGIN_L3METHODMAP(CEnergyHistoryData,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergyHistoryData,CL3Object)
END_L3EVENTSINK_MAP(CEnergyHistoryData)

CEnergyHistoryData::CEnergyHistoryData(void)
{
}

CEnergyHistoryData::~CEnergyHistoryData(void)
{
}
