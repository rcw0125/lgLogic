// �߼���CCCM_Heat_HoldTempMatԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_HoldTempMat.h"

IMPLEMENT_L3CLASS(CCCM_Heat_HoldTempMat,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_HoldTempMat,CL3Object)
	///2009-02-13 ������κš�ʹ�����
	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_STRING(Element)
	L3PROP_FLOAT(Weight)
	L3PROP_STRING(Origin)
	L3PROP_STRING(Batch_ID)
	L3PROP_STRING(UseInformation)
END_L3PROPTABLE(CCCM_Heat_HoldTempMat)

BEGIN_L3METHODMAP(CCCM_Heat_HoldTempMat,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_HoldTempMat,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_HoldTempMat)

CCCM_Heat_HoldTempMat::CCCM_Heat_HoldTempMat(void)
{
}

CCCM_Heat_HoldTempMat::~CCCM_Heat_HoldTempMat(void)
{
}
