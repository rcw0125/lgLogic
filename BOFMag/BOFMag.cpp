// BOFMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "BOFMag.h"
#include "_CBOF_Communicator.h"
#include "_CBOF_Prod_Area.h"
#include "_CBOF_Unit_Mag.h"
#include "_CBOF_Temp_Data.h"
#include "_CBOF_Oxygen_Data.h"
#include "_CBOF_Addition_Data.h"
#include "_CBOF_Process_Status.h"
#include "_CBOF_Bottom_Blowing.h"
#include "_CBOF_Top_Blowing.h"
#include "_CBOF_MainPipe_Data.h"
#include "_CBOF_Base_Data.h"
#include "_CBOF_Feed_Data.h"
#include "_CBOF_Process_Data.h"
#include "_CBOF_Equipment_Status.h"
#include "_CBOF_Proc_Stat_Def.h"
#include "_CBOF_Equip_Stat_Def.h"
#include "_CDuty_Definition.h"
#include "_CBOF_ChangeLanceReason.h"
#include "_CBOF_FenderSlagConsume.h"
#include "_CBOF_HeatRemark.h"
#include "_CBOF_Remark_Type.h"
#include "_CBOF_Stack_Maintenance.h"
#include "_CBOF_ReturnSteel.h"

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

// CBOFMagApp

BEGIN_MESSAGE_MAP(CBOFMagApp, CWinApp)
END_MESSAGE_MAP()


// CBOFMagApp 构造

CBOFMagApp::CBOFMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBOFMagApp 对象

CBOFMagApp theApp;


// CBOFMagApp 初始化

BOOL CBOFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BOFMag)
//L3CLASS(CBOF_Communicator,XGMESLogic\\BOFMag\\CBOF_Communicator)
L3CLASS(CBOF_Prod_Area,XGMESLogic\\BOFMag\\CBOF_Prod_Area)
L3CLASS(CBOF_Unit_Mag,XGMESLogic\\BOFMag\\CBOF_Unit_Mag)
L3CLASS(CBOF_Temp_Data,XGMESLogic\\BOFMag\\CBOF_Temp_Data)
L3CLASS(CBOF_Oxygen_Data,XGMESLogic\\BOFMag\\CBOF_Oxygen_Data)
L3CLASS(CBOF_Addition_Data,XGMESLogic\\BOFMag\\CBOF_Addition_Data)
L3CLASS(CBOF_Process_Status,XGMESLogic\\BOFMag\\CBOF_Process_Status)
L3CLASS(CBOF_Bottom_Blowing,XGMESLogic\\BOFMag\\CBOF_Bottom_Blowing)
L3CLASS(CBOF_Top_Blowing,XGMESLogic\\BOFMag\\CBOF_Top_Blowing)
//L3CLASS(CBOF_MainPipe_Data,XGMESLogic\\BOFMag\\CBOF_MainPipe_Data)
L3CLASS(CBOF_Base_Data,XGMESLogic\\BOFMag\\CBOF_Base_Data)
L3CLASS(CBOF_Feed_Data,XGMESLogic\\BOFMag\\CBOF_Feed_Data)
L3CLASS(CBOF_Process_Data,XGMESLogic\\BOFMag\\CBOF_Process_Data)
L3CLASS(CBOF_Equipment_Status,XGMESLogic\\BOFMag\\CBOF_Equipment_Status)
//L3CLASS(CBOF_Proc_Stat_Def,XGMESLogic\\BOFMag\\CBOF_Proc_Stat_Def)
//L3CLASS(CBOF_Equip_Stat_Def,XGMESLogic\\BOFMag\\CBOF_Equip_Stat_Def)
L3CLASS(CDuty_Definition,XGMESLogic\\BOFMag\\CDuty_Definition)
//L3CLASS(CBOF_ChangeLanceReason,XGMESLogic\\BOFMag\\CBOF_ChangeLanceReason)
//L3CLASS(CBOF_FenderSlagConsume,XGMESLogic\\BOFMag\\CBOF_FenderSlagConsume)
L3CLASS(CBOF_HeatRemark,XGMESLogic\\BOFMag\\CBOF_HeatRemark)
//L3CLASS(CBOF_Remark_Type,XGMESLogic\\BOFMag\\CBOF_Remark_Type)
L3CLASS(CBOF_Stack_Maintenance,XGMESLogic\\BOFMag\\CBOF_Stack_Maintenance)
//L3CLASS(CBOF_ReturnSteel,XGMESLogic\\BOFMag\\CBOF_ReturnSteel)
END_L3COMP_CLASSTABLE(BOFMag)

BEGIN_L3COMP_EVENTTABLE(BOFMag)
END_L3COMP_EVENTTABLE(BOFMag)

