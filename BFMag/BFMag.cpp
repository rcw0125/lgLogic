// BFMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "BFMag.h"
#include "_CBF_Iron_Mag.h"
#include "_CBFIronInLog.h"
#include "_CBFIronOutLog.h"
#include "_CBF_IronLadle_Info.h"
#include "_CBF_Iron_Back_Log.h"

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

// CBFMagApp

BEGIN_MESSAGE_MAP(CBFMagApp, CWinApp)
END_MESSAGE_MAP()


// CBFMagApp 构造

CBFMagApp::CBFMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBFMagApp 对象

CBFMagApp theApp;


// CBFMagApp 初始化

BOOL CBFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BFMag)
L3CLASS(CBF_Iron_Mag,XGMESLogic\\BFMag\\CBF_Iron_Mag)
L3CLASS(CBFIronInLog,XGMESLogic\\BFMag\\CBFIronInLog)
L3CLASS(CBFIronOutLog,XGMESLogic\\BFMag\\CBFIronOutLog)
L3CLASS(CBF_IronLadle_Info,XGMESLogic\\BFMag\\CBF_IronLadle_Info)
L3CLASS(CBF_Iron_Back_Log,XGMESLogic\\BFMag\\CBF_Iron_Back_Log)
END_L3COMP_CLASSTABLE(BFMag)

BEGIN_L3COMP_EVENTTABLE(BFMag)
END_L3COMP_EVENTTABLE(BFMag)

