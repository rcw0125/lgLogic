// �߼���CTap_Addition_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CTap_Addition_Data.h"

IMPLEMENT_L3CLASS(CTap_Addition_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CTap_Addition_Data,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Element)
	L3PROP_FLOAT(Weight)
	L3PROP_FLOAT(Length)
	L3PROP_DATETIME(Discharge_Time)
	L3PROP_SHORT(Type)
	L3PROP_STRING(Batch_ID)
END_L3PROPTABLE(CTap_Addition_Data)

BEGIN_L3METHODMAP(CTap_Addition_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CTap_Addition_Data,CL3Object)
END_L3EVENTSINK_MAP(CTap_Addition_Data)

CTap_Addition_Data::CTap_Addition_Data(void)
{
}

CTap_Addition_Data::~CTap_Addition_Data(void)
{
}
