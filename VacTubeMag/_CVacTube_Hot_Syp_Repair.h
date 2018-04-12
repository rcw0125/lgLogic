// 逻辑类CVacTube_Hot_Syp_Repair头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Hot_Syp_Repair :
	public CL3Object
{
public:
	CVacTube_Hot_Syp_Repair(void);
	virtual ~CVacTube_Hot_Syp_Repair(void);

	DECLARE_L3CLASS(CVacTube_Hot_Syp_Repair,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Hot_Syp_Repair)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Build_ID" type="L3STRING">
	/// 砌筑编号
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Hot_Syp_ID" type="L3STRING">
	/// 热弯管编号
	/// </Property>
	DECLARE_L3PROP_STRING(Hot_Syp_ID)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Refra_Fac" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Hot_Syp_Age" type="L3LONG">
	/// 寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Syp_Age)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Mg_Cr_Bri_Dir_Waste" type="L3DOUBLE">
	/// 直接结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Dir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Mg_Cr_Bri_Half_Waste" type="L3DOUBLE">
	/// 半再结合Mg-Cr砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Mg_Cr_Bri_Half_Waste)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Bear_Fir_Waste" type="L3DOUBLE">
	/// 耐火泥[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bear_Fir_Waste)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Si_Ca_Boa_Waste" type="L3DOUBLE">
	/// 硅钙板[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Si_Ca_Boa_Waste)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Light_Mat_Bri_Waste" type="L3DOUBLE">
	/// 轻质砖[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Light_Mat_Bri_Waste)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Cast_Wast" type="L3DOUBLE">
	/// 浇注料[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Repair_Position" type="L3STRING">
	/// 修补部位
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Position)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Repair_Case" type="L3STRING">
	/// 修补情况
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Case)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Repair_Per" type="L3STRING">
	/// 修补人
	/// </Property>
	DECLARE_L3PROP_STRING(Repair_Per)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Hot_Syp_Repair" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)
};
