// �߼���CScrapOutStoreDetailԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CScrapOutStoreDetail.h"

IMPLEMENT_L3CLASS(CScrapOutStoreDetail,CL3Object,1)

BEGIN_L3PROPTABLE(CScrapOutStoreDetail,CL3Object)
	L3PROP_STRING(SCRAP_SLOT_ID)
	L3PROP_STRING(MATERIAL)
	L3PROP_STRING(MATERIAL_CODE)
	L3PROP_STRING(AMOUNT)
END_L3PROPTABLE(CScrapOutStoreDetail)

BEGIN_L3METHODMAP(CScrapOutStoreDetail,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CScrapOutStoreDetail,CL3Object)
END_L3EVENTSINK_MAP(CScrapOutStoreDetail)

CScrapOutStoreDetail::CScrapOutStoreDetail(void)
{
}

CScrapOutStoreDetail::~CScrapOutStoreDetail(void)
{
}
