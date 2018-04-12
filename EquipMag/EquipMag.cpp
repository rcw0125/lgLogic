// EquipMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "EquipMag.h"
#include "_CCalibration_Set.h"
#include "_CCalibration_Log.h"
#include "_CCalibration_Detail.h"
#include "_CEquip_Unit_Mag.h"
#include "_CEupip_Adjust_Std.h"
#include "_CEquip_Level_Log.h"
#include "_CEquip_Coil_Log.h"
#include "_CEquip_Oscillate_Log.h"
#include "_CEquip_Mold_Arc_Log.h"
#include "_CEquip_Sect_Arc_Log.h"
#include "_CEquip_Roller_Log.h"
#include "_CEquip_Pole_Log.h"
#include "_CEquip_Collet_Log.h"
#include "_CEquip_Lance_Log.h"
#include "_CEquip_Runtime_Data.h"
#include "_CEquip_SupplyWater_Data.h"
#include "_CEquip_Cleaning_Data.h"
#include "_CEquip_Cooling_Log.h"

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

// CEquipMagApp

BEGIN_MESSAGE_MAP(CEquipMagApp, CWinApp)
END_MESSAGE_MAP()


// CEquipMagApp 构造

CEquipMagApp::CEquipMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CEquipMagApp 对象

CEquipMagApp theApp;


// CEquipMagApp 初始化

BOOL CEquipMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(EquipMag)
L3CLASS(CCalibration_Set,XGMESLogic\\EquipMag\\CCalibration_Set)
L3CLASS(CCalibration_Log,XGMESLogic\\EquipMag\\CCalibration_Log)
L3CLASS(CCalibration_Detail,XGMESLogic\\EquipMag\\CCalibration_Detail)
L3CLASS(CEquip_Unit_Mag,XGMESLogic\\EquipMag\\CEquip_Unit_Mag)
L3CLASS(CEupip_Adjust_Std,XGMESLogic\\EquipMag\\CEupip_Adjust_Std)
L3CLASS(CEquip_Level_Log,XGMESLogic\\EquipMag\\CEquip_Level_Log)
L3CLASS(CEquip_Coil_Log,XGMESLogic\\EquipMag\\CEquip_Coil_Log)
L3CLASS(CEquip_Oscillate_Log,XGMESLogic\\EquipMag\\CEquip_Oscillate_Log)
L3CLASS(CEquip_Mold_Arc_Log,XGMESLogic\\EquipMag\\CEquip_Mold_Arc_Log)
L3CLASS(CEquip_Sect_Arc_Log,XGMESLogic\\EquipMag\\CEquip_Sect_Arc_Log)
L3CLASS(CEquip_Roller_Log,XGMESLogic\\EquipMag\\CEquip_Roller_Log)
L3CLASS(CEquip_Pole_Log,XGMESLogic\\EquipMag\\CEquip_Pole_Log)
L3CLASS(CEquip_Collet_Log,XGMESLogic\\EquipMag\\CEquip_Collet_Log)
L3CLASS(CEquip_Lance_Log,XGMESLogic\\EquipMag\\CEquip_Lance_Log)
L3CLASS(CEquip_Runtime_Data,XGMESLogic\\EquipMag\\CEquip_Runtime_Data)
L3CLASS(CEquip_SupplyWater_Data,XGMESLogic\\EquipMag\\CEquip_SupplyWater_Data)
L3CLASS(CEquip_Cleaning_Data,XGMESLogic\\EquipMag\\CEquip_Cleaning_Data)
L3CLASS(CEquip_Cooling_Log,XGMESLogic\\EquipMag\\CEquip_Cooling_Log)
END_L3COMP_CLASSTABLE(EquipMag)

BEGIN_L3COMP_EVENTTABLE(EquipMag)
END_L3COMP_EVENTTABLE(EquipMag)

