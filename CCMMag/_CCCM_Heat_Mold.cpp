// �߼���CCCM_Heat_MoldԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Mold.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Mold,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Mold,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_SHORT(StrandID)
	L3PROP_FLOAT(Flow)
	L3PROP_FLOAT(Wide_Flow)
	L3PROP_FLOAT(Narrow_Flow)
	L3PROP_SHORT(In_Temp)
	L3PROP_SHORT(Out_Temp)
	L3PROP_SHORT(Diff_Temp)
END_L3PROPTABLE(CCCM_Heat_Mold)

BEGIN_L3METHODMAP(CCCM_Heat_Mold,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Mold,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Mold)

CCCM_Heat_Mold::CCCM_Heat_Mold(void)
{
}

CCCM_Heat_Mold::~CCCM_Heat_Mold(void)
{
}
