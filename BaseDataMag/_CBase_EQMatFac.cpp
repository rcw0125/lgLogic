// �߼���CBase_EQMatFacԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_EQMatFac.h"

IMPLEMENT_L3CLASS(CBase_EQMatFac,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_EQMatFac,CL3Object)
	L3PROP_STRING(MatFactory)
	L3PROP_STRING(MatName)
	L3PROP_STRING(MatGroup_Code)
	L3PROP_STRING(MatGroup_Des)
END_L3PROPTABLE(CBase_EQMatFac)

BEGIN_L3METHODMAP(CBase_EQMatFac,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_EQMatFac,CL3Object)
END_L3EVENTSINK_MAP(CBase_EQMatFac)

CBase_EQMatFac::CBase_EQMatFac(void)
{
}

CBase_EQMatFac::~CBase_EQMatFac(void)
{
}
