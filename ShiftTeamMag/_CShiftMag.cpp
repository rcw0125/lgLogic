// 逻辑类ShiftMag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CShiftMag.h"

IMPLEMENT_L3CLASS(CShiftMag,CL3Object,1)

BEGIN_L3PROPTABLE(CShiftMag,CL3Object)
	L3PROP_STRING(L3Name)				//主键
END_L3PROPTABLE(CShiftMag)

BEGIN_L3METHODMAP(CShiftMag,CL3Object)
	  L3_METHOD(CShiftMag,"AutoModifyProcessShift",     0, AutoModifyProcessShift,	L3VT_BOOL,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"GetShiftTeamOrder",			1, GetShiftTeamOrder,		L3VT_RECORDSET,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"CommitShiftTeamOrder",		2, CommitShiftTeamOrder,	L3VT_BOOL,L3VTS_RECORDSET)
	  L3_METHOD(CShiftMag,"DeleteShiftTeamOrder",		3, DeleteShiftTeamOrder,	L3VT_BOOL,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"GetUnitTime",				4, GetUnitTime,				L3VT_RECORDSET,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"CommitUnitTime",				5, CommitUnitTime,			L3VT_BOOL,L3VTS_RECORDSET)
	  L3_METHOD(CShiftMag,"DeleteUnitTime",				6, DeleteUnitTime,			L3VT_BOOL,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"GetUnitOperator",			7, GetUnitOperator,			L3VT_RECORDSET,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"CommitUnitOperator",			8, CommitUnitOperator,		L3VT_BOOL,L3VTS_RECORDSET)
	  L3_METHOD(CShiftMag,"DeleteUnitOperator",			9, DeleteUnitOperator,		L3VT_BOOL,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"GetShiftTeamID",			   10, GetShiftTeamID,			L3VT_RECORDSET,L3VTS_STRING)
	  L3_METHOD(CShiftMag,"GetCurrentShiftTeamID",	   11, GetCurrentShiftTeamID,	L3VT_RECORDSET,L3VTS_SHORT)
	  L3_METHOD(CShiftMag,"GetSessionShiftTeam",	   12, GetSessionShiftTeam,		L3VT_RECORDSET,L3VTS_NONE)
	  L3_METHOD(CShiftMag,"AutoWarning",			   13, AutoWarning,				L3VT_BOOL,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CShiftMag,CL3Object)
END_L3EVENTSINK_MAP(CShiftMag)

CShiftMag::CShiftMag(void)
{
}

CShiftMag::~CShiftMag(void)
{
}
