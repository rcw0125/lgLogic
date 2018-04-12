// 逻辑类CPlan_Order源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CPlan_Order.h"

IMPLEMENT_L3CLASS(CPlan_Order,ProducePlan,1)

BEGIN_L3PROPTABLE(CPlan_Order,ProducePlan)
	L3PROP_LONG(Length)
	L3PROP_LONG(Width)
	L3PROP_LONG(Thickness)
	L3PROP_STRING(SteelGrade)
	L3PROP_STRING(MaterialCode)
	L3PROP_STRING(Unit)
	L3PROP_STRING(Assist_Unit)
	L3PROP_DOUBLE(Weight)
	L3PROP_DOUBLE(ActWeight)
	L3PROP_DOUBLE(SpareWeight)
	L3PROP_DOUBLE(Assisi_Weight)
	L3PROP_DATETIME(PlanRec_Date)
	L3PROP_DATETIME(Request_Date)
	L3PROP_STRING(Corp)
	L3PROP_STRING(Factory)
	L3PROP_STRING(Work_Center)
	L3PROP_STRING(Client)
	L3PROP_STRING(Tech_Request)
	L3PROP_STRING(Inside_Note)
	L3PROP_STRING(Imm_Flag)
	L3PROP_STRING(CasterID)
	L3PROP_SHORT(New_BOF_Flag)
	L3PROP_STRING(Protocol)
	L3PROP_STRING(ProduceStd)
	L3PROP_STRING(pk_poid)
	L3PROP_STRING(MaterialCode_ID)
	L3PROP_STRING(Product_Route)
	L3PROP_STRING(Other_Tech_Request)
END_L3PROPTABLE(CPlan_Order)

BEGIN_L3METHODMAP(CPlan_Order,ProducePlan)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CPlan_Order,ProducePlan)
END_L3EVENTSINK_MAP(CPlan_Order)

CPlan_Order::CPlan_Order(void)
{
}

CPlan_Order::~CPlan_Order(void)
{
}
