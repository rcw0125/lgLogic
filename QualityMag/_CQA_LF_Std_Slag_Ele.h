// �߼���CQA_LF_Std_Slag_Eleͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Slag_Ele :
	public CL3Object
{
public:
	CQA_LF_Std_Slag_Ele(void);
	virtual ~CQA_LF_Std_Slag_Ele(void);

	DECLARE_L3CLASS(CQA_LF_Std_Slag_Ele,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Slag_Ele)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="CaO_Max" type="L3DOUBLE">
	/// ������CaO���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="CaO_Min" type="L3DOUBLE">
	/// ������CaO��С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SiO2_Max" type="L3DOUBLE">
	/// ������SiO2���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="SiO2_Min" type="L3DOUBLE">
	/// ������SiO2��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MgO_Max" type="L3DOUBLE">
	/// ������MgO���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MgO_Min" type="L3DOUBLE">
	/// ������MgO��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="Al2O3_Max" type="L3DOUBLE">
	/// ������Al2O3���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al2O3_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="Al2O3_Min" type="L3DOUBLE">
	/// ������Al2O3��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al2O3_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="S_Max" type="L3DOUBLE">
	/// ������S���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="S_Min" type="L3DOUBLE">
	/// ������S��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(S_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="P_Max" type="L3DOUBLE">
	/// ������P���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="P_Min" type="L3DOUBLE">
	/// ������P��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(P_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MnO_Max" type="L3DOUBLE">
	/// ������MnO���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MnO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="MnO_Min" type="L3DOUBLE">
	/// ������MnO��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MnO_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="TiO2_Max" type="L3DOUBLE">
	/// ������TiO2���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TiO2_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="TiO2_Min" type="L3DOUBLE">
	/// ������TiO2��С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TiO2_Min)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="FeO_Max" type="L3DOUBLE">
	/// ������FeO���
	/// </Property>
	DECLARE_L3PROP_DOUBLE(FeO_Max)

	/// <Property class="CQA_LF_Std_Slag_Ele" name="FeO_Min" type="L3DOUBLE">
	/// ������FeO��С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(FeO_Min)

};
