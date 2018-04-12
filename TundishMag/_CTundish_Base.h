// 逻辑类CTundish_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Base :
	public CL3Object
{
public:
	CTundish_Base(void);
	virtual ~CTundish_Base(void);

	DECLARE_L3CLASS(CTundish_Base,XGMESLogic\\TundishMag, TundishID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	
	/// <Property class="CTundish_Base" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	
	/// <Property class="CTundish_Base" name="Cast_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Base" name="Refra_Pro" type="L3STRING">
	/// 耐材产地
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Pro)

	/// <Property class="CTundish_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CTundish_Base" name="Tundish_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Age)

	/// <Property class="CTundish_Base" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Base" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Base" name="TundishNO" type="L3STRING">
	/// 包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_Base" name="Flag" type="L3LONG">
	/// 完成标志
	/// </Property>
	DECLARE_L3PROP_LONG(Flag)

	/// <Property class="CTundish_Base" name="TundishType" type="L3SHORT">
	/// 中包类型
	/// </Property>
	DECLARE_L3PROP_SHORT(TundishType)

	/// <Property class="CTundish_Base" name="VehicleID" type="L3STRING">
	/// 中包车号
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

};
