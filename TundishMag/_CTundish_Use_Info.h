// 逻辑类CTundish_Use_Info头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_Use_Info :
	public CL3Object
{
public:
	CTundish_Use_Info(void);
	virtual ~CTundish_Use_Info(void);

	DECLARE_L3CLASS(CTundish_Use_Info,XGMESLogic\\TundishMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_Use_Info)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_Use_Info" name="Creat_Time" type="L3DATETIME">
	/// 创建日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Creat_Time)

	/// <Property class="CTundish_Use_Info" name="TundishID" type="L3STRING">
	/// 中包包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_Use_Info" name="TundishNO" type="L3STRING">
	/// 包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_Use_Info" name="InnerID" type="L3STRING">
	/// 永久层编号
	/// </Property>
	DECLARE_L3PROP_STRING(InnerID)

	/// <Property class="CTundish_Use_Info" name="WorkID" type="L3STRING">
	/// 工作层编号
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CTundish_Use_Info" name="Vehicle_ID" type="L3STRING">
	/// 中包车号
	/// </Property>
	DECLARE_L3PROP_STRING(Vehicle_ID)

	/// <Property class="CTundish_Use_Info" name="Cast_ID" type="L3STRING">
	/// 去向
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_Use_Info" name="Inner_Tie_Start_Time" type="L3DATETIME">
	/// 永久层打结开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Tie_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Tie_End_Time" type="L3DATETIME">
	/// 永久层打结结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Tie_End_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Small_Fire_Time" type="L3DATETIME">
	/// 永久层开始烘烤时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Small_Fire_Time)

	/// <Property class="CTundish_Use_Info" name="Inner_Close_Fire_Time" type="L3DATETIME">
	/// 永久层结束烘烤时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Inner_Close_Fire_Time)

	/// <Property class="CTundish_Use_Info" name="Daub_Start_Time" type="L3DATETIME">
	/// 涂抹(干振)开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Daub_End_Time" type="L3DATETIME">
	/// 涂抹(干振)结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Daub_End_Time)

	/// <Property class="CTundish_Use_Info" name="Fire_Start_Time" type="L3DATETIME">
	/// 工作层烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Fire_End_Time" type="L3DATETIME">
	/// 工作层烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CTundish_Use_Info" name="Install_Start_Time" type="L3DATETIME">
	/// 上件开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Install_End_Time" type="L3DATETIME">
	/// 上件结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Install_End_Time)

	/// <Property class="CTundish_Use_Info" name="Hot_Small_Start_Time" type="L3DATETIME">
	/// 热备烘烤开始时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Hot_Small_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Hot_Big_End_Time" type="L3DATETIME">
	/// 热备烘烤结束时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Hot_Big_End_Time)

	/// <Property class="CTundish_Use_Info" name="Cast_Start_Time" type="L3DATETIME">
	/// 中包上线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cast_Start_Time)

	/// <Property class="CTundish_Use_Info" name="Cast_End_Time" type="L3DATETIME">
	/// 中包下线时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cast_End_Time)

	/// <Property class="CTundish_Use_Info" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};
