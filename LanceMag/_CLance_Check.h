// 逻辑类CLance_Check头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLance_Check :
	public CL3Object
{
public:
	CLance_Check(void);
	virtual ~CLance_Check(void);

	DECLARE_L3CLASS(CLance_Check,XGMESLogic\\LanceMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLance_Check)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLance_Check" name="Input_Time" type="L3DATETIME">
	/// 录入日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLance_Check" name="LanceID" type="L3STRING">
	/// 枪号
	/// </Property>
	DECLARE_L3PROP_STRING(LanceID)

	/// <Property class="CLance_Check" name="MakeID" type="L3STRING">
	/// 氧枪制作编号
	/// </Property>
	DECLARE_L3PROP_STRING(MakeID)

	/// <Property class="CLance_Check" name="Lance_Head_Type" type="L3STRING">
	/// 枪头型号
	/// </Property>
	DECLARE_L3PROP_STRING(Lance_Head_Type)

	/// <Property class="CLance_Check" name="Nozzle_Factury" type="L3STRING">
	/// 喷头厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Nozzle_Factury)

	/// <Property class="CLance_Check" name="Nozzle_Throat_Dia" type="L3DOUBLE">
	/// 喷头喉口直径[mm]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Throat_Dia)

	/// <Property class="CLance_Check" name="Nozzle_Angle" type="L3DOUBLE">
	/// 喷头夹角[°]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Nozzle_Angle)

	/// <Property class="CLance_Check" name="Off_Date" type="L3DATETIME">
	/// 下线日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Date)

	/// <Property class="CLance_Check" name="Nasal_Erosion" type="L3LONG">
	/// 鼻区是否腐蚀
	/// </Property>
	DECLARE_L3PROP_LONG(Nasal_Erosion)

	/// <Property class="CLance_Check" name="Exit_Shape" type="L3LONG">
	/// 出口是否变形
	/// </Property>
	DECLARE_L3PROP_LONG(Exit_Shape)

	/// <Property class="CLance_Check" name="Nozzle_Assembly_Date" type="L3DATETIME">
	/// 喷头装配日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Nozzle_Assembly_Date)

	/// <Property class="CLance_Check" name="Lance_Body_Shap" type="L3LONG">
	/// 枪身是否变形
	/// </Property>
	DECLARE_L3PROP_LONG(Lance_Body_Shap)

	/// <Property class="CLance_Check" name="In_Mid_Out_Replace" type="L3LONG">
	/// 内、中、外管是否更换
	/// </Property>
	DECLARE_L3PROP_LONG(In_Mid_Out_Replace)

	/// <Property class="CLance_Check" name="Weld_Check" type="L3LONG">
	/// 焊缝检查
	/// </Property>
	DECLARE_L3PROP_LONG(Weld_Check)

	/// <Property class="CLance_Check" name="N2_And_Baffle_Check" type="L3LONG">
	/// 氮封孔及挡块检查
	/// </Property>
	DECLARE_L3PROP_LONG(N2_And_Baffle_Check)

	/// <Property class="CLance_Check" name="Ring_Check" type="L3LONG">
	/// 吊挂检查
	/// </Property>
	DECLARE_L3PROP_LONG(Ring_Check)

	/// <Property class="CLance_Check" name="Flange_Check" type="L3LONG">
	/// 氧枪法兰检查
	/// </Property>
	DECLARE_L3PROP_LONG(Flange_Check)

	/// <Property class="CLance_Check" name="Test_Water_Pressure" type="L3DOUBLE">
	/// 试水压力[MPa]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Water_Pressure)

	/// <Property class="CLance_Check" name="Keep_Pressure_Time" type="L3DOUBLE">
	/// 保压时间
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Keep_Pressure_Time)

	/// <Property class="CLance_Check" name="Test_Water_Result" type="L3LONG">
	/// 试水作业结果
	/// </Property>
	DECLARE_L3PROP_LONG(Test_Water_Result)

	/// <Property class="CLance_Check" name="Test_Water_Operator" type="L3STRING">
	/// 试水作业人
	/// </Property>
	DECLARE_L3PROP_STRING(Test_Water_Operator)

	/// <Property class="CLance_Check" name="BOFID" type="L3STRING">
	/// 使用转炉炉号
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CLance_Check" name="Rise_Lance_Date" type="L3DATETIME">
	/// 上枪日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rise_Lance_Date)

	/// <Property class="CLance_Check" name="On_Lance_Operator" type="L3STRING">
	/// 上枪作业人员
	/// </Property>
	DECLARE_L3PROP_STRING(On_Lance_Operator)

	/// <Property class="CLance_Check" name="Off_Lance_Operator" type="L3STRING">
	/// 下枪作业人员
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Lance_Operator)

	/// <Property class="CLance_Check" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLance_Check" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLance_Check" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLance_Check" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)


};
