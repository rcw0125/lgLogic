// 逻辑类CCCM_Heat_FaultyGoods头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_FaultyGoods :
	public CL3Object
{
public:
	CCCM_Heat_FaultyGoods(void);
	virtual ~CCCM_Heat_FaultyGoods(void);

	DECLARE_L3CLASS(CCCM_Heat_FaultyGoods,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_FaultyGoods)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_FaultyGoods" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_FaultyGoods" name="BloomID" type="L3STRING">
	/// 
	/// 不合格支号
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(BloomID)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Weight" type="L3FLOAT">
	/// 
	/// 不合格重量
	/// 
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Reason" type="L3STRING">
	/// 
	/// 不合格原因
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CCCM_Heat_FaultyGoods" name="Log_Time" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};
