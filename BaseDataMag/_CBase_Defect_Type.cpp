// �߼���CBase_Defect_TypeԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Defect_Type.h"

IMPLEMENT_L3CLASS(CBase_Defect_Type,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Defect_Type,CL3Object)
	L3PROP_STRING(Pk_Defec_Type)
	L3PROP_STRING(Defect_Type_Code)
	L3PROP_STRING(Defect_Type_Name)
END_L3PROPTABLE(CBase_Defect_Type)

BEGIN_L3METHODMAP(CBase_Defect_Type,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Defect_Type,CL3Object)
END_L3EVENTSINK_MAP(CBase_Defect_Type)

CBase_Defect_Type::CBase_Defect_Type(void)
{
}

CBase_Defect_Type::~CBase_Defect_Type(void)
{
}
