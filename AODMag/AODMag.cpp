// 这是主 DLL 文件。

#include "stdafx.h"

#include "AODMag.h"


// AODMag.cpp : 定义 DLL 的初始化例程。
//

//#include "stdafx.h"
//#include "AODMag.h"
//#include "_CAOD_Communicator.h"
#include "_CAOD_Unit_Mag.h"
#include "_CAOD_Process_Status.h"
#include "_CAOD_Equipment_Status.h"
#include "_CAOD_Process_Data.h"
//#include "_CAOD_Oxygen_Data.h"
#include "_CAOD_Temp_Data.h"
#include "_CAOD_Addition_Data.h"
#include "_CAOD_HeatRemark.h"
//#include "_CAOD_Wire_Data.h"
//#include "_CAOD_Ladle_Data.h"
//#include "_CAOD_Ladle_Weight.h"
#include "_CAOD_Base_Data.h"
#include "_CAOD_Prod_Area.h"
#include "_CAOD_Top_Blowing.h"
#include "_CAOD_Side_Blowing.h"
//#include "_CAOD_Ladle_Info.h"

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

// CAODMagApp

BEGIN_MESSAGE_MAP(CAODMagApp, CWinApp)
END_MESSAGE_MAP()


// CAODMagApp 构造

CAODMagApp::CAODMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAODMagApp 对象

CAODMagApp theApp;


// CAODMagApp 初始化

BOOL CAODMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(AODMag)
//L3CLASS(CAOD_Communicator,XGMESLogic\\AODMag\\CAOD_Communicator)
L3CLASS(CAOD_Unit_Mag,XGMESLogic\\AODMag\\CAOD_Unit_Mag)
L3CLASS(CAOD_Process_Status,XGMESLogic\\AODMag\\CAOD_Process_Status)
L3CLASS(CAOD_Equipment_Status,XGMESLogic\\AODMag\\CAOD_Equipment_Status)
L3CLASS(CAOD_Process_Data,XGMESLogic\\AODMag\\CAOD_Process_Data)
//L3CLASS(CAOD_Oxygen_Data,XGMESLogic\\AODMag\\CAOD_Oxygen_Data)
L3CLASS(CAOD_Temp_Data,XGMESLogic\\AODMag\\CAOD_Temp_Data)
L3CLASS(CAOD_Addition_Data,XGMESLogic\\AODMag\\CAOD_Addition_Data)
L3CLASS(CAOD_HeatRemark,XGMESLogic\\AODMag\\CAOD_HeatRemark)
//L3CLASS(CAOD_Wire_Data,XGMESLogic\\AODMag\\CAOD_Wire_Data)
//L3CLASS(CAOD_Ladle_Data,XGMESLogic\\AODMag\\CAOD_Ladle_Data)
//L3CLASS(CAOD_Ladle_Weight,XGMESLogic\\AODMag\\CAOD_Ladle_Weight)
L3CLASS(CAOD_Base_Data,XGMESLogic\\AODMag\\CAOD_Base_Data)
L3CLASS(CAOD_Prod_Area,XGMESLogic\\AODMag\\CAOD_Prod_Area)
L3CLASS(CAOD_Top_Blowing,XGMESLogic\\AODMag\\CAOD_Top_Blowing)
L3CLASS(CAOD_Side_Blowing,XGMESLogic\\AODMag\\CAOD_Side_Blowing)
//L3CLASS(CAOD_Ladle_Info,XGMESLogic\\AODMag\\CAOD_Ladle_Info)
END_L3COMP_CLASSTABLE(AODMag)

BEGIN_L3COMP_EVENTTABLE(AODMag)
END_L3COMP_EVENTTABLE(AODMag)


