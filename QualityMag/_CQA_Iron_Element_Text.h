// �߼���CQA_Iron_Element_Text_Textͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
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

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Iron_Element_Text" name="AppID" type="L3STRING">
	/// ί�е����
	/// </Property>
	DECLARE_L3PROP_STRING(AppID)

	/// <Property class="CQA_Iron_Element_Text" name="TAP_No" type="L3STRING">
	/// ���κ�
	/// </Property>
	DECLARE_L3PROP_STRING(TAP_No)

	/// <Property class="CQA_Iron_Element_Text" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Code" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Code)

	/// <Property class="CQA_Iron_Element_Text" name="Arrive_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Date)

	/// <Property class="CQA_Iron_Element_Text" name="Report_Date" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Report_Date)

	/// <Property class="CQA_Iron_Element_Text" name="UnitTypeID" type="L3SHORT">
	/// ����0����ˮ��1������¯��2��ת¯��3��¯��4��LF��5��RH��6������
	/// </Property>
	DECLARE_L3PROP_LONG(UnitTypeID)

	/// <Property class="CQA_Iron_Element_Text" name="UnitID" type="L3SHORT">
	/// ��λ
	/// </Property>
	DECLARE_L3PROP_LONG(UnitID)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Address" type="L3STRING">
	/// ȡ���ص�
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Address)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Type" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Sample_Type)

	/// <Property class="CQA_Iron_Element_Text" name="Sample_Count" type="L3STRING">
	/// ȡ������
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

	//add by hyh 2012-08-09 Ӧҵ��Ҫ��������Ni(��)��Mo(��)��Cu(ͭ) ��Cr(��)��B(��)��V(��)��Al(��)��Nb(��)��Zn(п)��W(��)
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
	/// ���ݼ�¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(LogTime)

	/// <Property class="CQA_Iron_Element_Text" name="DataLogMode" type="L3SHORT">
	/// ���ݲ�����ʽ��0���Զ��ɼ������ң�1���˹����뻯����;
	/// </Property>
	DECLARE_L3PROP_LONG(DataLogMode)

	/// <Property class="CQA_Iron_Element_Text" name="Operator" type="L3STRING">
	/// ������
	/// </Property>2009-04-23
	DECLARE_L3PROP_STRING(Operator)


};
