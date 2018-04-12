// 逻辑类CBulk_Store_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBulk_Store_Mag.h"

IMPLEMENT_L3CLASS(CBulk_Store_Mag,MaterialStore,1)

BEGIN_L3PROPTABLE(CBulk_Store_Mag,MaterialStore)
	L3PROP_LONG(Bulk_Add_Material)
END_L3PROPTABLE(CBulk_Store_Mag)

BEGIN_L3METHODMAP(CBulk_Store_Mag,MaterialStore)
	L3_METHOD(CBulk_Store_Mag,"BulkDataAccept",0,BulkDataAccept,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"BulkDataAcceptFromNC",0,BulkDataAcceptFromNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"GetMaterialOnInputCache",0,GetMaterialOnInputCache,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBulk_Store_Mag,"GetAreaIDByUnitID",0,GetAreaIDByUnitID,L3VT_STRING,L3VTS_STRING)
	L3_METHOD(CBulk_Store_Mag,"BulkApp",0,BulkApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"BulkAppConfirm",0,BulkAppConfirm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"BulkInStore",0,BulkInStore,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"GetBulkAppInfor",0,GetBulkAppInfor,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBulk_Store_Mag,"BulkAndAreaMap",0,BulkAndAreaMap,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"ModifyMaterialAmount",0,ModifyMaterialAmount,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"GetMaterialOnStore",0,GetMaterialOnStore,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBulk_Store_Mag,"BulkChangeStore",0,BulkChangeStore,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"GetAllMaterialOnStore",0,GetAllMaterialOnStore,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBulk_Store_Mag,"GetBulkArea",0,GetBulkArea,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CBulk_Store_Mag,"BulkInStoreCancel",0,BulkInStoreCancel,L3VT_LONG, L3VTS_RECORDSET)
	L3_METHOD(CBulk_Store_Mag,"BulkTransToAlloy",0,BulkTransToAlloy,L3VT_LONG, L3VTS_RECORDSET)
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Store_Mag,MaterialStore)
END_L3EVENTSINK_MAP(CBulk_Store_Mag)

CBulk_Store_Mag::CBulk_Store_Mag(void)
{
}

CBulk_Store_Mag::~CBulk_Store_Mag(void)
{
}
