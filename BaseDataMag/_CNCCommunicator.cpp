// �߼���CNCCommunicatorԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CNCCommunicator.h"

IMPLEMENT_L3CLASS(CNCCommunicator,CL3Object,1)

BEGIN_L3PROPTABLE(CNCCommunicator,CL3Object)
END_L3PROPTABLE(CNCCommunicator)

BEGIN_L3METHODMAP(CNCCommunicator,CL3Object)
	L3_METHOD(CNCCommunicator,"SendCastIronDataToNC",0,SendCastIronDataToNC,L3VT_LONG,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CNCCommunicator,CL3Object)
END_L3EVENTSINK_MAP(CNCCommunicator)

CNCCommunicator::CNCCommunicator(void)
{
}

CNCCommunicator::~CNCCommunicator(void)
{
}
