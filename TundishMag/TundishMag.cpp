// TundishMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "TundishMag.h"
#include "_CTundish_Mag.h"
#include "_CTundish_Base.h"
#include "_CTundish_Inner_Build.h"
#include "_CTundish_Daub.h"
#include "_CTundish_Inner_Fire.h"
#include "_CTundish_OT_Install.h"
#include "_CTundish_TFF_Install.h"
#include "_CTundish_OT_Hot_Fire.h"
#include "_CTundish_TFF_Hot_Fire.h"
#include "_CTundish_OT_Refra_Use.h"
#include "_CTundish_TFF_Refra_Use.h"
#include "_CTundish_Use_Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//	注意！
//
//		如果此 DLL 动态链接到 MFC
//		DLL，从此 DLL 导出并
//		调入 MFC 的任何函数在函数的最前面
//		都必须添加 AFX_MANAGE_State 宏。
//
//		例如:
//
//		extern "C" BOOL PASCAL EXPORT AccessedFunction()
//		{
//			AFX_MANAGE_State(AfxGetStaticModuleStatus());
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

// CTundishMagApp

BEGIN_MESSAGE_MAP(CTundishMagApp, CWinApp)
END_MESSAGE_MAP()


// CTundishMagApp 构造

CTundishMagApp::CTundishMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CTundishMagApp 对象

CTundishMagApp theApp;


// CTundishMagApp 初始化

BOOL CTundishMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(TundishMag)
L3CLASS(CTundish_Base,XGMESLogic\\TundishMag\\CTundish_Base)
L3CLASS(CTundish_Inner_Build,XGMESLogic\\TundishMag\\CTundish_Inner_Build)
L3CLASS(CTundish_Daub,XGMESLogic\\TundishMag\\CTundish_Daub)
L3CLASS(CTundish_Inner_Fire,XGMESLogic\\TundishMag\\CTundish_Inner_Fire)
L3CLASS(CTundish_OT_Install,XGMESLogic\\TundishMag\\CTundish_OT_Install)
L3CLASS(CTundish_TFF_Install,XGMESLogic\\TundishMag\\CTundish_TFF_Install)
L3CLASS(CTundish_OT_Hot_Fire,XGMESLogic\\TundishMag\\CTundish_OT_Hot_Fire)
L3CLASS(CTundish_TFF_Hot_Fire,XGMESLogic\\TundishMag\\CTundish_TFF_Hot_Fire)
L3CLASS(CTundish_OT_Refra_Use,XGMESLogic\\TundishMag\\CTundish_OT_Refra_Use)
L3CLASS(CTundish_TFF_Refra_Use,XGMESLogic\\TundishMag\\CTundish_TFF_Refra_Use)
L3CLASS(CTundish_Mag,XGMESLogic\\TundishMag\\CTundish_Mag)
L3CLASS(CTundish_Use_Info,XGMESLogic\\TundishMag\\CTundish_Use_Info)
END_L3COMP_CLASSTABLE(TundishMag)

BEGIN_L3COMP_EVENTTABLE(TundishMag)
END_L3COMP_EVENTTABLE(TundishMag)

