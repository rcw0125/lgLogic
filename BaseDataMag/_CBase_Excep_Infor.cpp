// �߼���CBase_Excep_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Excep_Infor.h"

IMPLEMENT_L3CLASS(CBase_Excep_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Excep_Infor,CL3Object)
	L3PROP_STRING(Pk_Exception)
	L3PROP_STRING(Exception_Code)
	L3PROP_STRING(Exception_Name)
END_L3PROPTABLE(CBase_Excep_Infor)

BEGIN_L3METHODMAP(CBase_Excep_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Excep_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Excep_Infor)

CBase_Excep_Infor::CBase_Excep_Infor(void)
{
}

CBase_Excep_Infor::~CBase_Excep_Infor(void)
{
}
