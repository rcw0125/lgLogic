// �߼���CStoreOperateLogԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CStoreOperateLog.h"

IMPLEMENT_L3CLASS(CStoreOperateLog,CL3Object,1)

BEGIN_L3PROPTABLE(CStoreOperateLog,CL3Object)
	L3PROP_STRING(StoreID)
	L3PROP_STRING(BeforeMaterialID)
	L3PROP_STRING(BeforMaterialName)
	L3PROP_STRING(OperateMode)
	L3PROP_STRING(Operater)
	L3PROP_STRING(OperatorTime)
	L3PROP_STRING(AfterMaterialID)
	L3PROP_STRING(AfterMaterialName)
	L3PROP_STRING(BeforeWeight)
	L3PROP_STRING(AfterWeight)
END_L3PROPTABLE(CStoreOperateLog)

BEGIN_L3METHODMAP(CStoreOperateLog,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CStoreOperateLog,CL3Object)
END_L3EVENTSINK_MAP(CStoreOperateLog)

CStoreOperateLog::CStoreOperateLog(void)
{
}

CStoreOperateLog::~CStoreOperateLog(void)
{
}
