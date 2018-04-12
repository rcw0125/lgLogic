// 逻辑类CLance_In_Yard头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_In_Yard :
	public CL3Object
{
public:
	CLance_In_Yard(void);
	virtual ~CLance_In_Yard(void);

	DECLARE_L3CLASS(CLance_In_Yard,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_In_Yard)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_In_Yard" name="Input_Time" type="L3DATETIME">
	/// 日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_In_Yard" name="Lance_Head_Type" type="L3STRING">
	/// 枪头型号
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_In_Yard" name="Nozzle_Factury" type="L3STRING">
	/// 喷头厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_In_Yard" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// 喷头喉口直径[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_In_Yard" name="Nozzle_Angle" type="L3DOUBLE">
	/// 喷头夹角[°]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_In_Yard" name="IN_Yard" type="L3LONG">
	/// 入库量
	/// </Property>
	DECLARE_L3PROP_LONG(IN_Yard)

	/// <Property class="CLance_In_Yard" name="IN_Total" type="L3LONG">
	/// 入库总量
	/// </Property>
	DECLARE_L3PROP_LONG(IN_Total)

	/// <Property class="CLance_In_Yard" name="In_Confirm" type="L3STRING">
	/// 入库确认人
	/// </Property>
	DECLARE_L3PROP_STRING(In_Confirm)

	/// <Property class="CLance_In_Yard" name="TeamID" type="L3STRING">
	/// 入库班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_In_Yard" name="ShiftID" type="L3STRING">
	/// 入库班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_In_Yard" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
