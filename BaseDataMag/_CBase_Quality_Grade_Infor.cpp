// �߼���Quality_Grade_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Quality_Grade_Infor.h"

IMPLEMENT_L3CLASS(CBase_Quality_Grade_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Quality_Grade_Infor,CL3Object)
	L3PROP_STRING(Pk_Qua_Grade)
	L3PROP_STRING(Qua_Grade_Name)
	L3PROP_STRING(Qua_Grade_Code)
	L3PROP_STRING(Qualified)
	L3PROP_STRING(Pk_Qua_Grade_Group)
END_L3PROPTABLE(CBase_Quality_Grade_Infor)

BEGIN_L3METHODMAP(CBase_Quality_Grade_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Quality_Grade_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Quality_Grade_Infor)

CBase_Quality_Grade_Infor::CBase_Quality_Grade_Infor(void)
{
}

CBase_Quality_Grade_Infor::~CBase_Quality_Grade_Infor(void)
{
}
