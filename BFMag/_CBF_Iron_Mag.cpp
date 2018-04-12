// 逻辑类CBF_Iron_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBF_Iron_Mag.h"

IMPLEMENT_L3CLASS(CBF_Iron_Mag,MaterialStore,1)

BEGIN_L3PROPTABLE(CBF_Iron_Mag,MaterialStore)
	L3PROP_LONG(EventIronChanged)
END_L3PROPTABLE(CBF_Iron_Mag)

BEGIN_L3METHODMAP(CBF_Iron_Mag,MaterialStore)
	L3_METHOD(CBF_Iron_Mag,"NewIronData",0,NewIronData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"ModifyIronData",0,ModifyIronData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"DeleteIronData",0,DeleteIronData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"DesignatePath",0,DesignatePath,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"SendIronDataToNC",0,SendIronDataToNC,L3VT_LONG,L3VTS_STRING)
	L3_METHOD(CBF_Iron_Mag,"GetUnprocessedIrons",0,GetUnprocessedIrons,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBF_Iron_Mag,"GetIronsForDefineDest",0,GetIronsForDefineDest,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBF_Iron_Mag,"QueryIronInfo",0,QueryIronInfo,L3VT_RECORDSET,L3VTS_DATETIME L3VTS_DATETIME L3VTS_LONG)
	L3_METHOD(CBF_Iron_Mag,"GetMaxTAPNoByBFID",0,GetMaxTAPNoByBFID,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CBF_Iron_Mag,"GetLastTareWeightByTPCNo",0,GetLastTareWeightByTPCNo,L3VT_DOUBLE,L3VTS_STRING)
	L3_METHOD(CBF_Iron_Mag,"GetUnArrivedIrons",0,GetUnArrivedIrons,L3VT_RECORDSET,L3VTS_LONG)
	L3_METHOD(CBF_Iron_Mag,"ConfirmIronArrive",0,ConfirmIronArrive,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"SetIronTare",0,SetIronTare,L3VT_LONG,L3VTS_STRING L3VTS_STRING L3VTS_FLOAT)
	L3_METHOD(CBF_Iron_Mag,"GetBFChemicalData",0,GetBFChemicalData,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CBF_Iron_Mag,"NewIronInfo",0,NewIronInfo,L3VT_LONG,L3VTS_RECORDSET)
	//L3_METHOD(CBF_Iron_Mag,"RetoLab",0,RetoLab,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"Complete",0,Complete,L3VT_BOOL,L3VTS_STRING)
	L3_METHOD(CBF_Iron_Mag,"AcceptWeightData",0,AcceptWeightData,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"SendBackIrons",0,SendBackIrons,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"SendBackArrivedIrons",0,SendBackArrivedIrons,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"SendIronToCast",0,SendIronToCast,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"MarkIronSource",0,MarkIronSource,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBF_Iron_Mag,"GetUnprocessSampIrons",0,GetUnprocessSampIrons,L3VT_RECORDSET,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBF_Iron_Mag,MaterialStore)
END_L3EVENTSINK_MAP(CBF_Iron_Mag)

CBF_Iron_Mag::CBF_Iron_Mag(void)
{
}

CBF_Iron_Mag::~CBF_Iron_Mag(void)
{
}
