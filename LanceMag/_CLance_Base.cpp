// �߼���CLance_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CLance_Base.h"

IMPLEMENT_L3CLASS(CLance_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CLance_Base,CL3Object)
	L3PROP_STRING(LanceID)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(Status)
	L3PROP_STRING(Nozzle_Factury)
	L3PROP_STRING(Lance_Head_Type)
	L3PROP_LONG(Lance_Age)
	L3PROP_STRING(MakeID)
	L3PROP_DATETIME(Make_Start_Time)
	L3PROP_DATETIME(Make_End_Time)
END_L3PROPTABLE(CLance_Base)

BEGIN_L3METHODMAP(CLance_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CLance_Base,CL3Object)
END_L3EVENTSINK_MAP(CLance_Base)

CLance_Base::CLance_Base(void)
{
}

CLance_Base::~CLance_Base(void)
{
}
