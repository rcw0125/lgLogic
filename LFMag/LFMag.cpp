// LFMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "LFMag.h"
#include "_CLF_Communicator.h"
#include "_CLF_Unit_Mag.h"
#include "_CLF_Process_Satus.h"
#include "_CLF_Equipment_Status.h"
#include "_CLF_Process_Data.h"
#include "_CLF_Oxygen_Data.h"
#include "_CLF_Temp_Data.h"
#include "_CLF_Addition_Data.h"
#include "_CLF_HeatRemark.h"
#include "_CLF_Wire_Data.h"
#include "_CLF_Ladle_Data.h"
#include "_CLF_Ladle_Weight.h"
#include "_CLF_Base_Data.h"
#include "_CLF_Prod_Area.h"
#include "_CLF_Heat_Gears.h"
#include "_CLF_BlowAr_Data.h"
#include "_CLF_Ladle_Info.h"

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

// CLFMagApp

BEGIN_MESSAGE_MAP(CLFMagApp, CWinApp)
END_MESSAGE_MAP()


// CLFMagApp ����

CLFMagApp::CLFMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLFMagApp ����

CLFMagApp theApp;


// CLFMagApp ��ʼ��

BOOL CLFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LFMag)
//L3CLASS(CLF_Communicator,XGMESLogic\\LFMag\\CLF_Communicator)
L3CLASS(CLF_Unit_Mag,XGMESLogic\\LFMag\\CLF_Unit_Mag)
L3CLASS(CLF_Process_Satus,XGMESLogic\\LFMag\\CLF_Process_Satus)
L3CLASS(CLF_Equipment_Status,XGMESLogic\\LFMag\\CLF_Equipment_Status)
L3CLASS(CLF_Process_Data,XGMESLogic\\LFMag\\CLF_Process_Data)
L3CLASS(CLF_Oxygen_Data,XGMESLogic\\LFMag\\CLF_Oxygen_Data)
L3CLASS(CLF_Temp_Data,XGMESLogic\\LFMag\\CLF_Temp_Data)
L3CLASS(CLF_Addition_Data,XGMESLogic\\LFMag\\CLF_Addition_Data)
L3CLASS(CLF_HeatRemark,XGMESLogic\\LFMag\\CLF_HeatRemark)
L3CLASS(CLF_Wire_Data,XGMESLogic\\LFMag\\CLF_Wire_Data)
//L3CLASS(CLF_Ladle_Data,XGMESLogic\\LFMag\\CLF_Ladle_Data)
L3CLASS(CLF_Ladle_Weight,XGMESLogic\\LFMag\\CLF_Ladle_Weight)
L3CLASS(CLF_Base_Data,XGMESLogic\\LFMag\\CLF_Base_Data)
L3CLASS(CLF_Prod_Area,XGMESLogic\\LFMag\\CLF_Prod_Area)
L3CLASS(CLF_Heat_Gears,XGMESLogic\\LFMag\\CLF_Heat_Gears)
L3CLASS(CLF_BlowAr_Data,XGMESLogic\\LFMag\\CLF_BlowAr_Data)
L3CLASS(CLF_Ladle_Info,XGMESLogic\\LFMag\\CLF_Ladle_Info)
END_L3COMP_CLASSTABLE(LFMag)

BEGIN_L3COMP_EVENTTABLE(LFMag)
END_L3COMP_EVENTTABLE(LFMag)

