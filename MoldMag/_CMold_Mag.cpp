// 逻辑类CMold_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CMold_Mag.h"

IMPLEMENT_L3CLASS(CMold_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Mag,CL3Object)
END_L3PROPTABLE(CMold_Mag)

BEGIN_L3METHODMAP(CMold_Mag,CL3Object)
	L3_METHOD(CMold_Mag,"MoldInstallStart",0,MoldInstallStart,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"MoldInstallEnd",0,MoldInstallEnd,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"MoldOnLine",0,MoldOnLine,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"MoldOffLine",0,MoldOffLine,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"InsertPipeInstallInfo",0,InsertPipeInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"UpdatePipeInstallInfo",0,UpdatePipeInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"DeletePipeInstallInfo",0,DeletePipeInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"GetPipeInstallInfo",0,GetPipeInstallInfo,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CMold_Mag,"InsertBoardInstallInfo",0,InsertBoardInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"UpdateBoardInstallInfo",0,UpdateBoardInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"DeleteBoardInstallInfo",0,DeleteBoardInstallInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"GetBoardInstallInfo",0,GetBoardInstallInfo,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CMold_Mag,"InsertPipeUseInfo",0,InsertPipeUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"UpdatePipeUseInfo",0,UpdatePipeUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"DeletePipeUseInfo",0,DeletePipeUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"GetPipeUseInfo",0,GetPipeUseInfo,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CMold_Mag,"InsertBoardUseInfo",0,InsertBoardUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"UpdateBoardUseInfo",0,UpdateBoardUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"DeleteBoardUseInfo",0,DeleteBoardUseInfo,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"GetBoardUseInfo",0,GetBoardUseInfo,L3VT_RECORDSET,L3VTS_STRING)

	L3_METHOD(CMold_Mag,"MoldCheckCold",0,MoldCheckCold,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CMold_Mag,"MoldCheckBuild",0,MoldCheckBuild,L3VT_LONG,L3VTS_RECORDSET)

	L3_METHOD(CMold_Mag,"MoldChangeFlowID",0,MoldChangeFlowID,L3VT_LONG,L3VTS_STRING L3VTS_STRING)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Mag,CL3Object)
END_L3EVENTSINK_MAP(CMold_Mag)

CMold_Mag::CMold_Mag(void)
{
}

CMold_Mag::~CMold_Mag(void)
{
}
