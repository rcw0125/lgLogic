// �߼���CDeS_Addition_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDeS_Addition_Data.h"

IMPLEMENT_L3CLASS(CDeS_Addition_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Addition_Data,CL3Object)
    L3PROP_STRING(UnitID)
	L3PROP_STRING(Mat_Code)
	L3PROP_STRING(Mat_Vendor)
	L3PROP_FLOAT(Weight)
	L3PROP_DATETIME(Time_Discharge)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
	L3PROP_DATETIME(Time_Begin_Discharge)
	L3PROP_DATETIME(Time_Stop_Discharge)
END_L3PROPTABLE(CDeS_Addition_Data)

BEGIN_L3METHODMAP(CDeS_Addition_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Addition_Data,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Addition_Data)

CDeS_Addition_Data::CDeS_Addition_Data(void)
{
}

CDeS_Addition_Data::~CDeS_Addition_Data(void)
{
}
