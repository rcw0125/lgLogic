// 逻辑类CVacTube_Hot_Syp_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CVacTube_Hot_Syp_Use :
	public CL3Object
{
public:
	CVacTube_Hot_Syp_Use(void);
	virtual ~CVacTube_Hot_Syp_Use(void);

	DECLARE_L3CLASS(CVacTube_Hot_Syp_Use,XGMESLogic\\VacTubeMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CVacTube_Hot_Syp_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CVacTube_Hot_Syp_Use" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Build_ID" type="L3STRING">
	/// 砌筑编号
	/// </Property>
	DECLARE_L3PROP_STRING(Build_ID)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Hot_Syp_ID" type="L3STRING">
	/// 热弯管编号
	/// </Property>
	DECLARE_L3PROP_STRING(Hot_Syp_ID)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Refra_Fac" type="L3STRING">
	/// 耐材厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Refra_Fac)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Time" type="L3DATETIME">
	/// 上线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(On_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Position" type="L3STRING">
	/// 上线工位
	/// </Property>
	DECLARE_L3PROP_STRING(Position)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_TeamID" type="L3STRING">
	/// 上线班组
	/// </Property>
	DECLARE_L3PROP_STRING(On_TeamID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Age" type="L3LONG">
	/// 上线寿命
	/// </Property>
	DECLARE_L3PROP_LONG(On_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Cur_Age" type="L3LONG">
	/// 在线寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Total_Age" type="L3LONG">
	/// 累计寿命
	/// </Property>
	DECLARE_L3PROP_LONG(Total_Age)

	/// <Property class="CVacTube_Hot_Syp_Use" name="OffLine_Time" type="L3DATETIME">
	/// 下线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(OffLine_Time)

	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_TeamID" type="L3STRING">
	/// 下线班组
	/// </Property>
	DECLARE_L3PROP_STRING(Off_TeamID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_Reason" type="L3STRING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Reason)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="OnLine_Len" type="L3DOUBLE">
	/// 在线时长[天]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(OnLine_Len)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CVacTube_Hot_Syp_Use" name="On_Operator" type="L3STRING">
	/// 上线操作员
	/// </Property>
	DECLARE_L3PROP_STRING(On_Operator)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="On_ShiftID" type="L3STRING">
	/// 上线班次
	/// </Property>
	DECLARE_L3PROP_STRING(On_ShiftID)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_Operator" type="L3STRING">
	/// 下线操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Operator)
	
	/// <Property class="CVacTube_Hot_Syp_Use" name="Off_ShiftID" type="L3STRING">
	/// 下线班次
	/// </Property>
	DECLARE_L3PROP_STRING(Off_ShiftID)
	
	
};
