// �߼���CBase_Wire_CoefficientԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Wire_Coefficient.h"

IMPLEMENT_L3CLASS(CBase_Wire_Coefficient,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Wire_Coefficient,CL3Object)
	L3PROP_STRING(WireCode)
	L3PROP_FLOAT(Coefficient)
END_L3PROPTABLE(CBase_Wire_Coefficient)

BEGIN_L3METHODMAP(CBase_Wire_Coefficient,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Wire_Coefficient,CL3Object)
END_L3EVENTSINK_MAP(CBase_Wire_Coefficient)

CBase_Wire_Coefficient::CBase_Wire_Coefficient(void)
{
}

CBase_Wire_Coefficient::~CBase_Wire_Coefficient(void)
{
}
