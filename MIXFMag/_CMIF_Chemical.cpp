// �߼���CMIF_ChemicalԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMIF_Chemical.h"

IMPLEMENT_L3CLASS(CMIF_Chemical,CL3Object,1)

BEGIN_L3PROPTABLE(CMIF_Chemical,CL3Object)
	L3PROP_DATETIME(Sample_Time)
	L3PROP_DOUBLE(C)
	L3PROP_DOUBLE(Si)
	L3PROP_DOUBLE(Mn)
	L3PROP_DOUBLE(S)
	L3PROP_DOUBLE(P)
	L3PROP_DOUBLE(Ti)
	L3PROP_SHORT(Mode)
	L3PROP_SHORT(Used_Flag)
	L3PROP_SHORT(Shift)
	L3PROP_SHORT(Team)
END_L3PROPTABLE(CMIF_Chemical)

BEGIN_L3METHODMAP(CMIF_Chemical,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMIF_Chemical,CL3Object)
END_L3EVENTSINK_MAP(CMIF_Chemical)

CMIF_Chemical::CMIF_Chemical(void)
{
}

CMIF_Chemical::~CMIF_Chemical(void)
{
}
