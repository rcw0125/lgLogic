// MIXFMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "MIXFMag.h"
#include "_CMIF_Communicator.h"
#include "_CMIF_Temp_Data.h"
#include "_CMIF_Weight.h"
#include "_CMIF_Chemical.h"
#include "_CMIF_Mag.h"
#include "_CMIF_Unit_Mag.h"
#include "_CMIF_Feed_Log.h"

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

// CMIXFMagApp

BEGIN_MESSAGE_MAP(CMIXFMagApp, CWinApp)
END_MESSAGE_MAP()


// CMIXFMagApp 构造

CMIXFMagApp::CMIXFMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CMIXFMagApp 对象

CMIXFMagApp theApp;


// CMIXFMagApp 初始化

BOOL CMIXFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(MIXFMag)
//L3CLASS(CMIF_Communicator,XGMESLogic\\MIXFMag\\CMIF_Communicator)  2009-04-26
L3CLASS(CMIF_Temp_Data,XGMESLogic\\MIXFMag\\CMIF_Temp_Data)
L3CLASS(CMIF_Weight,XGMESLogic\\MIXFMag\\CMIF_Weight)
//L3CLASS(CMIF_Chemical,XGMESLogic\\MIXFMag\\CMIF_Chemical) 2009-04-26
L3CLASS(CMIF_Mag,XGMESLogic\\MIXFMag\\CMIF_Mag)
L3CLASS(CMIF_Unit_Mag,XGMESLogic\\MIXFMag\\CMIF_Unit_Mag)
L3CLASS(CMIF_Feed_Log,XGMESLogic\\MIXFMag\\CMIF_Feed_Log)
END_L3COMP_CLASSTABLE(MIXFMag)

BEGIN_L3COMP_EVENTTABLE(MIXFMag)
END_L3COMP_EVENTTABLE(MIXFMag)

