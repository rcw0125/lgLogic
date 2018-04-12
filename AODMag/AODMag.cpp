// ������ DLL �ļ���

#include "stdafx.h"

#include "AODMag.h"


// AODMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

//#include "stdafx.h"
//#include "AODMag.h"
//#include "_CAOD_Communicator.h"
#include "_CAOD_Unit_Mag.h"
#include "_CAOD_Process_Status.h"
#include "_CAOD_Equipment_Status.h"
#include "_CAOD_Process_Data.h"
//#include "_CAOD_Oxygen_Data.h"
#include "_CAOD_Temp_Data.h"
#include "_CAOD_Addition_Data.h"
#include "_CAOD_HeatRemark.h"
//#include "_CAOD_Wire_Data.h"
//#include "_CAOD_Ladle_Data.h"
//#include "_CAOD_Ladle_Weight.h"
#include "_CAOD_Base_Data.h"
#include "_CAOD_Prod_Area.h"
#include "_CAOD_Top_Blowing.h"
#include "_CAOD_Side_Blowing.h"
//#include "_CAOD_Ladle_Info.h"

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

// CAODMagApp

BEGIN_MESSAGE_MAP(CAODMagApp, CWinApp)
END_MESSAGE_MAP()


// CAODMagApp ����

CAODMagApp::CAODMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAODMagApp ����

CAODMagApp theApp;


// CAODMagApp ��ʼ��

BOOL CAODMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(AODMag)
//L3CLASS(CAOD_Communicator,XGMESLogic\\AODMag\\CAOD_Communicator)
L3CLASS(CAOD_Unit_Mag,XGMESLogic\\AODMag\\CAOD_Unit_Mag)
L3CLASS(CAOD_Process_Status,XGMESLogic\\AODMag\\CAOD_Process_Status)
L3CLASS(CAOD_Equipment_Status,XGMESLogic\\AODMag\\CAOD_Equipment_Status)
L3CLASS(CAOD_Process_Data,XGMESLogic\\AODMag\\CAOD_Process_Data)
//L3CLASS(CAOD_Oxygen_Data,XGMESLogic\\AODMag\\CAOD_Oxygen_Data)
L3CLASS(CAOD_Temp_Data,XGMESLogic\\AODMag\\CAOD_Temp_Data)
L3CLASS(CAOD_Addition_Data,XGMESLogic\\AODMag\\CAOD_Addition_Data)
L3CLASS(CAOD_HeatRemark,XGMESLogic\\AODMag\\CAOD_HeatRemark)
//L3CLASS(CAOD_Wire_Data,XGMESLogic\\AODMag\\CAOD_Wire_Data)
//L3CLASS(CAOD_Ladle_Data,XGMESLogic\\AODMag\\CAOD_Ladle_Data)
//L3CLASS(CAOD_Ladle_Weight,XGMESLogic\\AODMag\\CAOD_Ladle_Weight)
L3CLASS(CAOD_Base_Data,XGMESLogic\\AODMag\\CAOD_Base_Data)
L3CLASS(CAOD_Prod_Area,XGMESLogic\\AODMag\\CAOD_Prod_Area)
L3CLASS(CAOD_Top_Blowing,XGMESLogic\\AODMag\\CAOD_Top_Blowing)
L3CLASS(CAOD_Side_Blowing,XGMESLogic\\AODMag\\CAOD_Side_Blowing)
//L3CLASS(CAOD_Ladle_Info,XGMESLogic\\AODMag\\CAOD_Ladle_Info)
END_L3COMP_CLASSTABLE(AODMag)

BEGIN_L3COMP_EVENTTABLE(AODMag)
END_L3COMP_EVENTTABLE(AODMag)


