// 逻辑类CCCM_BigWaterGap头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_BigWaterGap :
	public CL3Object
{
public:
	CCCM_BigWaterGap(void);
	virtual ~CCCM_BigWaterGap(void);

	DECLARE_L3CLASS(CCCM_BigWaterGap,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_BigWaterGap)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_BigWaterGap" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_BigWaterGap" name="StrandNo" type="L3LONG">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_BigWaterGap" name="GapID" type="L3STRING">
	/// 水口
	/// </Property>
	DECLARE_L3PROP_STRING(GapID)

	/// <Property class="CCCM_BigWaterGap" name="Factory" type="L3STRING">
	/// 水口厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_BigWaterGap" name="MatType" type="L3STRING">
	/// 材质
	/// </Property>
	DECLARE_L3PROP_STRING(MatType)

	/// <Property class="CCCM_BigWaterGap" name="ChangeTime" type="L3DATETIME">
	/// 换上时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeTime)

	/// <Property class="CCCM_BigWaterGap" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_BigWaterGap" name="GapLife" type="L3LONG">
	/// 使用寿命
	/// </Property>
	DECLARE_L3PROP_LONG(GapLife)

	/// <Property class="CCCM_BigWaterGap" name="Reason" type="L3STRING">
	/// 换下原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)


};
