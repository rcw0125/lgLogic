// �߼���CSrap_CodeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CSrap_Code.h"

IMPLEMENT_L3CLASS(CSrap_Code,CL3Object,1)

BEGIN_L3PROPTABLE(CSrap_Code,CL3Object)
	L3PROP_STRING(Scrap_Code)
	L3PROP_STRING(Scrap_Des)
END_L3PROPTABLE(CSrap_Code)

BEGIN_L3METHODMAP(CSrap_Code,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CSrap_Code,CL3Object)
END_L3EVENTSINK_MAP(CSrap_Code)

CSrap_Code::CSrap_Code(void)
{
}

CSrap_Code::~CSrap_Code(void)
{
}
