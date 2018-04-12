// 逻辑类CEnergy_Manual_Data源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CEnergy_Manual_Data.h"

IMPLEMENT_L3CLASS(CEnergy_Manual_Data,CL3Object,1)

BEGIN_L3PROPTABLE(CEnergy_Manual_Data,CL3Object)
	L3PROP_STRING(ProductionDate)
	L3PROP_FLOAT(Flow_CFCO)
	L3PROP_FLOAT(Flow_BOFCO)
	L3PROP_FLOAT(Flow_BOFCO_CallBack)
	L3PROP_FLOAT(Flow_N2)
	L3PROP_FLOAT(Flow_N2_SpecialSteel)
	L3PROP_FLOAT(Flow_O2)
	L3PROP_FLOAT(CFCO_D)
	L3PROP_FLOAT(BOFCO_D)
	L3PROP_FLOAT(BOFCO_CallBack_D)
	L3PROP_FLOAT(N2_D)
	L3PROP_FLOAT(N2_SpecialSteel_D)
	L3PROP_FLOAT(O2_D)
	L3PROP_FLOAT(CFCO_D_Avg)
	L3PROP_FLOAT(BOFCO_D_Avg)
	L3PROP_FLOAT(BOFCO_CallBack_D_Avg)
	L3PROP_FLOAT(N2_D_Avg)
	L3PROP_FLOAT(N2_SpecialSteel_D_Avg)
	L3PROP_FLOAT(O2_D_Avg)
	L3PROP_FLOAT(CFCO_M)
	L3PROP_FLOAT(BOFCO_M)
	L3PROP_FLOAT(BOFCO_CallBack_M)
	L3PROP_FLOAT(N2_M)
	L3PROP_FLOAT(N2_SpecialSteel_M)
	L3PROP_FLOAT(O2_M)
	L3PROP_FLOAT(CFCO_M_Avg)
	L3PROP_FLOAT(BOFCO_M_Avg)
	L3PROP_FLOAT(BOFCO_CallBack_M_Avg)
	L3PROP_FLOAT(N2_M_Avg)
	L3PROP_FLOAT(N2_SpecialSteel_M_Avg)
	L3PROP_FLOAT(O2_M_Avg)
	L3PROP_FLOAT(Production_D)
	L3PROP_FLOAT(Production_M)
	L3PROP_DATETIME(CreateTime)
	L3PROP_STRING(Operator)
	L3PROP_LONG(Status)
	L3PROP_FLOAT(Production_Special_D)
	L3PROP_FLOAT(Production_Special_M)
END_L3PROPTABLE(CEnergy_Manual_Data)

BEGIN_L3METHODMAP(CEnergy_Manual_Data,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CEnergy_Manual_Data,CL3Object)
END_L3EVENTSINK_MAP(CEnergy_Manual_Data)

CEnergy_Manual_Data::CEnergy_Manual_Data(void)
{
}

CEnergy_Manual_Data::~CEnergy_Manual_Data(void)
{
}
