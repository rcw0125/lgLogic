// �߼���CBase_Address_Bulk_RelationԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Address_Bulk_Relation.h"

IMPLEMENT_L3CLASS(CBase_Address_Bulk_Relation,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Address_Bulk_Relation,CL3Object)
	L3PROP_STRING(PLC_Address)
	L3PROP_STRING(Area)
END_L3PROPTABLE(CBase_Address_Bulk_Relation)

BEGIN_L3METHODMAP(CBase_Address_Bulk_Relation,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Address_Bulk_Relation,CL3Object)
END_L3EVENTSINK_MAP(CBase_Address_Bulk_Relation)

CBase_Address_Bulk_Relation::CBase_Address_Bulk_Relation(void)
{
}

CBase_Address_Bulk_Relation::~CBase_Address_Bulk_Relation(void)
{
}
