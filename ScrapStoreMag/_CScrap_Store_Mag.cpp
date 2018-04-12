// 逻辑类CScrap_Store_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CScrap_Store_Mag.h"

IMPLEMENT_L3CLASS(CScrap_Store_Mag,MaterialStore,1)

BEGIN_L3PROPTABLE(CScrap_Store_Mag,MaterialStore)
END_L3PROPTABLE(CScrap_Store_Mag)

BEGIN_L3METHODMAP(CScrap_Store_Mag,MaterialStore)
	L3_METHOD(CScrap_Store_Mag,"ScrapDataAccept",0,ScrapDataAccept,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"ScrapDataAcceptFromNC",0,ScrapDataAcceptFromNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"ScrapInStore",0,ScrapInStore,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"ScrapOutStore",0,ScrapOutStore,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"GetMaterialOnInputCache",0,GetMaterialOnInputCache,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CScrap_Store_Mag,"ModifyMaterialAmount",0,ModifyMaterialAmount,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"GetMaterialOnStore",0,GetMaterialOnStore,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CScrap_Store_Mag,"ScrapCancelOutStore",0,ScrapCancelOutStore,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CScrap_Store_Mag,"GetScrapes",0,GetScrapes,L3VT_RECORDSET,L3VTS_NONE)
	
	
	L3_METHOD(CScrap_Store_Mag,"SaveScrapOutDetail",0,SaveScrapOutDetail,L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrap_Store_Mag,MaterialStore)
END_L3EVENTSINK_MAP(CScrap_Store_Mag)

CScrap_Store_Mag::CScrap_Store_Mag(void)
{
}

CScrap_Store_Mag::~CScrap_Store_Mag(void)
{
}
