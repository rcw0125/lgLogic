// �߼���CDeS_Process_SatusԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDeS_Process_Satus.h"

IMPLEMENT_L3CLASS(CDeS_Process_Satus,CL3Object,1)

BEGIN_L3PROPTABLE(CDeS_Process_Satus,CL3Object)
L3PROP_STRING(ID_Object)
L3PROP_SHORT(Status)
L3PROP_DATETIME(Change_Time)
END_L3PROPTABLE(CDeS_Process_Satus)

BEGIN_L3METHODMAP(CDeS_Process_Satus,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDeS_Process_Satus,CL3Object)
END_L3EVENTSINK_MAP(CDeS_Process_Satus)

CDeS_Process_Satus::CDeS_Process_Satus(void)
{
}

CDeS_Process_Satus::~CDeS_Process_Satus(void)
{
}
