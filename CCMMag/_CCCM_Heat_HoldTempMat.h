// 逻辑类CCCM_Heat_HoldTempMat头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_HoldTempMat :
	public CL3Object
{
public:
	CCCM_Heat_HoldTempMat(void);
	virtual ~CCCM_Heat_HoldTempMat(void);

	DECLARE_L3CLASS(CCCM_Heat_HoldTempMat,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_HoldTempMat)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 添加批次号、使用情况


	/// <Property class="CCCM_Heat_HoldTempMat" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_HoldTempMat" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Element" type="L3STRING">
	/// 
	/// 中包保温剂名称
	/// (1-钙质、2-碳化稻壳)
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Weight" type="L3FLOAT">
	/// 中包保温剂数量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Weight)

	/// <Property class="CCCM_Heat_HoldTempMat" name="Origin" type="L3STRING">
	/// 中包保温剂产地
	/// </Property>
	DECLARE_L3PROP_STRING(Origin)


	/// <Property class="CCCM_Heat_HoldTempMat" name="Batch_ID" type="L3STRING">
	/// 批次号
	/// </Property>
	DECLARE_L3PROP_STRING(Batch_ID)


	/// <Property class="CCCM_Heat_HoldTempMat" name="UseInformation" type="L3STRING">
	/// 使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)

};
