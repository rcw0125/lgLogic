// 逻辑类CRHL_HeatRemark头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CRHL_HeatRemark :
	public CL3Object
{
public:
	CRHL_HeatRemark(void);
	virtual ~CRHL_HeatRemark(void);

	DECLARE_L3CLASS(CRHL_HeatRemark,XGMESLogic\\RHLMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CRHL_HeatRemark)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CRHL_HeatRemark" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CRHL_HeatRemark" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CRHL_HeatRemark" name="Type" type="L3SHORT">
	/// 
	/// 分类
	/// (1:安全
	///  2:设备
	///  3:生产
	///  4:其他)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CRHL_HeatRemark" name="Remark" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CRHL_HeatRemark" name="LogTime" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

};
