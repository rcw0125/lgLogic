// �߼���CMIF_Feed_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMIF_Feed_Log.h"

IMPLEMENT_L3CLASS(CMIF_Feed_Log,UnitFeedingLog,1)

BEGIN_L3PROPTABLE(CMIF_Feed_Log,UnitFeedingLog)
	L3PROP_STRING(MIFID)
	L3PROP_STRING(BFID)
	L3PROP_STRING(TAP_No)
	L3PROP_STRING(TPC_No)
END_L3PROPTABLE(CMIF_Feed_Log)

BEGIN_L3METHODMAP(CMIF_Feed_Log,UnitFeedingLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Feed_Log,UnitFeedingLog)
END_L3EVENTSINK_MAP(CMIF_Feed_Log)

CMIF_Feed_Log::CMIF_Feed_Log(void)
{
}

CMIF_Feed_Log::~CMIF_Feed_Log(void)
{
}
