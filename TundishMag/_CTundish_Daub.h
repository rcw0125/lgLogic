// 逻辑类CTundish_Daub头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Daub :
	public CL3Object
{
public:
	CTundish_Daub(void);
	virtual ~CTundish_Daub(void);

	DECLARE_L3CLASS(CTundish_Daub,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Daub)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_Daub" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Daub" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Daub" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Daub" name="Inner_Use_Count" type="L3SHORT">
	/// 永久层使用次数
	/// </Property>
	DECLARE_L3PROP_SHORT(Inner_Use_Count)

	/// <Property class="CTundish_Daub" name="Cast_ID" type="L3STRING">
	/// 去向
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Daub" name="Project" type="L3STRING">
	/// 项目
	/// </Property>
	DECLARE_L3PROP_STRING(Project)

	/// <Property class="CTundish_Daub" name="Gap_Bri_Fac" type="L3STRING">
	/// 座砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Gap_Bri_Fac)

	/// <Property class="CTundish_Daub" name="Gap_Bri_Consume" type="L3DOUBLE">
	/// 座砖消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gap_Bri_Consume)

	/// <Property class="CTundish_Daub" name="Ward_Dregs_Fac" type="L3STRING">
	/// 挡渣墙厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Ward_Dregs_Fac)

	/// <Property class="CTundish_Daub" name="Ward_Dregs_Consume" type="L3DOUBLE">
	/// 挡渣墙消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ward_Dregs_Consume)

	/// <Property class="CTundish_Daub" name="Tranq_Fac" type="L3STRING">
	/// 紊流器厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Tranq_Fac)

	/// <Property class="CTundish_Daub" name="Tranq_Consume" type="L3DOUBLE">
	/// 紊流器消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tranq_Consume)

	/// <Property class="CTundish_Daub" name="Daub_Fac" type="L3STRING">
	/// 涂抹料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Fac)

	/// <Property class="CTundish_Daub" name="Daub_Consume" type="L3DOUBLE">
	/// 涂抹料消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Daub_Consume)

	/// <Property class="CTundish_Daub" name="Dry_Flap_Fac" type="L3STRING">
	/// 干振料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Dry_Flap_Fac)

	/// <Property class="CTundish_Daub" name="Dry_Flap_Consume" type="L3DOUBLE">
	/// 干振料消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Dry_Flap_Consume)

	/// <Property class="CTundish_Daub" name="Gluemud_Fac" type="L3STRING">
	/// 胶泥厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Gluemud_Fac)

	/// <Property class="CTundish_Daub" name="Gluemud_Consume" type="L3DOUBLE">
	/// 胶泥消耗量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gluemud_Consume)

	/// <Property class="CTundish_Daub" name="Daub_Start_Time" type="L3DATETIME">
	/// 涂抹(干振)开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_Start_Time)

	/// <Property class="CTundish_Daub" name="Daub_End_Time" type="L3DATETIME">
	/// 涂抹(干振)结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_End_Time)

	/// <Property class="CTundish_Daub" name="Fire_Start_Time" type="L3DATETIME">
	/// 烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_Daub" name="Fire_End_Time" type="L3DATETIME">
	/// 烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_Daub" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_Daub" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_Daub" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_Daub" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_Daub" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};
