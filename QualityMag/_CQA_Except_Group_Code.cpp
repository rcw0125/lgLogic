// �߼���CQA_Except_Group_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Except_Group_Code.h"

IMPLEMENT_L3CLASS(CQA_Except_Group_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Except_Group_Code,CL3Object)
	L3PROP_STRING(Code)
	L3PROP_STRING(Des)
END_L3PROPTABLE(CQA_Except_Group_Code)

BEGIN_L3METHODMAP(CQA_Except_Group_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Except_Group_Code,CL3Object)
END_L3EVENTSINK_MAP(CQA_Except_Group_Code)

CQA_Except_Group_Code::CQA_Except_Group_Code(void)
{
}

CQA_Except_Group_Code::~CQA_Except_Group_Code(void)
{
}
