// �߼���CQA_Heat_Except_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Heat_Except_Code.h"

IMPLEMENT_L3CLASS(CQA_Heat_Except_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Heat_Except_Code,CL3Object)
	L3PROP_STRING(Exceptional_Code)
	L3PROP_STRING(Exceptional_Des)
	L3PROP_STRING(Unit)
	L3PROP_LONG(Auto_Judge_Flag)
END_L3PROPTABLE(CQA_Heat_Except_Code)

BEGIN_L3METHODMAP(CQA_Heat_Except_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Heat_Except_Code,CL3Object)
END_L3EVENTSINK_MAP(CQA_Heat_Except_Code)

CQA_Heat_Except_Code::CQA_Heat_Except_Code(void)
{
}

CQA_Heat_Except_Code::~CQA_Heat_Except_Code(void)
{
}
