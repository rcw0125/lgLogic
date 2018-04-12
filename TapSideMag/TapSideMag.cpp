// TapSideMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TapSideMag.h"
#include "_CTap_Oxygen_Data.h"
#include "_CTap_Temp_Data.h"
#include "_CTap_Addition_Data.h"
#include "_CTap_Base_Data.h"
#include "_CTap_Process_Data.h"
#include "_CTap_Unit_Mag.h"
#include "_CTap_Ladle_Weight.h"
#include "_CTAP_Communicator.h"

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

// CTapSideMagApp

BEGIN_MESSAGE_MAP(CTapSideMagApp, CWinApp)
END_MESSAGE_MAP()


// CTapSideMagApp ����

CTapSideMagApp::CTapSideMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTapSideMagApp ����

CTapSideMagApp theApp;


// CTapSideMagApp ��ʼ��

BOOL CTapSideMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(TapSideMag)
L3CLASS(CTap_Oxygen_Data,XGMESLogic\\TapSideMag\\CTap_Oxygen_Data)
L3CLASS(CTap_Temp_Data,XGMESLogic\\TapSideMag\\CTap_Temp_Data)
L3CLASS(CTap_Addition_Data,XGMESLogic\\TapSideMag\\CTap_Addition_Data)
L3CLASS(CTap_Base_Data,XGMESLogic\\TapSideMag\\CTap_Base_Data)
L3CLASS(CTap_Process_Data,XGMESLogic\\TapSideMag\\CTap_Process_Data)
L3CLASS(CTap_Unit_Mag,XGMESLogic\\TapSideMag\\CTap_Unit_Mag)
L3CLASS(CTap_Ladle_Weight,XGMESLogic\\TapSideMag\\CTap_Ladle_Weight)
//L3CLASS(CTAP_Communicator,XGMESLogic\\TapSideMag\\CTAP_Communicator)
END_L3COMP_CLASSTABLE(TapSideMag)

BEGIN_L3COMP_EVENTTABLE(TapSideMag)
END_L3COMP_EVENTTABLE(TapSideMag)

