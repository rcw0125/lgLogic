// IronLadleMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "IronLadleMag.h"
#include "_CIronLadle_Mag.h"
#include "_CIronLadle_Base.h"
#include "_CIronLadle_Tie.h"
#include "_CIronLadle_Fire.h"
#include "_CIronLadle_Use.h"

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

// CIronLadleMagApp

BEGIN_MESSAGE_MAP(CIronLadleMagApp, CWinApp)
END_MESSAGE_MAP()


// CIronLadleMagApp ����

CIronLadleMagApp::CIronLadleMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CIronLadleMagApp ����

CIronLadleMagApp theApp;


// CIronLadleMagApp ��ʼ��

BOOL CIronLadleMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(IronLadleMag)
L3CLASS(CIronLadle_Mag,XGMESLogic\\IronLadleMag\\CIronLadle_Mag)
L3CLASS(CIronLadle_Base,XGMESLogic\\IronLadleMag\\CIronLadle_Base)
L3CLASS(CIronLadle_Tie,XGMESLogic\\IronLadleMag\\CIronLadle_Tie)
L3CLASS(CIronLadle_Fire,XGMESLogic\\IronLadleMag\\CIronLadle_Fire)
L3CLASS(CIronLadle_Use,XGMESLogic\\IronLadleMag\\CIronLadle_Use)
END_L3COMP_CLASSTABLE(IronLadleMag)

BEGIN_L3COMP_EVENTTABLE(IronLadleMag)
END_L3COMP_EVENTTABLE(IronLadleMag)

