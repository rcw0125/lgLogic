// �߼���CLF_Ladle_WeightԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Ladle_Weight.h"

IMPLEMENT_L3CLASS(CLF_Ladle_Weight,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Ladle_Weight,CL3Object)
	L3PROP_SHORT(LFID)
	L3PROP_DOUBLE(Weight)
	L3PROP_SHORT(Status)
	L3PROP_STRING(LadleNo)
	L3PROP_DATETIME(Log_Time)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CLF_Ladle_Weight)

BEGIN_L3METHODMAP(CLF_Ladle_Weight,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Ladle_Weight,CL3Object)
END_L3EVENTSINK_MAP(CLF_Ladle_Weight)

CLF_Ladle_Weight::CLF_Ladle_Weight(void)
{
}

CLF_Ladle_Weight::~CLF_Ladle_Weight(void)
{
}
