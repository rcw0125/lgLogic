// DeSMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "DeSMag.h"
#include "_CDeS_Unit_Mag.h"
#include "_CDeS_Prod_Area.h"
#include "_CDeS_Base_Data.h"
#include "_CDeS_Process_Data.h"
#include "_CDeS_Runtime_Data.h"
#include "_CDeS_Process_Status.h"
#include "_CDeS_Equipment_Status.h"
#include "_CDeS_Addition_Data.h"
#include "_CDeS_Lance_Data.h"
#include "_CDeS_Lance_Log.h"

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

// CDeSMagApp

BEGIN_MESSAGE_MAP(CDeSMagApp, CWinApp)
END_MESSAGE_MAP()


// CDeSMagApp 构造

CDeSMagApp::CDeSMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDeSMagApp 对象

CDeSMagApp theApp;


// CDeSMagApp 初始化

BOOL CDeSMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DeSMag)
L3CLASS(CDeS_Unit_Mag,XGMESLogic\\DeSMag\\CDeS_Unit_Mag)
L3CLASS(CDeS_Prod_Area,XGMESLogic\\DeSMag\\CDeS_Prod_Area)
L3CLASS(CDeS_Base_Data,XGMESLogic\\DeSMag\\CDeS_Base_Data)
L3CLASS(CDeS_Process_Data,XGMESLogic\\DeSMag\\CDeS_Process_Data)
L3CLASS(CDeS_Runtime_Data,XGMESLogic\\DeSMag\\CDeS_Runtime_Data)
L3CLASS(CDeS_Process_Status,XGMESLogic\\DeSMag\\CDeS_Process_Status)
L3CLASS(CDeS_Equipment_Status,XGMESLogic\\DeSMag\\CDeS_Equipment_Status)
L3CLASS(CDeS_Addition_Data,XGMESLogic\\DeSMag\\CDeS_Addition_Data)
L3CLASS(CDeS_Lance_Data,XGMESLogic\\DeSMag\\CDeS_Lance_Data)
L3CLASS(CDeS_Lance_Log,XGMESLogic\\DeSMag\\CDeS_Lance_Log)
END_L3COMP_CLASSTABLE(DeSMag)

BEGIN_L3COMP_EVENTTABLE(DeSMag)
END_L3COMP_EVENTTABLE(DeSMag)

