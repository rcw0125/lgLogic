// 逻辑类CAOD_Addition_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CAOD_Addition_Data :
	public CL3Object
{
public:
	CAOD_Addition_Data(void);
	virtual ~CAOD_Addition_Data(void);

	DECLARE_L3CLASS(CAOD_Addition_Data,XGMESLogic\\AODMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAOD_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CAOD_Addition_Data" name="TreatNo" type="L3STRING">
	/// 处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CAOD_Addition_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CAOD_Addition_Data" name="Element" type="L3STRING">
	/// 辅料代码
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CAOD_Addition_Data" name="Weight" type="L3FLOAT">
	/// 加料量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CAOD_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// 加料时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CAOD_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// 加料性质(1-加料;
	///          2:合金)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CAOD_Addition_Data" name="Area" type="L3STRING">
	/// 料仓号
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

	/// <Property class="CAOD_Addition_Data" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CAOD_Addition_Data" name="Vendor" type="L3STRING">
	/// 厂家
	/// </Property> 2009-03-19
	DECLARE_L3PROP_STRING(Vendor)
};
