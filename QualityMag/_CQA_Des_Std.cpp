// �߼���CQA_Des_StdԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Des_Std.h"

IMPLEMENT_L3CLASS(CQA_Des_Std,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Des_Std,CL3Object)
	L3PROP_LONG(Des_Proc_Mod)
	L3PROP_DATETIME(Valid_Date)
	L3PROP_DOUBLE(S)
	L3PROP_DOUBLE(Weight)
END_L3PROPTABLE(CQA_Des_Std)

BEGIN_L3METHODMAP(CQA_Des_Std,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Des_Std,CL3Object)
END_L3EVENTSINK_MAP(CQA_Des_Std)

CQA_Des_Std::CQA_Des_Std(void)
{
}

CQA_Des_Std::~CQA_Des_Std(void)
{
}
