// PlanMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "PlanMag.h"
#include "_CPlan_Casting.h"
#include "_CPlan_Order.h"
#include "_CPlan_Tapping.h"
#include "_CPlan_Tapping_Act.h"
#include "_CPlan_Mag.h"
#include "_CPlan_Cur_PreLotNo.h"
#include "_CPlan_Cur_PreHeatID.h"
#include "_CPlan_Communicator.h"
#include "_CSteel_To_Steel_Map.h"
#include "_CPlan_BOF_Status.h"
#include "_CPlan_BOFNon_Proc_Time.h"
#include "_CPlan_Equipment.h"
#include "_CPlan_Order_Tel_Data.h"

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

// CPlanMagApp

BEGIN_MESSAGE_MAP(CPlanMagApp, CWinApp)
END_MESSAGE_MAP()


// CPlanMagApp 构造

CPlanMagApp::CPlanMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CPlanMagApp 对象

CPlanMagApp theApp;


// CPlanMagApp 初始化

BOOL CPlanMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(PlanMag)
L3CLASS(CPlan_Casting,XGMESLogic\\PlanMag\\CPlan_Casting)
L3CLASS(CPlan_Order,XGMESLogic\\PlanMag\\CPlan_Order)
L3CLASS(CPlan_Tapping,XGMESLogic\\PlanMag\\CPlan_Tapping)
L3CLASS(CPlan_Tapping_Act,XGMESLogic\\PlanMag\\CPlan_Tapping_Act)
L3CLASS(CPlan_Mag,XGMESLogic\\PlanMag\\CPlan_Mag)
//L3CLASS(CPlan_Cur_PreLotNo,XGMESLogic\\PlanMag\\CPlan_Cur_PreLotNo)  2009-04-26
L3CLASS(CPlan_Cur_PreHeatID,XGMESLogic\\PlanMag\\CPlan_Cur_PreHeatID)
//L3CLASS(CPlan_Communicator,XGMESLogic\\PlanMag\\CPlan_Communicator)
//L3CLASS(CSteel_To_Steel_Map,XGMESLogic\\PlanMag\\CSteel_To_Steel_Map)
//L3CLASS(CPlan_BOF_Status,XGMESLogic\\PlanMag\\CPlan_BOF_Status)
//L3CLASS(CPlan_BOFNon_Proc_Time,XGMESLogic\\PlanMag\\CPlan_BOFNon_Proc_Time) 2009-04-26
//L3CLASS(CPlan_Equipment,XGMESLogic\\PlanMag\\CPlan_Equipment) 2009-04-26
L3CLASS(CPlan_Order_Tel_Data,XGMESLogic\\PlanMag\\CPlan_Order_Tel_Data)
END_L3COMP_CLASSTABLE(PlanMag)

BEGIN_L3COMP_EVENTTABLE(PlanMag)
END_L3COMP_EVENTTABLE(PlanMag)

