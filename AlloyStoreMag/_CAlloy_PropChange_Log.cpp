// �߼���CAlloy_PropChange_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_PropChange_Log.h"

IMPLEMENT_L3CLASS(CAlloy_PropChange_Log,MaterialPropLog,1)

BEGIN_L3PROPTABLE(CAlloy_PropChange_Log,MaterialPropLog)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CAlloy_PropChange_Log)

BEGIN_L3METHODMAP(CAlloy_PropChange_Log,MaterialPropLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_PropChange_Log,MaterialPropLog)
END_L3EVENTSINK_MAP(CAlloy_PropChange_Log)

CAlloy_PropChange_Log::CAlloy_PropChange_Log(void)
{
}

CAlloy_PropChange_Log::~CAlloy_PropChange_Log(void)
{
}
