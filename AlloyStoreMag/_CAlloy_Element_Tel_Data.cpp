// �߼���CAlloy_Element_Tel_DataԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CAlloy_Element_Tel_Data.h"

IMPLEMENT_L3CLASS(CAlloy_Element_Tel_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CAlloy_Element_Tel_Data,CL3Object)
	L3PROP_DATETIME(Rec_Time)
	L3PROP_STRING(vstobatchcode)
	L3PROP_STRING(vcheckbillcode)
	L3PROP_STRING(bcompcheck)
	L3PROP_LONG(ninassistnum)
	L3PROP_STRING(cstoreorganization)
	L3PROP_STRING(cpraycorp)
	L3PROP_STRING(ccheckbillid)
	L3PROP_STRING(cbaseid)
	L3PROP_STRING(vsamplecode)
	L3PROP_STRING(ninnum)
	L3PROP_STRING(ccheckitemid)
	L3PROP_DOUBLE(cresult)
END_L3PROPTABLE(CAlloy_Element_Tel_Data)

BEGIN_L3METHODMAP(CAlloy_Element_Tel_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CAlloy_Element_Tel_Data,CL3Object)
END_L3EVENTSINK_MAP(CAlloy_Element_Tel_Data)

CAlloy_Element_Tel_Data::CAlloy_Element_Tel_Data(void)
{
}

CAlloy_Element_Tel_Data::~CAlloy_Element_Tel_Data(void)
{
}
