// �߼���CPlan_BOF_StatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CPlan_BOF_Status.h"

IMPLEMENT_L3CLASS(CPlan_BOF_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CPlan_BOF_Status,CL3Object)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Status)
	L3PROP_SHORT(New_BOF_Flag)
END_L3PROPTABLE(CPlan_BOF_Status)

BEGIN_L3METHODMAP(CPlan_BOF_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_BOF_Status,CL3Object)
END_L3EVENTSINK_MAP(CPlan_BOF_Status)

CPlan_BOF_Status::CPlan_BOF_Status(void)
{
}

CPlan_BOF_Status::~CPlan_BOF_Status(void)
{
}
