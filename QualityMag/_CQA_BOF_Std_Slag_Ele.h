// �߼���CQA_BOF_Std_Slag_Eleͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Slag_Ele :
	public CL3Object
{
public:
	CQA_BOF_Std_Slag_Ele(void);
	virtual ~CQA_BOF_Std_Slag_Ele(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Slag_Ele,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Slag_Ele)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="CaO_Max" type="L3DOUBLE">
	/// ת¯¯��CaO�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="CaO_Min" type="L3DOUBLE">
	/// ת¯¯��CaO������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaO_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SiO2_Max" type="L3DOUBLE">
	/// ת¯¯��SiO2�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="SiO2_Min" type="L3DOUBLE">
	/// ת¯¯��SiO2������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(SiO2_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="MgO_Max" type="L3DOUBLE">
	/// ת¯¯��SiO2�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="MgO_Min" type="L3DOUBLE">
	/// ת¯¯��MgO������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(MgO_Min)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="TFe_Max" type="L3DOUBLE">
	/// ת¯¯��TFe�������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TFe_Max)

	/// <Property class="CQA_BOF_Std_Slag_Ele" name="TFe_Min" type="L3DOUBLE">
	/// ת¯¯��TFe������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(TFe_Min)

};
