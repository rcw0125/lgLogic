// 逻辑类CCCM_Heat_ProtectMat头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_ProtectMat :
	public CL3Object
{
public:
	CCCM_Heat_ProtectMat(void);
	virtual ~CCCM_Heat_ProtectMat(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectMat,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectMat)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_ProtectMat" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectMat" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectMat" name="Element" type="L3STRING">
	/// 保护套管材质
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_ProtectMat" name="Factory" type="L3STRING">
	/// 保护套管产地
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

};
