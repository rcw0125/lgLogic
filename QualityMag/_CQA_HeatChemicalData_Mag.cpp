// 逻辑类CQA_HeatChemicalData_Mag源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CQA_HeatChemicalData_Mag.h"

IMPLEMENT_L3CLASS(CQA_HeatChemicalData_Mag,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_HeatChemicalData_Mag,CL3Object)
END_L3PROPTABLE(CQA_HeatChemicalData_Mag)

BEGIN_L3METHODMAP(CQA_HeatChemicalData_Mag,CL3Object)
	L3_METHOD(CQA_HeatChemicalData_Mag,"NewLabSheet",       0,NewLabSheet,       L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"ModifyLabSheet",    0,ModifyLabSheet,    L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"DeleteLabSheet",    0,DeleteLabSheet,    L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"SendSheetDataToLab",0,SendSheetDataToLab,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetLatelyNewHeatChemicalData",0,GetLatelyNewHeatChemicalData,L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetApplyDataByApplyID",       0,GetApplyDataByApplyID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetApplyIDByHeatIDAndAddr",  0,GetApplyIDByHeatIDAndAddr,L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING)

	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptLabSteelElement",          0,AcceptLabSteelElement,     L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptLabSteelElementText",      0,AcceptLabSteelElementText,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptLabIronElement",			 0,AcceptLabIronElement,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptLabIronElementText",       0,AcceptLabIronElementText,L3VT_LONG,L3VTS_RECORDSET)	
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptSlagElement",				 0,AcceptSlagElement,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptSlagElementText",			 0,AcceptSlagElementText,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptSPrintData",				0,AcceptSPrintData,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptBFIronElementData",		 0,AcceptBFIronElementData,     L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptErrorInfo",				0,AcceptErrorInfo,     L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"AcceptReSampleInfor",			0,AcceptReSampleInfor,     L3VT_LONG,L3VTS_RECORDSET)
	

	L3_METHOD(CQA_HeatChemicalData_Mag,"GetCutAdviceData",            0,GetCutAdviceData,     L3VT_RECORDSET,L3VTS_NONE)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetGradeByHeatID",            0,GetGradeByHeatID,     L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatChemicalData_Mag,"LabCutAdvice",                0,LabCutAdvice,        L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"DeleteCutAdvice",             0,DeleteCutAdvice,     L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetFinalActualHeatChemicalByHeatID",0,GetFinalActualHeatChemicalByHeatID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetFinalStandardHeatChemicalByHeatID",0,GetFinalStandardHeatChemicalByHeatID,L3VT_RECORDSET,L3VTS_STRING)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GetReHeatCount",0,GetReHeatCount,L3VT_LONG,L3VTS_STRING L3VTS_LONG L3VTS_LONG)
	L3_METHOD(CQA_HeatChemicalData_Mag,"NewHeatExceptionData",0,NewHeatExceptionData,L3VT_LONG,L3VTS_STRING L3VTS_LONG L3VTS_LONG L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GenLabSheet",       0,GenLabSheet,       L3VT_RECORDSET,L3VTS_STRING L3VTS_STRING L3VTS_STRING L3VTS_LONG)
	L3_METHOD(CQA_HeatChemicalData_Mag,"GenLabSheetNew",       0,GenLabSheetNew,L3VT_LONG,L3VTS_STRING L3VTS_STRING L3VTS_STRING L3VTS_STRING L3VTS_LONG)
	L3_METHOD(CQA_HeatChemicalData_Mag,"SendSheetDataToAnaL2",       0,SendSheetDataToAnaL2,L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"SendAnalysisDataToPLC",       0,SendAnalysisDataToPLC,L3VT_LONG,L3VTS_FLOAT L3VTS_FLOAT L3VTS_FLOAT)
	L3_METHOD(CQA_HeatChemicalData_Mag,"NewBFIronSheet",       0,NewBFIronSheet,       L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"NewDeSIronSheet",       0,NewDeSIronSheet,       L3VT_LONG,L3VTS_RECORDSET)
	L3_METHOD(CQA_HeatChemicalData_Mag,"NewBFSlagSheet",       0,NewBFSlagSheet,       L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_HeatChemicalData_Mag,CL3Object)
END_L3EVENTSINK_MAP(CQA_HeatChemicalData_Mag)

CQA_HeatChemicalData_Mag::CQA_HeatChemicalData_Mag(void)
{
}

CQA_HeatChemicalData_Mag::~CQA_HeatChemicalData_Mag(void)
{
}
