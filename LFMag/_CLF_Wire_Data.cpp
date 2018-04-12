// �߼���CLF_Wire_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Wire_Data.h"

IMPLEMENT_L3CLASS(CLF_Wire_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Wire_Data,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(WireCode)
	L3PROP_FLOAT(Weight)
	L3PROP_FLOAT(Speed)
	L3PROP_DATETIME(WireTime)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Vendor)
	L3PROP_FLOAT(Amount)
END_L3PROPTABLE(CLF_Wire_Data)

BEGIN_L3METHODMAP(CLF_Wire_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Wire_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Wire_Data)

CLF_Wire_Data::CLF_Wire_Data(void)
{
}

CLF_Wire_Data::~CLF_Wire_Data(void)
{
}
