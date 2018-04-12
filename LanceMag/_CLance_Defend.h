// 逻辑类CLance_Defend头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Defend :
	public CL3Object
{
public:
	CLance_Defend(void);
	virtual ~CLance_Defend(void);

	DECLARE_L3CLASS(CLance_Defend,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Defend)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_Defend" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Defend" name="LanceID" type="L3STRING">
	/// 枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Defend" name="Check_Date" type="L3DATETIME">
	/// 检查日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Check_Date)

	/// <Property class="CLance_Defend" name="Lance_Head_Type" type="L3STRING">
	/// 枪头型号
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Defend" name="MakeID" type="L3STRING">
	/// 氧枪制作编号
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Defend" name="Test_Water_Pressure" type="L3DOUBLE">
	/// 试水压力[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Defend" name="Nasal_Erosion" type="L3DOUBLE">
	/// 鼻区侵蚀[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nasal_Erosion)

	/// <Property class="CLance_Defend" name="Exit_Shape" type="L3LONG">
	/// 出口是否变形
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Defend" name="Sundry" type="L3LONG">
	/// 喷口内是否有杂物
	/// </Property>
	DECLARE_L3PROP_LONG(Sundry)

	/// <Property class="CLance_Defend" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Defend" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Defend" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Defend" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
