// �߼���CQA_Operate_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Operate_Log.h"

IMPLEMENT_L3CLASS(CQA_Operate_Log,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Operate_Log,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(ActionCode)
	L3PROP_STRING(Shift)
	L3PROP_STRING(Team)
	L3PROP_STRING(Operator)
	L3PROP_DATETIME(OpeateTime)
END_L3PROPTABLE(CQA_Operate_Log)

BEGIN_L3METHODMAP(CQA_Operate_Log,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Operate_Log,CL3Object)
END_L3EVENTSINK_MAP(CQA_Operate_Log)

CQA_Operate_Log::CQA_Operate_Log(void)
{
}

CQA_Operate_Log::~CQA_Operate_Log(void)
{
}
