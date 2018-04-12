// �߼���CMaterial_PriceԴ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����

#include "StdAfx.h"
#include "_CMaterial_Price.h"

IMPLEMENT_L3CLASS(CMaterial_Price,CL3Object,1)

BEGIN_L3PROPTABLE(CMaterial_Price,CL3Object)
	L3PROP_STRING(Material_Code)
	L3PROP_STRING(Material_Name)
	L3PROP_DOUBLE(Standard_Price)
	L3PROP_DOUBLE(Budget_Price_Jan)
	L3PROP_DOUBLE(Budget_Price_Feb)
	L3PROP_DOUBLE(Budget_Price_Mar)
	L3PROP_DOUBLE(Budget_Price_Apr)
	L3PROP_DOUBLE(Budget_Price_May)
	L3PROP_DOUBLE(Budget_Price_Jun)
	L3PROP_DOUBLE(Budget_Price_Jul)
	L3PROP_DOUBLE(Budget_Price_Aug)
	L3PROP_DOUBLE(Budget_Price_Sep)
	L3PROP_DOUBLE(Budget_Price_Oct)
	L3PROP_DOUBLE(Budget_Price_Nov)
	L3PROP_DOUBLE(Budget_Price_Dec)
	L3PROP_STRING(Work_Year)
	L3PROP_DOUBLE(Latest_Price)
	L3PROP_STRING(Object_ID)
END_L3PROPTABLE(CMaterial_Price)

BEGIN_L3METHODMAP(CMaterial_Price,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CMaterial_Price,CL3Object)
END_L3EVENTSINK_MAP(CMaterial_Price)

CMaterial_Price::CMaterial_Price(void)
{
}

CMaterial_Price::~CMaterial_Price(void)
{
}
