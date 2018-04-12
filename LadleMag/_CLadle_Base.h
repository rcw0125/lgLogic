// 逻辑类CLadle_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。

/////2009-02-28加入各个使用实绩中实绩确认标志

#pragma once

class CLadle_Base :
	public CL3Object
{
public:
	CLadle_Base(void);
	virtual ~CLadle_Base(void);

	DECLARE_L3CLASS(CLadle_Base,XGMESLogic\\LadleMag, LadleID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_Base" name="LadleID" type="L3STRING">
	/// 钢包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Base" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Base" name="Refra_Facturer" type="L3STRING">
	/// 耐材产地
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Facturer)

	/// <Property class="CLadle_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CLadle_Base" name="Ladle_Grade" type="L3STRING">
	/// 包况
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CLadle_Base" name="Ladle_Age" type="L3LONG">
	/// 包龄
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Age)

	/// <Property class="CLadle_Base" name="New_BOF_Flag" type="L3LONG">
	/// 80t转炉标志
	/// </Property>
	DECLARE_L3PROP_LONG(New_BOF_Flag)

	/// <Property class="CLadle_Base" name="Tare_WT" type="L3DOUBLE">
	/// 钢包皮重
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tare_WT)

	/// <Property class="CLadle_Base" name="LadleType" type="L3LONG">
	/// 钢包类型
	/// </Property>
	DECLARE_L3PROP_LONG(LadleType)

	/// <Property class="CLadle_Base" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_Base" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Base" name="ComFlag" type="L3LONG">
	/// 完成标志
	/// </Property>
	DECLARE_L3PROP_LONG(ComFlag)

	/// <Property class="CLadle_Base" name="OnFireID" type="L3LONG">
	/// 在线烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(OnFireID)

	/// <Property class="CLadle_Base" name="WorkFireID" type="L3LONG">
	/// 工作层烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(WorkFireID)
	
	//2009-04-13
	/// <Property class="CLadle_Base" name="Measure_Flag" type="L3LONG">
	/// 钢包称重准备标志
	/// </Property>
	DECLARE_L3PROP_LONG(Measure_Flag)

	/// <Property class="CLadle_Base" name="InnerFireID" type="L3LONG">
	/// 永久层烘烤次数
	/// </Property>
	DECLARE_L3PROP_LONG(InnerFireID)

};
