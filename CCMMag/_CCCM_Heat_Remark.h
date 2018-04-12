// 逻辑类CCCM_Heat_Remark头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Remark :
	public CL3Object
{
public:
	CCCM_Heat_Remark(void);
	virtual ~CCCM_Heat_Remark(void);

	DECLARE_L3CLASS(CCCM_Heat_Remark,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Remark)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Remark" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Remark" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Remark" name="TypeID" type="L3SHORT">
	/// 
	/// 分类
	/// (1:安全
	///  2:设备
	///  3:生产
	///  4:其他)
	/// </Property>
	DECLARE_L3PROP_SHORT(TypeID)

	/// <Property class="CCCM_Heat_Remark" name="Remark" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Remark)

	/// <Property class="CCCM_Heat_Remark" name="Log_Time" type="L3DATETIME">
	/// 记录时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

};
