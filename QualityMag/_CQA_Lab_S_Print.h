// 逻辑类CQA_Lab_S_Print头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_S_Print :
	public CL3Object
{
public:
	CQA_Lab_S_Print(void);
	virtual ~CQA_Lab_S_Print(void);

	DECLARE_L3CLASS(CQA_Lab_S_Print,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_S_Print)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_S_Print" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_S_Print" name="Arrive_Date" type="L3DATETIME">
	/// 到样时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Lab_S_Print" name="Report_Date" type="L3DATETIME">
	/// 报告时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Lab_S_Print" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Type" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Count" type="L3STRING">
	/// 取样次数
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_S_Print" name="Sample_Code" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_S_Print" name="Shrinkage_Hole" type="L3STRING">
	/// 缩孔
	/// </Property>
	DECLARE_L3PROP_STRING(Shrinkage_Hole)

	/// <Property class="CQA_Lab_S_Print" name="Center_Loose" type="L3STRING">
	/// 中心疏松
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Loose)

	/// <Property class="CQA_Lab_S_Print" name="Common_Loose" type="L3STRING">
	/// 一般疏松
	/// </Property>
	DECLARE_L3PROP_STRING(Common_Loose)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack_Lev" type="L3STRING">
	/// 中心裂纹级别
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack_Lev)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack_Len" type="L3STRING">
	/// 中心裂纹长度
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack_Len)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Bubble" type="L3STRING">
	/// 皮下气泡
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Bubble)

	/// <Property class="CQA_Lab_S_Print" name="Center_Crack" type="L3STRING">
	/// 中间裂纹
	/// </Property>
	DECLARE_L3PROP_STRING(Center_Crack)

	/// <Property class="CQA_Lab_S_Print" name="Equiaxed_Grain" type="L3STRING">
	/// 等轴晶
	/// </Property>
	DECLARE_L3PROP_STRING(Equiaxed_Grain)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_D" type="L3STRING">
	/// 皮下裂纹d
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_D)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_L" type="L3STRING">
	/// 皮下裂纹l
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_L)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_Q" type="L3STRING">
	/// 皮下裂纹q
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_Q)

	/// <Property class="CQA_Lab_S_Print" name="Hypo_Crack_Lev" type="L3STRING">
	/// 皮下裂纹级别
	/// </Property>
	DECLARE_L3PROP_STRING(Hypo_Crack_Lev)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Eyelet" type="L3STRING">
	/// 纵表面针眼
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Eyelet)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Crack" type="L3STRING">
	/// 纵表面裂纹
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Crack)

	/// <Property class="CQA_Lab_S_Print" name="Surface_Slag" type="L3STRING">
	/// 纵表面夹渣
	/// </Property>
	DECLARE_L3PROP_STRING(Surface_Slag)

	/// <Property class="CQA_Lab_S_Print" name="Nonmetal_Slag" type="L3STRING">
	/// 非金属夹渣
	/// </Property>
	DECLARE_L3PROP_STRING(Nonmetal_Slag)

	/// <Property class="CQA_Lab_S_Print" name="Spot" type="L3STRING">
	/// 斑点
	/// </Property>
	DECLARE_L3PROP_STRING(Spot)

	/// <Property class="CQA_Lab_S_Print" name="AcidTime" type="L3STRING">
	/// 酸蚀时间
	/// </Property>
	DECLARE_L3PROP_STRING(AcidTime)

	/// <Property class="CQA_Lab_S_Print" name="S_Print" type="L3STRING">
	/// 硫印结果"0:不合格，1：合格，空：没有做"
	/// </Property>
	DECLARE_L3PROP_STRING(S_Print)

	/// <Property class="CQA_Lab_S_Print" name="LogTime" type="L3DATETIME">
	/// 接收时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Lab_S_Print" name="DataLogMode" type="L3DATETIME">
	/// 数据产生方式：0：自动采集化验室；1：人工输入化验室;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Lab_S_Print" name="StrandID" type="L3STRING">
	///流号
	/// </Property>
	DECLARE_L3PROP_STRING(StrandID)

	/// <Property class="CQA_Lab_S_Print" name="Size" type="L3STRING">
	///尺寸
	/// </Property>
	DECLARE_L3PROP_STRING(Size)

	/// <Property class="CQA_Lab_S_Print" name="Operator" type="L3STRING">
	/// 检验人
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)

};
