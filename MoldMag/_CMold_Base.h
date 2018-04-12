// 逻辑类CMold_Base头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CMold_Base :
	public CL3Object
{
public:
	CMold_Base(void);
	virtual ~CMold_Base(void);

	DECLARE_L3CLASS(CMold_Base,XGMESLogic\\MoldMag, MoldID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CMold_Base)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CMold_Base" name="MoldID" type="L3STRING">
	/// 结晶器编号
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CMold_Base" name="Break_Face_Mea" type="L3DOUBLE">
	/// 断面尺寸
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Break_Face_Mea)

	/// <Property class="CMold_Base" name="Status" type="L3STRING">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CMold_Base" name="Cast_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CMold_Base" name="FlowID" type="L3STRING">
	/// 流次
	/// </Property>
	DECLARE_L3PROP_STRING(FlowID)

	/// <Property class="CMold_Base" name="Copper_Fac" type="L3STRING">
	/// 铜管(板)厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CMold_Base" name="Copper_ID" type="L3STRING">
	/// 铜管(板)编号
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CMold_Base" name="InStallID" type="L3STRING">
	/// 装配编号
	/// </Property>
	DECLARE_L3PROP_STRING(InStallID)

	/// <Property class="CMold_Base" name="UnitID" type="L3STRING">
	/// 结晶器所属工位
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

};
