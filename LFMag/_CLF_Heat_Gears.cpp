// �߼���CLF_Heat_GearsԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_Heat_Gears.h"

IMPLEMENT_L3CLASS(CLF_Heat_Gears,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_Heat_Gears,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_LONG(Gears)
	L3PROP_DATETIME(LogTime)
END_L3PROPTABLE(CLF_Heat_Gears)

BEGIN_L3METHODMAP(CLF_Heat_Gears,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_Heat_Gears,CL3Object)
END_L3EVENTSINK_MAP(CLF_Heat_Gears)

CLF_Heat_Gears::CLF_Heat_Gears(void)
{
}

CLF_Heat_Gears::~CLF_Heat_Gears(void)
{
}
