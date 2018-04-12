// �߼���CAlloy_Pos_Change_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Trans_Log.h"

IMPLEMENT_L3CLASS(CAlloy_Trans_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Trans_Log,CL3Object)

	L3PROP_STRING(SourceID)
	L3PROP_STRING(TargetID)
	L3PROP_STRING(MaterialID)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Alloy_Code)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(TeamID)
	L3PROP_STRING(ShiftID)
	L3PROP_DATETIME(Trans_Date)
	L3PROP_STRING(Operator)

END_L3PROPTABLE(CAlloy_Trans_Log)

BEGIN_L3METHODMAP(CAlloy_Trans_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Trans_Log,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Trans_Log)

CAlloy_Trans_Log::CAlloy_Trans_Log(void)
{
}

CAlloy_Trans_Log::~CAlloy_Trans_Log(void)
{
}
