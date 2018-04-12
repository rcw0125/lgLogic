// 逻辑类CBloom_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once
#include "Material.h"

class CBloom_Data :
	public Material
{
public:
	CBloom_Data(void);
	virtual ~CBloom_Data(void);

	DECLARE_L3CLASS(CBloom_Data, MES\\MaterialData, MaterialID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBloom_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CBloom_Data" name="CasterID" type="L3STRING">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_STRING(CasterID)

	/// <Property class="CBloom_Data" name="Casting_No" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(Casting_No)

	/// <Property class="CBloom_Data" name="Casting_Heat_Cnt" type="L3LONG">
	/// 浇次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_Heat_Cnt)

	/// <Property class="CBloom_Data" name="Pre_SteelGradeIndex" type="L3STRING">
	/// 预定炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Cut_SteelGradeIndex" type="L3STRING">
	/// 切断炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Cut_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Final_SteelGradeIndex" type="L3STRING">
	/// 最终炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(Final_SteelGradeIndex)

	/// <Property class="CBloom_Data" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CBloom_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CBloom_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CBloom_Data" name="Cur_Section_ID" type="L3STRING">
	/// 当前区
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Section_ID)

	/// <Property class="CBloom_Data" name="Cur_Pile_ID" type="L3STRING">
	/// 当前垛
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Pile_ID)

	/// <Property class="CBloom_Data" name="Cur_Layer_ID" type="L3LONG">
	/// 当前层
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Layer_ID)//2009-03-09 将类型改为串，一炉钢坯可以放几个层

	/// <Property class="CBloom_Data" name="Cur_Seq_ID" type="L3LONG">
	/// 当前顺序
	/// </Property>
	DECLARE_L3PROP_LONG(Cur_Seq_ID)

	/// <Property class="CBloom_Data" name="Cur_Bay_ID" type="L3STRING">
	/// 当前跨
	/// </Property>
	DECLARE_L3PROP_STRING(Cur_Bay_ID)

	/// <Property class="CBloom_Data" name="Destination" type="L3STRING">
	/// 去向
	/// </Property>
	DECLARE_L3PROP_STRING(Destination)

	/// <Property class="CBloom_Data" name="Hot_Send_Flag" type="L3LONG">
	/// 热送标志
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Send_Flag)

	/// <Property class="CBloom_Data" name="Process_Type" type="L3LONG">
	/// 处置方式
	/// </Property>
	DECLARE_L3PROP_LONG(Process_Type)

	/// <Property class="CBloom_Data" name="Plan_Ord_ID" type="L3STRING">
	/// 计划订单号
	/// </Property>
	DECLARE_L3PROP_STRING(Plan_Ord_ID)

	/// <Property class="CBloom_Data" name="Produce_Date" type="L3DATETIME">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_DATETIME(Produce_Date)

	/// <Property class="CBloom_Data" name="Finish_Flag" type="L3LONG">
	/// 质量抽检标志，0：正常，1：抽检，2：已冷检判定
	/// </Property>
	DECLARE_L3PROP_LONG(Finish_Flag)

	/// <Property class="CBloom_Data" name="FinishedTime" type="L3DATETIME">
	/// 质量抽检时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinishedTime)

	/// <Property class="CBloom_Data" name="Bloom_Count" type="L3LONG">
	/// 实际钢坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Bloom_Count)

	/// <Property class="CBloom_Data" name="Cal_Weight" type="L3DOUBLE">
	/// 理论重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cal_Weight)

	/// <Property class="CBloom_Data" name="Right_Count" type="L3LONG">
	/// 合格钢坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Right_Count)

	/// <Property class="CBloom_Data" name="Right_Weight" type="L3DOUBLE">
	/// 合格重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Right_Weight)

	/// <Property class="CBloom_Data" name="Waster_Count" type="L3DOUBLE">
	/// 甩废钢坯总长度
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count)

	/// <Property class="CBloom_Data" name="Waster_Weight" type="L3DOUBLE">
	/// 甩废重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight)

	/// <Property class="CBloom_Data" name="Waster_Count1" type="L3LONG">
	/// 甩废钢坯长度1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count1)

	/// <Property class="CBloom_Data" name="Waster_Weight1" type="L3DOUBLE">
	/// 甩废重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight1)

	/// <Property class="CBloom_Data" name="Waster_Reason1" type="L3STRING">
	/// 甩废原因1
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason1)

	/// <Property class="CBloom_Data" name="Waster_Count2" type="L3DOUBLE">
	/// 甩废钢坯长度2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count2)

	/// <Property class="CBloom_Data" name="Waster_Weight2" type="L3DOUBLE">
	/// 甩废重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight2)

	/// <Property class="CBloom_Data" name="Waster_Reason2" type="L3STRING">
	/// 甩废原因2
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason2)

	/// <Property class="CBloom_Data" name="Waster_Count3" type="L3DOUBLE">
	/// 甩废钢坯长度3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Count3)

	/// <Property class="CBloom_Data" name="Waster_Weight3" type="L3DOUBLE">
	/// 甩废重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Waster_Weight3)

	/// <Property class="CBloom_Data" name="Waster_Reason3" type="L3STRING">
	/// 甩废原因3
	/// </Property>
	DECLARE_L3PROP_STRING(Waster_Reason3)

	/// <Property class="CBloom_Data" name="Wrong_Count" type="L3LONG">
	/// 不合格钢坯总支数
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count)

	/// <Property class="CBloom_Data" name="Wrong_Weight" type="L3DOUBLE">
	/// 不合格总重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight)

	/// <Property class="CBloom_Data" name="Wrong_Count1" type="L3LONG">
	/// 不合格钢坯支数1
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count1)

	/// <Property class="CBloom_Data" name="Wrong_Weight1" type="L3DOUBLE">
	/// 不合格重量1
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight1)

	/// <Property class="CBloom_Data" name="Wrong_Reason1" type="L3STRING">
	/// 不合格原因1
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason1)

	/// <Property class="CBloom_Data" name="Wrong_Count2" type="L3LONG">
	/// 不合格钢坯支数2
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count2)

	/// <Property class="CBloom_Data" name="Wrong_Weight2" type="L3DOUBLE">
	/// 不合格重量2
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight2)

	/// <Property class="CBloom_Data" name="Wrong_Reason2" type="L3STRING">
	/// 不合格原因2
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason2)

	/// <Property class="CBloom_Data" name="Wrong_Count3" type="L3LONG">
	/// 不合格钢坯支数3
	/// </Property>
	DECLARE_L3PROP_LONG(Wrong_Count3)

	/// <Property class="CBloom_Data" name="Wrong_Weight3" type="L3DOUBLE">
	/// 不合格重量3
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wrong_Weight3)

	/// <Property class="CBloom_Data" name="Wrong_Reason3" type="L3STRING">
	/// 不合格原因3
	/// </Property>
	DECLARE_L3PROP_STRING(Wrong_Reason3)

	/// <Property class="CBloom_Data" name="SufaceDefactDes" type="L3STING">
	/// 表面缺陷描述
	/// </Property>
	DECLARE_L3PROP_STRING(SufaceDefactDes)

	/// <Property class="CBloom_Data" name="Reason" type="L3STING">
	/// 下线原因
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)

	/// <Property class="CBloom_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CBloom_Data" name="Test_Roll_Count" type="L3LONG">
	/// 试轧钢坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Test_Roll_Count)

	/// <Property class="CBloom_Data" name="Test_Roll_Weight" type="L3DOUBLE">
	/// 试轧钢坯重量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Test_Roll_Weight)

	/// <Property class="CBloom_Data" name="Back_Flag" type="L3LONG">
	/// 钢坯逆送标志2009-04-02
	/// </Property>
	DECLARE_L3PROP_LONG(Back_Flag)

	/// <Property class="CBloom_Data" name="Back_Date" type="L3LONG">
	/// 钢坯逆送时间2009-04-02
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Date)

	
	/// <Property class="CBloom_Data" name="Add_Bloom_Count" type="L3LONG">
	/// 拨入钢坯支数1 2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Add_Bloom_Count)

	/// <Property class="CBloom_Data" name="Div_Bloom_Count" type="L3LONG">
	/// 拨出钢坯支数2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Div_Bloom_Count)

	/// <Property class="CBloom_Data" name="Plan_Bloom_Count" type="L3LONG">
	/// 计划钢坯支数2009-08-06
	/// </Property>
	DECLARE_L3PROP_LONG(Plan_Bloom_Count)


	/// <Property class="CBloom_Data" name="Add_Div_HeatID" type="L3STRING">
	/// 拨出炉号
	/// </Property>
	DECLARE_L3PROP_STRING(Add_Div_HeatID)


	/// <Property class="CBloom_Data" name="Add_HeatID1" type="L3STRING">
	/// 拨入炉号1 2009-08-21
	/// </Property>
	DECLARE_L3PROP_STRING(Add_HeatID1)

	/// <Property class="CBloom_Data" name="Add_HeatID2" type="L3STRING">
	/// 拨入炉号2 2009-08-21
	/// </Property>
	DECLARE_L3PROP_STRING(Add_HeatID2)

	/// <Property class="CBloom_Data" name="Add_Bloom_Count2" type="L3LONG">
	/// 拨入钢坯支数2 2009-08-21
	/// </Property>
	DECLARE_L3PROP_LONG(Add_Bloom_Count2)

};
