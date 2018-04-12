// 逻辑类CCCM_Heat_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CCCM_Heat_Data :
	public CL3Object
{
public:
	CCCM_Heat_Data(void);
	virtual ~CCCM_Heat_Data(void);

	DECLARE_L3CLASS(CCCM_Heat_Data,XGMESLogic\\CCMMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CCCM_Heat_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CCCM_Heat_Data" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CCCM_Heat_Data" name="CastingID" type="L3STRING">
	/// 浇次号
	/// </Property>
	DECLARE_L3PROP_STRING(CastingID)

	/// <Property class="CCCM_Heat_Data" name="CCMID" type="L3SHORT">
	/// 铸机号
	/// </Property>
	DECLARE_L3PROP_SHORT(CCMID)

	/// <Property class="CCCM_Heat_Data" name="Tundish_SeqNo" type="L3STRING">
	/// 中包序号
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_SeqNo)

	/// <Property class="CCCM_Heat_Data" name="TreatNo" type="L3STRING">
	/// 连铸处理号
	/// </Property>
	DECLARE_L3PROP_STRING(TreatNo)

	/// <Property class="CCCM_Heat_Data" name="Casting_HeatNum" type="L3LONG">
	/// 浇次内炉数
	/// </Property>
	DECLARE_L3PROP_LONG(Casting_HeatNum)

	/// <Property class="CCCM_Heat_Data" name="Tundish_HeatNum" type="L3LONG">
	/// 包次内连铸序号
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_HeatNum)

	/// <Property class="CCCM_Heat_Data" name="Pre_HeatID" type="L3STRING">
	/// 预定炉号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_HeatID)

	/// <Property class="CCCM_Heat_Data" name="Pre_LotNo" type="L3STRING">
	/// 预定包次号
	/// </Property>
	DECLARE_L3PROP_STRING(Pre_LotNo)

	/// <Property class="CCCM_Heat_Data" name="ShopSign" type="L3STRING">
	/// 产品牌号
	/// </Property>
	DECLARE_L3PROP_STRING(ShopSign)

	/// <Property class="CCCM_Heat_Data" name="Casting_Width" type="L3FLOAT">
	/// 铸造宽
	/// </Property>
	DECLARE_L3PROP_FLOAT(Casting_Width)

	/// <Property class="CCCM_Heat_Data" name="Casting_Thickness" type="L3FLOAT">
	/// 铸造厚
	/// </Property>
	DECLARE_L3PROP_FLOAT(Casting_Thickness)

	/// <Property class="CCCM_Heat_Data" name="Introduced_Count" type="L3LONG">
	/// 引流次数
	/// </Property>
	DECLARE_L3PROP_LONG(Introduced_Count)

	/// <Property class="CCCM_Heat_Data" name="Protect_Casting" type="L3LONG">
	/// 
	/// 保护浇注
	/// (1-是
	///  0-不是)
	/// </Property>
	DECLARE_L3PROP_LONG(Protect_Casting)

	/// <Property class="CCCM_Heat_Data" name="Blooms_Num" type="L3LONG">
	/// 铸坯支数
	/// </Property>
	DECLARE_L3PROP_LONG(Blooms_Num)

	/// <Property class="CCCM_Heat_Data" name="Primary_Weight" type="L3LONG">
	/// 粗坯量
	/// </Property>
	DECLARE_L3PROP_LONG(Primary_Weight)

	/// <Property class="CCCM_Heat_Data" name="StdBlooms_Num" type="L3LONG">
	/// 合格支数
	/// </Property>
	DECLARE_L3PROP_LONG(StdBlooms_Num)

	/// <Property class="CCCM_Heat_Data" name="StdBlooms_Weight" type="L3LONG">
	/// 合格重量
	/// </Property>
	DECLARE_L3PROP_LONG(StdBlooms_Weight)

	/// <Property class="CCCM_Heat_Data" name="SubStd_Blooms_Num" type="L3LONG">
	/// 不合格支数
	/// </Property>
	DECLARE_L3PROP_LONG(SubStd_Blooms_Num)

	/// <Property class="CCCM_Heat_Data" name="SubStd_Blooms_Weight" type="L3LONG">
	/// 不合格重量
	/// </Property>
	DECLARE_L3PROP_LONG(SubStd_Blooms_Weight)

	/// <Property class="CCCM_Heat_Data" name="Waster_Num" type="L3LONG">
	/// 甩废支数
	/// </Property>
	DECLARE_L3PROP_LONG(Waster_Num)

	/// <Property class="CCCM_Heat_Data" name="FinalCut_Time" type="L3DATETIME">
	/// 最终切断时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(FinalCut_Time)

	/// <Property class="CCCM_Heat_Data" name="SteelGradeIndex" type="L3STRING">
	/// 炼钢记号
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CCCM_Heat_Data" name="Waster_Weight" type="L3LONG">
	/// 甩废重量
	/// </Property>
	DECLARE_L3PROP_LONG(Waster_Weight)

	/// <Property class="CCCM_Heat_Data" name="Goods_Num" type="L3LONG">
	/// 合格支数
	/// </Property>
	DECLARE_L3PROP_LONG(Goods_Num)

	/// <Property class="CCCM_Heat_Data" name="InjectionBar_BlowAr" type="L3SHORT">
	/// 
	/// 是否塞棒吹氩
	/// (1-是
	///  0-不是)
	/// </Property>
	DECLARE_L3PROP_SHORT(InjectionBar_BlowAr)

	/// <Property class="CCCM_Heat_Data" name="Thickness" type="L3LONG">
	/// 厚度
	/// </Property>
	DECLARE_L3PROP_LONG(Thickness)

	/// <Property class="CCCM_Heat_Data" name="Width" type="L3LONG">
	/// 宽度
	/// </Property>
	DECLARE_L3PROP_LONG(Width)

	/// <Property class="CCCM_Heat_Data" name="Length" type="L3LONG">
	/// 长度
	/// </Property>
	DECLARE_L3PROP_LONG(Length)

	/// <Property class="CCCM_Heat_Data" name="Steel_Return_Div" type="L3SHORT">
	/// 
	/// 钢水返送区分
	/// (
	/// 0|正常
	/// 1|CC间全量移动
	/// 2|CC间部份移动
	/// 3|全量返送精炼
	/// 4|部份返送精炼
	/// 7|全量回炉
	/// 8|部份回炉
	/// 9|废弃)
	/// 
	/// </Property>
	DECLARE_L3PROP_SHORT(Steel_Return_Div)

	/// <Property class="CCCM_Heat_Data" name="Weight_Return" type="L3DOUBLE">
	/// 返回钢水量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Return)

	/// <Property class="CCCM_Heat_Data" name="Second_Cooling_Mode" type="L3SHORT">
	/// 
	/// 二冷水模式
	/// (1-L1、2-L2、0-手动)
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_Mode)

	/// <Property class="CCCM_Heat_Data" name="Second_Cooling_CurveNo" type="L3SHORT">
	/// 二冷水水表号
	/// </Property>
	DECLARE_L3PROP_SHORT(Second_Cooling_CurveNo)

	/// <Property class="CCCM_Heat_Data" name="Weight_Cut_Head" type="L3DOUBLE">
	/// 切头量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Head)

	/// <Property class="CCCM_Heat_Data" name="Weight_Cut_Trail" type="L3DOUBLE">
	/// 切尾量
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Weight_Cut_Trail)

	/// <Property class="CCCM_Heat_Data" name="Leak_Steel_Num" type="L3LONG">
	/// 漏钢次数
	/// </Property>
	DECLARE_L3PROP_LONG(Leak_Steel_Num)

};
