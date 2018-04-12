// 逻辑类CVacTube_Use_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Use_Info :
	public CL3Object
{
public:
	CVacTube_Use_Info(void);
	virtual ~CVacTube_Use_Info(void);

	DECLARE_L3CLASS(CVacTube_Use_Info,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Use_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	
	/// <Property class="CVacTube_Use_Info" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Use_Info" name="Install_ID" type="L3STRING">
	/// 真空槽组装编号
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Use_Info" name="Position" type="L3STRING">
	/// 处理位置
	/// </Property>
	DECLARE_L3PROP_STRING(Position)
	
	/// <Property class="CVacTube_Use_Info" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)
	
	/// <Property class="CVacTube_Use_Info" name="SteelGrade" type="L3STRING">
	/// 钢种
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)
	
	/// <Property class="CVacTube_Use_Info" name="VacTube_Code" type="L3STRING">
	/// 真空槽编号
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)
	
	/// <Property class="CVacTube_Use_Info" name="Up_Slot_ID" type="L3STRING">
	/// 上部槽号
	/// </Property>
	DECLARE_L3PROP_STRING(Up_Slot_ID)

	/// <Property class="CVacTube_Use_Info" name="Bel_Slot_ID" type="L3STRING">
	/// 下部槽号
	/// </Property>
	DECLARE_L3PROP_STRING(Bel_Slot_ID)

	/// <Property class="CVacTube_Use_Info" name="Up_Total_Age" type="L3LONG">
	/// 上部槽累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Up_Total_Age)

	/// <Property class="CVacTube_Use_Info" name="Bel_Total_Age" type="L3LONG">
	/// 下部槽累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Bel_Total_Age)

	/// <Property class="CVacTube_Use_Info" name="Cir_Total_Age" type="L3LONG">
	/// 环流管累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Cir_Total_Age)

	/// <Property class="CVacTube_Use_Info" name="Aes_Soa_On_Len" type="L3LONG">
	/// 上升管在线时长[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Aes_Soa_On_Len)

	/// <Property class="CVacTube_Use_Info" name="Aes_Soa_Total_Len" type="L3LONG">
	/// 上升管累计时长[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Aes_Soa_Total_Len)

	/// <Property class="CVacTube_Use_Info" name="Aes_Soa_Total_Age" type="L3LONG">
	/// 上升管累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Aes_Soa_Total_Age)

	/// <Property class="CVacTube_Use_Info" name="Des_Soa_On_Len" type="L3LONG">
	/// 下降管在线时长[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Soa_On_Len)

	/// <Property class="CVacTube_Use_Info" name="Des_Soa_Total_Len" type="L3LONG">
	/// 下降管累计时长[min]
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Soa_Total_Len)

	/// <Property class="CVacTube_Use_Info" name="Des_Soa_Total_Age" type="L3LONG">
	/// 下降管累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Des_Soa_Total_Age)

	/// <Property class="CVacTube_Use_Info" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Use_Info" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Use_Info" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CVacTube_Use_Info" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
