// �߼���CLadle_Cha_Dre_Linͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Cha_Dre_Lin :
	public CL3Object
{
public:
	CLadle_Cha_Dre_Lin(void);
	virtual ~CLadle_Cha_Dre_Lin(void);

	DECLARE_L3CLASS(CLadle_Cha_Dre_Lin,XGMESLogic\\LadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Cha_Dre_Lin)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Cha_Dre_Lin" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="ChaID" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(ChaID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Slag_Line_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cha_Slag_Line_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Water_gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Bot_Wall_Rep_Mat_Fac" type="L3STRING">
	/// ���ױ��޲��ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Bot_Wall_Rep_Mat_Wast" type="L3DOUBLE">
	/// �����޲���������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Spi_Cast_Fac" type="L3STRING">
	/// �⾧ʯ�����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Spi_Cast_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Spi_Cast_Wast" type="L3DOUBLE">
	/// �⾧ʯ������������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spi_Cast_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Dre_Lin_Per" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Cha_Dre_Lin_Per)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Cha_Dre_Lin_Wast" type="L3DOUBLE">
	/// ����������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cha_Dre_Lin_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Seat_Bri_Installer" type="L3STRING">
	/// ��ש��װ
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Buttom_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Buttom_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Wall_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Rep_Ladle_Bot" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Bot)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Thr_Ladle_Time" type="L3DATETIME">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Cha_Dre_Lin" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Cha_Dre_Lin" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Cha_Dre_Lin" name="Object_ID" type="L3STRING">
	/// ����[WorkID + ChaID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
