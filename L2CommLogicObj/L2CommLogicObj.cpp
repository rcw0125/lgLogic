// L2CommLogicObj.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "L2CommLogicObj.h"
#include "L2CommLogic.h"



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
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
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

// CL2CommLogicObjApp

BEGIN_MESSAGE_MAP(CL2CommLogicObjApp, CWinApp)
END_MESSAGE_MAP()


// CL2CommLogicObjApp ����

CL2CommLogicObjApp::CL2CommLogicObjApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CL2CommLogicObjApp ����

CL2CommLogicObjApp theApp;


// CL2CommLogicObjApp ��ʼ��

BOOL CL2CommLogicObjApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(L2CommLogicObj)
	L3CLASS(CL2CommLogic,L3\\AppLogic\\CL2CommLogic)
END_L3COMP_CLASSTABLE(L2CommLogicObj)

BEGIN_L3COMP_EVENTTABLE(L2CommLogicObj)
	
END_L3COMP_EVENTTABLE(L2CommLogicObj)