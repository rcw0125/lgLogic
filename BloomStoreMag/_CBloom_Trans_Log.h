// 逻辑类CBloom_Trans_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBloom_Trans_Log :
	public CL3Object
{
public:
	CBloom_Trans_Log(void);
	virtual ~CBloom_Trans_Log(void);

	DECLARE_L3CLASS(CBloom_Trans_Log,XGMESLogic\\BloomStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Trans_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBloom_Trans_Log" name="MaterialType" type="L3STRING">
	/// 材料类型
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialType)

	/// <Property class="CBloom_Trans_Log" name="MaterialID" type="L3STRING">
	/// 材料号
	/// </Property>
	DECLARE_L3PROP_STRING(MaterialID)

	/// <Property class="CBloom_Trans_Log" name="Amount" type="L3STRING">
	/// 钢坯支数
	/// </Property>
	DECLARE_L3PROP_STRING(Amount)

	/// <Property class="CBloom_Trans_Log" name="SourceID" type="L3STRING">
	/// 原库区
	/// </Property>
	DECLARE_L3PROP_STRING(SourceID)

	/// <Property class="CBloom_Trans_Log" name="Cur_Pile_ID" type="L3STRING">
	/// 原垛位
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Trans_Log" name="Cur_Layer_ID" type="L3STRING">
	/// 原层
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)

	/// <Property class="CBloom_Trans_Log" name="TargetID" type="L3STRING">
	/// 目标库区
	/// </Property>
	DECLARE_L3PROP_STRING(TargetID)

	/// <Property class="CBloom_Trans_Log" name="Target_Pile_ID" type="L3STRING">
	/// 目标垛位
	/// </Property>
	DECLARE_L3PROP_STRING(Target_Pile_ID)

	/// <Property class="CBloom_Trans_Log" name="Target_Layer_ID" type="L3STRING">
	/// 目标层
	/// </Property>
	DECLARE_L3PROP_STRING(Target_Layer_ID)

	/// <Property class="CBloom_Trans_Log" name="Operator" type="L3STRING">
	/// 操作人员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CBloom_Trans_Log" name="Trans_Date" type="L3STRING">
	/// 转移日期
	/// </Property>
	DECLARE_L3PROP_STRING(Trans_Date)

	/// <Property class="CBloom_Trans_Log" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CBloom_Trans_Log" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

};
