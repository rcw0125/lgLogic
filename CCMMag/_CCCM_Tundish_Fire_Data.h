// 逻辑类CCCM_Tundish_Fire_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Tundish_Fire_Data :
	public CL3Object
{
public:
	CCCM_Tundish_Fire_Data(void);
	virtual ~CCCM_Tundish_Fire_Data(void);

	DECLARE_L3CLASS(CCCM_Tundish_Fire_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_Fire_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Tundish_Fire_Data" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Cast_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Flow_Gas" type="L3FLOAT">
	/// 煤气流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_Gas)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Position" type="L3STRING">
	/// 烘烤位置
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CCCM_Tundish_Fire_Data" name="Fire_Type" type="L3STRING">
	/// 烘烤类型
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CCCM_Tundish_Fire_Data" name="MeasureTime" type="L3DATETIME">
	/// 检测时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(MeasureTime)

};
