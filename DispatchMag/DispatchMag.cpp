// DispatchMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "DispatchMag.h"
#include "_CDisp_SteelBack_App.h"
#include "_CDisp_SteelTurn_App.h"
#include "_CDisp_SteelDiv_App.h"
#include "_CDisp_SteelExchange_App.h"
#include "_CDispatch_Mag.h"
#include "_CDisp_Duty_Note.h"
#include "_CDisp_Unit_ProcessTime.h"
#include "_CDisp_Account.h"
#include "_CDisp_Exceptional.h"
#include "_CDisp_Exceptional_Items.h"

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

// CDispatchMagApp

BEGIN_MESSAGE_MAP(CDispatchMagApp, CWinApp)
END_MESSAGE_MAP()


// CDispatchMagApp ����

CDispatchMagApp::CDispatchMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CDispatchMagApp ����

CDispatchMagApp theApp;


// CDispatchMagApp ��ʼ��

BOOL CDispatchMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(DispatchMag)
L3CLASS(CDisp_SteelBack_App,XGMESLogic\\DispatchMag\\CDisp_SteelBack_App)
L3CLASS(CDisp_SteelTurn_App,XGMESLogic\\DispatchMag\\CDisp_SteelTurn_App)
//L3CLASS(CDisp_SteelDiv_App,XGMESLogic\\DispatchMag\\CDisp_SteelDiv_App)  2009-04-26
L3CLASS(CDisp_SteelExchange_App,XGMESLogic\\DispatchMag\\CDisp_SteelExchange_App)
L3CLASS(CDispatch_Mag,XGMESLogic\\DispatchMag\\CDispatch_Mag)
L3CLASS(CDisp_Duty_Note,XGMESLogic\\DispatchMag\\CDisp_Duty_Note)
L3CLASS(CDisp_Unit_ProcessTime,XGMESLogic\\DispatchMag\\CDisp_Unit_ProcessTime)
L3CLASS(CDisp_Account,XGMESLogic\\DispatchMag\\CDisp_Account)
L3CLASS(CDisp_Exceptional,XGMESLogic\\DispatchMag\\CDisp_Exceptional)
L3CLASS(CDisp_Exceptional_Items,XGMESLogic\\DispatchMag\\CDisp_Exceptional_Items)
END_L3COMP_CLASSTABLE(DispatchMag)

BEGIN_L3COMP_EVENTTABLE(DispatchMag)
END_L3COMP_EVENTTABLE(DispatchMag)

