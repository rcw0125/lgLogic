// 逻辑类CEnergy_Manual_Data头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CEnergy_Manual_Data :
	public CL3Object
{
public:
	CEnergy_Manual_Data(void);
	virtual ~CEnergy_Manual_Data(void);

	DECLARE_L3CLASS(CEnergy_Manual_Data,XGMESLogic\\EnergyMag, ProductionDate)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CEnergy_Manual_Data)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CEnergy_Manual_Data" name="ProductionDate" type="L3STRING">
	/// 生产日期
	/// </Property>
	DECLARE_L3PROP_STRING(ProductionDate)

	/// <Property class="CEnergy_Manual_Data" name="Flow_CFCO" type="L3FLOAT">
	/// 焦炉煤气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_CFCO)

	/// <Property class="CEnergy_Manual_Data" name="Flow_BOFCO" type="L3FLOAT">
	/// 转炉煤气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_BOFCO)

	/// <Property class="CEnergy_Manual_Data" name="Flow_BOFCO_CallBack" type="L3FLOAT">
	/// 转炉煤气回收瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_BOFCO_CallBack)

	/// <Property class="CEnergy_Manual_Data" name="Flow_N2" type="L3FLOAT">
	/// 氮气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_N2)

	/// <Property class="CEnergy_Manual_Data" name="Flow_N2_SpecialSteel" type="L3FLOAT">
	/// 精品钢氮气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_N2_SpecialSteel)

	/// <Property class="CEnergy_Manual_Data" name="Flow_O2" type="L3FLOAT">
	/// 氧气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Flow_O2)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_D" type="L3FLOAT">
	/// 焦炉煤气日消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_D)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_D" type="L3FLOAT">
	/// 转炉煤气日消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_D)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_D" type="L3FLOAT">
	/// 转炉煤气回收日消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_D)

	/// <Property class="CEnergy_Manual_Data" name="N2_D" type="L3FLOAT">
	/// 氮气瞬时流量
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_D)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_D" type="L3FLOAT">
	/// 精品钢氮气日消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_D)

	/// <Property class="CEnergy_Manual_Data" name="O2_D" type="L3FLOAT">
	/// 氧气日消耗量
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_D)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_D_Avg" type="L3FLOAT">
	/// 焦炉煤气日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_D_Avg" type="L3FLOAT">
	/// 转炉煤气日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_D_Avg" type="L3FLOAT">
	/// 转炉煤气回收日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_D_Avg" type="L3FLOAT">
	/// 氮气日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_D_Avg" type="L3FLOAT">
	/// 精品钢氮气日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="O2_D_Avg" type="L3FLOAT">
	/// 氧气日单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_D_Avg)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_M" type="L3FLOAT">
	/// 焦炉煤气累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_M)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_M" type="L3FLOAT">
	/// 转炉煤气累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_M)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_M" type="L3FLOAT">
	/// 转炉煤气回收累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_M)

	/// <Property class="CEnergy_Manual_Data" name="N2_M" type="L3FLOAT">
	/// 氮气累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_M)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_M" type="L3FLOAT">
	/// 精品钢氮气累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_M)

	/// <Property class="CEnergy_Manual_Data" name="O2_M" type="L3FLOAT">
	/// 氧气累计消耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_M)

	/// <Property class="CEnergy_Manual_Data" name="CFCO_M_Avg" type="L3FLOAT">
	/// 焦炉煤气累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(CFCO_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_M_Avg" type="L3FLOAT">
	/// 转炉煤气累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="BOFCO_CallBack_M_Avg" type="L3FLOAT">
	/// 转炉煤气回收累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(BOFCO_CallBack_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_M_Avg" type="L3FLOAT">
	/// 氮气累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="N2_SpecialSteel_M_Avg" type="L3FLOAT">
	/// 精品钢氮气累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(N2_SpecialSteel_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="O2_M_Avg" type="L3FLOAT">
	/// 氧气累计单耗
	/// </Property>
	DECLARE_L3PROP_FLOAT(O2_M_Avg)

	/// <Property class="CEnergy_Manual_Data" name="Production_D" type="L3FLOAT">
	/// 日产量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_D)

	/// <Property class="CEnergy_Manual_Data" name="Production_M" type="L3FLOAT">
	/// 累计产量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_M)

	/// <Property class="CEnergy_Manual_Data" name="CreateTime" type="L3DATETIME">
	/// 录入时刻
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CEnergy_Manual_Data" name="Operator" type="L3STRING">
	/// 操作员
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CEnergy_Manual_Data" name="Status" type="L3LONG">
	/// 状态 
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CEnergy_Manual_Data" name="Production_Special_D" type="L3FLOAT">
	/// 精品钢日产量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_Special_D)

	/// <Property class="CEnergy_Manual_Data" name="Production_Special_M" type="L3FLOAT">
	/// 精品钢累计产量
	/// </Property>
	DECLARE_L3PROP_FLOAT(Production_Special_M)
};
