// BulkStoreMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "BulkStoreMag.h"
#include "_CBulk_Store_Mag.h"
#include "_CBulk_Data.h"
#include "_CBulk_Code.h"
#include "_CBulk_Input_Log.h"
#include "_CBulk_Output_Log.h"
#include "_CBulk_Purchase_Tel_Data.h"
#include "_CBulk_App.h"
#include "_CBulk_Store_Communicator.h"
#include "_CBulk_Bulk_Relation.h"
#include "_CBulk_PropChange_Log.h"
#include "_CBulk_Trans_Log.h"
#include "_CBulk_Trans_Tel_Data.h"

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

// CBulkStoreMagApp

BEGIN_MESSAGE_MAP(CBulkStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CBulkStoreMagApp ����

CBulkStoreMagApp::CBulkStoreMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CBulkStoreMagApp ����

CBulkStoreMagApp theApp;


// CBulkStoreMagApp ��ʼ��

BOOL CBulkStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(BulkStoreMag)
L3CLASS(CBulk_Store_Mag,XGMESLogic\\BulkStoreMag\\CBulk_Store_Mag)
L3CLASS(CBulk_Data,MES\\MaterialData\\CBulk_Data)
//L3CLASS(CBulk_Code,XGMESLogic\\BulkStoreMag\\CBulk_Code)
L3CLASS(CBulk_Input_Log,XGMESLogic\\BulkStoreMag\\CBulk_Input_Log)
L3CLASS(CBulk_Output_Log,XGMESLogic\\BulkStoreMag\\CBulk_Output_Log)
//L3CLASS(CBulk_Purchase_Tel_Data,XGMESLogic\\BulkStoreMag\\CBulk_Purchase_Tel_Data)
//L3CLASS(CBulk_App,XGMESLogic\\BulkStoreMag\\CBulk_App)
//L3CLASS(CBulk_Store_Communicator,XGMESLogic\\BulkStoreMag\\CBulk_Store_Communicator)
L3CLASS(CBulk_Bulk_Relation,XGMESLogic\\BulkStoreMag\\CBulk_Bulk_Relation)
L3CLASS(CBulk_PropChange_Log,XGMESLogic\\BulkStoreMag\\CBulk_PropChange_Log)
L3CLASS(CBulk_Trans_Log,XGMESLogic\\BulkStoreMag\\CBulk_Trans_Log)
//L3CLASS(CBulk_Trans_Tel_Data,XGMESLogic\\BulkStoreMag\\CBulk_Trans_Tel_Data)
END_L3COMP_CLASSTABLE(BulkStoreMag)

BEGIN_L3COMP_EVENTTABLE(BulkStoreMag)
END_L3COMP_EVENTTABLE(BulkStoreMag)

