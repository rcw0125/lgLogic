// �߼���CQA_LF_Std_Procͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_LF_Std_Proc :
	public CL3Object
{
public:
	CQA_LF_Std_Proc(void);
	virtual ~CQA_LF_Std_Proc(void);

	DECLARE_L3CLASS(CQA_LF_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_LF_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_LF_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Aim" type="L3LONG">
	/// Ŀ��LF��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Aim)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Min" type="L3LONG">
	/// ��СLF��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Min)

	/// <Property class="CQA_LF_Std_Proc" name="LeaFir_Temp_Max" type="L3LONG">
	/// ���LF��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Aim" type="L3LONG">
	/// Ŀ��LF��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Aim)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Min" type="L3LONG">
	/// ��СLF��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Lea_Temp_Max" type="L3LONG">
	/// ���LF��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Sample_Flag" type="L3LONG">
	/// ��վȡ��
	/// </Property>
	DECLARE_L3PROP_LONG(Sample_Flag)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Blow_Time_Min" type="L3LONG">
	/// ��С��ʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Blow_Time_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Time_Min" type="L3LONG">
	/// ����ʱ����С
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Time_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Time_Max" type="L3LONG">
	/// ����ʱ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Hot_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Ar_Min" type="L3DOUBLE">
	/// ���ȴ��������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hot_Ar_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Hot_Ar_Max" type="L3DOUBLE">
	/// ���ȴ���������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hot_Ar_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Ar_Min" type="L3DOUBLE">
	/// �����������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Soft_Ar_Min)

	/// <Property class="CQA_LF_Std_Proc" name="Soft_Ar_Max" type="L3DOUBLE">
	/// ������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Soft_Ar_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// ��վѹ��ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// ��վ�ȸ�ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Refine_Time_Max" type="L3DOUBLE">
	/// ����ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Refine_Time_Max)

	/// <Property class="CQA_LF_Std_Proc" name="Refine_Time_Min" type="L3DOUBLE">
	/// ����ʱ����С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Refine_Time_Min)

};
