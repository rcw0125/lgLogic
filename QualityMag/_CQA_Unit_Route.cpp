// �߼���CQA_Unit_RouteԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Unit_Route.h"

IMPLEMENT_L3CLASS(CQA_Unit_Route,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Unit_Route,CL3Object)
	L3PROP_LONG(Lev_Type)
	L3PROP_STRING(BOFID)
	L3PROP_STRING(LFID)
	L3PROP_STRING(RHID)
	L3PROP_STRING(CasterID)
END_L3PROPTABLE(CQA_Unit_Route)

BEGIN_L3METHODMAP(CQA_Unit_Route,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Unit_Route,CL3Object)
END_L3EVENTSINK_MAP(CQA_Unit_Route)

CQA_Unit_Route::CQA_Unit_Route(void)
{
}

CQA_Unit_Route::~CQA_Unit_Route(void)
{
}
