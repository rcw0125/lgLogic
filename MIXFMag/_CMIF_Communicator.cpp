// �߼���CMIF_CommunicatorԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMIF_Communicator.h"

IMPLEMENT_L3CLASS(CMIF_Communicator,CL3Object,1)

BEGIN_L3PROPTABLE(CMIF_Communicator,CL3Object)
END_L3PROPTABLE(CMIF_Communicator)

BEGIN_L3METHODMAP(CMIF_Communicator,CL3Object)
	L3_METHOD(CMIF_Communicator,"OnMIFTemperature",0,OnMIFTemperature,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CMIF_Communicator,"OnWeight",0,OnWeight,L3VT_BOOL,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Communicator,CL3Object)
END_L3EVENTSINK_MAP(CMIF_Communicator)

CMIF_Communicator::CMIF_Communicator(void)
{
}

CMIF_Communicator::~CMIF_Communicator(void)
{
}
