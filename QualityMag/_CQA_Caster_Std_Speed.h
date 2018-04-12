// �߼���CQA_Caster_Std_Speedͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Caster_Std_Speed :
	public CL3Object
{
public:
	CQA_Caster_Std_Speed(void);
	virtual ~CQA_Caster_Std_Speed(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Speed,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Speed)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Speed" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Fir_Min" type="L3DOUBLE">
	/// ������С��������һ¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Fir_Min)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Fir_Max" type="L3DOUBLE">
	/// �������������һ¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Fir_Max)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Min" type="L3DOUBLE">
	/// ������С������¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Min)

	/// <Property class="CQA_Caster_Std_Speed" name="Speed_Max" type="L3DOUBLE">
	/// �����������¯��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Speed_Max)

};
