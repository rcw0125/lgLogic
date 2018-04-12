// 逻辑类TB_L3_ANACOMMISSION头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class TB_L3_ANACOMMISSION :
	public CL3Object
{
public:
	TB_L3_ANACOMMISSION(void);
	virtual ~TB_L3_ANACOMMISSION(void);

	DECLARE_L3CLASS(TB_L3_ANACOMMISSION,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(TB_L3_ANACOMMISSION)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="TB_L3_ANACOMMISSION" name="CommissionID" type="L3STRING">
	/// 申请号
	/// </Property>
	DECLARE_L3PROP_STRING(CommissionID)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampID" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(SampID)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampSort" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(SampSort)

	/// <Property class="TB_L3_ANACOMMISSION" name="SampPlace" type="L3STRING">
	/// 试样地点
	/// </Property>
	DECLARE_L3PROP_STRING(SampPlace)

	/// <Property class="TB_L3_ANACOMMISSION" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="TB_L3_ANACOMMISSION" name="Contract" type="L3STRING">
	/// 协议号
	/// </Property>
	DECLARE_L3PROP_STRING(Contract)

	/// <Property class="TB_L3_ANACOMMISSION" name="SendDate" type="L3STRING">
	/// 发送时刻
	/// </Property>
	DECLARE_L3PROP_STRING(SendDate)

	/// <Property class="TB_L3_ANACOMMISSION" name="Permit_Delete_Flag" type="L3LONG">
	/// 允许删除标志
	/// </Property>
	DECLARE_L3PROP_LONG(Permit_Delete_Flag)

};
