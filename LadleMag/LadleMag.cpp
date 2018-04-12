// LadleMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "LadleMag.h"
#include "_CLadle_Base.h"
#include "_CLadle_In_Build.h"
#include "_CLadle_Com_Tie.h"
#include "_CLadle_Com_Lad_Rep.h"
#include "_CLadle_Fin_Build.h"
#include "_CLadle_Cha_Dre_Lin.h"
#include "_CLadle_Use.h"
#include "_CLadle_Fire.h"
#include "_CLadle_Pour.h"
#include "_CLadle_Fold.h"
#include "_CLadle_Plan.h"
#include "_CLadle_Mag.h"
#include "_CLadle_Process.h"

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

// CLadleMagApp

BEGIN_MESSAGE_MAP(CLadleMagApp, CWinApp)
END_MESSAGE_MAP()


// CLadleMagApp 构造

CLadleMagApp::CLadleMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CLadleMagApp 对象

CLadleMagApp theApp;


// CLadleMagApp 初始化

BOOL CLadleMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LadleMag)
L3CLASS(CLadle_Base,XGMESLogic\\LadleMag\\CLadle_Base)
L3CLASS(CLadle_In_Build,XGMESLogic\\LadleMag\\CLadle_In_Build)
L3CLASS(CLadle_Com_Tie,XGMESLogic\\LadleMag\\CLadle_Com_Tie)
L3CLASS(CLadle_Com_Lad_Rep,XGMESLogic\\LadleMag\\CLadle_Com_Lad_Rep)
L3CLASS(CLadle_Fin_Build,XGMESLogic\\LadleMag\\CLadle_Fin_Build)
L3CLASS(CLadle_Cha_Dre_Lin,XGMESLogic\\LadleMag\\CLadle_Cha_Dre_Lin)
L3CLASS(CLadle_Use,XGMESLogic\\LadleMag\\CLadle_Use)
L3CLASS(CLadle_Fire,XGMESLogic\\LadleMag\\CLadle_Fire)
L3CLASS(CLadle_Pour,XGMESLogic\\LadleMag\\CLadle_Pour)
L3CLASS(CLadle_Fold,XGMESLogic\\LadleMag\\CLadle_Fold)
//L3CLASS(CLadle_Plan,XGMESLogic\\LadleMag\\CLadle_Plan) 2009-04-26
L3CLASS(CLadle_Mag,XGMESLogic\\LadleMag\\CLadle_Mag)
L3CLASS(CLadle_Process,XGMESLogic\\LadleMag\\CLadle_Process)
END_L3COMP_CLASSTABLE(LadleMag)

BEGIN_L3COMP_EVENTTABLE(LadleMag)
END_L3COMP_EVENTTABLE(LadleMag)

