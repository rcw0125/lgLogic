// 逻辑类CCCM_Tundish_StrandInfo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Tundish_StrandInfo :
	public CL3Object
{
public:
	CCCM_Tundish_StrandInfo(void);
	virtual ~CCCM_Tundish_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Tundish_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Tundish_StrandInfo" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="TundishNo" type="L3STRING">
	/// 中包序号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_StrandInfo" name="StrandNo" type="L3STRING">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Start_Time" type="L3DATETIME">
	/// 中包开浇时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Stop_Time" type="L3DATETIME">
	/// 中包停浇时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Tundish_StrandInfo" name="InjectionBarNo" type="L3STRING">
	/// 塞棒结构编号
	/// </Property>
	DECLARE_L3PROP_STRING(InjectionBarNo)

	/// <Property class="CCCM_Tundish_StrandInfo" name="WaterGap_Usage Case" type="L3SHORT">
	/// 
	/// 浸入式水口使用情况
	/// (1、正常 2、渣线处坏 3、渣线以上裂纹、4、非质量原因)
	/// </Property>
	DECLARE_L3PROP_SHORT(WaterGap_Usage_Case)

	/// <Property class="CCCM_Tundish_StrandInfo" name="InjectionBar__Usage Case" type="L3STRING">
	/// 塞棒使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(InjectionBar_Usage_Case)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Reason_Holt_Casting" type="L3STRING">
	/// 停浇原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_Holt_Casting)

	/// <Property class="CCCM_Tundish_StrandInfo" name="RemainWeight" type="L3FLOAT">
	/// 中包浇余钢水量
	/// </Property>
	DECLARE_L3PROP_FLOAT(RemainWeight)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Fir_HeatID" type="">
	/// 浇次第一炉
	/// </Property>
	DECLARE_L3PROP_STRING(Fir_HeatID)

	/// <Property class="CCCM_Tundish_StrandInfo" name="Last_HeatID" type="">
	/// 浇次最后一炉
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

};
