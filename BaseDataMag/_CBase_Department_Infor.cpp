// �߼���Department_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Department_Infor.h"

IMPLEMENT_L3CLASS(CBase_Department_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Department_Infor,CL3Object)
	L3PROP_STRING(Pk_Department)
	L3PROP_STRING(Department_Name)
	L3PROP_STRING(Department_Code)
END_L3PROPTABLE(CBase_Department_Infor)

BEGIN_L3METHODMAP(CBase_Department_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Department_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Department_Infor)

CBase_Department_Infor::CBase_Department_Infor(void)
{
}

CBase_Department_Infor::~CBase_Department_Infor(void)
{
}
