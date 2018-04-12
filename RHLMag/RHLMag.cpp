// ������ DLL �ļ���

//#include "stdafx.h"
//
//#include "RHLMag.h"



// RHLMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "RHLMag.h"
#include "_CRHL_Unit_Mag.h"
#include "_CRHL_Process_Status.h"
#include "_CRHL_Equipment_Status.h"
#include "_CRHL_Process_Data.h"

#include "_CRHL_Temp_Data.h"
#include "_CRHL_Addition_Data.h"
#include "_CRHL_HeatRemark.h"


#include "_CRHL_Base_Data.h"
#include "_CRHL_Prod_Area.h"
//#include "_CRHL_Heat_Gears.h"
//#include "_CRHL_BlowAr_Data.h"
//#include "_CRHL_Ladle_Info.h"

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

// CRHLMagApp

BEGIN_MESSAGE_MAP(CRHLMagApp, CWinApp)
END_MESSAGE_MAP()


// CRHLMagApp ����

CRHLMagApp::CRHLMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CRHLMagApp ����

CRHLMagApp theApp;


// CRHLMagApp ��ʼ��

BOOL CRHLMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(RHLMag)
//L3CLASS(CRHL_Communicator,XGMESLogic\\RHLMag\\CRHL_Communicator)
L3CLASS(CRHL_Unit_Mag,XGMESLogic\\RHLMag\\CRHL_Unit_Mag)
L3CLASS(CRHL_Process_Status,XGMESLogic\\RHLMag\\CRHL_Process_Status)
L3CLASS(CRHL_Equipment_Status,XGMESLogic\\RHLMag\\CRHL_Equipment_Status)
L3CLASS(CRHL_Process_Data,XGMESLogic\\RHLMag\\CRHL_Process_Data)
//L3CLASS(CRHL_Oxygen_Data,XGMESLogic\\RHLMag\\CRHL_Oxygen_Data)
L3CLASS(CRHL_Temp_Data,XGMESLogic\\RHLMag\\CRHL_Temp_Data)
L3CLASS(CRHL_Addition_Data,XGMESLogic\\RHLMag\\CRHL_Addition_Data)
L3CLASS(CRHL_HeatRemark,XGMESLogic\\RHLMag\\CRHL_HeatRemark)
//L3CLASS(CRHL_Wire_Data,XGMESLogic\\RHLMag\\CRHL_Wire_Data)
//L3CLASS(CRHL_Ladle_Data,XGMESLogic\\RHLMag\\CRHL_Ladle_Data)
//L3CLASS(CRHL_Ladle_Weight,XGMESLogic\\RHLMag\\CRHL_Ladle_Weight)
L3CLASS(CRHL_Base_Data,XGMESLogic\\RHLMag\\CRHL_Base_Data)
L3CLASS(CRHL_Prod_Area,XGMESLogic\\RHLMag\\CRHL_Prod_Area)
//L3CLASS(CRHL_Heat_Gears,XGMESLogic\\RHLMag\\CRHL_Heat_Gears)
//L3CLASS(CRHL_BlowAr_Data,XGMESLogic\\RHLMag\\CRHL_BlowAr_Data)
//L3CLASS(CRHL_Ladle_Info,XGMESLogic\\RHLMag\\CRHL_Ladle_Info)
END_L3COMP_CLASSTABLE(RHLMag)

BEGIN_L3COMP_EVENTTABLE(RHLMag)
END_L3COMP_EVENTTABLE(RHLMag)

