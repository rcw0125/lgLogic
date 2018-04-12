// LanceMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "LanceMag.h"
#include "_CLance_Base.h"
#include "_CLance_Make.h"
#include "_CLance_Check.h"
#include "_CLance_In_Yard.h"
#include "_CLance_Out_Yard.h"
#include "_CLance_Mag.h"
#include "_CLance_Use.h"
#include "_CLance_Defend.h"

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

// CLanceMagApp

BEGIN_MESSAGE_MAP(CLanceMagApp, CWinApp)
END_MESSAGE_MAP()


// CLanceMagApp ����

CLanceMagApp::CLanceMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CLanceMagApp ����

CLanceMagApp theApp;


// CLanceMagApp ��ʼ��

BOOL CLanceMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(LanceMag)
L3CLASS(CLance_Base,XGMESLogic\\LanceMag\\CLance_Base)
L3CLASS(CLance_Make,XGMESLogic\\LanceMag\\CLance_Make)
L3CLASS(CLance_Check,XGMESLogic\\LanceMag\\CLance_Check)
L3CLASS(CLance_In_Yard,XGMESLogic\\LanceMag\\CLance_In_Yard)
L3CLASS(CLance_Out_Yard,XGMESLogic\\LanceMag\\CLance_Out_Yard)
L3CLASS(CLance_Mag,XGMESLogic\\LanceMag\\CLance_Mag)
L3CLASS(CLance_Use,XGMESLogic\\LanceMag\\CLance_Use)
L3CLASS(CLance_Defend,XGMESLogic\\LanceMag\\CLance_Defend)
END_L3COMP_CLASSTABLE(LanceMag)

BEGIN_L3COMP_EVENTTABLE(LanceMag)
END_L3COMP_EVENTTABLE(LanceMag)

