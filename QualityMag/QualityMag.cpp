// QualityMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "QualityMag.h"
#include "_CQuality_Mag.h"
#include "_CQuality_Communicator.h"
#include "_CQA_Product_Sheet.h"
#include "_CQA_Des_Std.h"
#include "_CQA_BOF_Std_Base.h"
#include "_CQA_BOF_Std_InToConver.h"
#include "_CQA_BOF_Std_BlowO2.h"
#include "_CQA_BOF_Std_Bulk.h"
#include "_CQA_BOF_Std_Blow.h"
#include "_CQA_BOF_Std_Tapping.h"
#include "_CQA_BOF_Std_Ladle.h"
#include "_CQA_BOF_Std_Ar.h"
#include "_CQA_BOF_Std_Feed.h"
#include "_CQA_BOF_Std_Slag_Ele.h"
#include "_CQA_BOF_Std_InCtr_Ele.h"
#include "_CQA_LF_Std_Base.h"
#include "_CQA_LF_Std_Proc.h"
#include "_CQA_LF_Std_Alloy.h"
#include "_CQA_LF_Std_Ladle.h"
#include "_CQA_LF_Std_Slag.h"
#include "_CQA_LF_Std_Feed.h"
#include "_CQA_LF_Std_InCtr_Ele.h"
#include "_CQA_LF_Std_Slag_Ele.h"
#include "_CQA_RH_Std_Base.h"
#include "_CQA_RH_Std_Proc.h"
#include "_CQA_RH_Std_Alloy.h"
#include "_CQA_RH_Std_Feed.h"
#include "_CQA_RH_Std_InCtr_Ele.h"
#include "_CQA_Cater_Std_Base.h"
#include "_CQA_Caster_Std_Proc.h"
#include "_CQA_Caster_Std_Flux.h"
#include "_CQA_Caster_Std_Tundish.h"
#include "_CQA_Caster_Std_Speed.h"
#include "_CQA_Unit_Proc_Time.h"
#include "_CQA_Unit_Trans_Time.h"
#include "_CQA_Caster_Std_Spec.h"
#include "_CQA_Caster_Std_ProdProc.h"
#include "_CQA_Cal_Weight_Std.h"
#include "_CQA_Heat_Except_Code.h"
#include "_CQA_Except_Group_Code.h"
#include "_CQA_Decide_Code.h"
#include "_CQA_Lab_Sheet_App.h"
#include "_CQA_Lab_Cut_Advice.h"
#include "_CQA_Lab_Element_Text.h"
#include "_CQA_Unit_Route.h"
#include "_CQA_Lab_SlagEle.h"
#include "_CQA_Lab_Element.h"
#include "_CQA_Lab_SlagEle_Text.h"
#include "_CQA_Lab_S_Print.h"
#include "_CQA_Lab_Sheet_AppID.h"
#include "_CQA_Heat_FinJudge_Log.h"
#include "_CQA_Heat_Judge_Log.h"
#include "_CQA_Heat_Data.h"
#include "_CQA_Bloom_Waster_Data.h"
#include "_CQA_Bloom_HotJudge_Data.h"
#include "_CQA_Heat_Except_Code_R.h"
#include "_CQA_SteelGradeIndex_R.h"
#include "_CQA_HeatGradeData.h"
#include "_CQA_Heat_Prod_Except.h"
#include "_CQA_HeatGradeAssume_Mag.h"
#include "_CQA_HeatGradeAssumeAlg_Mag.h"
#include "_CQA_HeatChemicalData_Mag.h"
#include "_CQA_HeatSufaceAssume_Mag.h"
#include "_CQA_Operate_Log.h"
#include "_CQA_Bloom_FinJudge_Data.h"
#include "_CQA_Iron_Element.h"
#include "_CQA_ChangeSteel_Std.h"
#include "_CQA_Iron_Element_Text.h"
#include "_CQA_Bloom_Std_Spile.h"
#include "_TB_L3_ANACOMMISSION.h"
#include "_TB_L3_CHANGECAST.h"
#include "_CQA_Element_Std.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//	注意！
//
//		如果此 DLL 动态链接到 MFC
//		DLL，从此 DLL 导出并
//		调入 MFC 的任何函数在函数的最前面
//		都必须添加 AFX_MANAGE_STATE 宏。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT AccessedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// 此处为普通函数体
//		}
//
//		此宏先于任何 MFC 调用
//		出现在每个函数中十分重要。这意味着
//		它必须作为函数中的第一个语句
//		出现，甚至先于所有对象变量声明，
//		这是因为它们的构造函数可能生成 MFC
//		DLL 调用。

//
//		有关其他详细信息，
//		请参阅 MFC 技术说明 33 和 58。
//

// CQualityMagApp

BEGIN_MESSAGE_MAP(CQualityMagApp, CWinApp)
END_MESSAGE_MAP()


// CQualityMagApp 构造

CQualityMagApp::CQualityMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CQualityMagApp 对象

CQualityMagApp theApp;


// CQualityMagApp 初始化

