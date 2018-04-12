// �߼���CCalibration_DetailԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCalibration_Detail.h"

IMPLEMENT_L3CLASS(CCalibration_Detail,CL3Object,1)

BEGIN_L3PROPTABLE(CCalibration_Detail,CL3Object)
	L3PROP_STRING(LogID)
	L3PROP_STRING(Load_B_Std)
	L3PROP_STRING(Load_B_Act)
	L3PROP_STRING(Load_B_Dif)
	L3PROP_STRING(UnLoad_B_Std)
	L3PROP_STRING(UnLoad_B_Act)
	L3PROP_STRING(UnLoad_B_Dif)
	L3PROP_STRING(Load_A_Std)
	L3PROP_STRING(Load_A_Act)
	L3PROP_STRING(Load_A_Dif)
	L3PROP_STRING(UnLoad_A_Std)
	L3PROP_STRING(UnLoad_A_Act)
	L3PROP_STRING(UnLoad_A_Dif)
	L3PROP_DATETIME(Create_Time)
END_L3PROPTABLE(CCalibration_Detail)

BEGIN_L3METHODMAP(CCalibration_Detail,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCalibration_Detail,CL3Object)
END_L3EVENTSINK_MAP(CCalibration_Detail)

CCalibration_Detail::CCalibration_Detail(void)
{
}

CCalibration_Detail::~CCalibration_Detail(void)
{
}
