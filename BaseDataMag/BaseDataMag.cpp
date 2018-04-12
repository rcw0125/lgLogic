// BaseDataMag.cpp : 定义 DLL 的初始化例程。
//

#include "stdafx.h"
#include "BaseDataMag.h"
#include "_CBaseData_Mag.h"
#include "_CBase_Team_Infor.h"
#include "_CBase_Prod_Center_Infor.h"
#include "_CBase_Stock_Infor.h"
#include "_CBase_Department_Infor.h"
#include "_CBase_Quality_Grade_Infor.h"


#include "MaterialPosition.h"
#include "MaterialType.h"
#include "MaterialMap.h"
#include "ProduceUnitDeviceMap.h"

#include "_CBFIron.h"
#include "_XGInterCache.h"
#include "_XGProduceArea.h"
#include "_XGStoreArea.h"
#include "_CNCCommunicator.h"
#include "_CIron_Data.h"
#include "_CSteel_Data.h"
#include "_CBloom_Data.h"
#include "_CBase_All_Code.h"
#include "_CBase_Material_Class_Infor.h"
#include "_CBase_Material_Base_Infor.h"
#include "_CBase_Cargo_Infor.h"
#include "_CBase_Shift_Infor.h"
#include "_CBase_Check_Item_Infor.h"
#include "_CBase_Check_Std_Infor.h"
#include "_CBase_Defect_Type.h"
#include "_CBase_Excep_Infor.h"
#include "_CBase_Error_Code.h"
#include "_CBase_Address_Bulk_Relation.h"
#include "_CBase_EQMatFac.h"
#include "_CBase_Address_Wire_Relation.h"
#include "_CBase_Operator_ID.h"
#include "_CBase_Steel_Mat_Tel_Data.h"
#include "_CMaterial_Price.h"
#include "_CRetrunData_NC.h"
#include "_CBase_Unit_Original_Data.h"
#include "_CCommunicationStatus.h"
#include "_CBase_Wire_Coefficient.h"
#include "_CCost_Medium_Consume_Std.h"
#include "_CCost_Standard_Rate.h"
#include "_CBase_Unit_Consume.h"
#include "_CBase_Unit_Price.h"
#include "_CSteelBulk_Consume_Rate.h"
#include "_CBase_UserPwd_Lock.h"
#include "_CBase_UserPwd_Lock_Mag.h"

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

// CBaseDataMagApp

BEGIN_MESSAGE_MAP(CBaseDataMagApp, CWinApp)
END_MESSAGE_MAP()


// CBaseDataMagApp 构造

CBaseDataMagApp::CBaseDataMagApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CBaseDataMagApp 对象

CBaseDataMagApp theApp;


// CBaseDataMagApp 初始化

BOOL CBaseDataMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BaseDataMag)
L3CLASS(MaterialPosition,					MES\\MaterialData\\MaterialPosition)	
L3CLASS(MaterialType,						MES\\MaterialData\\MaterialType)
L3CLASS(MaterialMap,						MES\\MaterialData\\MaterialMap)
L3CLASS(CBFIron,							MES\\MaterialData\\CBFIron)
L3CLASS(CIron_Data,							MES\\MaterialData\\CIron_Data)
L3CLASS(CSteel_Data,						MES\\MaterialData\\CSteel_Data)
L3CLASS(CBloom_Data,						MES\\MaterialData\\CBloom_Data)
L3CLASS(ProduceUnitDeviceMap,				MES\\ProduceUnit\\ProduceUnitDeviceMap)


L3CLASS(CBaseData_Mag,XGMESLogic\\BaseDataMag\\CBaseData_Mag)
L3CLASS(CBase_Team_Infor,XGMESLogic\\BaseDataMag\\CBase_Team_Infor)
L3CLASS(CBase_Prod_Center_Infor,XGMESLogic\\BaseDataMag\\CBase_Prod_Center_Infor)
L3CLASS(CBase_Stock_Infor,XGMESLogic\\BaseDataMag\\CBase_Stock_Infor)
L3CLASS(CBase_Department_Infor,XGMESLogic\\BaseDataMag\\CBase_Department_Infor)
L3CLASS(CBase_Quality_Grade_Infor,XGMESLogic\\BaseDataMag\\CBase_Quality_Grade_Infor)

