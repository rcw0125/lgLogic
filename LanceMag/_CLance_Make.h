// 逻辑类CLance_Make头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Make :
	public CL3Object
{
public:
	CLance_Make(void);
	virtual ~CLance_Make(void);

	DECLARE_L3CLASS(CLance_Make,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Make)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_Make" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Make" name="LanceID" type="L3STRING">
	/// 枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Make" name="Check_Date" type="L3DATETIME">
	/// 检查日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CLance_Make" name="Lance_Head_Type" type="L3STRING">
	/// 枪头型号
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Make" name="MakeID" type="L3STRING">
	/// 氧枪制作编号
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Make" name="Nozzle_Factury" type="L3STRING">
	/// 喷头厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Make" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// 喷头喉口直径[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_Make" name="Nozzle_Angle" type="L3DOUBLE">
	/// 喷头夹角[°]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_Make" name="Weld_Operator" type="L3STRING">
	/// 装配焊接人
	/// </Property>
	DECLARE_L3PROP_STRING(Weld_Operator)

	/// <Property class="CLance_Make" name="Suppress_Operator" type="L3STRING">
	/// 装配打压人
	/// </Property>
	DECLARE_L3PROP_STRING(Suppress_Operator)

	/// <Property class="CLance_Make" name="Test_Water_Pressure" type="L3DOUBLE">
	/// 试水压力[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Make" name="Assembly_Starte_Time" type="L3DATETIME">
	/// 制作开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Assembly_Starte_Time)

	/// <Property class="CLance_Make" name="Assembly_End_Time" type="L3DATETIME">
	/// 制作结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Assembly_End_Time)

	/// <Property class="CLance_Make" name="Nasal_Erosion" type="L3DOUBLE">
	/// 鼻区侵蚀[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nasal_Erosion)

	/// <Property class="CLance_Make" name="Exit_Shape" type="L3LONG">
	/// 出口是否变形
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Make" name="Sundry" type="L3LONG">
	/// 喷口内是否有杂物
	/// </Property>
	DECLARE_L3PROP_LONG(Sundry)

	/// <Property class="CLance_Make" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Make" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Make" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Make" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
