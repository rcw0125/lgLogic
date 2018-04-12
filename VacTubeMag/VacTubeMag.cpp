// VacTubeMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "VacTubeMag.h"
#include "_CVacTube_Base.h"
#include "_CVacTube_Build.h"
#include "_CVacTube_Hot_Syp_Bui.h"
#include "_CVacTube_Use.h"
#include "_CVacTube_Fire.h"
#include "_CVacTube_Mag.h"
#include "_CVacTube_Repair.h"
#include "_CVacTube_Hot_Syp_Repair.h"
#include "_CVacTube_Fire_Info.h"
#include "_CVacTube_Hot_Syp_Use.h"
#include "_CVacTube_Use_Info.h"

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

// CVacTubeMagApp

BEGIN_MESSAGE_MAP(CVacTubeMagApp, CWinApp)
END_MESSAGE_MAP()


// CVacTubeMagApp ����

CVacTubeMagApp::CVacTubeMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CVacTubeMagApp ����

CVacTubeMagApp theApp;


// CVacTubeMagApp ��ʼ��

BOOL CVacTubeMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(VacTubeMag)
L3CLASS(CVacTube_Base,XGMESLogic\\VacTubeMag\\CVacTube_Base)
L3CLASS(CVacTube_Build,XGMESLogic\\VacTubeMag\\CVacTube_Build)
L3CLASS(CVacTube_Hot_Syp_Bui,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Bui)
L3CLASS(CVacTube_Use,XGMESLogic\\VacTubeMag\\CVacTube_Use)
L3CLASS(CVacTube_Fire,XGMESLogic\\VacTubeMag\\CVacTube_Fire)
L3CLASS(CVacTube_Mag,XGMESLogic\\VacTubeMag\\CVacTube_Mag)
L3CLASS(CVacTube_Repair,XGMESLogic\\VacTubeMag\\CVacTube_Repair)
L3CLASS(CVacTube_Hot_Syp_Repair,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Repair)
L3CLASS(CVacTube_Fire_Info,XGMESLogic\\VacTubeMag\\CVacTube_Fire_Info)
L3CLASS(CVacTube_Hot_Syp_Use,XGMESLogic\\VacTubeMag\\CVacTube_Hot_Syp_Use)
L3CLASS(CVacTube_Use_Info,XGMESLogic\\VacTubeMag\\CVacTube_Use_Info)
END_L3COMP_CLASSTABLE(VacTubeMag)

BEGIN_L3COMP_EVENTTABLE(VacTubeMag)
END_L3COMP_EVENTTABLE(VacTubeMag)

