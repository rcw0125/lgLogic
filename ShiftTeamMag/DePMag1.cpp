// ������ DLL �ļ���

#include "stdafx.h"

#include "DePMag1.h"


// ������ DLL �ļ���

//#include "stdafx.h"
//
//#include "DePMag1.h"



// DeSMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

//#include "stdafx.h"
//#include "DePMag1.h"
#include "_CDEP_Unit_Mag.h"
#include "_CDEP_Prod_Area.h"
#include "_CDEP_Base_Data.h"
#include "_CDEP_Process_Data.h"
#include "_CDEP_Runtime_Data.h"
#include "_CDEP_Process_Status.h"
#include "_CDEP_Equipment_Status.h"
#include "_CDEP_Addition_Data.h"


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

BEGIN_MESSAGE_MAP(CDePMag1App, CWinApp)
END_MESSAGE_MAP()


// CDeSMagApp ����

CDePMag1App::CDePMag1App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDeSMagApp ����

CDePMag1App theApp;


// CDeSMagApp ��ʼ��

BOOL CDePMag1App::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DePMag1)
L3CLASS(CDEP_Unit_Mag,XGMESLogic\\DePMag1\\CDEP_Unit_Mag)
L3CLASS(CDEP_Prod_Area,XGMESLogic\\DePMag1\\CDEP_Prod_Area)
L3CLASS(CDEP_Base_Data,XGMESLogic\\DePMag1\\CDEP_Base_Data)
L3CLASS(CDEP_Process_Data,XGMESLogic\\DePMag1\\CDEP_Process_Data)
L3CLASS(CDEP_Runtime_Data,XGMESLogic\\DePMag1\\CDEP_Runtime_Data)
L3CLASS(CDEP_Process_Status,XGMESLogic\\DePMag1\\CDEP_Process_Status)
L3CLASS(CDEP_Equipment_Status,XGMESLogic\\DePMag1\\CDEP_Equipment_Status)
L3CLASS(CDEP_Addition_Data,XGMESLogic\\DePMag1\\CDEP_Addition_Data)
END_L3COMP_CLASSTABLE(DePMag1)

BEGIN_L3COMP_EVENTTABLE(DePMag1)
END_L3COMP_EVENTTABLE(DePMag1)

