// 逻辑类CCCM_Duty头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Duty :
	public CL3Object
{
public:
	CCCM_Duty(void);
	virtual ~CCCM_Duty(void);

	DECLARE_L3CLASS(CCCM_Duty,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Duty)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Duty" name="CCMID" type="L3STRING">
	/// 铸机
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Duty" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CCCM_Duty" name="Ladle_Officer" type="L3STRING">
	/// 岗位
	/// </Property>
	DECLARE_L3PROP_STRING(Station)

	/// <Property class="CCCM_Duty" name="Tundish_1ST_Officer" type="L3STRING">
	/// 操作工姓名
	/// </Property>
	DECLARE_L3PROP_STRING(Operator_name)

};
