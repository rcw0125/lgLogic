// 逻辑类CVacTube_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Fire :
	public CL3Object
{
public:
	CVacTube_Fire(void);
	virtual ~CVacTube_Fire(void);

	DECLARE_L3CLASS(CVacTube_Fire,XGMESLogic\\VacTubeMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Fire" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)
	
	/// <Property class="CVacTube_Fire" name="VacTube_Code" type="L3STRING">
	/// 真空槽编号
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Fire" name="Install_ID" type="L3STRING">
	/// 组装编号
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Fire" name="Position" type="L3STRING">
	/// 位置
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Fire" name="Up_Slot_ID" type="L3STRING">
	/// 上部槽编号
	/// </Property>
	DECLARE_L3PROP_STRING(Up_Slot_ID)

	/// <Property class="CVacTube_Fire" name="Bel_Slot_ID" type="L3STRING">
	/// 下部槽编号
	/// </Property>
	DECLARE_L3PROP_STRING(Bel_Slot_ID)

	/// <Property class="CVacTube_Fire" name="Fire_Start_Time" type="L3DATETIME">
	/// 点火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CVacTube_Fire" name="Fire_End_Time" type="L3DATETIME">
	/// 停火时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CVacTube_Fire" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Fire" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Fire" name="Log_Per" type="L3STRING">
	/// 记录人
	/// </Property>
	DECLARE_L3PROP_STRING(Log_Per)

	/// <Property class="CVacTube_Fire" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Fire" name="Object_ID" type="L3STRING">
	/// 主键 组装编号 + 烘烤次数
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

	/// <Property class="CVacTube_Fire" name="Fire_Soruce" type="L3LONG">
	/// 烘烤信号来源(0自动采集，1人工干预)
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Soruce)


};
