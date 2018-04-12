// 逻辑类CVacTube_Hot_Syp_Bui头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Hot_Syp_Bui :
	public CL3Object
{
public:
	CVacTube_Hot_Syp_Bui(void);
	virtual ~CVacTube_Hot_Syp_Bui(void);

	DECLARE_L3CLASS(CVacTube_Hot_Syp_Bui,XGMESLogic\\VacTubeMag, Build_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Hot_Syp_Bui)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_ID" type="L3STRING">
	/// 砌筑编号
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Hot_Syp_ID" type="L3STRING">
	/// 热弯管编号
	/// </Property>
	DECLARE_L3PROP_STRING(Hot_Syp_ID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_Start_Time" type="L3DATETIME">
	/// 砌筑开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Build_End_Time" type="L3DATETIME">
	/// 砌筑结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Refra_Fac" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Hot_Syp_Age" type="L3LONG">
	/// 寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Syp_Age)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Mg_Cr_Bri_Dir_Waste" type="L3DOUBLE">
	/// 直接结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Mg_Cr_Bri_Half_Waste" type="L3DOUBLE">
	/// 半再结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Bear_Fir_Waste" type="L3DOUBLE">
	/// 耐火泥[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bear_Fir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Si_Ca_Boa_Waste" type="L3DOUBLE">
	/// 硅钙板[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Ca_Boa_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Light_Mat_Bri_Waste" type="L3DOUBLE">
	/// 轻质砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Light_Mat_Bri_Waste)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Cast_Wast" type="L3DOUBLE">
	/// 浇注料[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CVacTube_Hot_Syp_Bui" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
	
};
