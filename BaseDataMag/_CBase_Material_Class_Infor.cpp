// �߼���CBase_Material_Class_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Material_Class_Infor.h"

IMPLEMENT_L3CLASS(CBase_Material_Class_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Material_Class_Infor,CL3Object)
    L3PROP_STRING(Pk_Material_Class)
	L3PROP_STRING(Material_Class_Code)
	L3PROP_STRING(Material_Class_Name)
	L3PROP_STRING(End_Flag)
END_L3PROPTABLE(CBase_Material_Class_Infor)

BEGIN_L3METHODMAP(CBase_Material_Class_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Material_Class_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Material_Class_Infor)

CBase_Material_Class_Infor::CBase_Material_Class_Infor(void)
{
}

CBase_Material_Class_Infor::~CBase_Material_Class_Infor(void)
{
}