BOOL CQualityMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(QualityMag)
L3CLASS(CQuality_Mag,XGMESLogic\\QualityMag\\CQuality_Mag)
//L3CLASS(CQuality_Communicator,XGMESLogic\\QualityMag\\CQuality_Communicator)
L3CLASS(CQA_Product_Sheet,XGMESLogic\\QualityMag\\CQA_Product_Sheet)
L3CLASS(CQA_Des_Std,XGMESLogic\\QualityMag\\CQA_Des_Std)
L3CLASS(CQA_BOF_Std_Base,XGMESLogic\\QualityMag\\CQA_BOF_Std_Base)
L3CLASS(CQA_BOF_Std_InToConver,XGMESLogic\\QualityMag\\CQA_BOF_Std_InToConver)
L3CLASS(CQA_BOF_Std_Blow,XGMESLogic\\QualityMag\\CQA_BOF_Std_Blow)
L3CLASS(CQA_BOF_Std_BlowO2,XGMESLogic\\QualityMag\\CQA_BOF_Std_BlowO2)
L3CLASS(CQA_BOF_Std_Bulk,XGMESLogic\\QualityMag\\CQA_BOF_Std_Bulk)
L3CLASS(CQA_BOF_Std_Tapping,XGMESLogic\\QualityMag\\CQA_BOF_Std_Tapping)
L3CLASS(CQA_BOF_Std_Ladle,XGMESLogic\\QualityMag\\CQA_BOF_Std_Ladle)
L3CLASS(CQA_BOF_Std_Ar,XGMESLogic\\QualityMag\\CQA_BOF_Std_Ar)
L3CLASS(CQA_BOF_Std_Feed,XGMESLogic\\QualityMag\\CQA_BOF_Std_Feed)
L3CLASS(CQA_BOF_Std_Slag_Ele,XGMESLogic\\QualityMag\\CQA_BOF_Std_Slag_Ele)
L3CLASS(CQA_BOF_Std_InCtr_Ele,XGMESLogic\\QualityMag\\CQA_BOF_Std_InCtr_Ele)
L3CLASS(CQA_LF_Std_Base,XGMESLogic\\QualityMag\\CQA_LF_Std_Base)
L3CLASS(CQA_LF_Std_Proc,XGMESLogic\\QualityMag\\CQA_LF_Std_Proc)
L3CLASS(CQA_LF_Std_Alloy,XGMESLogic\\QualityMag\\CQA_LF_Std_Alloy)
L3CLASS(CQA_LF_Std_Ladle,XGMESLogic\\QualityMag\\CQA_LF_Std_Ladle)
L3CLASS(CQA_LF_Std_Slag,XGMESLogic\\QualityMag\\CQA_LF_Std_Slag)
L3CLASS(CQA_LF_Std_Feed,XGMESLogic\\QualityMag\\CQA_LF_Std_Feed)
L3CLASS(CQA_LF_Std_InCtr_Ele,XGMESLogic\\QualityMag\\CQA_LF_Std_InCtr_Ele)
L3CLASS(CQA_LF_Std_Slag_Ele,XGMESLogic\\QualityMag\\CQA_LF_Std_Slag_Ele)
L3CLASS(CQA_RH_Std_Base,XGMESLogic\\QualityMag\\CQA_RH_Std_Base)
L3CLASS(CQA_RH_Std_Proc,XGMESLogic\\QualityMag\\CQA_RH_Std_Proc)
L3CLASS(CQA_RH_Std_Alloy,XGMESLogic\\QualityMag\\CQA_RH_Std_Alloy)
L3CLASS(CQA_RH_Std_Feed,XGMESLogic\\QualityMag\\CQA_RH_Std_Feed)
L3CLASS(CQA_RH_Std_InCtr_Ele,XGMESLogic\\QualityMag\\CQA_RH_Std_InCtr_Ele)
L3CLASS(CQA_Cater_Std_Base,XGMESLogic\\QualityMag\\CQA_Cater_Std_Base)
L3CLASS(CQA_Caster_Std_Proc,XGMESLogic\\QualityMag\\CQA_Caster_Std_Proc)
L3CLASS(CQA_Caster_Std_Flux,XGMESLogic\\QualityMag\\CQA_Caster_Std_Flux)
L3CLASS(CQA_Caster_Std_Tundish,XGMESLogic\\QualityMag\\CQA_Caster_Std_Tundish)
L3CLASS(CQA_Caster_Std_Speed,XGMESLogic\\QualityMag\\CQA_Caster_Std_Speed)
L3CLASS(CQA_Unit_Proc_Time,XGMESLogic\\QualityMag\\CQA_Unit_Proc_Time)
L3CLASS(CQA_Unit_Trans_Time,XGMESLogic\\QualityMag\\CQA_Unit_Trans_Time)
L3CLASS(CQA_Caster_Std_Spec,XGMESLogic\\QualityMag\\CQA_Caster_Std_Spec)
L3CLASS(CQA_Caster_Std_ProdProc,XGMESLogic\\QualityMag\\CQA_Caster_Std_ProdProc)
L3CLASS(CQA_Cal_Weight_Std,XGMESLogic\\QualityMag\\CQA_Cal_Weight_Std)
L3CLASS(CQA_Heat_Except_Code,XGMESLogic\\QualityMag\\CQA_Heat_Except_Code)
L3CLASS(CQA_Except_Group_Code,XGMESLogic\\QualityMag\\CQA_Except_Group_Code)
L3CLASS(CQA_Decide_Code,XGMESLogic\\QualityMag\\CQA_Decide_Code)
L3CLASS(CQA_Lab_Sheet_App,XGMESLogic\\QualityMag\\CQA_Lab_Sheet_App)
L3CLASS(CQA_Lab_Cut_Advice,XGMESLogic\\QualityMag\\CQA_Lab_Cut_Advice)
L3CLASS(CQA_Lab_Element,XGMESLogic\\QualityMag\\CQA_Lab_Element)
L3CLASS(CQA_Lab_Element_Text,XGMESLogic\\QualityMag\\CQA_Lab_Element_Text)
L3CLASS(CQA_Unit_Route,XGMESLogic\\QualityMag\\CQA_Unit_Route)
L3CLASS(CQA_Lab_SlagEle,XGMESLogic\\QualityMag\\CQA_Lab_SlagEle)
L3CLASS(CQA_Lab_SlagEle_Text,XGMESLogic\\QualityMag\\CQA_Lab_SlagEle_Text)
L3CLASS(CQA_Lab_S_Print,XGMESLogic\\QualityMag\\CQA_Lab_S_Print)
L3CLASS(CQA_Lab_Sheet_AppID,XGMESLogic\\QualityMag\\CQA_Lab_Sheet_AppID)
//L3CLASS(CQA_Heat_FinJudge_Log,XGMESLogic\\QualityMag\\CQA_Heat_FinJudge_Log) 2009-04-26
//L3CLASS(CQA_Heat_Judge_Log,XGMESLogic\\QualityMag\\CQA_Heat_Judge_Log) 2009-04-26
//L3CLASS(CQA_Heat_Data,XGMESLogic\\QualityMag\\CQA_Heat_Data) 2009-04-26
L3CLASS(CQA_Bloom_Waster_Data,XGMESLogic\\QualityMag\\CQA_Bloom_Waster_Data)
L3CLASS(CQA_Bloom_HotJudge_Data,XGMESLogic\\QualityMag\\CQA_Bloom_HotJudge_Data)
//L3CLASS(CQA_Heat_Except_Code_R,XGMESLogic\\QualityMag\\CQA_Heat_Except_Code_R)2009-04-26
L3CLASS(CQA_SteelGradeIndex_R,XGMESLogic\\QualityMag\\CQA_SteelGradeIndex_R)
L3CLASS(CQA_HeatGradeData,XGMESLogic\\QualityMag\\CQA_HeatGradeData)
L3CLASS(CQA_Heat_Prod_Except,XGMESLogic\\QualityMag\\CQA_Heat_Prod_Except)
L3CLASS(CQA_HeatGradeAssume_Mag,XGMESLogic\\QualityMag\\CQA_HeatGradeAssume_Mag)
L3CLASS(CQA_HeatGradeAssumeAlg_Mag,XGMESLogic\\QualityMag\\CQA_HeatGradeAssumeAlg_Mag)
L3CLASS(CQA_HeatChemicalData_Mag,XGMESLogic\\QualityMag\\CQA_HeatChemicalData_Mag)
L3CLASS(CQA_HeatSufaceAssume_Mag,XGMESLogic\\QualityMag\\CQA_HeatSufaceAssume_Mag)
//L3CLASS(CQA_Operate_Log,XGMESLogic\\QualityMag\\CQA_Operate_Log) 2009-04-26
L3CLASS(CQA_Bloom_FinJudge_Data,XGMESLogic\\QualityMag\\CQA_Bloom_FinJudge_Data)
L3CLASS(CQA_Iron_Element,XGMESLogic\\QualityMag\\CQA_Iron_Element)
L3CLASS(CQA_ChangeSteel_Std,XGMESLogic\\QualityMag\\CQA_ChangeSteel_Std)
L3CLASS(CQA_Iron_Element_Text,XGMESLogic\\QualityMag\\CQA_Iron_Element_Text)
L3CLASS(CQA_Bloom_Std_Spile,XGMESLogic\\QualityMag\\CQA_Bloom_Std_Spile)
L3CLASS(TB_L3_ANACOMMISSION,XGMESLogic\\QualityMag\\TB_L3_ANACOMMISSION)
L3CLASS(TB_L3_CHANGECAST,XGMESLogic\\QualityMag\\TB_L3_CHANGECAST)
L3CLASS(CQA_Element_Std,XGMESLogic\\QualityMag\\CQA_Element_Std)
END_L3COMP_CLASSTABLE(QualityMag)

BEGIN_L3COMP_EVENTTABLE(QualityMag)
END_L3COMP_EVENTTABLE(QualityMag)

