// 逻辑类CQA_HeatGradeAssume_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_HeatGradeAssume_Mag.h"

IMPLEMENT_L3CLASS(CQA_HeatGradeAssume_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_HeatGradeAssume_Mag,CL3Object)
	L3PROP_STRING(NewHeatAbnormalEvent)
	L3PROP_LONG (FinalJudgeEvent)
END_L3PROPTABLE(CQA_HeatGradeAssume_Mag)

BEGIN_L3METHODMAP(CQA_HeatGradeAssume_Mag,CL3Object)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"LogHeatExceptionData",    0,LogHeatExceptionData,    L3VT_SHORT,L3VTS_SHORT L3VTS_SHORT L3VTS_STRING L3VTS_SHORT L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"HeatJudge",               1,HeatJudge,               L3VT_LONG,L3VTS_STRING L3VTS_STRING L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"LogQAOperateInfo",        2,LogQAOperateInfo,        L3VT_SHORT,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"HeatFinalJudge",          3,HeatFinalJudge,          L3VT_SHORT,L3VTS_STRING L3VTS_RECORDSET L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetHeatGradeData",        4,GetHeatGradeData,        L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetHeatProcessExceptData",5,GetHeatProcessExceptData,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetHeatJudgeUnitInfo",    6,GetHeatJudgeUnitInfo,    L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetFinJudgeHeat",         7,GetFinJudgeHeat,         L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"ModHeatGrade",            8,ModHeatGrade,            L3VT_SHORT,L3VTS_STRING L3VTS_SHORT L3VTS_SHORT L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"CreateQAHeatGradeData",   9,CreateQAHeatGradeData,   L3VT_SHORT,L3VTS_STRING L3VTS_STRING L3VTS_SHORT L3VTS_SHORT L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetUnJudgeHeatID",        10,GetUnJudgeHeatID,       L3VT_RECORDSET,L3VTS_LONG)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetSurfaceJudgeInfor",    11,GetSurfaceJudgeInfor,   L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetBloomTerminalEle",	 12,GetBloomTerminalEle,	L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetBloomStdEle",			 13,GetBloomStdEle,			L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetFinJudgeInfor",		 14,GetFinJudgeInfor,		L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetRefineThirdEle",		 15,GetRefineThirdEle,		L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatGradeAssume_Mag,"BofSteelQualityJudge",    16,BofSteelQualityJudge,	L3VT_LONG,L3VTS_RECORDSET)
	
	
	
	L3_METHOD(CQA_HeatGradeAssume_Mag,"GetBofSteelJudgeHeat",0,GetBofSteelJudgeHeat,L3VT_RECORDSET,L3VTS_NONE)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_HeatGradeAssume_Mag,CL3Object)
END_L3EVENTSINK_MAP(CQA_HeatGradeAssume_Mag)

CQA_HeatGradeAssume_Mag::CQA_HeatGradeAssume_Mag(void)
{
}

CQA_HeatGradeAssume_Mag::~CQA_HeatGradeAssume_Mag(void)
{
}
