// �߼���CQA_Caster_Std_Tundishͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Caster_Std_Tundish :
	public CL3Object
{
public:
	CQA_Caster_Std_Tundish(void);
	virtual ~CQA_Caster_Std_Tundish(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Tundish,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Tundish)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Tundish" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Tundish" name="Tundish_Temp_Fir_Min" type="L3LONG">
	/// �а��¶���С��������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Temp_Fir_Min)

	/// <Property class="CQA_Caster_Std_Tundish" name="Tundish_Temp_Fir_Max" type="L3LONG">
	/// �а��¶����������һ¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Temp_Fir_Max)

	/// <Property class="CQA_Caster_Std_Tundish" name="Tundish_Temp_Min" type="L3LONG">
	/// �а��¶���С������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Temp_Min)

	/// <Property class="CQA_Caster_Std_Tundish" name="Tundish_Temp_Max" type="L3LONG">
	/// �а��¶��������¯��
	/// </Property>
	DECLARE_L3PROP_LONG(Tundish_Temp_Max)

};
