// �߼���CCCM_Mold_InTemp_CurveԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Mold_InTemp_Curve.h"

IMPLEMENT_L3CLASS(CCCM_Mold_InTemp_Curve,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Mold_InTemp_Curve,CL3Object)
	L3PROP_STRING(ObjectID)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(ValueID)
	L3PROP_DATETIME(Clock)
	L3PROP_DOUBLE(Val)
END_L3PROPTABLE(CCCM_Mold_InTemp_Curve)

BEGIN_L3METHODMAP(CCCM_Mold_InTemp_Curve,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Mold_InTemp_Curve,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Mold_InTemp_Curve)

CCCM_Mold_InTemp_Curve::CCCM_Mold_InTemp_Curve(void)
{
}

CCCM_Mold_InTemp_Curve::~CCCM_Mold_InTemp_Curve(void)
{
}
