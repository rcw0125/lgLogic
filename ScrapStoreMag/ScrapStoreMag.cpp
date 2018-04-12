// ScrapStoreMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "ScrapStoreMag.h"
#include "_CScrap_Store_Mag.h"
#include "_CScrap_Store_Communicator.h"
#include "_CScrap_Data.h"
#include "_CSrap_Code.h"
#include "_CScrap_Input_Log.h"
#include "_CScrap_Output_Log.h"
#include "_CScrap_Trans_Tel_Data.h"
#include "_CScrap_PropChange_Log.h"
#include "_CScrap_Purchase_Tel_Data.h"
#include "_CScrapOutStoreDetail.h"

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

// CScrapStoreMagApp

BEGIN_MESSAGE_MAP(CScrapStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CScrapStoreMagApp ����

CScrapStoreMagApp::CScrapStoreMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CScrapStoreMagApp ����

CScrapStoreMagApp theApp;


// CScrapStoreMagApp ��ʼ��

BOOL CScrapStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(ScrapStoreMag)
L3CLASS(CScrap_Store_Mag,XGMESLogic\\ScrapStoreMag\\CScrap_Store_Mag)
//L3CLASS(CScrap_Store_Communicator,XGMESLogic\\ScrapStoreMag\\CScrap_Store_Communicator)
L3CLASS(CScrap_Data,MES\\MaterialData\\CScrap_Data)
//L3CLASS(CSrap_Code,XGMESLogic\\ScrapStoreMag\\CSrap_Code)
L3CLASS(CScrap_Input_Log,XGMESLogic\\ScrapStoreMag\\CScrap_Input_Log)
L3CLASS(CScrap_Output_Log,XGMESLogic\\ScrapStoreMag\\CScrap_Output_Log)
//L3CLASS(CScrap_Trans_Tel_Data,XGMESLogic\\ScrapStoreMag\\CScrap_Trans_Tel_Data)
L3CLASS(CScrap_PropChange_Log,XGMESLogic\\ScrapStoreMag\\CScrap_PropChange_Log)
//L3CLASS(CScrap_Purchase_Tel_Data,XGMESLogic\\ScrapStoreMag\\CScrap_Purchase_Tel_Data)
L3CLASS(CScrapOutStoreDetail,XGMESLogic\\ScrapStoreMag\\CScrapOutStoreDetail)
END_L3COMP_CLASSTABLE(ScrapStoreMag)

BEGIN_L3COMP_EVENTTABLE(ScrapStoreMag)
END_L3COMP_EVENTTABLE(ScrapStoreMag)

