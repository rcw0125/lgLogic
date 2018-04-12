// 逻辑类CQA_RH_Std_Proc头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_RH_Std_Proc :
	public CL3Object
{
public:
	CQA_RH_Std_Proc(void);
	virtual ~CQA_RH_Std_Proc(void);

	DECLARE_L3CLASS(CQA_RH_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_RH_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_RH_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Aim" type="L3LONG">
	/// 目标RH离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Min" type="L3LONG">
	/// 最小RH离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Min)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Max" type="L3LONG">
	/// 最大RH离站温度(连铸第一炉)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Aim" type="L3LONG">
	/// 目标RH离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Min" type="L3LONG">
	/// 最小RH离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Max" type="L3LONG">
	/// 最大RH离站温度(连浇炉)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Depth_Min" type="L3DOUBLE">
	/// 插入深度最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Depth_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Depth_Max" type="L3DOUBLE">
	/// 插入深度最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Depth_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Min" type="L3DOUBLE">
	/// 插入深度最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Vacuum_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Max" type="L3DOUBLE">
	/// 真空度最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Vacuum_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Min" type="L3DOUBLE">
	/// 提升气体流量最小、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Aim" type="L3DOUBLE">
	/// 提升气体流量目标、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Max" type="L3DOUBLE">
	/// 提升气体流量最大、
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Flag" type="L3LONG">
	/// 氧脱碳否、
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Time_Min" type="L3LONG">
	/// 脱碳时间最小、
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Time_Max" type="L3LONG">
	/// 脱碳时间最大、
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_Time_Min" type="L3LONG">
	/// 纯处理时间最小、
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_Time_Max" type="L3LONG">
	/// 纯处理时间最大、
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Time_Min" type="L3LONG">
	/// 最低真空度保持时间、
	/// </Property>
	DECLARE_L3PROP_LONG(Vacuum_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Proc_Time_Min" type="L3LONG">
	/// 处理时间最小、
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Oxy_Flag" type="L3LONG">
	/// 定氧否、
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="H_Flag" type="L3LONG">
	/// 定氢否、
	/// </Property>
	DECLARE_L3PROP_LONG(H_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Soft_Blow_Flag" type="L3LONG">
	/// 软吹否、
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Blow_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Calm_Flag" type="L3LONG">
	/// 镇静否、
	/// </Property>
	DECLARE_L3PROP_LONG(Calm_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Al_Hot_Flag" type="L3LONG">
	/// 允许AL加热否、
	/// </Property>
	DECLARE_L3PROP_LONG(Al_Hot_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Cold_Mat_Add" type="L3STRING">
	/// 冷料加入量基准、
	/// </Property>
	DECLARE_L3PROP_STRING(Cold_Mat_Add)

	/// <Property class="CQA_RH_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// 进站压钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// 进站等钢时间最大
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_DeO_Time_Min" type="L3LONG">
	/// 纯脱气时间最小
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_DeO_Time_Min)

};
