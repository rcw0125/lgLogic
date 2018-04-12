// 这是主 DLL 文件。

#include "stdafx.h"

#include "DePMag1.h"


// 这是主 DLL 文件。

//#include "stdafx.h"
//
//#include "DePMag1.h"



// DeSMag.cpp : 定义 DLL 的初始化例程。
//

//#include "stdafx.h"
//#include "DePMag1.h"
#include "_CDEP_Unit_Mag.h"
#include "_CDEP_Prod_Area.h"
#include "_CDEP_Base_Data.h"
#include "_CDEP_Process_Data.h"
#include "_CDEP_Runtime_Data.h"
#include "_CDEP_Process_Status.h"
#include "_CDEP_Equipment_Status.h"
#include "_CDEP_Addition_Data.h"


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

BEGIN_MESSAGE_MAP(CDePMag1App, CWinApp)
END_MESSAGE_MAP()


// CDeSMagApp 构造

CDePMag1App::CDePMag1App()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CDeSMagApp 对象

CDePMag1App theApp;


// CDeSMagApp 初始化

BOOL CDePMag1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DePMag1)
L3CLASS(CDEP_Unit_Mag,XGMESLogic\\DePMag1\\CDEP_Unit_Mag)
L3CLASS(CDEP_Prod_Area,XGMESLogic\\DePMag1\\CDEP_Prod_Area)
L3CLASS(CDEP_Base_Data,XGMESLogic\\DePMag1\\CDEP_Base_Data)
L3CLASS(CDEP_Process_Data,XGMESLogic\\DePMag1\\CDEP_Process_Data)
L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag1\\CDEP_Runtime_Data)
L3CLASS(CDEP_Process_Status,XGMESLogic\\DePMag1\\CDEP_Process_Status)
L3CLASS(CDEP_Equipment_Status,XGMESLogic\\DePMag1\\CDEP_Equipment_Status)
L3CLASS(CDEP_Addition_Data,XGMESLogic\\DePMag1\\CDEP_Addition_Data)
END_L3COMP_CLASSTABLE(DePMag1)

BEGIN_L3COMP_EVENTTABLE(DePMag1)
END_L3COMP_EVENTTABLE(DePMag1)

