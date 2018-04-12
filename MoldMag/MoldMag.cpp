// MoldMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MoldMag.h"
#include "_CMold_Base.h"
#include "_CMold_Pipe_Install.h"
#include "_CMold_Board_Install.h"
#include "_CMold_Pipe_Par_Use.h"
#include "_CMold_Board_Par_Use.h"
#include "_CMold_Mag.h"
#include "_CMold_Board_Check.h"

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
//			AFX_MANAGE_STATE(AfxGetStaticModuleStatus());
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

// CMoldMagApp

BEGIN_MESSAGE_MAP(CMoldMagApp, CWinApp)
END_MESSAGE_MAP()


// CMoldMagApp ����

CMoldMagApp::CMoldMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMoldMagApp ����

CMoldMagApp theApp;


// CMoldMagApp ��ʼ��

BOOL CMoldMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(MoldMag)
L3CLASS(CMold_Base,XGMESLogic\\MoldMag\\CMold_Base)
L3CLASS(CMold_Pipe_Install,XGMESLogic\\MoldMag\\CMold_Pipe_Install)
L3CLASS(CMold_Board_Install,XGMESLogic\\MoldMag\\CMold_Board_Install)
L3CLASS(CMold_Pipe_Par_Use,XGMESLogic\\MoldMag\\CMold_Pipe_Par_Use)
L3CLASS(CMold_Board_Par_Use,XGMESLogic\\MoldMag\\CMold_Board_Par_Use)
L3CLASS(CMold_Mag,XGMESLogic\\MoldMag\\CMold_Mag)
L3CLASS(CMold_Board_Check,XGMESLogic\\MoldMag\\CMold_Board_Check)
END_L3COMP_CLASSTABLE(MoldMag)

BEGIN_L3COMP_EVENTTABLE(MoldMag)
END_L3COMP_EVENTTABLE(MoldMag)
