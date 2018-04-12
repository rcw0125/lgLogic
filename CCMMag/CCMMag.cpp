// CCMMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "CCMMag.h"
#include "_CCCM_Casting_Data.h"
#include "_CCCM_Tundish_Data.h"
#include "_CCCM_Process_Data.h"
#include "_CCCM_Heat_Ladle.h"
#include "_CCCM_Heat_Cover.h"
#include "_CCCM_Heat_HoldTempMat.h"
#include "_CCCM_Heat_ProtectCasting.h"
#include "_CCCM_Heat_ProtectMat.h"
#include "_CCCM_Heat_Mold.h"
#include "_CCCM_Heat_ElecStirring.h"
#include "_CCCM_Heat_Cooling.h"
#include "_CCCM_Heat_ProtectSlag.h"
#include "_CCCM_Heat_TundishTemp.h"
#include "_CCCM_Heat_Speed.h"
#include "_CCCM_Heat_StrandInfo.h"
#include "_CCCM_Process_Status.h"
#include "_CCCM_Equipment_Status.h"
#include "_CCCM_Heat_Remark.h"
#include "_CCCM_Heat_Waster.h"
#include "_CCCM_Heat_FaultyGoods.h"
#include "_CCCM_WaterGap.h"
#include "_CCCM_SmoothBlock.h"
#include "_CCCM_Unit_Mag.h"
#include "_CCCM_Communicator.h"
#include "_CCCM_Casting_StrandInfo.h"
#include "_CCCM_Tundish_StrandInfo.h"
#include "_CCCM_Base_Data.h"
#include "_CCCM_Runtime_Data.h"
#include "_CCCM_Temp_Curve.h"
#include "_CCCM_Speed_Curve.h"
#include "_CCCM_PlugBar_Curve.h"
#include "_CCCM_Mold_Height_Curve.h"
#include "_CCCM_Mold_InTemp_Curve.h"
#include "_CCCM_Mold_OutTemp_Curve.h"
#include "_CCCM_Prod_Area.h"
#include "_CCCM_Duty.h"
#include "_CCCM_Tundish_Fire_Data.h"
#include "_CCCM_BigWaterGap.h"
#include "_CCCM_StrandInfo.h"
#include "_CCCM5_Runtime_Data.h"
#include "_CCCM5_Runtime1_Data.h"
#include "_CCCM5_Runtime2_Data.h"
#include "_CCCM_TundishTemp_TwoMinute.h"


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

// CCCMMagApp

BEGIN_MESSAGE_MAP(CCCMMagApp, CWinApp)
END_MESSAGE_MAP()


// CCCMMagApp ����

CCCMMagApp::CCCMMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCCMMagApp ����

CCCMMagApp theApp;


// CCCMMagApp ��ʼ��

