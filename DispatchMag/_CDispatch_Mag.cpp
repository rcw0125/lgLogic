// 逻辑类CDispatch_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CDispatch_Mag.h"

IMPLEMENT_L3CLASS(CDispatch_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CDispatch_Mag,CL3Object)

	L3PROP_LONG(SteelBackAppEvent)      //钢水返送申请事件
	L3PROP_LONG(SteelReturnAppEvent)     //钢水回炉申请事件
	L3PROP_LONG(SteelDivAppEvent)		//钢水炉次分割申请事件
	L3PROP_LONG(SteelExchangeAppEvent)	//钢水改钢申请事件

END_L3PROPTABLE(CDispatch_Mag)

BEGIN_L3METHODMAP(CDispatch_Mag,CL3Object)

	L3_METHOD(CDispatch_Mag,"SteelTurnApp",0,SteelTurnApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelTurn",0,SteelTurn,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelBackApp",0,SteelBackApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelBack",0,SteelBack,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelDivApp",0,SteelDivApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelDiv",0,SteelDiv,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelExchangeApp",0,SteelExchangeApp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"SteelExchange",0,SteelExchange,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"DispatchLog",0,DispatchLog,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"GetBOFRealData",0,GetBOFRealData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetBOFSideRealData",0,GetBOFSideRealData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetFactoryEnergyData",0,GetFactoryEnergyData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetLFRealData",0,GetLFRealData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetRHRealData",0,GetRHRealData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetCasterRealData",0,GetCasterRealData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetAlloyStoreData",0,GetAlloyStoreData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetScrapStoreData",0,GetScrapStoreData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetBloomStoreData",0,GetBloomStoreData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetBulkStoreData",0,GetBulkStoreData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetCurSteelBackInfor",0,GetCurSteelBackInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetCurSteelTurnInfor",0,GetCurSteelTurnInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetCurSteelDivInfor",0,GetCurSteelDivInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetCurSteelExInfor",0,GetCurSteelExInfor,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CDispatch_Mag,"GetDestination",0,GetDestination,L3VT_STRING,L3VTS_STRING L3VTS_STRING)
	
	L3_METHOD(CDispatch_Mag,"AddDisExceptional",0,AddDisExceptional,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"ModifyDisExceptional",0,ModifyDisExceptional,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"DeleteDisExceptional",0,DeleteDisExceptional,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"AddDisExceptionalItems",0,AddDisExceptionalItems,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"ModifyDisExceptionalItems",0,ModifyDisExceptionalItems,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"DelDisExceptionalItems",0,DelDisExceptionalItems,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CDispatch_Mag,"GetDispExceData",0,GetDispExceData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CDispatch_Mag,"GetDispExceItemData",0,GetDispExceItemData,L3VT_RECORDSET,L3VTS_STRING)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDispatch_Mag,CL3Object)
END_L3EVENTSINK_MAP(CDispatch_Mag)

CDispatch_Mag::CDispatch_Mag(void)
{
}

CDispatch_Mag::~CDispatch_Mag(void)
{
}
