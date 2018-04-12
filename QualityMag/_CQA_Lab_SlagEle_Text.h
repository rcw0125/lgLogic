// 逻辑类CQA_Lab_SlagEle_Text头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_SlagEle_Text :
	public CL3Object
{
public:
	CQA_Lab_SlagEle_Text(void);
	virtual ~CQA_Lab_SlagEle_Text(void);

	DECLARE_L3CLASS(CQA_Lab_SlagEle_Text,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_SlagEle_Text)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_SlagEle_Text" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Arrive_Date" type="L3DATETIME">
	/// 到样时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Report_Date" type="L3DATETIME">
	/// 报告时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Lab_SlagEle_Text" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Sample_Type" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Sample_Count" type="L3STRING">
	/// 取样次数
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Sample_Code" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_SlagEle_Text" name="TFe" type="L3STRING">
	/// TFe
	/// </Property>
	DECLARE_L3PROP_STRING(TFe)

	/// <Property class="CQA_Lab_SlagEle_Text" name="FeO" type="L3STRING">
	/// FeO、SiO2、TCa、CaO、MgO、Al203、MnO、TiO2、P2O5、S、R
	/// </Property>
	DECLARE_L3PROP_STRING(FeO)

	/// <Property class="CQA_Lab_SlagEle_Text" name="SiO2" type="L3STRING">
	/// SiO2
	/// </Property>
	DECLARE_L3PROP_STRING(SiO2)

	/// <Property class="CQA_Lab_SlagEle_Text" name="TCa" type="L3STRING">
	/// TCa
	/// </Property>
	DECLARE_L3PROP_STRING(TCa)

	/// <Property class="CQA_Lab_SlagEle_Text" name="CaO" type="L3STRING">
	/// CaO
	/// </Property>
	DECLARE_L3PROP_STRING(CaO)

	/// <Property class="CQA_Lab_SlagEle_Text" name="MgO" type="L3STRING">
	/// MgO
	/// </Property>
	DECLARE_L3PROP_STRING(MgO)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Al2O3" type="L3STRING">
	/// Al203
	/// </Property>
	DECLARE_L3PROP_STRING(Al2O3)

	/// <Property class="CQA_Lab_SlagEle_Text" name="MnO" type="L3STRING">
	/// MnO
	/// </Property>
	DECLARE_L3PROP_STRING(MnO)

	/// <Property class="CQA_Lab_SlagEle_Text" name="TiO2" type="L3STRING">
	/// TiO2
	/// </Property>
	DECLARE_L3PROP_STRING(TiO2)

	/// <Property class="CQA_Lab_SlagEle_Text" name="P2O5" type="L3STRING">
	/// P2O5、S、R
	/// </Property>
	DECLARE_L3PROP_STRING(P2O5)

	/// <Property class="CQA_Lab_SlagEle_Text" name="S" type="L3STRING">
	/// S
	/// </Property>
	DECLARE_L3PROP_STRING(S)

	/// <Property class="CQA_Lab_SlagEle_Text" name="R" type="L3STRING">
	/// R
	/// </Property>
	DECLARE_L3PROP_STRING(R)

	/// <Property class="CQA_Lab_SlagEle_Text" name="LogTime" type="L3DATETIME">
	/// 数据记录时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Lab_SlagEle_Text" name="DataLogMode" type="L3SHORT">
	/// 数据产生方式：0：自动采集化验室；1：人工输入化验室;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Lab_SlagEle_Text" name="Operator" type="L3STRING">
	/// 检验人
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)

};
