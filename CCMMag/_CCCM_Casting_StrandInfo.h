// 逻辑类CCCM_Casting_StrandInfo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Casting_StrandInfo :
	public CL3Object
{
public:
	CCCM_Casting_StrandInfo(void);
	virtual ~CCCM_Casting_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Casting_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Casting_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Casting_StrandInfo" name="CastingNo" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingNo)

	/// <Property class="CCCM_Casting_StrandInfo" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Casting_StrandInfo" name="StrandNo" type="L3SHORT">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_SHORT(StrandNo)

	/// <Property class="CCCM_Casting_StrandInfo" name="LEAD_TIME" type="L3DATETIME">
	/// 送引锭时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(LEAD_TIME)

	/// <Property class="CCCM_Casting_StrandInfo" name="Mold" type="L3STRING">
	/// 结晶器号
	/// </Property>
	DECLARE_L3PROP_STRING(Mold)

	/// <Property class="CCCM_Casting_StrandInfo" name="Cu_Factory" type="L3STRING">
	/// 铜板产地
	/// </Property>
	DECLARE_L3PROP_STRING(Cu_Factory)

	/// <Property class="CCCM_Casting_StrandInfo" name="Pass_Steel_Weight" type="L3DOUBLE">
	/// 通钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pass_Steel_Weight)

};
