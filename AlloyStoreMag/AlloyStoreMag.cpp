// AlloyStoreMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "AlloyStoreMag.h"
#include "_CAlloy_Store_Mag.h"
#include "_CAlloy_Data.h"
#include "_CAlloy_Code.h"
#include "_CAlloy_Input_Log.h"
#include "_CAlloy_Output_Log.h"
#include "_CAlloy_Store_Communicator.h"
#include "_CAlloy_Trans_Tel_Data.h"
#include "_CAlloy_App.h"
#include "_CAlloy_Bulk_Relation.h"
#include "_CAlloy_PropChange_Log.h"
#include "_CAlloy_Trans_Log.h"
#include "_CAlloy_Element_Tel_Data.h"
#include "_CStoreOperateLog.h"

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

// CAlloyStoreMagApp

BEGIN_MESSAGE_MAP(CAlloyStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CAlloyStoreMagApp 构造

CAlloyStoreMagApp::CAlloyStoreMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CAlloyStoreMagApp 对象

CAlloyStoreMagApp theApp;


// CAlloyStoreMagApp 初始化

BOOL CAlloyStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(AlloyStoreMag)
L3CLASS(CAlloy_Store_Mag,XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag)
L3CLASS(CAlloy_Data,MES\\MaterialData\\CAlloy_Data)
//L3CLASS(CAlloy_Code,XGMESLogic\\AlloyStoreMag\\CAlloy_Code)
L3CLASS(CAlloy_Input_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Input_Log)
L3CLASS(CAlloy_Output_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Output_Log)
//L3CLASS(CAlloy_Store_Communicator,XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Communicator)
//L3CLASS(CAlloy_Trans_Tel_Data,XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Tel_Data)
//L3CLASS(CAlloy_App,XGMESLogic\\AlloyStoreMag\\CAlloy_App) 2009-04-26
L3CLASS(CAlloy_Bulk_Relation,XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation)
L3CLASS(CAlloy_PropChange_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_PropChange_Log)
L3CLASS(CAlloy_Trans_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Log)
L3CLASS(CAlloy_Element_Tel_Data,XGMESLogic\\AlloyStoreMag\\CAlloy_Element_Tel_Data)
L3CLASS(CStoreOperateLog,XGMESLogic\\AlloyStoreMag\\CStoreOperateLog)
END_L3COMP_CLASSTABLE(AlloyStoreMag)

BEGIN_L3COMP_EVENTTABLE(AlloyStoreMag)
END_L3COMP_EVENTTABLE(AlloyStoreMag)

