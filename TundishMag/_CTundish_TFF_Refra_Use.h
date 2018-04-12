// 逻辑类CTundish_TFF_Refra_Use头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CTundish_TFF_Refra_Use :
	public CL3Object
{
public:
	CTundish_TFF_Refra_Use(void);
	virtual ~CTundish_TFF_Refra_Use(void);

	DECLARE_L3CLASS(CTundish_TFF_Refra_Use,XGMESLogic\\TundishMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CTundish_TFF_Refra_Use)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CTundish_TFF_Refra_Use" name="Input_Time" type="L3DATETIME">
	/// 录入时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CTundish_TFF_Refra_Use" name="TundishID" type="L3STRING">
	/// 中包号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishID)

	/// <Property class="CTundish_TFF_Refra_Use" name="Cast_ID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_ID)

	/// <Property class="CTundish_TFF_Refra_Use" name="Stop_Cast_Reason" type="L3STRING">
	/// 停浇原因
	/// </Property>
	DECLARE_L3PROP_STRING(Stop_Cast_Reason)

	/// <Property class="CTundish_TFF_Refra_Use" name="Daub_Use_Case" type="L3STRING">
	/// 涂抹(干振)料使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Daub_Use_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Tranq_Case" type="L3STRING">
	/// 紊流器使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Tranq_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Frist_Tuck_Stick_Case" type="L3STRING">
	/// 1流塞棒使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Frist_Tuck_Stick_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Sec_Tuck_Stick_Case" type="L3STRING">
	/// 2流塞棒使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Sec_Tuck_Stick_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Thr_Tuck_Stick_Case" type="L3STRING">
	/// 3流塞棒使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Thr_Tuck_Stick_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="For_Tuck_Stick_Case" type="L3STRING">
	/// 4流塞棒使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(For_Tuck_Stick_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Frist_Water_Gap_Case" type="L3STRING">
	/// 1流水口使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Frist_Water_Gap_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Sec_Water_Gap_Case" type="L3STRING">
	/// 2流水口使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Sec_Water_Gap_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Thr_Water_Gap_Case" type="L3STRING">
	/// 3流水口使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Thr_Water_Gap_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="For_Water_Gap_Case" type="L3STRING">
	/// 4流水口使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(For_Water_Gap_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Ward_Dregs_Case" type="L3STRING">
	/// 挡渣墙使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Ward_Dregs_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Cover_Use_Case" type="L3STRING">
	/// 覆盖剂使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Cover_Use_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Protect_Use_Case" type="L3STRING">
	/// 保护渣使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Protect_Use_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Pro_Temp_Use_Case" type="L3STRING">
	/// 保温剂使用情况
	/// </Property>
	DECLARE_L3PROP_STRING(Pro_Temp_Use_Case)

	/// <Property class="CTundish_TFF_Refra_Use" name="Note" type="L3STRING">
	/// 过程异常说明
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CTundish_TFF_Refra_Use" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CTundish_TFF_Refra_Use" name="ShiftID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CTundish_TFF_Refra_Use" name="Operator" type="L3STRING">
	/// 责任人
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CTundish_TFF_Refra_Use" name="TundishNO" type="L3STRING">
	/// 包次号
	/// </Property>
	DECLARE_L3PROP_STRING(TundishNO)

	/// <Property class="CTundish_TFF_Refra_Use" name="Confirm_Flag" type="L3LONG">
	/// 实绩确认标志
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)
};
