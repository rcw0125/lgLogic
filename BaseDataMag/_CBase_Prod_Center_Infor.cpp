// �߼���Produce_Center_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Prod_Center_Infor.h"

IMPLEMENT_L3CLASS(CBase_Prod_Center_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Prod_Center_Infor,CL3Object)
	L3PROP_STRING(Pk_Center)
	L3PROP_STRING(Center_Name)
	L3PROP_STRING(Center_Code)
	L3PROP_STRING(Pk_Department)
END_L3PROPTABLE(CBase_Prod_Center_Infor)

BEGIN_L3METHODMAP(CBase_Prod_Center_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Prod_Center_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Prod_Center_Infor)

CBase_Prod_Center_Infor::CBase_Prod_Center_Infor(void)
{
}

CBase_Prod_Center_Infor::~CBase_Prod_Center_Infor(void)
{
}
