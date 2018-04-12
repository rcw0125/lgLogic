// DeSMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "DeSMag.h"
#include "_CDeS_Unit_Mag.h"
#include "_CDeS_Prod_Area.h"
#include "_CDeS_Base_Data.h"
#include "_CDeS_Process_Data.h"
#include "_CDeS_Runtime_Data.h"
#include "_CDeS_Process_Status.h"
#include "_CDeS_Equipment_Status.h"
#include "_CDeS_Addition_Data.h"
#include "_CDeS_Lance_Data.h"
#include "_CDeS_Lance_Log.h"

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

// CDeSMagApp

BEGIN_MESSAGE_MAP(CDeSMagApp, CWinApp)
END_MESSAGE_MAP()


// CDeSMagApp ����

CDeSMagApp::CDeSMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDeSMagApp ����

CDeSMagApp theApp;


// CDeSMagApp ��ʼ��

BOOL CDeSMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DeSMag)
L3CLASS(CDeS_Unit_Mag,XGMESLogic\\DeSMag\\CDeS_Unit_Mag)
L3CLASS(CDeS_Prod_Area,XGMESLogic\\DeSMag\\CDeS_Prod_Area)
L3CLASS(CDeS_Base_Data,XGMESLogic\\DeSMag\\CDeS_Base_Data)
L3CLASS(CDeS_Process_Data,XGMESLogic\\DeSMag\\CDeS_Process_Data)
L3CLASS(CDeS_Runtime_Data,XGMESLogic\\DeSMag\\CDeS_Runtime_Data)
L3CLASS(CDeS_Process_Status,XGMESLogic\\DeSMag\\CDeS_Process_Status)
L3CLASS(CDeS_Equipment_Status,XGMESLogic\\DeSMag\\CDeS_Equipment_Status)
L3CLASS(CDeS_Addition_Data,XGMESLogic\\DeSMag\\CDeS_Addition_Data)
L3CLASS(CDeS_Lance_Data,XGMESLogic\\DeSMag\\CDeS_Lance_Data)
L3CLASS(CDeS_Lance_Log,XGMESLogic\\DeSMag\\CDeS_Lance_Log)
END_L3COMP_CLASSTABLE(DeSMag)

BEGIN_L3COMP_EVENTTABLE(DeSMag)
END_L3COMP_EVENTTABLE(DeSMag)

