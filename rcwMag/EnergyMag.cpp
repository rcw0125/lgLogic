// EnergyMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "EnergyMag.h"
#include "_CEnergyRunTimeData.h"
#include "_CEnergyHistoryData.h"
#include "_CEnergy_Unit_Mag.h"
#include "_CEnergyConsumption.h"
#include "_CEnergy_Manual_Data.h"
#include "_CLF_Temp_Control.h"

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

// CEnergyMagApp

BEGIN_MESSAGE_MAP(CEnergyMagApp, CWinApp)
END_MESSAGE_MAP()


// CEnergyMagApp 构造

CEnergyMagApp::CEnergyMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CEnergyMagApp 对象

CEnergyMagApp theApp;


// CEnergyMagApp 初始化

BOOL CEnergyMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(EnergyMag)
L3CLASS(CEnergyRunTimeData,XGMESLogic\\EnergyMag\\CEnergyRunTimeData)
L3CLASS(CEnergyHistoryData,XGMESLogic\\EnergyMag\\CEnergyHistoryData)
L3CLASS(CEnergy_Unit_Mag,XGMESLogic\\EnergyMag\\CEnergy_Unit_Mag)
L3CLASS(CEnergyConsumption,XGMESLogic\\EnergyMag\\CEnergyConsumption)
L3CLASS(CEnergy_Manual_Data,XGMESLogic\\EnergyMag\\CEnergy_Manual_Data)
L3CLASS(CLF_Temp_Control,XGMESLogic\\EnergyMag\\CLF_Temp_Control)
END_L3COMP_CLASSTABLE(EnergyMag)

BEGIN_L3COMP_EVENTTABLE(EnergyMag)
END_L3COMP_EVENTTABLE(EnergyMag)

