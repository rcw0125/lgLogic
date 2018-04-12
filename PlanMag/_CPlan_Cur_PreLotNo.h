// 逻辑类CPlan_Cur_PreLotNo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CPlan_Cur_PreLotNo :
	public CL3Object
{
public:
	CPlan_Cur_PreLotNo(void);
	virtual ~CPlan_Cur_PreLotNo(void);

	DECLARE_L3CLASS(CPlan_Cur_PreLotNo,XGMESLogic\\PlanMag, CasterID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_Cur_PreLotNo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CPlan_Cur_PreLotNo" name="Cur_PreLotNo" type="L3STRING">
	/// 当前预定包次号
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_PreLotNo)

	/// <Property class="CPlan_Cur_PreLotNo" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

};
