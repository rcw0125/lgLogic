// BFMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "BFMag.h"
#include "_CBF_Iron_Mag.h"
#include "_CBFIronInLog.h"
#include "_CBFIronOutLog.h"
#include "_CBF_IronLadle_Info.h"
#include "_CBF_Iron_Back_Log.h"

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

// CBFMagApp

BEGIN_MESSAGE_MAP(CBFMagApp, CWinApp)
END_MESSAGE_MAP()


// CBFMagApp ����

CBFMagApp::CBFMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CBFMagApp ����

CBFMagApp theApp;


// CBFMagApp ��ʼ��

BOOL CBFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BFMag)
L3CLASS(CBF_Iron_Mag,XGMESLogic\\BFMag\\CBF_Iron_Mag)
L3CLASS(CBFIronInLog,XGMESLogic\\BFMag\\CBFIronInLog)
L3CLASS(CBFIronOutLog,XGMESLogic\\BFMag\\CBFIronOutLog)
L3CLASS(CBF_IronLadle_Info,XGMESLogic\\BFMag\\CBF_IronLadle_Info)
L3CLASS(CBF_Iron_Back_Log,XGMESLogic\\BFMag\\CBF_Iron_Back_Log)
END_L3COMP_CLASSTABLE(BFMag)

BEGIN_L3COMP_EVENTTABLE(BFMag)
END_L3COMP_EVENTTABLE(BFMag)

