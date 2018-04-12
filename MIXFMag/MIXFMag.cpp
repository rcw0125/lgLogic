// MIXFMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MIXFMag.h"
#include "_CMIF_Communicator.h"
#include "_CMIF_Temp_Data.h"
#include "_CMIF_Weight.h"
#include "_CMIF_Chemical.h"
#include "_CMIF_Mag.h"
#include "_CMIF_Unit_Mag.h"
#include "_CMIF_Feed_Log.h"

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

// CMIXFMagApp

BEGIN_MESSAGE_MAP(CMIXFMagApp, CWinApp)
END_MESSAGE_MAP()


// CMIXFMagApp ����

CMIXFMagApp::CMIXFMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMIXFMagApp ����

CMIXFMagApp theApp;


// CMIXFMagApp ��ʼ��

BOOL CMIXFMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(MIXFMag)
//L3CLASS(CMIF_Communicator,XGMESLogic\\MIXFMag\\CMIF_Communicator)  2009-04-26
L3CLASS(CMIF_Temp_Data,XGMESLogic\\MIXFMag\\CMIF_Temp_Data)
L3CLASS(CMIF_Weight,XGMESLogic\\MIXFMag\\CMIF_Weight)
//L3CLASS(CMIF_Chemical,XGMESLogic\\MIXFMag\\CMIF_Chemical) 2009-04-26
L3CLASS(CMIF_Mag,XGMESLogic\\MIXFMag\\CMIF_Mag)
L3CLASS(CMIF_Unit_Mag,XGMESLogic\\MIXFMag\\CMIF_Unit_Mag)
L3CLASS(CMIF_Feed_Log,XGMESLogic\\MIXFMag\\CMIF_Feed_Log)
END_L3COMP_CLASSTABLE(MIXFMag)

BEGIN_L3COMP_EVENTTABLE(MIXFMag)
END_L3COMP_EVENTTABLE(MIXFMag)

