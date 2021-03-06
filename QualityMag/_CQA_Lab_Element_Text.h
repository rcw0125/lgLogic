// 逻辑类CQA_Lab_Element_Text头文件
// 本文件是由L3集成开发环境自动生成，在没有充分了解本文件的内容前，请不要随意修改本文件中的内容
// 否则可能带来严重后果。
#pragma once

class CQA_Lab_Element_Text :
	public CL3Object
{
public:
	CQA_Lab_Element_Text(void);
	virtual ~CQA_Lab_Element_Text(void);

	DECLARE_L3CLASS(CQA_Lab_Element_Text,XGMESLogic\\QualityMag, AppID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Lab_Element_Text)
	DECLARE_L3EVENTSINK_MAP()

	//当对象被装载到系统中时，被调用
	virtual void OnLoaded();
	//当对象被卸载时，被调用
	virtual void OnUnloaded();

	/// <Property class="CQA_Lab_Element_Text" name="AppID" type="L3STRING">
	/// 委托单编号
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Lab_Element_Text" name="Sample_Code" type="L3STRING">
	/// 试样编码
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Lab_Element_Text" name="Arrive_Date" type="L3DATETIME">
	/// 到样时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Lab_Element_Text" name="Report_Date" type="L3DATETIME">
	/// 报告时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Lab_Element_Text" name="HeatID" type="L3STRING">
	/// 炉号
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CQA_Lab_Element_Text" name="UnitTypeID" type="L3SHORT">
	/// 工序：0：铁水，1：混铁炉，2：转炉，3：炉后，4：LF，5：RH，6：铸机
	/// </Property>
	DECLARE_L3PROP_LONG(UnitTypeID)

	/// <Property class="CQA_Lab_Element_Text" name="UnitID" type="L3SHORT">
	/// 工位
	/// </Property>
	DECLARE_L3PROP_LONG(UnitID)

	/// <Property class="CQA_Lab_Element_Text" name="Sample_Address" type="L3STRING">
	/// 取样地点
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Lab_Element_Text" name="Sample_Type" type="L3STRING">
	/// 试样类别
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Lab_Element_Text" name="Sample_Count" type="L3STRING">
	/// 取样次数
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Count)

	/// <Property class="CQA_Lab_Element_Text" name="C" type="L3STRING">
	/// C
	/// </Property>
	DECLARE_L3PROP_STRING(C)

	/// <Property class="CQA_Lab_Element_Text" name="Si" type="L3STRING">
	/// Si
	/// </Property>
	DECLARE_L3PROP_STRING(Si)

	/// <Property class="CQA_Lab_Element_Text" name="Mn" type="L3STRING">
	/// Mn
	/// </Property>
	DECLARE_L3PROP_STRING(Mn)

	/// <Property class="CQA_Lab_Element_Text" name="P" type="L3STRING">
	/// P
	/// </Property>
	DECLARE_L3PROP_STRING(P)

	/// <Property class="CQA_Lab_Element_Text" name="S" type="L3STRING">
	/// S
	/// </Property>
	DECLARE_L3PROP_STRING(S)

	/// <Property class="CQA_Lab_Element_Text" name="Cu" type="L3STRING">
	/// Cu
	/// </Property>
	DECLARE_L3PROP_STRING(Cu)

	/// <Property class="CQA_Lab_Element_Text" name="Ni" type="L3STRING">
	/// Ni
	/// </Property>
	DECLARE_L3PROP_STRING(Ni)

	/// <Property class="CQA_Lab_Element_Text" name="Cr" type="L3STRING">
	/// Cr
	/// </Property>
	DECLARE_L3PROP_STRING(Cr)

	/// <Property class="CQA_Lab_Element_Text" name="Mo" type="L3STRING">
	/// Mo
	/// </Property>
	DECLARE_L3PROP_STRING(Mo)

	/// <Property class="CQA_Lab_Element_Text" name="V" type="L3STRING">
	/// V
	/// </Property>
	DECLARE_L3PROP_STRING(V)

	/// <Property class="CQA_Lab_Element_Text" name="Nb" type="L3STRING">
	/// Nb
	/// </Property>
	DECLARE_L3PROP_STRING(Nb)

	/// <Property class="CQA_Lab_Element_Text" name="Al" type="L3STRING">
	/// Al
	/// </Property>
	DECLARE_L3PROP_STRING(Al)

	/// <Property class="CQA_Lab_Element_Text" name="AlS" type="L3STRING">
	/// AlS
	/// </Property>
	DECLARE_L3PROP_STRING(AlS)

	/// <Property class="CQA_Lab_Element_Text" name="Ti" type="L3STRING">
	/// Ti
	/// </Property>
	DECLARE_L3PROP_STRING(Ti)

	/// <Property class="CQA_Lab_Element_Text" name="B" type="L3STRING">
	/// B
	/// </Property>
	DECLARE_L3PROP_STRING(B)

	/// <Property class="CQA_Lab_Element_Text" name="Sb" type="L3STRING">
	/// Sb
	/// </Property>
	DECLARE_L3PROP_STRING(Sb)

	/// <Property class="CQA_Lab_Element_Text" name="Sn" type="L3STRING">
	/// Sn
	/// </Property>
	DECLARE_L3PROP_STRING(Sn)

	/// <Property class="CQA_Lab_Element_Text" name="As" type="L3STRING">
	/// As
	/// </Property>
	DECLARE_L3PROP_STRING(As)

	/// <Property class="CQA_Lab_Element_Text" name="Zn" type="L3STRING">
	/// Zn
	/// </Property>
	DECLARE_L3PROP_STRING(Zn)

	/// <Property class="CQA_Lab_Element_Text" name="Zr" type="L3STRING">
	/// Zr
	/// </Property>
	DECLARE_L3PROP_STRING(Zr)

	/// <Property class="CQA_Lab_Element_Text" name="Ca" type="L3STRING">
	/// Ca
	/// </Property>
	DECLARE_L3PROP_STRING(Ca)

	/// <Property class="CQA_Lab_Element_Text" name="W" type="L3STRING">
	/// W
	/// </Property>
	DECLARE_L3PROP_STRING(W)

	/// <Property class="CQA_Lab_Element_Text" name="Pb" type="L3STRING">
	/// Pb
	/// </Property>
	DECLARE_L3PROP_STRING(Pb)

	/// <Property class="CQA_Lab_Element_Text" name="Re" type="L3STRING">
	/// Re
	/// </Property>
	DECLARE_L3PROP_STRING(Re)

	/// <Property class="CQA_Lab_Element_Text" name="Ceq" type="L3STRING">
	/// Ceq
	/// </Property>
	DECLARE_L3PROP_STRING(Ceq)

	/// <Property class="CQA_Lab_Element_Text" name="N" type="L3STRING">
	/// N
	/// </Property>
	DECLARE_L3PROP_STRING(N)

	/// <Property class="CQA_Lab_Element_Text" name="H" type="L3STRING">
	/// H
	/// </Property>
	DECLARE_L3PROP_STRING(H)

	/// <Property class="CQA_Lab_Element_Text" name="O" type="L3STRING">
	/// O
	/// </Property>
	DECLARE_L3PROP_STRING(O)

	/// <Property class="CQA_Lab_Element_Text" name="CrNi" type="L3STRING">
	/// CrNi
	/// </Property>
	DECLARE_L3PROP_STRING(CrNi)

	/// <Property class="CQA_Lab_Element_Text" name="CrCu" type="L3STRING">
	/// CrCu
	/// </Property>
	DECLARE_L3PROP_STRING(CrCu)

	/// <Property class="CQA_Lab_Element_Text" name="CrNiCu" type="L3STRING">
	/// CrNiCu
	/// </Property>
	DECLARE_L3PROP_STRING(CrNiCu)

	/// <Property class="CQA_Lab_Element_Text" name="Other1" type="L3STRING">
	/// Other1
	/// </Property>
	DECLARE_L3PROP_STRING(Other1)

	/// <Property class="CQA_Lab_Element_Text" name="Other2" type="L3STRING">
	/// Other2
	/// </Property>
	DECLARE_L3PROP_STRING(Other2)

	/// <Property class="CQA_Lab_Element_Text" name="Other3" type="L3DOUBLE">
	/// 其他3
	/// </Property>
	DECLARE_L3PROP_STRING(Other3)


	/// <Property class="CQA_Lab_Element_Text" name="LogTime" type="L3DATETIME">
	/// 数据记录时间
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Lab_Element_Text" name="DataLogMode" type="L3SHORT">
	/// 数据产生方式：0：自动采集化验室；1：人工输入化验室;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Lab_Element_Text" name="Operator" type="L3STRING">
	/// 检验人
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)
};
