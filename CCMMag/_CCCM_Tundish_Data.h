// 逻辑类CCCM_Tundish_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Tundish_Data :
	public CL3Object
{
public:
	CCCM_Tundish_Data(void);
	virtual ~CCCM_Tundish_Data(void);

	DECLARE_L3CLASS(CCCM_Tundish_Data,XGMESLogic\\CCMMag, TundishNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Tundish_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 删除中包工作层材质、中包工作层产地、中包挡渣墙、中包挡渣墙厂家、
	///中包挡渣墙材质、预热小火开始时刻、预热中火开始时刻、预热大火开始时刻、预热结束时刻、
	///预热结束中包工作层温度、预热结束浸入式水口温度、浸入式水口型号、浸入式水口产地、
	///塞棒型号、塞棒产地、中包盖编号、中包盖编号、中包废弃品、中包厂内废、中包覆盖剂名称、中包覆盖剂数量
	///增加：包次开始时刻、包次结束时刻

	/// <Property class="CCCM_Tundish_Data" name="TundishNo" type="L3STRING">
	/// 包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_Tundish_Data" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Tundish_Data" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CCCM_Tundish_Data" name="Tundish_CarID" type="L3STRING">
	/// 中包车号
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_CarID)

	/// <Property class="CCCM_Casting_Data" name="First_HeatID" type="L3STRING">
	/// 包次第一炉
	/// </Property>
	DECLARE_L3PROP_STRING(First_HeatID)

	/// <Property class="CCCM_Casting_Data" name="Last_HeatID" type="L3STRING">
	/// 包次最后一炉
	/// </Property>
	DECLARE_L3PROP_STRING(Last_HeatID)

	/// <Property class="CCCM_Casting_Data" name="HeatCount" type="L3LONG">
	/// 当前包次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(HeatCount)


	/// <Property class="CCCM_Tundish_Data" name="Fender_Slag_Usage Case" type="L3STRING">
	/// 中包挡渣墙使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Fender_Slag_Usage_Case)

	/// <Property class="CCCM_Tundish_Data" name="Cover_Factory" type="L3STRING">
	/// 中包盖产地
	/// </Property>
	DECLARE_L3PROP_STRING(Cover_Factory)


	/// <Property class="CCCM_Tundish_Data" name="Reason_Holt_Casting" type="L3STRING">
	/// 停浇原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason_Holt_Casting)

	
	/// <Property class="CCCM_Tundish_Data" name="Remain_Steel_Weight" type="L3DOUBLE">
	/// 中包浇余钢水量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Remain_Steel_Weight)

	/// <Property class="CCCM_Tundish_Data" name="Casting_Start_Time" type="L3DATETIME">
	/// 包次开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Start_Time)

	/// <Property class="CCCM_Tundish_Data" name="Casting_Stop_Time" type="L3DATETIME">
	/// 包次结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Casting_Stop_Time)	

	/// <Property class="CCCM_Tundish_Data" name="WorkID" type="L3STRING">
	/// 中包工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

};
