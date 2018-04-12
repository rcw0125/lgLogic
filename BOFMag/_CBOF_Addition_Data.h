// 逻辑类CBOF_Addition_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Addition_Data :
	public CL3Object
{
public:
	CBOF_Addition_Data(void);
	virtual ~CBOF_Addition_Data(void);

	DECLARE_L3CLASS(CBOF_Addition_Data,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Addition_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Addition_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBOF_Addition_Data" name="Element" type="L3STRING">
	/// 辅料代码
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CBOF_Addition_Data" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>20081213 tangyi
	DECLARE_L3PROP_STRING(Batch_ID)

	/// <Property class="CBOF_Addition_Data" name="Weight" type="L3FLOAT">
	/// 加料量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CBOF_Addition_Data" name="Discharge_Time" type="L3DATETIME">
	/// 加料时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Discharge_Time)

	/// <Property class="CBOF_Addition_Data" name="Type" type="L3SHORT">
	/// 
	/// 加料性质(1-散状料;
	///                  2-拉碳调料;
	///                  3:顶渣;
	///                  4:脱氧剂;
	///                  5:合金)
	/// </Property>
	DECLARE_L3PROP_SHORT(Type)

	/// <Property class="CBOF_Addition_Data" name="Area" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Area)

};
