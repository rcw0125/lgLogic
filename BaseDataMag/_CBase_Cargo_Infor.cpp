// �߼���CBase_Cargo_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Cargo_Infor.h"

IMPLEMENT_L3CLASS(CBase_Cargo_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Cargo_Infor,CL3Object)
    L3PROP_STRING(Pk_Cargo)
	L3PROP_STRING(Cargo_Code)
	L3PROP_STRING(Carge_name)
	L3PROP_STRING(Pk_Stock)
END_L3PROPTABLE(CBase_Cargo_Infor)

BEGIN_L3METHODMAP(CBase_Cargo_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Cargo_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Cargo_Infor)

CBase_Cargo_Infor::CBase_Cargo_Infor(void)
{
}

CBase_Cargo_Infor::~CBase_Cargo_Infor(void)
{
}
