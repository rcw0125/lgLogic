// 逻辑类CLadle_In_Build头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_In_Build :
	public CL3Object
{
public:
	CLadle_In_Build(void);
	virtual ~CLadle_In_Build(void);

	DECLARE_L3CLASS(CLadle_In_Build,XGMESLogic\\LadleMag, InnerID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_In_Build)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_In_Build" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_In_Build" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CLadle_In_Build" name="LadleID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_In_Build" name="Build_Start_Time" type="L3DATETIME">
	/// 开始砌筑时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_In_Build" name="Build_End_Time" type="L3DATETIME">
	/// 结束砌筑时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_In_Build" name="Ato_Lig_Cast_Fac" type="L3STRING">
	/// 微孔轻质浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Ato_Lig_Cast_Fac)

	/// <Property class="CLadle_In_Build" name="Ato_Lig_Cast_Wast" type="L3DOUBLE">
	/// 微孔轻质浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ato_Lig_Cast_Wast)

	/// <Property class="CLadle_In_Build" name="Hard_Fi_Adi_Boa_Fac" type="L3STRING">
	/// 硬质纤维隔热板厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)

	/// <Property class="CLadle_In_Build" name="Hard_Fi_Adi_Boa_Wast" type="L3DOUBLE">
	/// 硬质纤维隔热板消耗量[m2]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)

	/// <Property class="CLadle_In_Build" name="Spinel_Cast_Fac" type="L3STRING">
	/// 尖晶石浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Spinel_Cast_Fac)

	/// <Property class="CLadle_In_Build" name="Spinel_Cast_Wast" type="L3DOUBLE">
	/// 尖晶石浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spinel_Cast_Wast)

	/// <Property class="CLadle_In_Build" name="Al_Mg_Brick_Fac" type="L3STRING">
	/// 铝镁砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Mg_Brick_Fac)

	/// <Property class="CLadle_In_Build" name="Al_Mg_Brick_Wast" type="L3DOUBLE">
	/// 铝镁砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Mg_Brick_Wast)

	/// <Property class="CLadle_In_Build" name="Mg_Firecaly_Fact" type="L3STRING">
	/// 镁火泥厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Mg_Firecaly_Fact)

	/// <Property class="CLadle_In_Build" name="Mg_Firecaly_Wast" type="L3DOUBLE">
	/// 镁火泥消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Firecaly_Wast)

	/// <Property class="CLadle_In_Build" name="Ladle_Inner_Use_Count" type="L3LONG">
	/// 永久层使用次数
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_In_Build" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_In_Build" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_In_Build" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_In_Build" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_In_Build" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};
