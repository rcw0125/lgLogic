// 逻辑类CVacTube_Build头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Build :
	public CL3Object
{
public:
	CVacTube_Build(void);
	virtual ~CVacTube_Build(void);

	DECLARE_L3CLASS(CVacTube_Build,XGMESLogic\\VacTubeMag, Build_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Build)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Build" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Build" name="Build_ID" type="L3STRING">
	/// 砌筑编号
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Build" name="VacTube_Name" type="L3STRING">
	/// 槽管名称
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Name)

	/// <Property class="CVacTube_Build" name="VacTube_Id" type="L3STRING">
	/// 槽管编号
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Id)

	/// <Property class="CVacTube_Build" name="Build_Start_Time" type="L3DATETIME">
	/// 砌筑开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CVacTube_Build" name="Build_End_Time" type="L3DATETIME">
	/// 砌筑结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CVacTube_Build" name="Refra_Fac" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Build" name="Wall_Bri_Thick" type="L3DOUBLE">
	/// 槽壁砖厚度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wall_Bri_Thick)

	/// <Property class="CVacTube_Build" name="Bot_Bri_Thick" type="L3DOUBLE">
	/// 槽底砖厚度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Bri_Thick)

	/// <Property class="CVacTube_Build" name="RH_Age" type="L3LONG">
	/// 槽寿命
	/// </Property>
	DECLARE_L3PROP_LONG(RH_Age)

	/// <Property class="CVacTube_Build" name="InWall_Bri_Thick" type="L3DOUBLE">
	/// 槽壁残砖厚度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(InWall_Bri_Thick)

	/// <Property class="CVacTube_Build" name="InBot_Bri_Thick" type="L3DOUBLE">
	/// 槽底残砖厚度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(InBot_Bri_Thick)

	/// <Property class="CVacTube_Build" name="Mg_Cr_Bri_Ele_Waste" type="L3DOUBLE">
	/// 电熔再结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Ele_Waste)

	/// <Property class="CVacTube_Build" name="Mg_Cr_Bri_Dir_Waste" type="L3DOUBLE">
	/// 直接结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)

	/// <Property class="CVacTube_Build" name="Mg_Cr_Bri_Half_Waste" type="L3DOUBLE">
	/// 半再结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)

	/// <Property class="CVacTube_Build" name="Mg_Cr_Fir_Waste" type="L3DOUBLE">
	/// Mg-Cr火泥[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Fir_Waste)

	/// <Property class="CVacTube_Build" name="Bear_Fir_Waste" type="L3DOUBLE">
	/// 耐火泥[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bear_Fir_Waste)

	/// <Property class="CVacTube_Build" name="Si_Ca_Boa_Waste" type="L3DOUBLE">
	/// 硅钙板[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Ca_Boa_Waste)

	/// <Property class="CVacTube_Build" name="Light_Mat_Bri_Waste" type="L3DOUBLE">
	/// 轻质砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Light_Mat_Bri_Waste)

	/// <Property class="CVacTube_Build" name="Pug_Hit_Mat_Waste" type="L3DOUBLE">
	/// 捣打料[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Pug_Hit_Mat_Waste)

	/// <Property class="CVacTube_Build" name="Cast_Wast" type="L3DOUBLE">
	/// 浇注料[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CVacTube_Build" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Build" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Build" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CVacTube_Build" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
