// �߼���CBase_Check_Item_InforԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Check_Item_Infor.h"

IMPLEMENT_L3CLASS(CBase_Check_Item_Infor,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Check_Item_Infor,CL3Object)
	L3PROP_STRING(Pk_Check_Item)
	L3PROP_STRING(Check_Item_Code)
	L3PROP_STRING(Check_Item_Name)
	L3PROP_STRING(Check_Unit_Id)
END_L3PROPTABLE(CBase_Check_Item_Infor)

BEGIN_L3METHODMAP(CBase_Check_Item_Infor,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Check_Item_Infor,CL3Object)
END_L3EVENTSINK_MAP(CBase_Check_Item_Infor)

CBase_Check_Item_Infor::CBase_Check_Item_Infor(void)
{
}

CBase_Check_Item_Infor::~CBase_Check_Item_Infor(void)
{
}
