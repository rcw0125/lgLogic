// �߼���CBase_NC_Steel_MaterialԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CBase_Steel_Mat_Tel_Data.h"

IMPLEMENT_L3CLASS(CBase_Steel_Mat_Tel_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CBase_Steel_Mat_Tel_Data,CL3Object)

	L3PROP_DATETIME(Rec_Time)
	L3PROP_STRING(vbillcode)
	L3PROP_STRING(cinventoryid)
	L3PROP_STRING(cbaseid)
	L3PROP_STRING(Invcode)
	L3PROP_STRING(Invname)
	L3PROP_STRING(Invspec)
	L3PROP_STRING(Invtype)
	L3PROP_DATETIME(dbizdate)
	L3PROP_STRING(cotherwhid)
	L3PROP_STRING(cwarehouseid)
	L3PROP_DOUBLE(ninnum)
	L3PROP_LONG(ninassistnum)
	L3PROP_STRING(vbatchcode)
	L3PROP_STRING(vuserdef1)
	L3PROP_STRING(vuserdef2)
	L3PROP_STRING(vuserdef3)
	L3PROP_STRING(vuserdef4)
	L3PROP_STRING(vuserdef5)
	L3PROP_STRING(vfree1)
	L3PROP_STRING(vfree2)
	L3PROP_STRING(vfree3)
	L3PROP_STRING(vfree4)
	L3PROP_STRING(vfree5)
	L3PROP_STRING(pk_corp)

END_L3PROPTABLE(CBase_Steel_Mat_Tel_Data)

BEGIN_L3METHODMAP(CBase_Steel_Mat_Tel_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBase_Steel_Mat_Tel_Data,CL3Object)
END_L3EVENTSINK_MAP(CBase_Steel_Mat_Tel_Data)

CBase_Steel_Mat_Tel_Data::CBase_Steel_Mat_Tel_Data(void)
{
}

CBase_Steel_Mat_Tel_Data::~CBase_Steel_Mat_Tel_Data(void)
{
}
