// �߼���CDisp_AccountԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CDisp_Account.h"

IMPLEMENT_L3CLASS(CDisp_Account,CL3Object,1)

BEGIN_L3PROPTABLE(CDisp_Account,CL3Object)
	L3PROP_STRING(ProductDate)
	L3PROP_STRING(UnitID)
	L3PROP_STRING(Team)
	L3PROP_STRING(AccountType)
	L3PROP_LONG(AccountCount)
	L3PROP_STRING(AccountReason)
	L3PROP_STRING(Responsibility_Organ)
	L3PROP_DATETIME(CreateTime)
	L3PROP_DOUBLE(AccountAmount)
END_L3PROPTABLE(CDisp_Account)

BEGIN_L3METHODMAP(CDisp_Account,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CDisp_Account,CL3Object)
END_L3EVENTSINK_MAP(CDisp_Account)

CDisp_Account::CDisp_Account(void)
{
}

CDisp_Account::~CDisp_Account(void)
{
}
