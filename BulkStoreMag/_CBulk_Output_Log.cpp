// �߼���CBulk_Output_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_Output_Log.h"

IMPLEMENT_L3CLASS(CBulk_Output_Log,MaterialOutputLog,1)

BEGIN_L3PROPTABLE(CBulk_Output_Log,MaterialOutputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CBulk_Output_Log)

BEGIN_L3METHODMAP(CBulk_Output_Log,MaterialOutputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Output_Log,MaterialOutputLog)
END_L3EVENTSINK_MAP(CBulk_Output_Log)

CBulk_Output_Log::CBulk_Output_Log(void)
{
}

CBulk_Output_Log::~CBulk_Output_Log(void)
{
}
