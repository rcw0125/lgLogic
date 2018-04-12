// �߼���CQA_BOF_Std_Tappingͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Tapping :
	public CL3Object
{
public:
	CQA_BOF_Std_Tapping(void);
	virtual ~CQA_BOF_Std_Tapping(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Tapping,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Tapping)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Tapping" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Tapping" name="Tapping_Temp_Min" type="L3LONG">
	/// �����¶���С
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Temp_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="Tapping_Time_Min" type="L3LONG">
	/// ����ʱ����С
	/// </Property>
	DECLARE_L3PROP_LONG(Tapping_Time_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_O2_UpLimit" type="L3DOUBLE">
	/// �յ�����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_O2_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_C_UpLimit" type="L3DOUBLE">
	/// �յ�ɷ�C����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_C_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_C_LowLimit" type="L3DOUBLE">
	/// �յ�ɷ�C����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_C_LowLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_S_UpLimit" type="L3DOUBLE">
	/// �յ�ɷ�S����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_S_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_P_UpLimit" type="L3DOUBLE">
	/// �յ�ɷ�P����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_P_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="End_Mn_UpLimit" type="L3DOUBLE">
	/// �յ�ɷ�Mn����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(End_Mn_UpLimit)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Press_Max" type="L3LONG">
	/// ���ֹ��̴��ѹ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Max)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Press_Min" type="L3LONG">
	/// ���ֹ��̴��ѹ����С
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Min)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Blow_Max" type="L3DOUBLE">
	/// ���ֹ��̴���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Max)

	/// <Property class="CQA_BOF_Std_Tapping" name="Ar_Blow_Min" type="L3DOUBLE">
	/// ���ֹ��̴��������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Min)

};
