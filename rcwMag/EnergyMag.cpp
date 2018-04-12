// EnergyMag.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "EnergyMag.h"
#include "_CEnergyRunTimeData.h"
#include "_CEnergyHistoryData.h"
#include "_CEnergy_Unit_Mag.h"
#include "_CEnergyConsumption.h"
#include "_CEnergy_Manual_Data.h"
#include "_CLF_Temp_Control.h"

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

// CEnergyMagApp

BEGIN_MESSAGE_MAP(CEnergyMagApp, CWinApp)
END_MESSAGE_MAP()


// CEnergyMagApp ����

CEnergyMagApp::CEnergyMagApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CEnergyMagApp ����

CEnergyMagApp theApp;


// CEnergyMagApp ��ʼ��

BOOL CEnergyMagApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

BEGIN_L3COMP_CLASSTABLE(EnergyMag)
L3CLASS(CEnergyRunTimeData,XGMESLogic\\EnergyMag\\CEnergyRunTimeData)
L3CLASS(CEnergyHistoryData,XGMESLogic\\EnergyMag\\CEnergyHistoryData)
L3CLASS(CEnergy_Unit_Mag,XGMESLogic\\EnergyMag\\CEnergy_Unit_Mag)
L3CLASS(CEnergyConsumption,XGMESLogic\\EnergyMag\\CEnergyConsumption)
L3CLASS(CEnergy_Manual_Data,XGMESLogic\\EnergyMag\\CEnergy_Manual_Data)
L3CLASS(CLF_Temp_Control,XGMESLogic\\EnergyMag\\CLF_Temp_Control)
END_L3COMP_CLASSTABLE(EnergyMag)

BEGIN_L3COMP_EVENTTABLE(EnergyMag)
END_L3COMP_EVENTTABLE(EnergyMag)

