// BloomStoreMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "BloomStoreMag.h"
#include "_CBloom_Store_Mag.h"
#include "_CBloom_Input_Log.h"
#include "_CBloom_Output_Log.h"
#include "_CBloom_Store_Communicator.h"
#include "_CBloom_Tel_Data.h"
#include "_CBloom_Trans_Log.h"

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

// CBloomStoreMagApp

BEGIN_MESSAGE_MAP(CBloomStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CBloomStoreMagApp ����

CBloomStoreMagApp::CBloomStoreMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CBloomStoreMagApp ����

CBloomStoreMagApp theApp;


// CBloomStoreMagApp ��ʼ��

BOOL CBloomStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BloomStoreMag)
L3CLASS(CBloom_Store_Mag,XGMESLogic\\BloomStoreMag\\CBloom_Store_Mag)
L3CLASS(CBloom_Input_Log,XGMESLogic\\BloomStoreMag\\CBloom_Input_Log)
L3CLASS(CBloom_Output_Log,XGMESLogic\\BloomStoreMag\\CBloom_Output_Log)
//L3CLASS(CBloom_Store_Communicator,XGMESLogic\\BloomStoreMag\\CBloom_Store_Communicator)
//L3CLASS(CBloom_Tel_Data,XGMESLogic\\BloomStoreMag\\CBloom_Tel_Data)
L3CLASS(CBloom_Trans_Log,XGMESLogic\\BloomStoreMag\\CBloom_Trans_Log)
END_L3COMP_CLASSTABLE(BloomStoreMag)

BEGIN_L3COMP_EVENTTABLE(BloomStoreMag)
END_L3COMP_EVENTTABLE(BloomStoreMag)

