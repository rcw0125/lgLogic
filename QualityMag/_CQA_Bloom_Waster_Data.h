// 逻辑类CQA_Bloom_Waster_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Bloom_Waster_Data :
	public CL3Object
{
public:
	CQA_Bloom_Waster_Data(void);
	virtual ~CQA_Bloom_Waster_Data(void);

	DECLARE_L3CLASS(CQA_Bloom_Waster_Data,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Bloom_Waster_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Bloom_Waster_Data" name="Produce_Date" type="L3DATETIME">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Produce_Date)

	/// <Property class="CQA_Bloom_Waster_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Bloom_Waster_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Bloom_Waster_Data" name="Cut_SteelGradeIndex" type="L3STRING">
	/// 切断炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_SteelGradeIndex)

	/// <Property class="CQA_Bloom_Waster_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CQA_Bloom_Waster_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CQA_Bloom_Waster_Data" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CQA_Bloom_Waster_Data" name="Bloom_Count" type="L3LONG">
	/// 钢坯枝数
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CQA_Bloom_Waster_Data" name="Cal_Weight" type="L3DOUBLE">
	/// 理论重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count" type="L3DOUBLE">
	/// 甩废总长度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight" type="L3DOUBLE">
	/// 甩废总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count1" type="L3DOUBLE">
	/// 甩废长度1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight1" type="L3DOUBLE">
	/// 甩废重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason1" type="L3STRING">
	/// 甩废原因1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count2" type="L3DOUBLE">
	/// 甩废长度2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight2" type="L3DOUBLE">
	/// 甩废重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason2" type="L3STRING">
	/// 甩废原因2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Count3" type="L3DOUBLE">
	/// 甩废长度3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Weight3" type="L3DOUBLE">
	/// 甩废重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Reason3" type="L3STRING">
	/// 甩废原因3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop1" type="L3STRING">
	/// 责任车间1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop2" type="L3STRING">
	/// 责任车间2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Shop3" type="L3STRING">
	/// 责任车间3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Shop3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit1" type="L3STRING">
	/// 责任机组1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit2" type="L3STRING">
	/// 责任机组2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Unit3" type="L3STRING">
	/// 责任机组3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Unit3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per1" type="L3STRING">
	/// 责任人1
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per1)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per2" type="L3STRING">
	/// 责任人2
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per2)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Per3" type="L3STRING">
	/// 责任人3
	/// </Property>
	DECLARE_L3PROP_STRING(Duty_Per3)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID1" type="L3STRING">
	/// 班组1
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID1)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID2" type="L3STRING">
	/// 班组2
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID2)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID3" type="L3STRING">
	/// 班组3
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID3)

	/// <Property class="CQA_Bloom_Waster_Data" name="Confirm_Per" type="L3STRING">
	/// 确认人
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Per)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Operator" type="L3STRING">
	/// 甩废人
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Operator)

	/// <Property class="CQA_Bloom_Waster_Data" name="Waster_Date" type="L3DATETIME">
	/// 甩废日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Waster_Date)

	/// <Property class="CQA_Bloom_Waster_Data" name="ShitID" type="L3STRING">
	/// 班次
	/// </Property>
	DECLARE_L3PROP_STRING(ShitID)

	/// <Property class="CQA_Bloom_Waster_Data" name="TeamID" type="L3STRING">
	/// 班别
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CQA_Bloom_Waster_Data" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CQA_Bloom_Waster_Data" name="Duty_Flag" type="L3SHORT">
	/// 指定责任标志
	/// </Property>
	DECLARE_L3PROP_LONG(Duty_Flag)

	/// <Property class="CQA_Bloom_Waster_Data" name="Object_ID" type="L3STRING">
	/// 主键
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
