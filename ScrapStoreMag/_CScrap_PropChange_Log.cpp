// �߼���CScrap_PropChange_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CScrap_PropChange_Log.h"

IMPLEMENT_L3CLASS(CScrap_PropChange_Log,MaterialPropLog,1)

BEGIN_L3PROPTABLE(CScrap_PropChange_Log,MaterialPropLog)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CScrap_PropChange_Log)

BEGIN_L3METHODMAP(CScrap_PropChange_Log,MaterialPropLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrap_PropChange_Log,MaterialPropLog)
END_L3EVENTSINK_MAP(CScrap_PropChange_Log)

CScrap_PropChange_Log::CScrap_PropChange_Log(void)
{
}

CScrap_PropChange_Log::~CScrap_PropChange_Log(void)
{
}
