// �߼���CAlloy_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Code.h"

IMPLEMENT_L3CLASS(CAlloy_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Code,CL3Object)
	L3PROP_STRING(Alloy_Code)
	L3PROP_STRING(Alloy_Des)
END_L3PROPTABLE(CAlloy_Code)

BEGIN_L3METHODMAP(CAlloy_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Code,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Code)

CAlloy_Code::CAlloy_Code(void)
{
}

CAlloy_Code::~CAlloy_Code(void)
{
}
