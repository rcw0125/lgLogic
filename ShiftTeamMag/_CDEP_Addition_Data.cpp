// �߼���CDEP_Addition_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDEP_Addition_Data.h"

IMPLEMENT_L3CLASS(CDEP_Addition_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CDEP_Addition_Data,CL3Object)

	L3PROP_STRING(IronLadle)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Element)
	L3PROP_STRING(Batch_ID)
	L3PROP_FLOAT(Weight)
	L3PROP_DATETIME(Discharge_Time)
	L3PROP_SHORT(Type)
	L3PROP_STRING(Area)	
END_L3PROPTABLE(CDEP_Addition_Data)

BEGIN_L3METHODMAP(CDEP_Addition_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDEP_Addition_Data,CL3Object)
END_L3EVENTSINK_MAP(CDEP_Addition_Data)

CDEP_Addition_Data::CDEP_Addition_Data(void)
{
}

CDEP_Addition_Data::~CDEP_Addition_Data(void)
{
}
