// �߼���CCCM_SmoothBlockԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CCCM_SmoothBlock.h"

IMPLEMENT_L3CLASS(CCCM_SmoothBlock,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_SmoothBlock,CL3Object)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandNo)
	L3PROP_STRING(BlockID)
	L3PROP_LONG(Block_Life)
	L3PROP_STRING(Factory)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(End_Time)
	L3PROP_STRING(Block_Size)
	L3PROP_STRING(Reason)
	L3PROP_STRING(HeatID)
END_L3PROPTABLE(CCCM_SmoothBlock)

BEGIN_L3METHODMAP(CCCM_SmoothBlock,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_SmoothBlock,CL3Object)
END_L3EVENTSINK_MAP(CCCM_SmoothBlock)

CCCM_SmoothBlock::CCCM_SmoothBlock(void)
{
}

CCCM_SmoothBlock::~CCCM_SmoothBlock(void)
{
}
