// 逻辑类CIronLadle_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CIronLadle_Mag.h"

IMPLEMENT_L3CLASS(CIronLadle_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CIronLadle_Mag,CL3Object)
END_L3PROPTABLE(CIronLadle_Mag)

BEGIN_L3METHODMAP(CIronLadle_Mag,CL3Object)
	L3_METHOD(CIronLadle_Mag,"GetInfos",0,GetInfos,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CIronLadle_Mag,"InsertInfos",0,InsertInfos,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CIronLadle_Mag,"UpdateInfos",0,UpdateInfos,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CIronLadle_Mag,"DeleteInfos",0,DeleteInfos,L3VT_LONG,L3VTS_RECORDSET L3VTS_STRING)

	L3_METHOD(CIronLadle_Mag,"IronLadleTieStart",0,IronLadleTieStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleTieEnd",0,IronLadleTieEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleSmallFireStart",0,IronLadleSmallFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleSmallFireEnd",0,IronLadleSmallFireEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleMiddleFireStart",0,IronLadleMiddleFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleMiddleFireEnd",0,IronLadleMiddleFireEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleBigFireStart",0,IronLadleBigFireStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleBigFireEnd",0,IronLadleBigFireEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLaldeStopUse",0,IronLaldeStopUse,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleWaitRepair",0,IronLadleWaitRepair,L3VT_LONG,L3VTS_RECORDSET)
	
	L3_METHOD(CIronLadle_Mag,"InsertTieInfos",0,InsertTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"UpdateTieInfos",0,UpdateTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"DeleteTieInfos",0,DeleteTieInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"GetTieInfos",0,GetTieInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CIronLadle_Mag,"InsertFireInfos",0,InsertFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"UpdateFireInfos",0,UpdateFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"DeleteFireInfos",0,DeleteFireInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"GetFireInfos",0,GetFireInfos,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CIronLadle_Mag,"InsertUseInfos",0,InsertUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"UpdateUseInfos",0,UpdateUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"DeleteUseInfos",0,DeleteUseInfos,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"GetUseInfos",0,GetUseInfos,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CIronLadle_Mag,"GetIronLadle_Age",0,GetIronLadle_Age,L3VT_LONG,L3VTS_STRING)
	
	L3_METHOD(CIronLadle_Mag,"IronLadleUse",0,IronLadleUse,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleHot",0,IronLadleHot,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CIronLadle_Mag,"IronLadleOffLineException",0,IronLadleOffLineException,L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CIronLadle_Mag,CL3Object)
END_L3EVENTSINK_MAP(CIronLadle_Mag)

CIronLadle_Mag::CIronLadle_Mag(void)
{
}

CIronLadle_Mag::~CIronLadle_Mag(void)
{
}
