// �߼���CBOF_Remark_TypeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBOF_Remark_Type.h"

IMPLEMENT_L3CLASS(CBOF_Remark_Type,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Remark_Type,CL3Object)
	L3PROP_SHORT(TypeID)
	L3PROP_STRING(TypeDes)
END_L3PROPTABLE(CBOF_Remark_Type)

BEGIN_L3METHODMAP(CBOF_Remark_Type,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Remark_Type,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Remark_Type)

CBOF_Remark_Type::CBOF_Remark_Type(void)
{
}

CBOF_Remark_Type::~CBOF_Remark_Type(void)
{
}
