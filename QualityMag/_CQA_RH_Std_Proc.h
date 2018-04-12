// �߼���CQA_RH_Std_Procͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CQA_RH_Std_Proc :
	public CL3Object
{
public:
	CQA_RH_Std_Proc(void);
	virtual ~CQA_RH_Std_Proc(void);

	DECLARE_L3CLASS(CQA_RH_Std_Proc,XGMESLogic\\QualityMag, SteelGradeIndex)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CQA_RH_Std_Proc)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CQA_RH_Std_Proc" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Aim" type="L3LONG">
	/// Ŀ��RH��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Min" type="L3LONG">
	/// ��СRH��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Min)

	/// <Property class="CQA_RH_Std_Proc" name="LeaFir_Temp_Max" type="L3LONG">
	/// ���RH��վ�¶�(������һ¯)
	/// </Property>
	DECLARE_L3PROP_LONG(LeaFir_Temp_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Aim" type="L3LONG">
	/// Ŀ��RH��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Min" type="L3LONG">
	/// ��СRH��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Lea_Temp_Max" type="L3LONG">
	/// ���RH��վ�¶�(����¯)
	/// </Property>
	DECLARE_L3PROP_LONG(Lea_Temp_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Depth_Min" type="L3DOUBLE">
	/// ���������С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Depth_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Depth_Max" type="L3DOUBLE">
	/// ����������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Depth_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Min" type="L3DOUBLE">
	/// ���������С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Vacuum_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Max" type="L3DOUBLE">
	/// ��ն����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Vacuum_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Min" type="L3DOUBLE">
	/// ��������������С��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Aim" type="L3DOUBLE">
	/// ������������Ŀ�ꡢ
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Aim)

	/// <Property class="CQA_RH_Std_Proc" name="Up_Blow_Max" type="L3DOUBLE">
	/// ���������������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Up_Blow_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Flag" type="L3LONG">
	/// ����̼��
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Time_Min" type="L3LONG">
	/// ��̼ʱ����С��
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Dec_Time_Max" type="L3LONG">
	/// ��̼ʱ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Dec_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_Time_Min" type="L3LONG">
	/// ������ʱ����С��
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_Time_Max" type="L3LONG">
	/// ������ʱ�����
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Vacuum_Time_Min" type="L3LONG">
	/// �����նȱ���ʱ�䡢
	/// </Property>
	DECLARE_L3PROP_LONG(Vacuum_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Proc_Time_Min" type="L3LONG">
	/// ����ʱ����С��
	/// </Property>
	DECLARE_L3PROP_LONG(Proc_Time_Min)

	/// <Property class="CQA_RH_Std_Proc" name="Oxy_Flag" type="L3LONG">
	/// ������
	/// </Property>
	DECLARE_L3PROP_LONG(Oxy_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="H_Flag" type="L3LONG">
	/// �����
	/// </Property>
	DECLARE_L3PROP_LONG(H_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Soft_Blow_Flag" type="L3LONG">
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Soft_Blow_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Calm_Flag" type="L3LONG">
	/// �򾲷�
	/// </Property>
	DECLARE_L3PROP_LONG(Calm_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Al_Hot_Flag" type="L3LONG">
	/// ����AL���ȷ�
	/// </Property>
	DECLARE_L3PROP_LONG(Al_Hot_Flag)

	/// <Property class="CQA_RH_Std_Proc" name="Cold_Mat_Add" type="L3STRING">
	/// ���ϼ�������׼��
	/// </Property>
	DECLARE_L3PROP_STRING(Cold_Mat_Add)

	/// <Property class="CQA_RH_Std_Proc" name="Hold_Steel_Time_Max" type="L3DOUBLE">
	/// ��վѹ��ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Hold_Steel_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Stay_Steel_Time_Max" type="L3DOUBLE">
	/// ��վ�ȸ�ʱ�����
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stay_Steel_Time_Max)

	/// <Property class="CQA_RH_Std_Proc" name="Pure_DeO_Time_Min" type="L3LONG">
	/// ������ʱ����С
	/// </Property>
	DECLARE_L3PROP_LONG(Pure_DeO_Time_Min)

};
