// �߼���CLF_Ladle_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Ladle_Data.h"

IMPLEMENT_L3CLASS(CLF_Ladle_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Ladle_Data,CL3Object)
	L3PROP_SHORT(LFID)
	L3PROP_STRING(LadleNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Status)
	L3PROP_DOUBLE(Weight)
END_L3PROPTABLE(CLF_Ladle_Data)

BEGIN_L3METHODMAP(CLF_Ladle_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Ladle_Data,CL3Object)
END_L3EVENTSINK_MAP(CLF_Ladle_Data)

CLF_Ladle_Data::CLF_Ladle_Data(void)
{
}

CLF_Ladle_Data::~CLF_Ladle_Data(void)
{
}
