// VacTubeMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "VacTubeMag.h"
#include "_CVacTube_Base.h"
#include "_CVacTube_Build.h"
#include "_CVacTube_Hot_Syp_Bui.h"
#include "_CVacTube_Use.h"
#include "_CVacTube_Fire.h"
#include "_CVacTube_Mag.h"
#include "_CVacTube_Repair.h"
#include "_CVacTube_Hot_Syp_Repair.h"
#include "_CVacTube_Fire_Info.h"
#include "_CVacTube_Hot_Syp_Use.h"
#include "_CVacTube_Use_Info.h"

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

// CVacTubeMagApp

BEGIN_MESSAGE_MAP(CVacTubeMagApp, CWinApp)
END_MESSAGE_MAP()


// CVacTubeMagApp 构造

CVacTubeMagApp::CVacTubeMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CVacTubeMagApp 对象

CVacTubeMagApp theApp;


// CVacTubeMagApp 初始化

BOOL CVacTubeMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(VacTubeMag)
L3CLASS(CVacTube_Base,XGMESLogic\\VacTubeMag\\CVacTube_Base)
L3CLASS(CVacTube_Build,XGMESLogic\\VacTubeMag\\CVacTube_Build)
L3CLASS(CVacTube_Hot_Syp_Bui,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Bui)
L3CLASS(CVacTube_Use,XGMESLogic\\VacTubeMag\\CVacTube_Use)
L3CLASS(CVacTube_Fire,XGMESLogic\\VacTubeMag\\CVacTube_Fire)
L3CLASS(CVacTube_Mag,XGMESLogic\\VacTubeMag\\CVacTube_Mag)
L3CLASS(CVacTube_Repair,XGMESLogic\\VacTubeMag\\CVacTube_Repair)
L3CLASS(CVacTube_Hot_Syp_Repair,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Repair)
L3CLASS(CVacTube_Fire_Info,XGMESLogic\\VacTubeMag\\CVacTube_Fire_Info)
L3CLASS(CVacTube_Hot_Syp_Use,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Use)
L3CLASS(CVacTube_Use_Info,XGMESLogic\\VacTubeMag\\CVacTube_Use_Info)
END_L3COMP_CLASSTABLE(VacTubeMag)

BEGIN_L3COMP_EVENTTABLE(VacTubeMag)
END_L3COMP_EVENTTABLE(VacTubeMag)

