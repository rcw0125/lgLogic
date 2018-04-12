// 逻辑类CCommunicationStatus源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCommunicationStatus.h"

IMPLEMENT_L3CLASS(CCommunicationStatus,CL3Object,1)

BEGIN_L3PROPTABLE(CCommunicationStatus,CL3Object)
	L3PROP_STRING  (WorkShop)     //工位        
	L3PROP_LONG    (WatchDog)     //计数值  
END_L3PROPTABLE(CCommunicationStatus)

BEGIN_L3METHODMAP(CCommunicationStatus,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCommunicationStatus,CL3Object)
END_L3EVENTSINK_MAP(CCommunicationStatus)

CCommunicationStatus::CCommunicationStatus(void)
{
}

CCommunicationStatus::~CCommunicationStatus(void)
{
}
