// �߼���CBOF_ReturnSteelԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_ReturnSteel.h"

IMPLEMENT_L3CLASS(CBOF_ReturnSteel,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_ReturnSteel,CL3Object)
	L3PROP_STRING(HeatID)
	L3PROP_DOUBLE(Return_Steel_Weight)
END_L3PROPTABLE(CBOF_ReturnSteel)

BEGIN_L3METHODMAP(CBOF_ReturnSteel,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_ReturnSteel,CL3Object)
END_L3EVENTSINK_MAP(CBOF_ReturnSteel)

CBOF_ReturnSteel::CBOF_ReturnSteel(void)
{
}

CBOF_ReturnSteel::~CBOF_ReturnSteel(void)
{
}
