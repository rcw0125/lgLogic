// 逻辑类CCCM_StrandInfo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_StrandInfo :
	public CL3Object
{
public:
	CCCM_StrandInfo(void);
	virtual ~CCCM_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_StrandInfo" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_StrandInfo" name="StrandNo" type="L3LONG">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_LONG(StrandNo)

	/// <Property class="CCCM_StrandInfo" name="OnOff" type="L3LONG">
	/// 开停浇状态
	/// </Property>
	DECLARE_L3PROP_LONG(OnOff)

	/// <Property class="CCCM_StrandInfo" name="ChangeTime" type="L3DATETIME">
	/// 开停浇时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(ChangeTime)

	/// <Property class="CCCM_StrandInfo" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_StrandInfo" name="TundishNo" type="L3STRING">
	/// 包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNo)

	/// <Property class="CCCM_StrandInfo" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

};
