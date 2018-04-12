// 逻辑类CTap_Addition_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTap_Addition_Data :
	public CL3Object
{
public:
	CTap_Addition_Data(void);
	virtual ~CTap_Addition_Data(void);

	DECLARE_L3CLASS(CTap_Addition_Data,XGMESLogic\\TapSideMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTap_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTap_Addition_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CTap_Addition_Data" name="Element" type="L3STRING">
	/// 加料代码
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CTap_Addition_Data" name="Weight" type="L3FLOAT">
	/// 加料量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CTap_Addition_Data" name="Length" type="L3FLOAT">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_FLOAT(Length)

	/// <Property class="CTap_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// 加料时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CTap_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// 加料性质(1-脱氧剂;
	///                  2-喂丝)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CTap_Addition_Data" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)
};
