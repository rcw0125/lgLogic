// �߼���CBulk_PropChange_LogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_PropChange_Log.h"

IMPLEMENT_L3CLASS(CBulk_PropChange_Log,MaterialPropLog,1)

BEGIN_L3PROPTABLE(CBulk_PropChange_Log,MaterialPropLog)
	L3PROP_DOUBLE(Amount)
	L3PROP_STRING(Operator)
END_L3PROPTABLE(CBulk_PropChange_Log)

BEGIN_L3METHODMAP(CBulk_PropChange_Log,MaterialPropLog)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_PropChange_Log,MaterialPropLog)
END_L3EVENTSINK_MAP(CBulk_PropChange_Log)

CBulk_PropChange_Log::CBulk_PropChange_Log(void)
{
}

CBulk_PropChange_Log::~CBulk_PropChange_Log(void)
{
}
