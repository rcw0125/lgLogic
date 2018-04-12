// 逻辑类CAlloy_Store_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CAlloy_Store_Mag.h"

IMPLEMENT_L3CLASS(CAlloy_Store_Mag,MaterialStore,1)

BEGIN_L3PROPTABLE(CAlloy_Store_Mag,MaterialStore)
	L3PROP_LONG(Alloy_Add_Material)
END_L3PROPTABLE(CAlloy_Store_Mag)

BEGIN_L3METHODMAP(CAlloy_Store_Mag,MaterialStore)
	L3_METHOD(CAlloy_Store_Mag,"AlloyDataAccept",0,AlloyDataAccept,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyElementDataAccept",0,AlloyElementDataAccept,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"GetMaterialOnInputCache",0,GetMaterialOnInputCache,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CAlloy_Store_Mag,"GetAreaIDByUnitID",0,GetAreaIDByUnitID,L3VT_STRING,L3VTS_STRING)
	L3_METHOD(CAlloy_Store_Mag,"AlloyApp",0,AlloyApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyAppConfirm",0,AlloyAppConfirm,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyInStore",0,AlloyInStore,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"GetAlloyAppInfor",0,GetAlloyAppInfor,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CAlloy_Store_Mag,"AlloyAndAreaMap",0,AlloyAndAreaMap,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"ModifyMaterialAmountFuction",0,ModifyMaterialAmountFuction,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"ModifyMaterialAmount",0,ModifyMaterialAmount,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"GetMaterialOnStore",0,GetMaterialOnStore,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CAlloy_Store_Mag,"GetAllMaterialOnStore",0,GetAllMaterialOnStore,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CAlloy_Store_Mag,"AlloyChangeStore",0,AlloyChangeStore,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"GetAlloyArea",0,GetAlloyArea,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CAlloy_Store_Mag,"GetUnitClosedHeatID",0,GetUnitClosedHeatID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CAlloy_Store_Mag,"AlloyDataAcceptFromNC",0,AlloyDataAcceptFromNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyElementDataAcceptFormNC",0,AlloyElementDataAcceptFormNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"ResetWeight",0,ResetWeight,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyBackAcceptFromNC",0,AlloyBackAcceptFromNC,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyInStoreCancel",0,AlloyInStoreCancel,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CAlloy_Store_Mag,"AlloyTransToBulk",0,AlloyTransToBulk,L3VT_LONG,L3VTS_RECORDSET)
	

END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Store_Mag,MaterialStore)
END_L3EVENTSINK_MAP(CAlloy_Store_Mag)

CAlloy_Store_Mag::CAlloy_Store_Mag(void)
{
}

CAlloy_Store_Mag::~CAlloy_Store_Mag(void)
{
}
