// �߼���CAlloy_Output_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Output_Log.h"

IMPLEMENT_L3CLASS(CAlloy_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CAlloy_Output_Log,MaterialOutputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Alloy_Code)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CAlloy_Output_Log)

BEGIN_L3METHODMAP(CAlloy_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CAlloy_Output_Log)

CAlloy_Output_Log::CAlloy_Output_Log(void)
{
}

CAlloy_Output_Log::~CAlloy_Output_Log(void)
{
}
