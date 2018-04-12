// LFMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "LFMag.h"
#include "_CLF_Communicator.h"
#include "_CLF_Unit_Mag.h"
#include "_CLF_Process_Satus.h"
#include "_CLF_Equipment_Status.h"
#include "_CLF_Process_Data.h"
#include "_CLF_Oxygen_Data.h"
#include "_CLF_Temp_Data.h"
#include "_CLF_Addition_Data.h"
#include "_CLF_HeatRemark.h"
#include "_CLF_Wire_Data.h"
#include "_CLF_Ladle_Data.h"
#include "_CLF_Ladle_Weight.h"
#include "_CLF_Base_Data.h"
#include "_CLF_Prod_Area.h"
#include "_CLF_Heat_Gears.h"
#include "_CLF_BlowAr_Data.h"
#include "_CLF_Ladle_Info.h"

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

// CLFMagApp

BEGIN_MESSAGE_MAP(CLFMagApp, CWinApp)
END_MESSAGE_MAP()


// CLFMagApp 构造

CLFMagApp::CLFMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CLFMagApp 对象

CLFMagApp theApp;


// CLFMagApp 初始化

BOOL CLFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LFMag)
//L3CLASS(CLF_Communicator,XGMESLogic\\LFMag\\CLF_Communicator)
L3CLASS(CLF_Unit_Mag,XGMESLogic\\LFMag\\CLF_Unit_Mag)
L3CLASS(CLF_Process_Satus,XGMESLogic\\LFMag\\CLF_Process_Satus)
L3CLASS(CLF_Equipment_Status,XGMESLogic\\LFMag\\CLF_Equipment_Status)
L3CLASS(CLF_Process_Data,XGMESLogic\\LFMag\\CLF_Process_Data)
L3CLASS(CLF_Oxygen_Data,XGMESLogic\\LFMag\\CLF_Oxygen_Data)
L3CLASS(CLF_Temp_Data,XGMESLogic\\LFMag\\CLF_Temp_Data)
L3CLASS(CLF_Addition_Data,XGMESLogic\\LFMag\\CLF_Addition_Data)
L3CLASS(CLF_HeatRemark,XGMESLogic\\LFMag\\CLF_HeatRemark)
L3CLASS(CLF_Wire_Data,XGMESLogic\\LFMag\\CLF_Wire_Data)
//L3CLASS(CLF_Ladle_Data,XGMESLogic\\LFMag\\CLF_Ladle_Data)
L3CLASS(CLF_Ladle_Weight,XGMESLogic\\LFMag\\CLF_Ladle_Weight)
L3CLASS(CLF_Base_Data,XGMESLogic\\LFMag\\CLF_Base_Data)
L3CLASS(CLF_Prod_Area,XGMESLogic\\LFMag\\CLF_Prod_Area)
L3CLASS(CLF_Heat_Gears,XGMESLogic\\LFMag\\CLF_Heat_Gears)
L3CLASS(CLF_BlowAr_Data,XGMESLogic\\LFMag\\CLF_BlowAr_Data)
L3CLASS(CLF_Ladle_Info,XGMESLogic\\LFMag\\CLF_Ladle_Info)
END_L3COMP_CLASSTABLE(LFMag)

BEGIN_L3COMP_EVENTTABLE(LFMag)
END_L3COMP_EVENTTABLE(LFMag)