BOOL CCCMMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(CCMMag)
//2009-02-13 �������±�
L3CLASS(CCCM_Casting_Data,XGMESLogic\\CCMMag\\CCCM_Casting_Data)
L3CLASS(CCCM_Tundish_Data,XGMESLogic\\CCMMag\\CCCM_Tundish_Data)
L3CLASS(CCCM_Process_Data,XGMESLogic\\CCMMag\\CCCM_Process_Data)
L3CLASS(CCCM_Heat_Ladle,XGMESLogic\\CCMMag\\CCCM_Heat_Ladle)
L3CLASS(CCCM_Heat_Cover,XGMESLogic\\CCMMag\\CCCM_Heat_Cover)
L3CLASS(CCCM_Heat_HoldTempMat,XGMESLogic\\CCMMag\\CCCM_Heat_HoldTempMat)
L3CLASS(CCCM_Heat_ProtectCasting,XGMESLogic\\CCMMag\\CCCM_Heat_ProtectCasting)
L3CLASS(CCCM_Heat_ProtectMat,XGMESLogic\\CCMMag\\CCCM_Heat_ProtectMat)
//L3CLASS(CCCM_Heat_Mold,XGMESLogic\\CCMMag\\CCCM_Heat_Mold)
//L3CLASS(CCCM_Heat_ElecStirring,XGMESLogic\\CCMMag\\CCCM_Heat_ElecStirring)
//L3CLASS(CCCM_Heat_Cooling,XGMESLogic\\CCMMag\\CCCM_Heat_Cooling)
L3CLASS(CCCM_Heat_ProtectSlag,XGMESLogic\\CCMMag\\CCCM_Heat_ProtectSlag)
L3CLASS(CCCM_Heat_TundishTemp,XGMESLogic\\CCMMag\\CCCM_Heat_TundishTemp)
L3CLASS(CCCM_Heat_Speed,XGMESLogic\\CCMMag\\CCCM_Heat_Speed)
L3CLASS(CCCM_Heat_StrandInfo,XGMESLogic\\CCMMag\\CCCM_Heat_StrandInfo)
L3CLASS(CCCM_Process_Status,XGMESLogic\\CCMMag\\CCCM_Process_Status)
L3CLASS(CCCM_Equipment_Status,XGMESLogic\\CCMMag\\CCCM_Equipment_Status)
L3CLASS(CCCM_Heat_Remark,XGMESLogic\\CCMMag\\CCCM_Heat_Remark)
//L3CLASS(CCCM_Heat_Waster,XGMESLogic\\CCMMag\\CCCM_Heat_Waster)
//L3CLASS(CCCM_Heat_FaultyGoods,XGMESLogic\\CCMMag\\CCCM_Heat_FaultyGoods)
L3CLASS(CCCM_WaterGap,XGMESLogic\\CCMMag\\CCCM_WaterGap)
L3CLASS(CCCM_SmoothBlock,XGMESLogic\\CCMMag\\CCCM_SmoothBlock)
L3CLASS(CCCM_Unit_Mag,XGMESLogic\\CCMMag\\CCCM_Unit_Mag)
//L3CLASS(CCCM_Communicator,XGMESLogic\\CCMMag\\CCCM_Communicator)
//L3CLASS(CCCM_Casting_StrandInfo,XGMESLogic\\CCMMag\\CCCM_Casting_StrandInfo)
//L3CLASS(CCCM_Tundish_StrandInfo,XGMESLogic\\CCMMag\\CCCM_Tundish_StrandInfo)
L3CLASS(CCCM_Base_Data,XGMESLogic\\CCMMag\\CCCM_Base_Data)
L3CLASS(CCCM_Runtime_Data,XGMESLogic\\CCMMag\\CCCM_Runtime_Data)
//L3CLASS(CCCM_Temp_Curve,XGMESLogic\\CCMMag\\CCCM_Temp_Curve)
//L3CLASS(CCCM_Speed_Curve,XGMESLogic\\CCMMag\\CCCM_Speed_Curve)
//L3CLASS(CCCM_PlugBar_Curve,XGMESLogic\\CCMMag\\CCCM_PlugBar_Curve)
//L3CLASS(CCCM_Mold_Height_Curve,XGMESLogic\\CCMMag\\CCCM_Mold_Height_Curve)
//L3CLASS(CCCM_Mold_InTemp_Curve,XGMESLogic\\CCMMag\\CCCM_Mold_InTemp_Curve)
//L3CLASS(CCCM_Mold_OutTemp_Curve,XGMESLogic\\CCMMag\\CCCM_Mold_OutTemp_Curve)
L3CLASS(CCCM_Prod_Area,XGMESLogic\\CCMMag\\CCCM_Prod_Area)
L3CLASS(CCCM_Duty,XGMESLogic\\CCMMag\\CCCM_Duty)
L3CLASS(CCCM_Tundish_Fire_Data,XGMESLogic\\CCMMag\\CCCM_Tundish_Fire_Data)
L3CLASS(CCCM_BigWaterGap,XGMESLogic\\CCMMag\\CCCM_BigWaterGap)
L3CLASS(CCCM_StrandInfo,XGMESLogic\\CCMMag\\CCCM_StrandInfo)
//L3CLASS(CCCM5_Runtime_Data,XGMESLogic\\CCMMag\\CCCM5_Runtime_Data)
L3CLASS(CCCM5_Runtime1_Data,XGMESLogic\\CCMMag\\CCCM5_Runtime1_Data)
L3CLASS(CCCM5_Runtime2_Data,XGMESLogic\\CCMMag\\CCCM5_Runtime2_Data)
L3CLASS(CCCM_TundishTemp_TwoMinute,XGMESLogic\\CCMMag\\CCCM_TundishTemp_TwoMinute)
END_L3COMP_CLASSTABLE(CCMMag)

BEGIN_L3COMP_EVENTTABLE(CCMMag)
END_L3COMP_EVENTTABLE(CCMMag)

