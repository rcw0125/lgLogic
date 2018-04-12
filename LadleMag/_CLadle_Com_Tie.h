// �߼���CLadle_Com_Tieͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Com_Tie :
	public CL3Object
{
public:
	CLadle_Com_Tie(void);
	virtual ~CLadle_Com_Tie(void);

	DECLARE_L3CLASS(CLadle_Com_Tie,XGMESLogic\\LadleMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Com_Tie)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Com_Tie" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Com_Tie" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Com_Tie" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Com_Tie" name="Tie_Start_Time" type="L3DATETIME">
	/// ��Ὺʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_Start_Time)

	/// <Property class="CLadle_Com_Tie" name="Tie_End_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tie_End_Time)

	/// <Property class="CLadle_Com_Tie" name="Water_gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Com_Tie" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Com_Tie" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Com_Tie" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Com_Tie" name="Cast_Fac" type="L3STRING">
	/// �����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_Fac)

	/// <Property class="CLadle_Com_Tie" name="Cast_Wast" type="L3DOUBLE">
	/// ��ע��������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CLadle_Com_Tie" name="Squ_Lead_Fac" type="L3STRING">
	/// ��Ƭ״ʯī�۳���
	/// </Property>
	DECLARE_L3PROP_STRING(Squ_Lead_Fac)

	/// <Property class="CLadle_Com_Tie" name="Squ_Lead_Wast" type="L3DOUBLE">
	/// ��Ƭ״ʯī��������[Kg]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Squ_Lead_Wast)

	/// <Property class="CLadle_Com_Tie" name="Half_Boa_Fac" type="L3STRING">
	/// ���Ƭ����
	/// </Property>
	DECLARE_L3PROP_STRING(Half_Boa_Fac)

	/// <Property class="CLadle_Com_Tie" name="Half_Boa_Wast" type="L3DOUBLE">
	/// ���Ƭ������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Half_Boa_Wast)

	/// <Property class="CLadle_Com_Tie" name="Crust_Checker" type="L3STRING">
	/// ��Ǽ��
	/// </Property>
	DECLARE_L3PROP_STRING(Crust_Checker)

	/// <Property class="CLadle_Com_Tie" name="Ladle_Inner_Checker" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Inner_Checker)

	/// <Property class="CLadle_Com_Tie" name="Seat_Bri_Installer" type="L3STRING">
	/// ��ש��װ
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Com_Tie" name="Bre_Bri_Installer" type="L3STRING">
	/// ͸��ש��װ
	/// </Property>
	DECLARE_L3PROP_STRING(Bre_Bri_Installer)

	/// <Property class="CLadle_Com_Tie" name="Sepa_Dose_Operator" type="L3STRING">
	/// ���������
	/// </Property>
	DECLARE_L3PROP_STRING(Sepa_Dose_Operator)

	/// <Property class="CLadle_Com_Tie" name="Whip_Operator" type="L3STRING">
	/// �������
	/// </Property>
	DECLARE_L3PROP_STRING(Whip_Operator)

	/// <Property class="CLadle_Com_Tie" name="Ladle_Bot_Quiver" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Bot_Quiver)

	/// <Property class="CLadle_Com_Tie" name="Seat_Tyre_Operator" type="L3STRING">
	/// ����̥����
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Tyre_Operator)

	/// <Property class="CLadle_Com_Tie" name="Face_A__Quiver" type="L3STRING">
	/// A����
	/// </Property>
	DECLARE_L3PROP_STRING(Face_A__Quiver)

	/// <Property class="CLadle_Com_Tie" name="Face_B__Quiver" type="L3STRING">
	/// B����
	/// </Property>
	DECLARE_L3PROP_STRING(Face_B__Quiver)

	/// <Property class="CLadle_Com_Tie" name="Doff_Mod_Time" type="L3DATETIME">
	/// ��ģʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Doff_Mod_Time)

	/// <Property class="CLadle_Com_Tie" name="Rep_Ladle_Builder" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Builder)

	/// <Property class="CLadle_Com_Tie" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Com_Tie" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Com_Tie" name="Thr_Ladle_Time" type="L3DATETIME">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Com_Tie" name="Ladle_Inner_Use_Count" type="L3LONG">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_Com_Tie" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Com_Tie" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Com_Tie" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Com_Tie" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Com_Tie" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

};
