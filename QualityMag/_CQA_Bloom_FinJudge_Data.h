// 逻辑类CQA_Bloom_CoolJudge_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Bloom_FinJudge_Data :
	public CL3Object
{
public:
	CQA_Bloom_FinJudge_Data(void);
	virtual ~CQA_Bloom_FinJudge_Data(void);

	DECLARE_L3CLASS(CQA_Bloom_FinJudge_Data,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Bloom_FinJudge_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Bloom_FinJudge_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

/// <Property class="CQA_Bloom_FinJudge_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Cut_SteelGradeIndex" type="L3STRING">
	/// 切断炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_SteelGradeIndex)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Final_SteelGradeIndex" type="L3STRING">
	/// 最终炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Final_SteelGradeIndex)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Bloom_Count" type="L3SHORT">
	/// 钢坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Cal_Weight" type="L3DOUBLE">
	/// 理论重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Right_Count" type="L3SHORT">
	/// 合格支数
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Right_Weight" type="L3DOUBLE">
	/// 合格重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Count" type="L3DOUBLE">
	/// 甩废总长度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Weight" type="L3DOUBLE">
	/// 甩废总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Count1" type="L3DOUBLE">
	/// 甩废长度1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Weight1" type="L3DOUBLE">
	/// 甩废重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Reason1" type="L3STRING">
	/// 甩废原因1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Count2" type="L3DOUBLE">
	/// 甩废长度2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Weight2" type="L3DOUBLE">
	/// 甩废重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Reason2" type="L3STRING">
	/// 甩废原因2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Count3" type="L3DOUBLE">
	/// 甩废长度3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Weight3" type="L3DOUBLE">
	/// 甩废重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Waster_Reason3" type="L3STRING">
	/// 甩废原因3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Count" type="L3SHORT">
	/// 不合格总支数
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Weight" type="L3DOUBLE">
	/// 不合格总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Count1" type="L3SHORT">
	/// 不合格支数1
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Weight1" type="L3DOUBLE">
	/// 不合格重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Reason1" type="L3STRING">
	/// 不合格原因1
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason1)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Count2" type="L3SHORT">
	/// 不合格支数2
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Weight2" type="L3DOUBLE">
	/// 不合格重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Reason2" type="L3STRING">
	/// 不合格原因2
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason2)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Count3" type="L3SHORT">
	/// 不合格支数3
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Weight3" type="L3DOUBLE">
	/// 不合格重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Wrong_Reason3" type="L3STRING">
	/// 不合格原因3
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason3)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="SufaceDefactDes" type="L3STRING">
	/// 表面缺陷描述
	/// </Property>
	DECLARE_L3PROP_STRING(SufaceDefactDes)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="FinishedTime" type="L3DATETIME">
	/// 精整时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinishedTime)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="FinalJudge_Time" type="L3DATETIME">
	/// 终判时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinalJudge_Time)


	/// <Property class="CQA_Bloom_FinJudge_Data" name="Process_Type" type="L3LONG">
	/// 处置方式
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Type)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Exceptional_Code" type="L3STRING">
	/// 异常代码
	/// </Property>
	DECLARE_L3PROP_STRING(Exceptional_Code)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Decide_Code" type="L3STRING">
	/// 处置代码
	/// </Property>
	DECLARE_L3PROP_STRING(Decide_Code)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Team" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Shift" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Test_Roll_Count" type="L3SHORT">
	/// 试轧钢坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Test_Roll_Count)

	/// <Property class="CQA_Bloom_FinJudge_Data" name="Test_Roll_Weight" type="L3DOUBLE">
	/// 试轧钢坯重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Roll_Weight)

	/// <Property class="CBOF_Base_Data" name="NC_Confirm_Flag" type="L3LONG">
	/// NC确认标志
	/// </Property>
	///2009-02-25
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

	/// <Property class="CBOF_Base_Data" name="Store_ChangeJudge_Flag" type="L3LONG">
	/// 库内改判标志
	/// </Property>
	///2009-02-25
	DECLARE_L3PROP_LONG(Store_ChangeJudge_Flag)


};