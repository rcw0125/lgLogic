// LadleMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "LadleMag.h"
#include "_CLadle_Base.h"
#include "_CLadle_In_Build.h"
#include "_CLadle_Com_Tie.h"
#include "_CLadle_Com_Lad_Rep.h"
#include "_CLadle_Fin_Build.h"
#include "_CLadle_Cha_Dre_Lin.h"
#include "_CLadle_Use.h"
#include "_CLadle_Fire.h"
#include "_CLadle_Pour.h"
#include "_CLadle_Fold.h"
#include "_CLadle_Plan.h"
#include "_CLadle_Mag.h"
#include "_CLadle_Process.h"

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

// CLadleMagApp

BEGIN_MESSAGE_MAP(CLadleMagApp, CWinApp)
END_MESSAGE_MAP()


// CLadleMagApp ����

CLadleMagApp::CLadleMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLadleMagApp ����

CLadleMagApp theApp;


// CLadleMagApp ��ʼ��

BOOL CLadleMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LadleMag)
L3CLASS(CLadle_Base,XGMESLogic\\LadleMag\\CLadle_Base)
L3CLASS(CLadle_In_Build,XGMESLogic\\LadleMag\\CLadle_In_Build)
L3CLASS(CLadle_Com_Tie,XGMESLogic\\LadleMag\\CLadle_Com_Tie)
L3CLASS(CLadle_Com_Lad_Rep,XGMESLogic\\LadleMag\\CLadle_Com_Lad_Rep)
L3CLASS(CLadle_Fin_Build,XGMESLogic\\LadleMag\\CLadle_Fin_Build)
L3CLASS(CLadle_Cha_Dre_Lin,XGMESLogic\\LadleMag\\CLadle_Cha_Dre_Lin)
L3CLASS(CLadle_Use,XGMESLogic\\LadleMag\\CLadle_Use)
L3CLASS(CLadle_Fire,XGMESLogic\\LadleMag\\CLadle_Fire)
L3CLASS(CLadle_Pour,XGMESLogic\\LadleMag\\CLadle_Pour)
L3CLASS(CLadle_Fold,XGMESLogic\\LadleMag\\CLadle_Fold)
//L3CLASS(CLadle_Plan,XGMESLogic\\LadleMag\\CLadle_Plan) 2009-04-26
L3CLASS(CLadle_Mag,XGMESLogic\\LadleMag\\CLadle_Mag)
L3CLASS(CLadle_Process,XGMESLogic\\LadleMag\\CLadle_Process)
END_L3COMP_CLASSTABLE(LadleMag)

BEGIN_L3COMP_EVENTTABLE(LadleMag)
END_L3COMP_EVENTTABLE(LadleMag)

