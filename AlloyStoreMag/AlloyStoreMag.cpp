// AlloyStoreMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AlloyStoreMag.h"
#include "_CAlloy_Store_Mag.h"
#include "_CAlloy_Data.h"
#include "_CAlloy_Code.h"
#include "_CAlloy_Input_Log.h"
#include "_CAlloy_Output_Log.h"
#include "_CAlloy_Store_Communicator.h"
#include "_CAlloy_Trans_Tel_Data.h"
#include "_CAlloy_App.h"
#include "_CAlloy_Bulk_Relation.h"
#include "_CAlloy_PropChange_Log.h"
#include "_CAlloy_Trans_Log.h"
#include "_CAlloy_Element_Tel_Data.h"
#include "_CStoreOperateLog.h"

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

// CAlloyStoreMagApp

BEGIN_MESSAGE_MAP(CAlloyStoreMagApp, CWinApp)
END_MESSAGE_MAP()


// CAlloyStoreMagApp ����

CAlloyStoreMagApp::CAlloyStoreMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAlloyStoreMagApp ����

CAlloyStoreMagApp theApp;


// CAlloyStoreMagApp ��ʼ��

BOOL CAlloyStoreMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(AlloyStoreMag)
L3CLASS(CAlloy_Store_Mag,XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Mag)
L3CLASS(CAlloy_Data,MES\\MaterialData\\CAlloy_Data)
//L3CLASS(CAlloy_Code,XGMESLogic\\AlloyStoreMag\\CAlloy_Code)
L3CLASS(CAlloy_Input_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Input_Log)
L3CLASS(CAlloy_Output_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Output_Log)
//L3CLASS(CAlloy_Store_Communicator,XGMESLogic\\AlloyStoreMag\\CAlloy_Store_Communicator)
//L3CLASS(CAlloy_Trans_Tel_Data,XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Tel_Data)
//L3CLASS(CAlloy_App,XGMESLogic\\AlloyStoreMag\\CAlloy_App) 2009-04-26
L3CLASS(CAlloy_Bulk_Relation,XGMESLogic\\AlloyStoreMag\\CAlloy_Bulk_Relation)
L3CLASS(CAlloy_PropChange_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_PropChange_Log)
L3CLASS(CAlloy_Trans_Log,XGMESLogic\\AlloyStoreMag\\CAlloy_Trans_Log)
L3CLASS(CAlloy_Element_Tel_Data,XGMESLogic\\AlloyStoreMag\\CAlloy_Element_Tel_Data)
L3CLASS(CStoreOperateLog,XGMESLogic\\AlloyStoreMag\\CStoreOperateLog)
END_L3COMP_CLASSTABLE(AlloyStoreMag)

BEGIN_L3COMP_EVENTTABLE(AlloyStoreMag)
END_L3COMP_EVENTTABLE(AlloyStoreMag)

