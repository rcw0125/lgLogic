// �߼���CQA_Element_Stdͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Element_Std :
	public CL3Object
{
public:
	CQA_Element_Std(void);
	virtual ~CQA_Element_Std(void);

	DECLARE_L3CLASS(CQA_Element_Std,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Element_Std)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	//add by hyh 2012-04-10
	//���������ڸ��ֳɷֱ�����ʾ
	//


	/// <Property class="CQA_Element_Std" name="SteelGrade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGrade)

	/// <Property class="CQA_Element_Std" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Element_Std" name="C_Max" type="L3STRING">
	/// C����
	/// </Property>
	DECLARE_L3PROP_STRING(C_Max)

	/// <Property class="CQA_Element_Std" name="C_Min" type="L3STRING">
	/// C����
	/// </Property>
	DECLARE_L3PROP_STRING(C_Min)

	/// <Property class="CQA_Element_Std" name="Si_Max" type="L3STRING">
	/// Si����
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Max)

	/// <Property class="CQA_Element_Std" name="Si_Min" type="L3STRING">
	/// Si����
	/// </Property>
	DECLARE_L3PROP_STRING(Si_Min)

	/// <Property class="CQA_Element_Std" name="Mn_Max" type="L3STRING">
	/// Mn����
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Max)

	/// <Property class="CQA_Element_Std" name="Mn_Min" type="L3STRING">
	/// Mn����
	/// </Property>
	DECLARE_L3PROP_STRING(Mn_Min)

	/// <Property class="CQA_Element_Std" name="P_Max" type="L3STRING">
	/// P����
	/// </Property>
	DECLARE_L3PROP_STRING(P_Max)

	/// <Property class="CQA_Element_Std" name="P_Min" type="L3STRING">
	/// P����
	/// </Property>
	DECLARE_L3PROP_STRING(P_Min)

	/// <Property class="CQA_Element_Std" name="S_Max" type="L3STRING">
	/// S����
	/// </Property>
	DECLARE_L3PROP_STRING(S_Max)

	/// <Property class="CQA_Element_Std" name="S_Min" type="L3STRING">
	/// S����
	/// </Property>
	DECLARE_L3PROP_STRING(S_Min)

	/// <Property class="CQA_Element_Std" name="Ti_Max" type="L3STRING">
	/// Ti����
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Max)

	/// <Property class="CQA_Element_Std" name="Ti_Min" type="L3STRING">
	/// Ti����
	/// </Property>
	DECLARE_L3PROP_STRING(Ti_Min)

	/// <Property class="CQA_Element_Std" name="Sn_Max" type="L3STRING">
	/// Sn����
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Max)

	/// <Property class="CQA_Element_Std" name="Sn_Min" type="L3STRING">
	/// Sn����
	/// </Property>
	DECLARE_L3PROP_STRING(Sn_Min)

	/// <Property class="CQA_Element_Std" name="Sb_Max" type="L3STRING">
	/// Sb����
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Max)

	/// <Property class="CQA_Element_Std" name="Sb_Min" type="L3STRING">
	/// Sb����
	/// </Property>
	DECLARE_L3PROP_STRING(Sb_Min)

	/// <Property class="CQA_Element_Std" name="As_Max" type="L3STRING">
	/// As����
	/// </Property>
	DECLARE_L3PROP_STRING(As_Max)

	/// <Property class="CQA_Element_Std" name="As_Min" type="L3STRING">
	/// As����
	/// </Property>
	DECLARE_L3PROP_STRING(As_Min)

	/// <Property class="CQA_Element_Std" name="Pb_Max" type="L3STRING">
	/// Pb����
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Max)

	/// <Property class="CQA_Element_Std" name="Pb_Min" type="L3STRING">
	/// Pb����
	/// </Property>
	DECLARE_L3PROP_STRING(Pb_Min)

};
