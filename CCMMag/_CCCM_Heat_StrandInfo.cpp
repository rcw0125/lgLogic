// 逻辑类CCCM_Heat_StrandInfo源文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

#include "StdAfx.h"
#include "_CCCM_Heat_StrandInfo.h"

IMPLEMENT_L3CLASS(CCCM_Heat_StrandInfo,CL3Object,1)

BEGIN_L3PROPTABLE(CCCM_Heat_StrandInfo,CL3Object)

	///2009-02-13 删除中包工,增加机构编号、液面波动、是否堵流、堵流原因、
	///漏钢次数、结晶器编号、铜管编号（5#机铜板）、铜管（铜板）厂家、炉次通钢量、累计通钢量(按铜管编号累计)

	L3PROP_STRING(HeatID)
	L3PROP_STRING(CCMID)
	L3PROP_LONG(StrandID)
	L3PROP_LONG(Soft_Press_Flag)
	L3PROP_LONG(Auto_Control)
	L3PROP_DATETIME(Start_Time)
	L3PROP_DATETIME(Stop_Time)
	L3PROP_LONG(Cast_Num)
	L3PROP_LONG(WaterGap_Center)
	L3PROP_LONG(WaterGap_Deepness)
	L3PROP_LONG(CastingStatus)
	L3PROP_STRING(Code)
	L3PROP_STRING(liquid_level)
	L3PROP_LONG(Block_Up)
	L3PROP_STRING(Block_Up_Reason)
	L3PROP_LONG(BreakOut_Num)
	L3PROP_STRING(MoldID)
	L3PROP_STRING(Copper_Fac)
	L3PROP_STRING(Copper_ID)
	L3PROP_DOUBLE(Heat_Weight)
	L3PROP_DOUBLE(Total_Weight)

END_L3PROPTABLE(CCCM_Heat_StrandInfo)

BEGIN_L3METHODMAP(CCCM_Heat_StrandInfo,CL3Object)
END_L3METHODMAP()

BEGIN_L3EVENTSINK_MAP(CCCM_Heat_StrandInfo,CL3Object)
END_L3EVENTSINK_MAP(CCCM_Heat_StrandInfo)

CCCM_Heat_StrandInfo::CCCM_Heat_StrandInfo(void)
{
}

CCCM_Heat_StrandInfo::~CCCM_Heat_StrandInfo(void)
{
}
