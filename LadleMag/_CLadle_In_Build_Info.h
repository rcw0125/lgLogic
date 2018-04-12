// 逻辑类CLadle_In_Build_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CLadle_In_Build_Info :
	public CL3Object
{
public:
	CLadle_In_Build_Info(void);
	virtual ~CLadle_In_Build_Info(void);

	DECLARE_L3CLASS(CLadle_In_Build_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_In_Build_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CLadle_In_Build_Info" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_In_Build_Info" name="Number" type="L3SHORT">
	/// 编号
	/// </Property>
	DECLARE_L3PROP_SHORT(Number)

	/// <Property class="CLadle_In_Build_Info" name="Ladle_ID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_In_Build_Info" name="Build_Start_Time" type="L3DATETIME">
	/// 开始砌筑时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_In_Build_Info" name="Build_End_Time" type="L3DATETIME">
	/// 结束砌筑时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_In_Build_Info" name="Ato_Lig_Cast_Fac" type="L3STRING">
	/// 微孔轻质浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Ato_Lig_Cast_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Ato_Lig_Cast_Wast" type="L3DOUBLE">
	/// 微孔轻质浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ato_Lig_Cast_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Hard_Fi_Adi_Boa_Fac" type="L3STRING">
	/// 硬质纤维隔热板厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Hard_Fi_Adi_Boa_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Hard_Fi_Adi_Boa_Wast" type="L3DOUBLE">
	/// 硬质纤维隔热板消耗量[m2]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hard_Fi_Adi_Boa_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Spinel_Cast_Fac" type="L3STRING">
	/// 尖晶石浇铸料厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Spinel_Cast_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Spinel_Cast_Wast" type="L3DOUBLE">
	/// 尖晶石浇铸料消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spinel_Cast_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Al_Mg_Brick_Fac" type="L3STRING">
	/// 铝镁砖厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Al_Mg_Brick_Fac)

	/// <Property class="CLadle_In_Build_Info" name="Al_Mg_Brick_Wast" type="L3DOUBLE">
	/// 铝镁砖消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Mg_Brick_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Mg_Firecaly_Fact" type="L3STRING">
	/// 镁火泥厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Mg_Firecaly_Fact)

	/// <Property class="CLadle_In_Build_Info" name="Mg_Firecaly_Wast" type="L3DOUBLE">
	/// 镁火泥消耗量[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Firecaly_Wast)

	/// <Property class="CLadle_In_Build_Info" name="Ladle_Inner_Use_Count" type="L3SHORT">
	/// 永久层使用次数
	/// </Property>
	DECLARE_L3PROP_SHORT(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_In_Build_Info" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_In_Build_Info" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_In_Build_Info" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_In_Build_Info" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
