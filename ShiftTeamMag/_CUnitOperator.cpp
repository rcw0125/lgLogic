// �߼���UnitOperatorԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CUnitOperator.h"

IMPLEMENT_L3CLASS(CUnitOperator,CL3Object,1)

BEGIN_L3PROPTABLE(CUnitOperator,CL3Object)
	L3PROP_SHORT(L3Index)				//����
	L3PROP_STRING(UnitIndex)			//����+��λ
	L3PROP_STRING(Operator)			//������
END_L3PROPTABLE(CUnitOperator)

BEGIN_L3METHODMAP(CUnitOperator,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CUnitOperator,CL3Object)
END_L3EVENTSINK_MAP(CUnitOperator)

CUnitOperator::CUnitOperator(void)
{
}

CUnitOperator::~CUnitOperator(void)
{
}
