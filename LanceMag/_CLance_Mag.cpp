// 逻辑类CLance_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CLance_Mag.h"

IMPLEMENT_L3CLASS(CLance_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Mag,CL3Object)
END_L3PROPTABLE(CLance_Mag)

BEGIN_L3METHODMAP(CLance_Mag,CL3Object)
	L3_METHOD(CLance_Mag,"SetLanceStatus",0,SetLanceStatus,L3VT_BOOL,L3VTS_RECORDSET L3VTS_STRING)

	L3_METHOD(CLance_Mag,"LanceDefendStrat",0,LanceDefendStrat,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"LanceDefendEnd",0,LanceDefendEnd,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"LanceChangeOn",0,LanceChangeOn,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"LanceOffLineCheck",0,LanceOffLineCheck,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"LanceFree",0,LanceFree,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"LanceChangeOff",0,LanceChangeOff,L3VT_BOOL,L3VTS_RECORDSET)

	L3_METHOD(CLance_Mag,"InsertLanceDefendInfo",0,InsertLanceDefendInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceDefendInfo",0,UpdateLanceDefendInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceDefendInfo",0,DeleteLanceDefendInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceDefendInfo",0,GetLanceDefendInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLance_Mag,"InsertLanceUseInfo",0,InsertLanceUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceUseInfo",0,UpdateLanceUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceUseInfo",0,DeleteLanceUseInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceUseInfo",0,GetLanceUseInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLance_Mag,"InsertLanceCheckInfo",0,InsertLanceCheckInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceCheckInfo",0,UpdateLanceCheckInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceCheckInfo",0,DeleteLanceCheckInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceCheckInfo",0,GetLanceCheckInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLance_Mag,"InsertLanceHeadInInfo",0,InsertLanceHeadInInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceHeadInInfo",0,UpdateLanceHeadInInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceHeadInInfo",0,DeleteLanceHeadInInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceLanceHeadInInfo",0,GetLanceLanceHeadInInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLance_Mag,"InsertLanceHeadOutInfo",0,InsertLanceHeadOutInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceHeadOutInfo",0,UpdateLanceHeadOutInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceHeadOutInfo",0,DeleteLanceHeadOutInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceLanceHeadOutInfo",0,GetLanceLanceHeadOutInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CLance_Mag,"InsertLanceMakeInfo",0,InsertLanceMakeInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"UpdateLanceMakeInfo",0,UpdateLanceMakeInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"DeleteLanceMakeInfo",0,DeleteLanceMakeInfo,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CLance_Mag,"GetLanceMakeInfo",0,GetLanceMakeInfo,L3VT_RECORDSET,L3VTS_STRING)
	
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Mag,CL3Object)
END_L3EVENTSINK_MAP(CLance_Mag)

CLance_Mag::CLance_Mag(void)
{
}

CLance_Mag::~CLance_Mag(void)
{
}
