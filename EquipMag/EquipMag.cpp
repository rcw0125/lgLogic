// EquipMag.cpp : ���� DLL �ĳ�ʼ�����̡�
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
//	ע�⣡
//
//		����� DLL ��̬���ӵ� MFC
//		DLL���Ӵ� DLL ������
//		���� MFC ���κκ����ں�������ǰ��
//		��������� AFX_MANAGE_STATE �ꡣ
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT AccessedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�

//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CEquipMagApp

BEGIN_MESSAGE_MAP(CEquipMagApp, CWinApp)
END_MESSAGE_MAP()


// CEquipMagApp ����

CEquipMagApp::CEquipMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CEquipMagApp ����

CEquipMagApp theApp;


// CEquipMagApp ��ʼ��

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

