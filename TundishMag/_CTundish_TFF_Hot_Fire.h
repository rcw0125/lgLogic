// 逻辑类CTundish_TFF_Hot_Fire头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_TFF_Hot_Fire :
	public CL3Object
{
public:
	CTundish_TFF_Hot_Fire(void);
	virtual ~CTundish_TFF_Hot_Fire(void);

	DECLARE_L3CLASS(CTundish_TFF_Hot_Fire,XGMESLogic\\TundishMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_TFF_Hot_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_TFF_Hot_Fire" name="TundishID" type="L3STRING">
	/// 包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Cast_ID" type="L3STRING">
	/// 去向
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)
	
	/// <Property class="CTundish_TFF_Hot_Fire" name="VehicleID" type="L3STRING">
	/// 中包车号
	/// </Property>
	DECLARE_L3PROP_STRING(VehicleID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Crane_TeamID" type="L3STRING">
	/// 吊包班组
	/// </Property>
	DECLARE_L3PROP_STRING(Crane_TeamID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="First_Fra_ID" type="L3STRING">
	/// 1流机构编号
	/// </Property>
	DECLARE_L3PROP_STRING(First_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Second_Fra_ID" type="L3STRING">
	/// 
	/// 2流机构编号
	/// 
	/// </Property>
	DECLARE_L3PROP_STRING(Second_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Third_Fra_ID" type="L3STRING">
	/// 3流机构编号
	/// </Property>
	DECLARE_L3PROP_STRING(Third_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fourth_Fra_ID" type="L3STRING">
	/// 4流机构编号
	/// </Property>
	DECLARE_L3PROP_STRING(Fourth_Fra_ID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Small_Start_Time" type="L3DATETIME">
	/// 小火开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Small_End_Time" type="L3DATETIME">
	/// 小火结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Small_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Mid_Start_Time" type="L3DATETIME">
	/// 中火开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Mid_End_Time" type="L3DATETIME">
	/// 中火结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Mid_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Big_Start_Time" type="L3DATETIME">
	/// 大火开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_Start_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Big_End_Time" type="L3DATETIME">
	/// 大火结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Big_End_Time)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Note" type="L3STRING">
	/// 备注
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_TFF_Hot_Fire" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fir_Gas_Flux" type="L3DOUBLE">
	/// (0～10)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fir_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fir_Gas_Press" type="L3DOUBLE">
	/// (0～10)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fir_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sec_Gas_Flux" type="L3DOUBLE">
	/// (10～20)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sec_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sec_Gas_Press" type="L3DOUBLE">
	/// (10～20)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sec_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gas_Flux" type="L3DOUBLE">
	/// (20～60)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gas_Press" type="L3DOUBLE">
	/// (20～60)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Wall_Temp" type="L3DOUBLE">
	/// (20～60)中间包壁温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Thi_Gap_Temp" type="L3DOUBLE">
	/// (20～60)水口温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Thi_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gas_Flux" type="L3DOUBLE">
	/// (60～90)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gas_Press" type="L3DOUBLE">
	/// (60～90)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Wall_Temp" type="L3DOUBLE">
	/// (60～90)中间包壁温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fou_Gap_Temp" type="L3DOUBLE">
	/// (60～90)水口温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fou_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gas_Flux" type="L3DOUBLE">
	/// (90～120)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gas_Press" type="L3DOUBLE">
	/// (90～120)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Wall_Temp" type="L3DOUBLE">
	/// (90～120)中间包壁温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Fiv_Gap_Temp" type="L3DOUBLE">
	/// (90～120)水口温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fiv_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gas_Flux" type="L3DOUBLE">
	/// (120～150)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gas_Press" type="L3DOUBLE">
	/// (120～150)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Wall_Temp" type="L3DOUBLE">
	/// (120～150)中间包壁温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Six_Gap_Temp" type="L3DOUBLE">
	/// (120～150)水口温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Six_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gas_Flux" type="L3DOUBLE">
	/// (150～开浇)分钟煤气流量m3/h
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gas_Flux)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gas_Press" type="L3DOUBLE">
	/// (150～开浇)煤气压力kpa
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gas_Press)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Wall_Temp" type="L3DOUBLE">
	/// (150～开浇)中间包壁温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Wall_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Sev_Gap_Temp" type="L3DOUBLE">
	/// (150～开浇)水口温度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Sev_Gap_Temp)

	/// <Property class="CTundish_TFF_Hot_Fire" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};
