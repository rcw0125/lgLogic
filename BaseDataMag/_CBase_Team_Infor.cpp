// �߼���Team_Base_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Team_Infor.h"

IMPLEMENT_L3CLASS(CBase_Team_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Team_Infor,CL3Object)
	L3PROP_STRING(Pk_Team)
	L3PROP_STRING(Team_Code)
	L3PROP_STRING(Team_Name)
	L3PROP_STRING(Pk_Center)
	L3PROP_STRING(Pk_Department)
END_L3PROPTABLE(CBase_Team_Infor)

BEGIN_L3METHODMAP(CBase_Team_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Team_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Team_Infor)

CBase_Team_Infor::CBase_Team_Infor(void)
{
}

CBase_Team_Infor::~CBase_Team_Infor(void)
{
}
