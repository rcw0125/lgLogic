// �߼���Stock_Base_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Stock_Infor.h"

IMPLEMENT_L3CLASS(CBase_Stock_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Stock_Infor,CL3Object)
	L3PROP_STRING(Pk_Stock)
	L3PROP_STRING(Stock_Code)
	L3PROP_STRING(Stock_Name)
END_L3PROPTABLE(CBase_Stock_Infor)

BEGIN_L3METHODMAP(CBase_Stock_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Stock_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Stock_Infor)

CBase_Stock_Infor::CBase_Stock_Infor(void)
{
}

CBase_Stock_Infor::~CBase_Stock_Infor(void)
{
}
