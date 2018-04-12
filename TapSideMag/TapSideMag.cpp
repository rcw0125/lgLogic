// TapSideMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "TapSideMag.h"
#include "_CTap_Oxygen_Data.h"
#include "_CTap_Temp_Data.h"
#include "_CTap_Addition_Data.h"
#include "_CTap_Base_Data.h"
#include "_CTap_Process_Data.h"
#include "_CTap_Unit_Mag.h"
#include "_CTap_Ladle_Weight.h"
#include "_CTAP_Communicator.h"

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

// CTapSideMagApp

BEGIN_MESSAGE_MAP(CTapSideMagApp, CWinApp)
END_MESSAGE_MAP()


// CTapSideMagApp 构造

CTapSideMagApp::CTapSideMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CTapSideMagApp 对象

CTapSideMagApp theApp;


// CTapSideMagApp 初始化

BOOL CTapSideMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(TapSideMag)
L3CLASS(CTap_Oxygen_Data,XGMESLogic\\TapSideMag\\CTap_Oxygen_Data)
L3CLASS(CTap_Temp_Data,XGMESLogic\\TapSideMag\\CTap_Temp_Data)
L3CLASS(CTap_Addition_Data,XGMESLogic\\TapSideMag\\CTap_Addition_Data)
L3CLASS(CTap_Base_Data,XGMESLogic\\TapSideMag\\CTap_Base_Data)
L3CLASS(CTap_Process_Data,XGMESLogic\\TapSideMag\\CTap_Process_Data)
L3CLASS(CTap_Unit_Mag,XGMESLogic\\TapSideMag\\CTap_Unit_Mag)
L3CLASS(CTap_Ladle_Weight,XGMESLogic\\TapSideMag\\CTap_Ladle_Weight)
//L3CLASS(CTAP_Communicator,XGMESLogic\\TapSideMag\\CTAP_Communicator)
END_L3COMP_CLASSTABLE(TapSideMag)

BEGIN_L3COMP_EVENTTABLE(TapSideMag)
END_L3COMP_EVENTTABLE(TapSideMag)

