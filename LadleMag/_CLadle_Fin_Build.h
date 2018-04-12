// �߼���CLadle_Fin_Buildͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Fin_Build :
	public CL3Object
{
public:
	CLadle_Fin_Build(void);
	virtual ~CLadle_Fin_Build(void);

	DECLARE_L3CLASS(CLadle_Fin_Build,XGMESLogic\\LadleMag, WorkID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Fin_Build)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Fin_Build" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Fin_Build" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Fin_Build" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Fin_Build" name="Build_Start_Time" type="L3DATETIME">
	/// ������ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_Start_Time)

	/// <Property class="CLadle_Fin_Build" name="Build_End_Time" type="L3DATETIME">
	/// ��������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Build_End_Time)

	/// <Property class="CLadle_Fin_Build" name="Water_Gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_Gap_Bri_Fac)

	/// <Property class="CLadle_Fin_Build" name="Water_Gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_Gap_Bri_Wast)

	/// <Property class="CLadle_Fin_Build" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Fin_Build" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bricklaying_Fac" type="L3STRING">
	/// ��ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Bricklaying_Fac)

	/// <Property class="CLadle_Fin_Build" name="Bot_Pro_Refr_Name" type="L3STRING">
	/// �������ױ������Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Pro_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Bot_Pro_Refr_Wast" type="L3DOUBLE">
	/// �������ױ������Ͳ�������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Pro_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bot_Woke_Refr_Name" type="L3STRING">
	/// �������׹������Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Woke_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Bot_Woke_Refr_Wast" type="L3DOUBLE">
	/// �������׹������Ͳ�������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Woke_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Wall_Refr_Name" type="L3STRING">
	/// ���������Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Refr_Name)

	/// <Property class="CLadle_Fin_Build" name="Wall_Refr_Wast" type="L3DOUBLE">
	/// ���������Ͳ�������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Wall_Refr_Wast)

	/// <Property class="CLadle_Fin_Build" name="Slag_Line_Refe_Name" type="L3STRING">
	/// ���������Ͳ�����
	/// </Property>
	DECLARE_L3PROP_STRING(Slag_Line_Refe_Name)

	/// <Property class="CLadle_Fin_Build" name="Slag_Line_Refe_Wast" type="L3DOUBLE">
	/// ���������Ͳ�������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Slag_Line_Refe_Wast)

	/// <Property class="CLadle_Fin_Build" name="Bot_Wall_Rep_Mat_Fac" type="L3STRING">
	/// ���ױ��޲��ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)

	/// <Property class="CLadle_Fin_Build" name="Bot_Wall_Rep_Mat_Wast" type="L3DOUBLE">
	/// �����޲���������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)

	/// <Property class="CLadle_Fin_Build" name="Spi_Cast_Fac" type="L3STRING">
	/// �⾧ʯ�����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Spi_Cast_Fac)

	/// <Property class="CLadle_Fin_Build" name="Spi_Cast_Wast" type="L3DOUBLE">
	/// �⾧ʯ������������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spi_Cast_Wast)

	/// <Property class="CLadle_Fin_Build" name="Ladle_Inner_Checker" type="L3STRING">
	/// ���ò���
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Inner_Checker)

	/// <Property class="CLadle_Fin_Build" name="Ladle_Inner_Use_Count" type="L3LONG">
	/// ���ò�ʹ�ô���
	/// </Property>
	DECLARE_L3PROP_LONG(Ladle_Inner_Use_Count)

	/// <Property class="CLadle_Fin_Build" name="Seat_Bri_Installer" type="L3STRING">
	/// ��ש��װ
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Fin_Build" name="Buttom_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Buttom_Builder)

	/// <Property class="CLadle_Fin_Build" name="Wall_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Builder)

	/// <Property class="CLadle_Fin_Build" name="Line_Refe_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Line_Refe_Builder)

	/// <Property class="CLadle_Fin_Build" name="Rep_Ladle_Bot" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Bot)

	/// <Property class="CLadle_Fin_Build" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Fin_Build" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Fin_Build" name="Thr_Ladle_Time" type="L3DATETIME">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Fin_Build" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Fin_Build" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Fin_Build" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Fin_Build" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Fin_Build" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)


};
