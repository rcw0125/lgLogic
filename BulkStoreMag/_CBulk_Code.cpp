// �߼���CBulk_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBulk_Code.h"

IMPLEMENT_L3CLASS(CBulk_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CBulk_Code,CL3Object)
	L3PROP_STRING(Bulk_Code)
	L3PROP_STRING(Bulk_Des)
	L3PROP_DOUBLE(Amount)
END_L3PROPTABLE(CBulk_Code)

BEGIN_L3METHODMAP(CBulk_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBulk_Code,CL3Object)
END_L3EVENTSINK_MAP(CBulk_Code)

CBulk_Code::CBulk_Code(void)
{
}

CBulk_Code::~CBulk_Code(void)
{
}
