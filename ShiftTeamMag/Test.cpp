// Test.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "Test.h"
//#include "_CCurrentShiftInfo.h"
//
//#include "_CShiftTeamOrder.h"
//#include "_CUnitOperator.h"
//#include "_CUnitTimeInfo.h"
#include "_CDEP_Unit_Mag.h"
#include "_CDEP_Prod_Area.h"
#include "_CDEP_Base_Data.h"
#include "_CDEP_Process_Data.h"
#include "_CDEP_Runtime_Data.h"
#include "_CDEP_Process_Status.h"
#include "_CDEP_Equipment_Status.h"
#include "_CDEP_Addition_Data.h"
#include "_CDEP_Duty.h"
#include "_CDEP_Feed_Data.h"
#include "_CDEP_HeatRemark.h"
#include "_CDEP_Temp_Data.h"
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

// CShiftTeamMagApp

BEGIN_MESSAGE_MAP(CTestApp, CWinApp)
END_MESSAGE_MAP()


// CShiftTeamMagApp 构造

CTestApp::CTestApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CShiftTeamMagApp 对象

CTestApp theApp;


// CShiftTeamMagApp 初始化

BOOL CTestApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DePMag)
//L3CLASS(CCurrentShiftInfo,XGMESLogic\\Test\\CCurrentShiftInfo)
//L3CLASS(CShiftMag,XGMESLogic\\Test\\CShiftMag)
//L3CLASS(CShiftTeamOrder,XGMESLogic\\Test\\CShiftTeamOrder)
////L3CLASS(CUnitOperator,XGMESLogic\\Test\\CUnitOperator) 2009-04-26
//L3CLASS(CUnitTimeInfo,XGMESLogic\\Test\\CUnitTimeInfo)
L3CLASS(CDEP_Unit_Mag,XGMESLogic\\DePMag\\CDEP_Unit_Mag)
L3CLASS(CDEP_Prod_Area,XGMESLogic\\DePMag\\CDEP_Prod_Area)
L3CLASS(CDEP_Base_Data,XGMESLogic\\DePMag\\CDEP_Base_Data)
L3CLASS(CDEP_Process_Data,XGMESLogic\\DePMag\\CDEP_Process_Data)
L3CLASS(CDEP_Process_Status,XGMESLogic\\DePMag\\CDEP_Process_Status)
//L3CLASS(CDEP_Equipment_Status,XGMESLogic\\DePMag\\CDEP_Equipment_Status)
L3CLASS(CDEP_Addition_Data,XGMESLogic\\DePMag\\CDEP_Addition_Data)
//L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag\\CDEP_Runtime_Data)
//L3CLASS(CDEP_Duty,XGMESLogic\\DePMag\\CDEP_Duty)
L3CLASS(CDEP_Feed_Data,XGMESLogic\\DePMag\\CDEP_Feed_Data)
L3CLASS(CDEP_HeatRemark,XGMESLogic\\DePMag\\CDEP_HeatRemark)
L3CLASS(CDEP_Temp_Data,XGMESLogic\\DePMag\\CDEP_Temp_Data)
END_L3COMP_CLASSTABLE(DePMag)

BEGIN_L3COMP_EVENTTABLE(DePMag)
END_L3COMP_EVENTTABLE(DePMag)

