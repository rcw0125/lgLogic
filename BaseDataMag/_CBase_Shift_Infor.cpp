// �߼���CBase_Shift_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Shift_Infor.h"

IMPLEMENT_L3CLASS(CBase_Shift_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Shift_Infor,CL3Object)
	L3PROP_STRING(Pk_Shift)
	L3PROP_STRING(Shift_Code)
	L3PROP_STRING(Shift_Name)
END_L3PROPTABLE(CBase_Shift_Infor)

BEGIN_L3METHODMAP(CBase_Shift_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Shift_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Shift_Infor)

CBase_Shift_Infor::CBase_Shift_Infor(void)
{
}

CBase_Shift_Infor::~CBase_Shift_Infor(void)
{
}
