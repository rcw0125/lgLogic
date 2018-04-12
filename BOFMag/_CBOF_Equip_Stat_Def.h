// 逻辑类CBOF_Equip_Stat_Def头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CBOF_Equip_Stat_Def :
	public CL3Object
{
public:
	CBOF_Equip_Stat_Def(void);
	virtual ~CBOF_Equip_Stat_Def(void);

	DECLARE_L3CLASS(CBOF_Equip_Stat_Def,XGMESLogic\\BOFMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBOF_Equip_Stat_Def)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBOF_Equip_Stat_Def" name="Status" type="L3SHORT">
	/// 状态
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CBOF_Equip_Stat_Def" name="Descr" type="L3STRING">
	/// 
	/// 设备状态
	/// (1:正常
	///  2:检修
	///  3:套管
	///  4:护炉
	///  5:故障)
	/// </Property>
	DECLARE_L3PROP_STRING(Descr)

};
