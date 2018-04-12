// 逻辑类CQA_Iron_Element_Text_Text头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Iron_Element_Text :
	public CL3Object
{
public:
	CQA_Iron_Element_Text(void);
	virtual ~CQA_Iron_Element_Text(void);

	DECLARE_L3CLASS(CQA_Iron_Element_Text,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Iron_Element_Text)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Iron_Element_Text" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Iron_Element_Text" name="TAP_No" type="L3STRING">
	/// 铁次号
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CQA_Iron_Element_Text" name="TPC_No" type="L3STRING">
	/// 罐号
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Code" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Iron_Element_Text" name="Arrive_Date" type="L3DATETIME">
	/// 到样时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Iron_Element_Text" name="Report_Date" type="L3DATETIME">
	/// 报告时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Iron_Element_Text" name="UnitTypeID" type="L3SHORT">
	/// 工序：0：铁水，1：混铁炉，2：转炉，3：炉后，4：LF，5：RH，6：铸机
	/// </Property>
	DECLARE_L3PROP_LONG(UnitTypeID)

	/// <Property class="CQA_Iron_Element_Text" name="UnitID" type="L3SHORT">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_LONG(UnitID)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Type" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Count" type="L3STRING">
	/// 取样次数
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Iron_Element_Text" name="C" type="L3STRING">
	/// C
	/// </Property>
	DECLARE_L3PROP_STRING(C)

	/// <Property class="CQA_Iron_Element_Text" name="Si" type="L3STRING">
	/// Si
	/// </Property>
	DECLARE_L3PROP_STRING(Si)

	/// <Property class="CQA_Iron_Element_Text" name="Mn" type="L3STRING">
	/// Mn
	/// </Property>
	DECLARE_L3PROP_STRING(Mn)

	/// <Property class="CQA_Iron_Element_Text" name="P" type="L3STRING">
	/// P
	/// </Property>
	DECLARE_L3PROP_STRING(P)

	/// <Property class="CQA_Iron_Element_Text" name="S" type="L3STRING">
	/// S
	/// </Property>
	DECLARE_L3PROP_STRING(S)

	/// <Property class="CQA_Iron_Element_Text" name="S_Before" type="L3STRING">
	/// S_Before
	/// </Property>
	DECLARE_L3PROP_STRING(S_Before)

	/// <Property class="CQA_Iron_Element_Text" name="S_After" type="L3STRING">
	/// S_After
	/// </Property>
	DECLARE_L3PROP_STRING(S_After)

	/// <Property class="CQA_Iron_Element_Text" name="Ti" type="L3STRING">
	/// Ti
	/// </Property>
	DECLARE_L3PROP_STRING(Ti)

	/// <Property class="CQA_Iron_Element_Text" name="Sn" type="L3STRING">
	/// add by hyh 2012-04-04
	/// </Property>
	DECLARE_L3PROP_STRING(Sn)

	/// <Property class="CQA_Iron_Element_Text" name="Sb" type="L3STRING">
	/// add by hyh 2012-04-04
	/// </Property>
	DECLARE_L3PROP_STRING(Sb)

	/// <Property class="CQA_Iron_Element_Text" name="As" type="L3STRING">
	/// add by hyh 2012-04-04
	/// </Property>
	DECLARE_L3PROP_STRING(As)

	/// <Property class="CQA_Iron_Element_Text" name="Pb" type="L3STRING">
	/// add by hyh 2012-04-04
	/// </Property>
	DECLARE_L3PROP_STRING(Pb)

	//add by hyh 2012-08-09 应业务方要求新增：Ni(镍)、Mo(钼)、Cu(铜) 、Cr(铬)、B(硼)、V(钒)、Al(铝)、Nb(铌)、Zn(锌)、W(钨)
	/// <Property class="CQA_Iron_Element" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni)

	/// <Property class="CQA_Iron_Element" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo)

	/// <Property class="CQA_Iron_Element" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu)

	/// <Property class="CQA_Iron_Element" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr)

	/// <Property class="CQA_Iron_Element" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B)

	/// <Property class="CQA_Iron_Element" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V)

	/// <Property class="CQA_Iron_Element" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al)

	/// <Property class="CQA_Iron_Element" name="Nb" type="L3STRING">
	///Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb)

	/// <Property class="CQA_Iron_Element" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn)

	/// <Property class="CQA_Iron_Element" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W)
	//end

	/// <Property class="CQA_Iron_Element_Text" name="LogTime" type="L3DATETIME">
	/// 数据记录时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Iron_Element_Text" name="DataLogMode" type="L3SHORT">
	/// 数据产生方式：0：自动采集化验室；1：人工输入化验室;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Iron_Element_Text" name="Operator" type="L3STRING">
	/// 检验人
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)


};
