// �߼���CMold_BaseԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMold_Base.h"

IMPLEMENT_L3CLASS(CMold_Base,CL3Object,1)

BEGIN_L3PROPTABLE(CMold_Base,CL3Object)
	L3PROP_STRING(MoldID)
	L3PROP_DOUBLE(Break_Face_Mea)
	L3PROP_STRING(Status)
	L3PROP_STRING(Cast_ID)
	L3PROP_STRING(FlowID)
	L3PROP_STRING(Copper_Fac)
	L3PROP_STRING(Copper_ID)
	L3PROP_STRING(InStallID)
	L3PROP_STRING(UnitID)
END_L3PROPTABLE(CMold_Base)

BEGIN_L3METHODMAP(CMold_Base,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMold_Base,CL3Object)
END_L3EVENTSINK_MAP(CMold_Base)

CMold_Base::CMold_Base(void)
{
}

CMold_Base::~CMold_Base(void)
{
}
