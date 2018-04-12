// 逻辑类CQA_Unit_Trans_Time头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Unit_Trans_Time :
	public CL3Object
{
public:
	CQA_Unit_Trans_Time(void);
	virtual ~CQA_Unit_Trans_Time(void);

	DECLARE_L3CLASS(CQA_Unit_Trans_Time,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Unit_Trans_Time)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Unit_Trans_Time" name="Start_Unit" type="L3STRING">
	/// 起始工位、
	/// </Property>
	DECLARE_L3PROP_STRING(Start_Unit)

	/// <Property class="CQA_Unit_Trans_Time" name="End_Unit" type="L3STRING">
	/// 结束工位
	/// </Property>
	DECLARE_L3PROP_STRING(End_Unit)

	/// <Property class="CQA_Unit_Trans_Time" name="Transport_Time" type="L3LONG">
	/// 运输时间
	/// </Property>
	DECLARE_L3PROP_LONG(Transport_Time)

};
