// �߼���CBase_Error_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Error_Code.h"

IMPLEMENT_L3CLASS(CBase_Error_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Error_Code,CL3Object)
	L3PROP_STRING(Error_Code)
	L3PROP_STRING(Error_Des)
	L3PROP_STRING(Owner)
	L3PROP_STRING(Owner_Des)
	L3PROP_STRING(Error_Val_Long)
END_L3PROPTABLE(CBase_Error_Code)

BEGIN_L3METHODMAP(CBase_Error_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Error_Code,CL3Object)
END_L3EVENTSINK_MAP(CBase_Error_Code)

CBase_Error_Code::CBase_Error_Code(void)
{
}

CBase_Error_Code::~CBase_Error_Code(void)
{
}
