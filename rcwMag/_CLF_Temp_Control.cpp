// �߼���CLF_Temp_ControlԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Temp_Control.h"

IMPLEMENT_L3CLASS(CLF_Temp_Control,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Temp_Control,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(Reasion) 
	L3PROP_STRING(FlagValue)
	L3PROP_DATETIME(CreateTime)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CLF_Temp_Control)

BEGIN_L3METHODMAP(CLF_Temp_Control,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Temp_Control,CL3Object)
END_L3EVENTSINK_MAP(CLF_Temp_Control)

CLF_Temp_Control::CLF_Temp_Control(void)
{
}

CLF_Temp_Control::~CLF_Temp_Control(void)
{
}
