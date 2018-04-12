// �߼���CQA_BOF_Std_Arͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_BOF_Std_Ar :
	public CL3Object
{
public:
	CQA_BOF_Std_Ar(void);
	virtual ~CQA_BOF_Std_Ar(void);

	DECLARE_L3CLASS(CQA_BOF_Std_Ar,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_BOF_Std_Ar)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_BOF_Std_Ar" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Max" type="L3LONG">
	/// �ǰ��ˮ�¶����������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Min" type="L3LONG">
	/// �ǰ��ˮ�¶���С��������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Fir_Aim" type="L3LONG">
	/// �ǰ��ˮ�¶�Ŀ�꣨������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Fir_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Max" type="L3LONG">
	/// �ǰ��ˮ�¶��������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Min" type="L3LONG">
	/// �ǰ��ˮ�¶���С������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_SteelTemp_Aim" type="L3LONG">
	/// �ǰ��ˮ�¶�Ŀ�꣨����¯��
	/// </Property>
	DECLARE_L3PROP_LONG(PreAr_SteelTemp_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Max" type="L3LONG">
	/// 벺��ˮ�¶����������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Min" type="L3LONG">
	/// 벺��ˮ�¶���С��������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Fir_Aim" type="L3LONG">
	/// 벺��ˮ�¶�Ŀ�꣨������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Fir_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Max" type="L3LONG">
	/// 벺��ˮ�¶��������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Min" type="L3LONG">
	/// 벺��ˮ�¶���С������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_SteelTemp_Aim" type="L3LONG">
	/// 벺��ˮ�¶�Ŀ�꣨����¯��
	/// </Property>
	DECLARE_L3PROP_LONG(BeAr_SteelTemp_Aim)

	/// <Property class="CQA_BOF_Std_Ar" name="Oxy_Flag" type="L3LONG">
	/// ¯������
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_Oxy_Max" type="L3DOUBLE">
	/// �ǰ�������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PreAr_Oxy_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="PreAr_Oxy_Min" type="L3DOUBLE">
	/// �ǰ������������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(PreAr_Oxy_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Time_UpLimit" type="L3LONG">
	/// ¯���ʱ������
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Time_UpLimit)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Time_LowLimit" type="L3LONG">
	/// ¯���ʱ������
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Time_LowLimit)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Press_Max" type="L3LONG">
	/// ¯���ѹ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Press_Min" type="L3LONG">
	/// ¯���ѹ����С
	/// </Property>
	DECLARE_L3PROP_LONG(Ar_Press_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Blow_Max" type="L3DOUBLE">
	/// ¯����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="Ar_Blow_Min" type="L3DOUBLE">
	/// ¯���������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ar_Blow_Min)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_Oxy_Max" type="L3DOUBLE">
	/// 벺������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BeAr_Oxy_Max)

	/// <Property class="CQA_BOF_Std_Ar" name="BeAr_Oxy_Min" type="L3DOUBLE">
	/// 벺�����������С
	/// </Property>
	DECLARE_L3PROP_DOUBLE(BeAr_Oxy_Min)

};
