// �߼���CQA_Lab_Sheet_AppIDԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CQA_Lab_Sheet_AppID.h"

IMPLEMENT_L3CLASS(CQA_Lab_Sheet_AppID,CL3Object,1)

BEGIN_L3PROPTABLE(CQA_Lab_Sheet_AppID,CL3Object)
	L3PROP_STRING(AppID)
	L3PROP_STRING(Sample_Address)
END_L3PROPTABLE(CQA_Lab_Sheet_AppID)

BEGIN_L3METHODMAP(CQA_Lab_Sheet_AppID,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CQA_Lab_Sheet_AppID,CL3Object)
END_L3EVENTSINK_MAP(CQA_Lab_Sheet_AppID)

CQA_Lab_Sheet_AppID::CQA_Lab_Sheet_AppID(void)
{
}

CQA_Lab_Sheet_AppID::~CQA_Lab_Sheet_AppID(void)
{
}
