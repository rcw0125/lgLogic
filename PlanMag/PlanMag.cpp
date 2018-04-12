// PlanMag.cpp : ���� DLL �ĳ�ʼ�����̡�
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

// CPlanMagApp

BEGIN_MESSAGE_MAP(CPlanMagApp, CWinApp)
END_MESSAGE_MAP()


// CPlanMagApp ����

CPlanMagApp::CPlanMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CPlanMagApp ����

CPlanMagApp theApp;


// CPlanMagApp ��ʼ��

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

