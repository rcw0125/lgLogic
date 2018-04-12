// LanceMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "LanceMag.h"
#include "_CLance_Base.h"
#include "_CLance_Make.h"
#include "_CLance_Check.h"
#include "_CLance_In_Yard.h"
#include "_CLance_Out_Yard.h"
#include "_CLance_Mag.h"
#include "_CLance_Use.h"
#include "_CLance_Defend.h"

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

// CLanceMagApp

BEGIN_MESSAGE_MAP(CLanceMagApp, CWinApp)
END_MESSAGE_MAP()


// CLanceMagApp 构造

CLanceMagApp::CLanceMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CLanceMagApp 对象

CLanceMagApp theApp;


// CLanceMagApp 初始化

BOOL CLanceMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LanceMag)
L3CLASS(CLance_Base,XGMESLogic\\LanceMag\\CLance_Base)
L3CLASS(CLance_Make,XGMESLogic\\LanceMag\\CLance_Make)
L3CLASS(CLance_Check,XGMESLogic\\LanceMag\\CLance_Check)
L3CLASS(CLance_In_Yard,XGMESLogic\\LanceMag\\CLance_In_Yard)
L3CLASS(CLance_Out_Yard,XGMESLogic\\LanceMag\\CLance_Out_Yard)
L3CLASS(CLance_Mag,XGMESLogic\\LanceMag\\CLance_Mag)
L3CLASS(CLance_Use,XGMESLogic\\LanceMag\\CLance_Use)
L3CLASS(CLance_Defend,XGMESLogic\\LanceMag\\CLance_Defend)
END_L3COMP_CLASSTABLE(LanceMag)

BEGIN_L3COMP_EVENTTABLE(LanceMag)
END_L3COMP_EVENTTABLE(LanceMag)

