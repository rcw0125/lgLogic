// IronLadleMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "IronLadleMag.h"
#include "_CIronLadle_Mag.h"
#include "_CIronLadle_Base.h"
#include "_CIronLadle_Tie.h"
#include "_CIronLadle_Fire.h"
#include "_CIronLadle_Use.h"

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

// CIronLadleMagApp

BEGIN_MESSAGE_MAP(CIronLadleMagApp, CWinApp)
END_MESSAGE_MAP()


// CIronLadleMagApp 构造

CIronLadleMagApp::CIronLadleMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CIronLadleMagApp 对象

CIronLadleMagApp theApp;


// CIronLadleMagApp 初始化

BOOL CIronLadleMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(IronLadleMag)
L3CLASS(CIronLadle_Mag,XGMESLogic\\IronLadleMag\\CIronLadle_Mag)
L3CLASS(CIronLadle_Base,XGMESLogic\\IronLadleMag\\CIronLadle_Base)
L3CLASS(CIronLadle_Tie,XGMESLogic\\IronLadleMag\\CIronLadle_Tie)
L3CLASS(CIronLadle_Fire,XGMESLogic\\IronLadleMag\\CIronLadle_Fire)
L3CLASS(CIronLadle_Use,XGMESLogic\\IronLadleMag\\CIronLadle_Use)
END_L3COMP_CLASSTABLE(IronLadleMag)

BEGIN_L3COMP_EVENTTABLE(IronLadleMag)
END_L3COMP_EVENTTABLE(IronLadleMag)

