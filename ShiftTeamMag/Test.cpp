// Test.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "Test.h"
//#include "_CCurrentShiftInfo.h"
//
//#include "_CShiftTeamOrder.h"
//#include "_CUnitOperator.h"
//#include "_CUnitTimeInfo.h"
#include "_CDEP_Unit_Mag.h"
#include "_CDEP_Prod_Area.h"
#include "_CDEP_Base_Data.h"
#include "_CDEP_Process_Data.h"
#include "_CDEP_Runtime_Data.h"
#include "_CDEP_Process_Status.h"
#include "_CDEP_Equipment_Status.h"
#include "_CDEP_Addition_Data.h"
#include "_CDEP_Duty.h"
#include "_CDEP_Feed_Data.h"
#include "_CDEP_HeatRemark.h"
#include "_CDEP_Temp_Data.h"
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

// CShiftTeamMagApp

BEGIN_MESSAGE_MAP(CTestApp, CWinApp)
END_MESSAGE_MAP()


// CShiftTeamMagApp ����

CTestApp::CTestApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CShiftTeamMagApp ����

CTestApp theApp;


// CShiftTeamMagApp ��ʼ��

BOOL CTestApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DePMag)
//L3CLASS(CCurrentShiftInfo,XGMESLogic\\Test\\CCurrentShiftInfo)
//L3CLASS(CShiftMag,XGMESLogic\\Test\\CShiftMag)
//L3CLASS(CShiftTeamOrder,XGMESLogic\\Test\\CShiftTeamOrder)
////L3CLASS(CUnitOperator,XGMESLogic\\Test\\CUnitOperator) 2009-04-26
//L3CLASS(CUnitTimeInfo,XGMESLogic\\Test\\CUnitTimeInfo)
L3CLASS(CDEP_Unit_Mag,XGMESLogic\\DePMag\\CDEP_Unit_Mag)
L3CLASS(CDEP_Prod_Area,XGMESLogic\\DePMag\\CDEP_Prod_Area)
L3CLASS(CDEP_Base_Data,XGMESLogic\\DePMag\\CDEP_Base_Data)
L3CLASS(CDEP_Process_Data,XGMESLogic\\DePMag\\CDEP_Process_Data)
L3CLASS(CDEP_Process_Status,XGMESLogic\\DePMag\\CDEP_Process_Status)
//L3CLASS(CDEP_Equipment_Status,XGMESLogic\\DePMag\\CDEP_Equipment_Status)
L3CLASS(CDEP_Addition_Data,XGMESLogic\\DePMag\\CDEP_Addition_Data)
//L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag\\CDEP_Runtime_Data)
//L3CLASS(CDEP_Duty,XGMESLogic\\DePMag\\CDEP_Duty)
L3CLASS(CDEP_Feed_Data,XGMESLogic\\DePMag\\CDEP_Feed_Data)
L3CLASS(CDEP_HeatRemark,XGMESLogic\\DePMag\\CDEP_HeatRemark)
L3CLASS(CDEP_Temp_Data,XGMESLogic\\DePMag\\CDEP_Temp_Data)
END_L3COMP_CLASSTABLE(DePMag)

BEGIN_L3COMP_EVENTTABLE(DePMag)
END_L3COMP_EVENTTABLE(DePMag)

