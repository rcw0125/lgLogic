// TundishMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "TundishMag.h"
#include "_CTundish_Mag.h"
#include "_CTundish_Base.h"
#include "_CTundish_Inner_Build.h"
#include "_CTundish_Daub.h"
#include "_CTundish_Inner_Fire.h"
#include "_CTundish_OT_Install.h"
#include "_CTundish_TFF_Install.h"
#include "_CTundish_OT_Hot_Fire.h"
#include "_CTundish_TFF_Hot_Fire.h"
#include "_CTundish_OT_Refra_Use.h"
#include "_CTundish_TFF_Refra_Use.h"
#include "_CTundish_Use_Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//	ע�⣡
//
//		����� DLL ��̬���ӵ� MFC
//		DLL���Ӵ� DLL ������
//		���� MFC ���κκ����ں�������ǰ��
//		��������� AFX_MANAGE_State �ꡣ
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT AccessedFunction()
//		{
//			AFX_MANAGE_State(AfxGetStaticModuleStatus());
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

// CTundishMagApp

BEGIN_MESSAGE_MAP(CTundishMagApp, CWinApp)
END_MESSAGE_MAP()


// CTundishMagApp ����

CTundishMagApp::CTundishMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTundishMagApp ����

CTundishMagApp theApp;


// CTundishMagApp ��ʼ��

BOOL CTundishMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(TundishMag)
L3CLASS(CTundish_Base,XGMESLogic\\TundishMag\\CTundish_Base)
L3CLASS(CTundish_Inner_Build,XGMESLogic\\TundishMag\\CTundish_Inner_Build)
L3CLASS(CTundish_Daub,XGMESLogic\\TundishMag\\CTundish_Daub)
L3CLASS(CTundish_Inner_Fire,XGMESLogic\\TundishMag\\CTundish_Inner_Fire)
L3CLASS(CTundish_OT_Install,XGMESLogic\\TundishMag\\CTundish_OT_Install)
L3CLASS(CTundish_TFF_Install,XGMESLogic\\TundishMag\\CTundish_TFF_Install)
L3CLASS(CTundish_OT_Hot_Fire,XGMESLogic\\TundishMag\\CTundish_OT_Hot_Fire)
L3CLASS(CTundish_TFF_Hot_Fire,XGMESLogic\\TundishMag\\CTundish_TFF_Hot_Fire)
L3CLASS(CTundish_OT_Refra_Use,XGMESLogic\\TundishMag\\CTundish_OT_Refra_Use)
L3CLASS(CTundish_TFF_Refra_Use,XGMESLogic\\TundishMag\\CTundish_TFF_Refra_Use)
L3CLASS(CTundish_Mag,XGMESLogic\\TundishMag\\CTundish_Mag)
L3CLASS(CTundish_Use_Info,XGMESLogic\\TundishMag\\CTundish_Use_Info)
END_L3COMP_CLASSTABLE(TundishMag)

BEGIN_L3COMP_EVENTTABLE(TundishMag)
END_L3COMP_EVENTTABLE(TundishMag)

