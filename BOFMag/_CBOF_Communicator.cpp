// �߼���CBOF_CommunicatorԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_Communicator.h"

IMPLEMENT_L3CLASS(CBOF_Communicator,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Communicator,CL3Object)
END_L3PROPTABLE(CBOF_Communicator)

BEGIN_L3METHODMAP(CBOF_Communicator,CL3Object)
	L3_METHOD(CBOF_Communicator,"OnFeedIron",0,OnFeedIron,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnChangeStatus",0,OnChangeStatus,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnDischarge",0,OnDischarge,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnMeasureTemp",0,OnMeasureTemp,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnMeasureO2",0,OnMeasureO2,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnTapped",0,OnTapped,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnBottomBlow",0,OnBottomBlow,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnTopBlow",0,OnTopBlow,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnSauceEvent",0,OnSauceEvent,L3VT_BOOL,L3VTS_RECORDSET)
	L3_METHOD(CBOF_Communicator,"OnTapStart",0,OnTapStart,L3VT_BOOL,L3VTS_RECORDSET)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Communicator,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Communicator)

CBOF_Communicator::CBOF_Communicator(void)
{
}

CBOF_Communicator::~CBOF_Communicator(void)
{
}
