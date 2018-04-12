// ScrapStoreMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "ScrapStoreMag.h"
#include "_CScrap_Store_Mag.h"
#include "_CScrap_Store_Communicator.h"
#include "_CScrap_Data.h"
#include "_CSrap_Code.h"
#include "_CScrap_Input_Log.h"
#include "_CScrap_Output_Log.h"
#include "_CScrap_Trans_Tel_Data.h"
#include "_CScrap_PropChange_Log.h"
#include "_CScrap_Purchase_Tel_Data.h"
#include "_CScrapOutStoreDetail.h"

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

// CScrapStoreMagApp

BEGIN_MESSAGE_MAP(CScrapStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CScrapStoreMagApp 构造

CScrapStoreMagApp::CScrapStoreMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CScrapStoreMagApp 对象

CScrapStoreMagApp theApp;


// CScrapStoreMagApp 初始化

BOOL CScrapStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(ScrapStoreMag)
L3CLASS(CScrap_Store_Mag,XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag)
//L3CLASS(CScrap_Store_Communicator,XGMESLogic\\ScrapStoreMag\\CScrap_Store_Communicator)
L3CLASS(CScrap_Data,MES\\MaterialData\\CScrap_Data)
//L3CLASS(CSrap_Code,XGMESLogic\\ScrapStoreMag\\CSrap_Code)
L3CLASS(CScrap_Input_Log,XGMESLogic\\ScrapStoreMag\\CScrap_Input_Log)
L3CLASS(CScrap_Output_Log,XGMESLogic\\ScrapStoreMag\\CScrap_Output_Log)
//L3CLASS(CScrap_Trans_Tel_Data,XGMESLogic\\ScrapStoreMag\\CScrap_Trans_Tel_Data)
L3CLASS(CScrap_PropChange_Log,XGMESLogic\\ScrapStoreMag\\CScrap_PropChange_Log)
//L3CLASS(CScrap_Purchase_Tel_Data,XGMESLogic\\ScrapStoreMag\\CScrap_Purchase_Tel_Data)
L3CLASS(CScrapOutStoreDetail,XGMESLogic\\ScrapStoreMag\\CScrapOutStoreDetail)
END_L3COMP_CLASSTABLE(ScrapStoreMag)

BEGIN_L3COMP_EVENTTABLE(ScrapStoreMag)
END_L3COMP_EVENTTABLE(ScrapStoreMag)

