// �߼���CLF_HeatRemarkԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLF_HeatRemark.h"

IMPLEMENT_L3CLASS(CLF_HeatRemark,CL3Object,1)

BEGIN_L3PROPTABLE(CLF_HeatRemark,CL3Object)
	L3PROP_STRING(TreatNo)
	L3PROP_STRING(HeatID)
	L3PROP_SHORT(Type)
	L3PROP_STRING(Remark)
	L3PROP_DATETIME(LogTime)
END_L3PROPTABLE(CLF_HeatRemark)

BEGIN_L3METHODMAP(CLF_HeatRemark,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLF_HeatRemark,CL3Object)
END_L3EVENTSINK_MAP(CLF_HeatRemark)

CLF_HeatRemark::CLF_HeatRemark(void)
{
}

CLF_HeatRemark::~CLF_HeatRemark(void)
{
}
