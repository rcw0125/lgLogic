// BloomStoreMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "BloomStoreMag.h"
#include "_CBloom_Store_Mag.h"
#include "_CBloom_Input_Log.h"
#include "_CBloom_Output_Log.h"
#include "_CBloom_Store_Communicator.h"
#include "_CBloom_Tel_Data.h"
#include "_CBloom_Trans_Log.h"

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

// CBloomStoreMagApp

BEGIN_MESSAGE_MAP(CBloomStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CBloomStoreMagApp 构造

CBloomStoreMagApp::CBloomStoreMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBloomStoreMagApp 对象

CBloomStoreMagApp theApp;


// CBloomStoreMagApp 初始化

BOOL CBloomStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BloomStoreMag)
L3CLASS(CBloom_Store_Mag,XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag)
L3CLASS(CBloom_Input_Log,XGMESLogic\\BloomStoreMag\\CBloom_Input_Log)
L3CLASS(CBloom_Output_Log,XGMESLogic\\BloomStoreMag\\CBloom_Output_Log)
//L3CLASS(CBloom_Store_Communicator,XGMESLogic\\BloomStoreMag\\CBloom_Store_Communicator)
//L3CLASS(CBloom_Tel_Data,XGMESLogic\\BloomStoreMag\\CBloom_Tel_Data)
L3CLASS(CBloom_Trans_Log,XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log)
END_L3COMP_CLASSTABLE(BloomStoreMag)

BEGIN_L3COMP_EVENTTABLE(BloomStoreMag)
END_L3COMP_EVENTTABLE(BloomStoreMag)

