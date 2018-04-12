// �߼���CQA_LF_Std_Feedͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Feed :
	public CL3Object
{
public:
	CQA_LF_Std_Feed(void);
	virtual ~CQA_LF_Std_Feed(void);

	DECLARE_L3CLASS(CQA_LF_Std_Feed,XGMESLogic\\QualityMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Feed)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Feed" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Feed" name="C_Absorption_Rate" type="L3DOUBLE">
	/// ̼����̼������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(C_Absorption_Rate)

	/// <Property class="CQA_LF_Std_Feed" name="Al_Absorption_Rate" type="L3DOUBLE">
	/// ��������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Al_Absorption_Rate)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1" type="L3STRING">
	/// Ca����ι˿��1
	/// </Property>
	DECLARE_L3PROP_STRING(CaProc_Code1)

	/// <Property class="CQA_LF_Std_Feed" name="CaProcFir_Code1_Weight_Max" type="L3DOUBLE">
	/// Ca����ι��1ι�������������һ¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProcFir_Code1_Weight_Max)

	/// <Property class="CQA_LF_Std_Feed" name="CaProcFir_Code1_Weight_Min" type="L3DOUBLE">
	/// Ca����ι��1ι������С��������һ¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProcFir_Code1_Weight_Min)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1_Weight_Max" type="L3DOUBLE">
	/// Ca����ι��1ι�����������¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code1_Weight_Max)

	/// <Property class="CQA_LF_Std_Feed" name="CaProc_Code1_Weight_Min" type="L3DOUBLE">
	/// Ca����ι��1ι������С������¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(CaProc_Code1_Weight_Min)

	/// <Property class="CQA_LF_Std_Feed" name="Oxy_Flag" type="L3SHORT">
	/// ������
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

};
