// �߼���CXGMES_All_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_All_Code.h"

IMPLEMENT_L3CLASS(CBase_All_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_All_Code,CL3Object)
	L3PROP_STRING(Code)
	L3PROP_STRING(Code_Des)
	L3PROP_STRING(Code_Group)
	L3PROP_STRING(Code_Group_Des)
	L3PROP_STRING(Code_Val_Str)
	L3PROP_LONG(Code_Val_Long)
	L3PROP_DOUBLE(Code_Val_Double)
	L3PROP_STRING(Code_Function_Group)
	L3PROP_STRING(NC_Code)
END_L3PROPTABLE(CBase_All_Code)

BEGIN_L3METHODMAP(CBase_All_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_All_Code,CL3Object)
END_L3EVENTSINK_MAP(CBase_All_Code)

CBase_All_Code::CBase_All_Code(void)
{
}

CBase_All_Code::~CBase_All_Code(void)
{
}
