// 逻辑类CLF_Feed_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "UnitFeedingLog.h"
class CLF_Feed_Data :
	public UnitFeedingLog
{
public:
	CLF_Feed_Data(void);
	virtual ~CLF_Feed_Data(void);

	DECLARE_L3CLASS(CLF_Feed_Data,XGMESLogic\\LFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLF_Feed_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLF_Feed_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CLF_Feed_Data" name="HeatID" type="L3STRING">
	///炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLF_Feed_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CLF_Feed_Data" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CLF_Feed_Data" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CLF_Feed_Data" name="LadleNo" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleNo)

};
