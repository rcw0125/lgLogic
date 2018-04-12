// 这是主 DLL 文件。

//#include "stdafx.h"
//
//#include "RHLMag.h"



// RHLMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "RHLMag.h"
#include "_CRHL_Unit_Mag.h"
#include "_CRHL_Process_Status.h"
#include "_CRHL_Equipment_Status.h"
#include "_CRHL_Process_Data.h"

#include "_CRHL_Temp_Data.h"
#include "_CRHL_Addition_Data.h"
#include "_CRHL_HeatRemark.h"


#include "_CRHL_Base_Data.h"
#include "_CRHL_Prod_Area.h"
//#include "_CRHL_Heat_Gears.h"
//#include "_CRHL_BlowAr_Data.h"
//#include "_CRHL_Ladle_Info.h"

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

// CRHLMagApp

BEGIN_MESSAGE_MAP(CRHLMagApp, CWinApp)
END_MESSAGE_MAP()


// CRHLMagApp 构造

CRHLMagApp::CRHLMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CRHLMagApp 对象

CRHLMagApp theApp;


// CRHLMagApp 初始化

BOOL CRHLMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(RHLMag)
//L3CLASS(CRHL_Communicator,XGMESLogic\\RHLMag\\CRHL_Communicator)
L3CLASS(CRHL_Unit_Mag,XGMESLogic\\RHLMag\\CRHL_Unit_Mag)
L3CLASS(CRHL_Process_Status,XGMESLogic\\RHLMag\\CRHL_Process_Status)
L3CLASS(CRHL_Equipment_Status,XGMESLogic\\RHLMag\\CRHL_Equipment_Status)
L3CLASS(CRHL_Process_Data,XGMESLogic\\RHLMag\\CRHL_Process_Data)
//L3CLASS(CRHL_Oxygen_Data,XGMESLogic\\RHLMag\\CRHL_Oxygen_Data)
L3CLASS(CRHL_Temp_Data,XGMESLogic\\RHLMag\\CRHL_Temp_Data)
L3CLASS(CRHL_Addition_Data,XGMESLogic\\RHLMag\\CRHL_Addition_Data)
L3CLASS(CRHL_HeatRemark,XGMESLogic\\RHLMag\\CRHL_HeatRemark)
//L3CLASS(CRHL_Wire_Data,XGMESLogic\\RHLMag\\CRHL_Wire_Data)
//L3CLASS(CRHL_Ladle_Data,XGMESLogic\\RHLMag\\CRHL_Ladle_Data)
//L3CLASS(CRHL_Ladle_Weight,XGMESLogic\\RHLMag\\CRHL_Ladle_Weight)
L3CLASS(CRHL_Base_Data,XGMESLogic\\RHLMag\\CRHL_Base_Data)
L3CLASS(CRHL_Prod_Area,XGMESLogic\\RHLMag\\CRHL_Prod_Area)
//L3CLASS(CRHL_Heat_Gears,XGMESLogic\\RHLMag\\CRHL_Heat_Gears)
//L3CLASS(CRHL_BlowAr_Data,XGMESLogic\\RHLMag\\CRHL_BlowAr_Data)
//L3CLASS(CRHL_Ladle_Info,XGMESLogic\\RHLMag\\CRHL_Ladle_Info)
END_L3COMP_CLASSTABLE(RHLMag)

BEGIN_L3COMP_EVENTTABLE(RHLMag)
END_L3COMP_EVENTTABLE(RHLMag)

