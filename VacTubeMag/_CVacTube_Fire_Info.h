// 逻辑类CVacTube_Fire_Info_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Fire_Info :
	public CL3Object
{
public:
	CVacTube_Fire_Info(void);
	virtual ~CVacTube_Fire_Info(void);

	DECLARE_L3CLASS(CVacTube_Fire_Info,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Fire_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Fire_Info" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Fire_Info" name="VacTube_Code" type="L3STRING">
	/// 真空槽编号
	/// </Property>
	DECLARE_L3PROP_STRING(VacTube_Code)

	/// <Property class="CVacTube_Fire_Info" name="Install_ID" type="L3STRING">
	/// 组装编号
	/// </Property>
	DECLARE_L3PROP_STRING(Install_ID)

	/// <Property class="CVacTube_Fire_Info" name="Time_ID" type="L3LONG">
	/// 时间[H]
	/// </Property>
	DECLARE_L3PROP_LONG(Time_ID)

	/// <Property class="CVacTube_Fire_Info" name="Position" type="L3STRING">
	/// 位置
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Fire_Info" name="Fact_Temp" type="L3DOUBLE">
	/// 实际温度[℃]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fact_Temp)

	/// <Property class="CVacTube_Fire_Info" name="Gun_Height" type="L3DOUBLE">
	/// 枪位高度[m]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gun_Height)

	/// <Property class="CVacTube_Fire_Info" name="Gas_Flow" type="L3DOUBLE">
	/// 煤气流量[Nm3/h]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Gas_Flow)

	/// <Property class="CVacTube_Fire_Info" name="O2_Flow" type="L3DOUBLE">
	/// 氧气流量[Nm3/h]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(O2_Flow)

	/// <Property class="CVacTube_Fire_Info" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CVacTube_Fire_Info" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CVacTube_Fire_Info" name="Log_Per" type="L3STRING">
	/// 记录人
	/// </Property>
	DECLARE_L3PROP_STRING(Log_Per)

	/// <Property class="CVacTube_Fire_Info" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Fire_Info" name="Object_ID" type="L3STRING">
	/// 主信息主键 组装编号 + 烘烤次数
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

	/// <Property class="CVacTube_Fire_Info" name="Fire_Soruce" type="L3LONG">
	/// 烘烤信号来源(0自动采集，1人工干预)
	/// </Property>
	DECLARE_L3PROP_LONG(Fire_Soruce)

};
