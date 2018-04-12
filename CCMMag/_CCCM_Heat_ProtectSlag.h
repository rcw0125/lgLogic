// 逻辑类CCCM_Heat_ProtectSlag头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_ProtectSlag :
	public CL3Object
{
public:
	CCCM_Heat_ProtectSlag(void);
	virtual ~CCCM_Heat_ProtectSlag(void);

	DECLARE_L3CLASS(CCCM_Heat_ProtectSlag,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_ProtectSlag)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 使用情况、加入量

	/// <Property class="CCCM_Heat_ProtectSlag" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="StrandID" type="L3SHORT">
	/// 结晶器流号
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandID)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Element" type="L3STRING">
	/// 保护渣型号
	/// </Property>
	DECLARE_L3PROP_STRING(Element)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Factory" type="L3STRING">
	/// 保护渣厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Factory)

	/// <Property class="CCCM_Heat_ProtectSlag" name="BatchNo" type="L3STRING">
	/// 保护渣验收批号
	/// </Property>
	DECLARE_L3PROP_STRING(BatchNo)

	/// <Property class="CCCM_Heat_ProtectSlag" name="UseInformation" type="L3STRING">
	/// 使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(UseInformation)

	/// <Property class="CCCM_Heat_ProtectSlag" name="Amount" type="L3DOUBLE">
	/// 加入数量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)


};
