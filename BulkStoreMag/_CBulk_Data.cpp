// �߼���CBulk_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_Data.h"

IMPLEMENT_L3CLASS(CBulk_Data,Material,1)

BEGIN_L3PROPTABLE(CBulk_Data,Material)
	L3PROP_STRING(Bulk_Destination)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(Bulk_Code)
	L3PROP_DOUBLE(Amount)
END_L3PROPTABLE(CBulk_Data)

BEGIN_L3METHODMAP(CBulk_Data,Material)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Data,Material)
END_L3EVENTSINK_MAP(CBulk_Data)

CBulk_Data::CBulk_Data(void)
{
}

CBulk_Data::~CBulk_Data(void)
{
}
