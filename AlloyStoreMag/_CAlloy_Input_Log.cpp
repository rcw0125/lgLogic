// �߼���CAlloy_Input_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Input_Log.h"

IMPLEMENT_L3CLASS(CAlloy_Input_Log,MaterialInputLog,1)

BEGIN_L3PROPTABLE(CAlloy_Input_Log,MaterialInputLog)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Alloy_Code)
	L3PROP_STRING(Alloy_Confirm_Man)
	L3PROP_STRING(Shop_Confirm_Man)
END_L3PROPTABLE(CAlloy_Input_Log)

BEGIN_L3METHODMAP(CAlloy_Input_Log,MaterialInputLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Input_Log,MaterialInputLog)
END_L3EVENTSINK_MAP(CAlloy_Input_Log)

CAlloy_Input_Log::CAlloy_Input_Log(void)
{
}

CAlloy_Input_Log::~CAlloy_Input_Log(void)
{
}
