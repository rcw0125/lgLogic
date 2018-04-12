// MoldMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "MoldMag.h"
#include "_CMold_Base.h"
#include "_CMold_Pipe_Install.h"
#include "_CMold_Board_Install.h"
#include "_CMold_Pipe_Par_Use.h"
#include "_CMold_Board_Par_Use.h"
#include "_CMold_Mag.h"
#include "_CMold_Board_Check.h"

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
//			AFX_MANAGE_STATE(AfxGetStaticModuleStatus());
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

// CMoldMagApp

BEGIN_MESSAGE_MAP(CMoldMagApp, CWinApp)
END_MESSAGE_MAP()


// CMoldMagApp 构造

CMoldMagApp::CMoldMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMoldMagApp 对象

CMoldMagApp theApp;


// CMoldMagApp 初始化

BOOL CMoldMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(MoldMag)
L3CLASS(CMold_Base,XGMESLogic\\MoldMag\\CMold_Base)
L3CLASS(CMold_Pipe_Install,XGMESLogic\\MoldMag\\CMold_Pipe_Install)
L3CLASS(CMold_Board_Install,XGMESLogic\\MoldMag\\CMold_Board_Install)
L3CLASS(CMold_Pipe_Par_Use,XGMESLogic\\MoldMag\\CMold_Pipe_Par_Use)
L3CLASS(CMold_Board_Par_Use,XGMESLogic\\MoldMag\\CMold_Board_Par_Use)
L3CLASS(CMold_Mag,XGMESLogic\\MoldMag\\CMold_Mag)
L3CLASS(CMold_Board_Check,XGMESLogic\\MoldMag\\CMold_Board_Check)
END_L3COMP_CLASSTABLE(MoldMag)

BEGIN_L3COMP_EVENTTABLE(MoldMag)
END_L3COMP_EVENTTABLE(MoldMag)
