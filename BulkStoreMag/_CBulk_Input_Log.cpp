// �߼���CBulk_Input_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_Input_Log.h"

IMPLEMENT_L3CLASS(CBulk_Input_Log,MaterialInputLog,1)

BEGIN_L3PROPTABLE(CBulk_Input_Log,MaterialInputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_STRING(Bulk_Confirm_Man)
	L3PROP_STRING(Shop_Confirm_Man)
END_L3PROPTABLE(CBulk_Input_Log)

BEGIN_L3METHODMAP(CBulk_Input_Log,MaterialInputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Input_Log,MaterialInputLog)
END_L3EVENTSINK_MAP(CBulk_Input_Log)

CBulk_Input_Log::CBulk_Input_Log(void)
{
}

CBulk_Input_Log::~CBulk_Input_Log(void)
{
}