L3CLASS(XGInterCache,XGMESLogic\\BaseDataMag\\XGInterCache)
L3CLASS(XGProduceArea,XGMESLogic\\BaseDataMag\\XGProduceArea)
L3CLASS(XGStoreArea,XGMESLogic\\BaseDataMag\\XGStoreArea)
//L3CLASS(CNCCommunicator,XGMESLogic\\BaseDataMag\\CNCCommunicator)
L3CLASS(CBase_All_Code,XGMESLogic\\BaseDataMag\\CBase_All_Code)
L3CLASS(CBase_Material_Class_Infor,XGMESLogic\\BaseDataMag\\CBase_Material_Class_Infor)
L3CLASS(CBase_Material_Base_Infor,XGMESLogic\\BaseDataMag\\CBase_Material_Base_Infor)
L3CLASS(CBase_Cargo_Infor,XGMESLogic\\BaseDataMag\\CBase_Cargo_Infor)
L3CLASS(CBase_Shift_Infor,XGMESLogic\\BaseDataMag\\CBase_Shift_Infor)
L3CLASS(CBase_Check_Item_Infor,XGMESLogic\\BaseDataMag\\CBase_Check_Item_Infor)
L3CLASS(CBase_Check_Std_Infor,XGMESLogic\\BaseDataMag\\CBase_Check_Std_Infor)
L3CLASS(CBase_Defect_Type,XGMESLogic\\BaseDataMag\\CBase_Defect_Type)
L3CLASS(CBase_Excep_Infor,XGMESLogic\\BaseDataMag\\CBase_Excep_Infor)
L3CLASS(CBase_Error_Code,XGMESLogic\\BaseDataMag\\CBase_Error_Code)
L3CLASS(CBase_Address_Bulk_Relation,XGMESLogic\\BaseDataMag\\CBase_Address_Bulk_Relation)
L3CLASS(CBase_EQMatFac,XGMESLogic\\BaseDataMag\\CBase_EQMatFac)
//L3CLASS(CBase_Address_Wire_Relation,XGMESLogic\\BaseDataMag\\CBase_Address_Wire_Relation)
L3CLASS(CBase_Operator_ID,XGMESLogic\\BaseDataMag\\CBase_Operator_ID)
L3CLASS(CBase_Steel_Mat_Tel_Data,XGMESLogic\\BaseDataMag\\CBase_Steel_Mat_Tel_Data)
L3CLASS(CMaterial_Price,XGMESLogic\\BaseDataMag\\CMaterial_Price)
L3CLASS(CRetrunData_NC,XGMESLogic\\BaseDataMag\\CRetrunData_NC)
//L3CLASS(CBase_Unit_Original_Data,XGMESLogic\\BaseDataMag\\CBase_Unit_Original_Data)
L3CLASS(CCommunicationStatus,XGMESLogic\\BaseDataMag\\CCommunicationStatus)
L3CLASS(CBase_Wire_Coefficient,XGMESLogic\\BaseDataMag\\CBase_Wire_Coefficient)

//2009-08-06
L3CLASS(CCost_Medium_Consume_Std,XGMESLogic\\BaseDataMag\\CCost_Medium_Consume_Std)
L3CLASS(CCost_Standard_Rate,XGMESLogic\\BaseDataMag\\CCost_Standard_Rate)


L3CLASS(CBase_Unit_Consume,XGMESLogic\\BaseDataMag\\CBase_Unit_Consume)
L3CLASS(CBase_Unit_Price,XGMESLogic\\BaseDataMag\\CBase_Unit_Price)
L3CLASS(CSteelBulk_Consume_Rate,XGMESLogic\\BaseDataMag\\CSteelBulk_Consume_Rate)
L3CLASS(CBase_UserPwd_Lock,XGMESLogic\\BaseDataMag\\CBase_UserPwd_Lock)
L3CLASS(CBase_UserPwd_Lock_Mag,XGMESLogic\\BaseDataMag\\CBase_UserPwd_Lock_Mag)
END_L3COMP_CLASSTABLE(BaseDataMag)

BEGIN_L3COMP_EVENTTABLE(BaseDataMag)
END_L3COMP_EVENTTABLE(BaseDataMag)
