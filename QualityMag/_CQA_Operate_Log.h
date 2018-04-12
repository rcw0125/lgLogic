// 逻辑类CQA_Operate_Log头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Operate_Log :
	public CL3Object
{
public:
	CQA_Operate_Log(void);
	virtual ~CQA_Operate_Log(void);

	DECLARE_L3CLASS(CQA_Operate_Log,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Operate_Log)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Operate_Log" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Operate_Log" name="ActionCode" type="L3STRING">
	/// 操作代码
	/// </Property>
	DECLARE_L3PROP_STRING(ActionCode)

	/// <Property class="CQA_Operate_Log" name="Shift" type="L3STRING">
	/// 别次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CQA_Operate_Log" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CQA_Operate_Log" name="Operator" type="L3STRING">
	/// 操作者
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CQA_Operate_Log" name="OpeateTime" type="L3DATETIME">
	/// 操作时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(OpeateTime)

};
