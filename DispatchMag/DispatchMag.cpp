// DispatchMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "DispatchMag.h"
#include "_CDisp_SteelBack_App.h"
#include "_CDisp_SteelTurn_App.h"
#include "_CDisp_SteelDiv_App.h"
#include "_CDisp_SteelExchange_App.h"
#include "_CDispatch_Mag.h"
#include "_CDisp_Duty_Note.h"
#include "_CDisp_Unit_ProcessTime.h"
#include "_CDisp_Account.h"
#include "_CDisp_Exceptional.h"
#include "_CDisp_Exceptional_Items.h"

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

// CDispatchMagApp

BEGIN_MESSAGE_MAP(CDispatchMagApp, CWinApp)
END_MESSAGE_MAP()


// CDispatchMagApp 构造

CDispatchMagApp::CDispatchMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDispatchMagApp 对象

CDispatchMagApp theApp;


// CDispatchMagApp 初始化

BOOL CDispatchMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DispatchMag)
L3CLASS(CDisp_SteelBack_App,XGMESLogic\\DispatchMag\\CDisp_SteelBack_App)
L3CLASS(CDisp_SteelTurn_App,XGMESLogic\\DispatchMag\\CDisp_SteelTurn_App)
//L3CLASS(CDisp_SteelDiv_App,XGMESLogic\\DispatchMag\\CDisp_SteelDiv_App)  2009-04-26
L3CLASS(CDisp_SteelExchange_App,XGMESLogic\\DispatchMag\\CDisp_SteelExchange_App)
L3CLASS(CDispatch_Mag,XGMESLogic\\DispatchMag\\CDispatch_Mag)
L3CLASS(CDisp_Duty_Note,XGMESLogic\\DispatchMag\\CDisp_Duty_Note)
L3CLASS(CDisp_Unit_ProcessTime,XGMESLogic\\DispatchMag\\CDisp_Unit_ProcessTime)
L3CLASS(CDisp_Account,XGMESLogic\\DispatchMag\\CDisp_Account)
L3CLASS(CDisp_Exceptional,XGMESLogic\\DispatchMag\\CDisp_Exceptional)
L3CLASS(CDisp_Exceptional_Items,XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items)
END_L3COMP_CLASSTABLE(DispatchMag)

BEGIN_L3COMP_EVENTTABLE(DispatchMag)
END_L3COMP_EVENTTABLE(DispatchMag)

