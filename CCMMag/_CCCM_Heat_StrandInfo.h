// 逻辑类CCCM_Heat_StrandInfo头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_StrandInfo :
	public CL3Object
{
public:
	CCCM_Heat_StrandInfo(void);
	virtual ~CCCM_Heat_StrandInfo(void);

	DECLARE_L3CLASS(CCCM_Heat_StrandInfo,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_StrandInfo)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	///2009-02-13 删除中包工,增加机构编号、液面波动、是否堵流、堵流原因、漏钢次数、结晶器编号、铜管编号（5#机铜板）、铜管（铜板）厂家、炉次通钢量、累计通钢量(按铜管编号累计)

	/// <Property class="CCCM_Heat_StrandInfo" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_StrandInfo" name="CCMID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CCMID)

	/// <Property class="CCCM_Heat_StrandInfo" name="StrandID" type="L3LONG">
	/// 流号
	/// </Property>
	DECLARE_L3PROP_LONG(StrandID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Soft_Press_Flag" type="L3LONG">
	/// 
	/// 轻压下
	/// (1-轻压下
	///  0-非轻压下)
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Press_Flag)

	/// <Property class="CCCM_Heat_StrandInfo" name="Auto_Control" type="L3LONG">
	/// 
	/// 液面自动控制
	/// (1-自动控制
	///  0-非自动控制)
	/// </Property>
	DECLARE_L3PROP_LONG(Auto_Control)

	/// <Property class="CCCM_Heat_StrandInfo" name="Start_Time" type="L3DATETIME">
	/// 流开浇时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CCCM_Heat_StrandInfo" name="Stop_Time" type="L3DATETIME">
	/// 流停浇时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(Stop_Time)

	/// <Property class="CCCM_Heat_StrandInfo" name="Cast_Num" type="L3LONG">
	/// 流开浇次数
	/// </Property>
	DECLARE_L3PROP_LONG(Cast_Num)


	/// <Property class="CCCM_Heat_StrandInfo" name="WaterGap_Center" type="L3LONG">
	/// 
	/// 水口是否对中(0-对中;1-偏东;2-偏西)
	/// </Property>
	DECLARE_L3PROP_LONG(WaterGap_Center)

	/// <Property class="CCCM_Heat_StrandInfo" name="WaterGap_Deepness" type="L3LONG">
	/// 
	/// 水口深度
	/// 
	/// </Property>
	DECLARE_L3PROP_LONG(WaterGap_Deepness)

	/// <Property class="CCCM_Heat_StrandInfo" name="CastingStatus" type="L3LONG">
	/// 开停机状态
	/// </Property>
	DECLARE_L3PROP_LONG(CastingStatus)

	/// <Property class="CCCM_Heat_StrandInfo" name="Code" type="L3STRING">
	/// 机构编号
	/// </Property>
	DECLARE_L3PROP_STRING(Code)

	/// <Property class="CCCM_Heat_StrandInfo" name="liquid_level" type="L3STRING">
	/// 液面波动
	/// </Property>
	DECLARE_L3PROP_STRING(liquid_level)

	/// <Property class="CCCM_Heat_StrandInfo" name="Block_Up" type="L3LONG">
	/// 是否堵流
	/// </Property>
	DECLARE_L3PROP_LONG(Block_Up)


	/// <Property class="CCCM_Heat_StrandInfo" name="Block_Up_Reason" type="L3STRING">
	/// 堵流原因
	/// </Property>
	DECLARE_L3PROP_STRING(Block_Up_Reason)

	/// <Property class="CCCM_Heat_StrandInfo" name="BreakOut_Num" type="L3LONG">
	/// 漏钢次数
	/// </Property>
	DECLARE_L3PROP_LONG(BreakOut_Num)


	/// <Property class="CCCM_Heat_StrandInfo" name="MoldID" type="L3STRING">
	/// 结晶器编号
	/// </Property>
	DECLARE_L3PROP_STRING(MoldID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Copper_Fac" type="L3STRING">
	/// 铜管(板)厂家
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_Fac)

	/// <Property class="CCCM_Heat_StrandInfo" name="Copper_ID" type="L3STRING">
	/// 铜管(板)编号
	/// </Property>
	DECLARE_L3PROP_STRING(Copper_ID)

	/// <Property class="CCCM_Heat_StrandInfo" name="Heat_Weight" type="L3DOUBLE">
	/// 炉次通钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Heat_Weight)

	/// <Property class="CCCM_Heat_StrandInfo" name="Total_Weight" type="L3DOUBLE">
	/// 累计通钢量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Total_Weight)

};
