// �߼���CCCM_Heat_RemarkԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_Heat_Remark.h"

IMPLEMENT_L3CLASS(CCCM_Heat_Remark,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_Remark,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_STRING(TreatNo)
	L3PROP_SHORT(TypeID)
	L3PROP_STRING(Remark)
	L3PROP_DATETIME(Log_Time)
END_L3PROPTABLE(CCCM_Heat_Remark)

BEGIN_L3METHODMAP(CCCM_Heat_Remark,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_Remark,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_Remark)

CCCM_Heat_Remark::CCCM_Heat_Remark(void)
{
}

CCCM_Heat_Remark::~CCCM_Heat_Remark(void)
{
}
