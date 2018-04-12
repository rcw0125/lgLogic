// �߼���CQA_Caster_Std_Procͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_Caster_Std_Proc :
	public CL3Object
{
public:
	CQA_Caster_Std_Proc(void);
	virtual ~CQA_Caster_Std_Proc(void);

	DECLARE_L3CLASS(CQA_Caster_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_Caster_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_Caster_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_Caster_Std_Proc" name="Mold_Cold_Base" type="L3STRING">
	/// �ᾧ����ȴ��׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Mold_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Mold_Shake_Base" type="L3STRING">
	/// �ᾧ���񶯻�׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Mold_Shake_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Sec_Cold_Base" type="L3STRING">
	/// ������ȴ��׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Sec_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Elec_Mix_Current" type="L3DOUBLE">
	/// ��Ž��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Elec_Mix_Current)

	/// <Property class="CQA_Caster_Std_Proc" name="Elec_Mix_Freq" type="L3DOUBLE">
	/// ��Ž���Ƶ�ʡ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Elec_Mix_Freq)

	/// <Property class="CQA_Caster_Std_Proc" name="ASTC_Flag" type="L3LONG">
	/// ��ѹ�¡�
	/// </Property>
	DECLARE_L3PROP_LONG(ASTC_Flag)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Coefficient" type="L3LONG">
	/// �и��ϵ��
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Coefficient)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Head_Max" type="L3LONG">
	/// ������ͷ�������
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Head_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Head_Min" type="L3LONG">
	/// ������ͷ������С
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Head_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Trail_Max" type="L3LONG">
	/// ������β�������
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Trail_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Cut_Trail_Min" type="L3LONG">
	/// ������β������С��
	/// </Property>
	DECLARE_L3PROP_LONG(Cut_Trail_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="DifSteel_Cut_Length_Max" type="L3LONG">
	/// ��������Ӻ�ǰ�и�����
	/// </Property>
	DECLARE_L3PROP_LONG(DifSteel_Cut_Length_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="DifSteel_Cut_Length_Min" type="L3LONG">
	/// ��������Ӻ�ǰ�и����С��
	/// </Property>
	DECLARE_L3PROP_LONG(DifSteel_Cut_Length_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Mark_Cut_Length_Max" type="L3LONG">
	/// �Ӻۺ��и�����
	/// </Property>
	DECLARE_L3PROP_LONG(Mark_Cut_Length_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Mark_Cut_Length_Min" type="L3LONG">
	/// �Ӻۺ��и����С��
	/// </Property>
	DECLARE_L3PROP_LONG(Mark_Cut_Length_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Bloom_Finish_Base" type="L3STRING">
	/// ���������׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Bloom_Finish_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Slab_Check_Base" type="L3STRING">
	/// ����������׼
	/// </Property>
	DECLARE_L3PROP_STRING(Slab_Check_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Water_Type" type="L3STRING">
	/// �а�ˮ�����͡�
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Water_Type)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Weight_Min" type="L3DOUBLE">
	/// �а���С��ˮ����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Tundish_Weight_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Protect_Slag_Base" type="L3STRING">
	/// ��������׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Protect_Slag_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Blow_Ar_Max" type="L3DOUBLE">
	/// ��������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Blow_Ar_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Blow_Ar_Min" type="L3DOUBLE">
	/// �������������С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Blow_Ar_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Ladle_Blow_Ar_Max" type="L3DOUBLE">
	/// �������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Blow_Ar_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Ladle_Blow_Ar_Min" type="L3DOUBLE">
	/// ������������С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Ladle_Blow_Ar_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Change_Time_Min" type="L3DOUBLE">
	/// �����û�ʱ����С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Change_Time_Min)

	/// <Property class="CQA_Caster_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// ѹ��ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// �ȸ�ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_Caster_Std_Proc" name="Liquid_Temp" type="L3DOUBLE">
	/// Һ�����¶ȡ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Liquid_Temp)

	/// <Property class="CQA_Caster_Std_Proc" name="Slow_Cold_Base" type="L3STRING">
	/// �����׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Slow_Cold_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Tundish_Speed_Base" type="L3STRING">
	/// �а�Ŀ���¶�ʱ�������ٻ�׼
	/// </Property>
	DECLARE_L3PROP_STRING(Tundish_Speed_Base)

	/// <Property class="CQA_Caster_Std_Proc" name="Bloom_Low_Base" type="L3STRING">
	/// �����ͱ���׼
	/// </Property>
	DECLARE_L3PROP_STRING(Bloom_Low_Base)

};
