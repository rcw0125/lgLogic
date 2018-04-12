// BulkStoreMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "BulkStoreMag.h"
#include "_CBulk_Store_Mag.h"
#include "_CBulk_Data.h"
#include "_CBulk_Code.h"
#include "_CBulk_Input_Log.h"
#include "_CBulk_Output_Log.h"
#include "_CBulk_Purchase_Tel_Data.h"
#include "_CBulk_App.h"
#include "_CBulk_Store_Communicator.h"
#include "_CBulk_Bulk_Relation.h"
#include "_CBulk_PropChange_Log.h"
#include "_CBulk_Trans_Log.h"
#include "_CBulk_Trans_Tel_Data.h"

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

// CBulkStoreMagApp

BEGIN_MESSAGE_MAP(CBulkStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CBulkStoreMagApp 构造

CBulkStoreMagApp::CBulkStoreMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBulkStoreMagApp 对象

CBulkStoreMagApp theApp;


// CBulkStoreMagApp 初始化

BOOL CBulkStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BulkStoreMag)
L3CLASS(CBulk_Store_Mag,XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag)
L3CLASS(CBulk_Data,MES\\MaterialData\\CBulk_Data)
//L3CLASS(CBulk_Code,XGMESLogic\\BulkStoreMag\\CBulk_Code)
L3CLASS(CBulk_Input_Log,XGMESLogic\\BulkStoreMag\\CBulk_Input_Log)
L3CLASS(CBulk_Output_Log,XGMESLogic\\BulkStoreMag\\CBulk_Output_Log)
//L3CLASS(CBulk_Purchase_Tel_Data,XGMESLogic\\BulkStoreMag\\CBulk_Purchase_Tel_Data)
//L3CLASS(CBulk_App,XGMESLogic\\BulkStoreMag\\CBulk_App)
//L3CLASS(CBulk_Store_Communicator,XGMESLogic\\BulkStoreMag\\CBulk_Store_Communicator)
L3CLASS(CBulk_Bulk_Relation,XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation)
L3CLASS(CBulk_PropChange_Log,XGMESLogic\\BulkStoreMag\\CBulk_PropChange_Log)
L3CLASS(CBulk_Trans_Log,XGMESLogic\\BulkStoreMag\\CBulk_Trans_Log)
//L3CLASS(CBulk_Trans_Tel_Data,XGMESLogic\\BulkStoreMag\\CBulk_Trans_Tel_Data)
END_L3COMP_CLASSTABLE(BulkStoreMag)

BEGIN_L3COMP_EVENTTABLE(BulkStoreMag)
END_L3COMP_EVENTTABLE(BulkStoreMag)

