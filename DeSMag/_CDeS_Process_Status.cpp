// �߼���CDeS_Process_StatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDeS_Process_Status.h"

IMPLEMENT_L3CLASS(CDeS_Process_Status,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Process_Status,CL3Object)
L3PROP_STRING(ID_Object)
L3PROP_SHORT(Status)
L3PROP_DATETIME(Change_Time)
L3PROP_STRING(AreaID)
END_L3PROPTABLE(CDeS_Process_Status)

BEGIN_L3METHODMAP(CDeS_Process_Status,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Process_Status,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Process_Status)

CDeS_Process_Status::CDeS_Process_Status(void)
{
}

CDeS_Process_Status::~CDeS_Process_Status(void)
{
}
