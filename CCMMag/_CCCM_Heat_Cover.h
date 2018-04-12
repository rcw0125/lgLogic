// 逻辑类CCCM_Heat_Cover头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Cover :
	public CL3Object
{
public:
	CCCM_Heat_Cover(void);
	virtual ~CCCM_Heat_Cover(void);

	DECLARE_L3CLASS(CCCM_Heat_Cover,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Cover)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 添加批次号、使用情况

	/// <Property class="CCCM_Heat_Cover" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Cover" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_Cover" name="Element" type="L3STRING">
	/// 
	/// 中包覆盖剂名称
	/// (1-镁质、2-钙质、3-无碳、4-普通)
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_Cover" name="Amount" type="L3FLOAT">
	/// 中包覆盖剂数量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Amount)

	/// <Property class="CCCM_Heat_Cover" name="Origin" type="L3STRING">
	/// 
	/// 中包覆盖剂产地
	/// (1-通宇、2-西保、3-荣祥、4-其它)
	/// </Property>
	DECLARE_L3PROP_STRING(Origin)


	/// <Property class="CCCM_Heat_Cover" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)


	/// <Property class="CCCM_Heat_Cover" name="UseInformation" type="L3STRING">
	/// 使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)


};
