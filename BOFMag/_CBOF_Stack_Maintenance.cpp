// 逻辑类CBOF_Stack_Maintenance源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CBOF_Stack_Maintenance.h"

IMPLEMENT_L3CLASS(CBOF_Stack_Maintenance,CL3Object,1)

BEGIN_L3PROPTABLE(CBOF_Stack_Maintenance,CL3Object)
	L3PROP_DATETIME(ProductionDate)
	L3PROP_STRING(Team)
	L3PROP_STRING(Content)
	L3PROP_STRING(Materiel)
	L3PROP_STRING(Taphole_Vendor)
	L3PROP_STRING(Materiel_Vendor)
	L3PROP_FLOAT(Wastage)
	L3PROP_STRING(BOFID)
END_L3PROPTABLE(CBOF_Stack_Maintenance)

BEGIN_L3METHODMAP(CBOF_Stack_Maintenance,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CBOF_Stack_Maintenance,CL3Object)
END_L3EVENTSINK_MAP(CBOF_Stack_Maintenance)

CBOF_Stack_Maintenance::CBOF_Stack_Maintenance(void)
{
}

CBOF_Stack_Maintenance::~CBOF_Stack_Maintenance(void)
{
}
