// 逻辑类CPlan_Casting头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "ProducePlan.h"

class CPlan_Casting :
	public ProducePlan
{
public:
	CPlan_Casting(void);
	virtual ~CPlan_Casting(void);

	DECLARE_L3CLASS(CPlan_Casting,XGMESLogic\\PlanMag, PlanID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Casting)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Casting" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CPlan_Casting" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CPlan_Casting" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CPlan_Casting" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CPlan_Casting" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CPlan_Casting" name="Pre_SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGrade)

	/// <Property class="CPlan_Casting" name="Refine_Type" type="L3STRING">
	/// 精炼区分
	/// </Property>
	DECLARE_L3PROP_STRING(Refine_Type)

	/// <Property class="CPlan_Casting" name="Pre_LotNo" type="L3STRING">
	/// 预定包次号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_LotNo)

	/// <Property class="CPlan_Casting" name="PreHeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CPlan_Casting" name="Aim_Tapped_Weight" type="L3DOUBLE">
	/// 目标出钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Aim_Tapped_Weight)

	/// <Property class="CPlan_Casting" name="Proc_Seq" type="L3LONG">
	/// 计划处理顺序
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Seq)

	/// <Property class="CPlan_Casting" name="Plan_Ord_ID" type="L3STRING">
	/// 计划订单号
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_Ord_ID)

	/// <Property class="CPlan_Casting" name="Bloom_Count" type="L3LONG">
	/// 计划钢坯块数
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CPlan_Casting" name="Aim_Time_CastingStart" type="L3DATETIME">
	/// 计划开浇时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Aim_Time_CastingStart)

	/// <Property class="CPlan_Casting" name="New_BOF_Flag" type="L3SHORT">
	/// 80t转炉标志
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)


	/// <Property class="CPlan_Casting" name="BOFID" type="L3STRING">
	/// 转炉炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_Casting" name="LFID" type="L3STRING">
	/// LF炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(LFID)

	/// <Property class="CPlan_Casting" name="RHID" type="L3STRING">
	/// RH炉座号
	/// </Property>
	DECLARE_L3PROP_STRING(RHID)

	/// <Property class="CPlan_Casting" name="ActWeight" type="L3DOUBLE">
	/// 实际投放量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ActWeight)

};
