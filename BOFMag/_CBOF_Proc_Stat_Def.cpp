// �߼���CBOF_Proc_Stat_DefԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_Proc_Stat_Def.h"

IMPLEMENT_L3CLASS(CBOF_Proc_Stat_Def,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Proc_Stat_Def,CL3Object)
	L3PROP_SHORT(Status)
	L3PROP_STRING(Descr)
END_L3PROPTABLE(CBOF_Proc_Stat_Def)

BEGIN_L3METHODMAP(CBOF_Proc_Stat_Def,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Proc_Stat_Def,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Proc_Stat_Def)

CBOF_Proc_Stat_Def::CBOF_Proc_Stat_Def(void)
{
}

CBOF_Proc_Stat_Def::~CBOF_Proc_Stat_Def(void)
{
}
