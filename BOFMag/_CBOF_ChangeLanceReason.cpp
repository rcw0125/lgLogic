// �߼���CBOF_ChangeLanceReasonԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_ChangeLanceReason.h"

IMPLEMENT_L3CLASS(CBOF_ChangeLanceReason,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_ChangeLanceReason,CL3Object)
	L3PROP_SHORT(BOFID)
	L3PROP_DATETIME(ChangeLance_Time)
	L3PROP_STRING(Reason)
END_L3PROPTABLE(CBOF_ChangeLanceReason)

BEGIN_L3METHODMAP(CBOF_ChangeLanceReason,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_ChangeLanceReason,CL3Object)
END_L3EVENTSINK_MAP(CBOF_ChangeLanceReason)

CBOF_ChangeLanceReason::CBOF_ChangeLanceReason(void)
{
}

CBOF_ChangeLanceReason::~CBOF_ChangeLanceReason(void)
{
}
