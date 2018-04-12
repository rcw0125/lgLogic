// 逻辑类TB_L3_CHANGECAST头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class TB_L3_CHANGECAST :
	public CL3Object
{
public:
	TB_L3_CHANGECAST(void);
	virtual ~TB_L3_CHANGECAST(void);

	DECLARE_L3CLASS(TB_L3_CHANGECAST,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(TB_L3_CHANGECAST)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="TB_L3_CHANGECAST" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="TB_L3_CHANGECAST" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="TB_L3_CHANGECAST" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="TB_L3_CHANGECAST" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="TB_L3_CHANGECAST" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="TB_L3_CHANGECAST" name="ProductionDate" type="L3STRING">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate)

	/// <Property class="TB_L3_CHANGECAST" name="Permit_Delete_Flag" type="L3LONG">
	/// 允许删除标志
	/// </Property>
	DECLARE_L3PROP_LONG(Permit_Delete_Flag)


};
