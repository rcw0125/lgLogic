// 逻辑类CBloom_Store_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBloom_Store_Mag.h"

IMPLEMENT_L3CLASS(CBloom_Store_Mag,MaterialStore,1)

BEGIN_L3PROPTABLE(CBloom_Store_Mag,MaterialStore)

 L3PROP_LONG(BloomOffLineEvent)
 L3PROP_LONG(BloomInStore)

END_L3PROPTABLE(CBloom_Store_Mag)

BEGIN_L3METHODMAP(CBloom_Store_Mag,MaterialStore)
	L3_METHOD(CBloom_Store_Mag,"GetMaterialOnInputCache",0,GetMaterialOnInputCache,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBloom_Store_Mag,"ChangeBloomPosition",0,ChangeBloomPosition,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"BloomColdSendInStore",0,BloomColdSendInStore,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"BloomHotSend",0,BloomHotSend,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"AcceptBloomOutStoreInfor",0,AcceptBloomOutStoreInfor,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"AcceptBloomOutStoreInforFromNC",0,AcceptBloomOutStoreInforFromNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"GetBloomOnStoreArea",0,GetBloomOnStoreArea,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CBloom_Store_Mag,"BloomFinish",0,BloomFinish,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"GetWillFinishBloom",0,GetWillFinishBloom,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CBloom_Store_Mag,"BloomBack",0,BloomBack,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBloom_Store_Mag,"AcceptBloomBackInforFromNC",0,AcceptBloomBackInforFromNC,L3VT_LONG,L3VTS_RECORDSET)
	
	
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBloom_Store_Mag,MaterialStore)
END_L3EVENTSINK_MAP(CBloom_Store_Mag)

CBloom_Store_Mag::CBloom_Store_Mag(void)
{
}

CBloom_Store_Mag::~CBloom_Store_Mag(void)
{
}
