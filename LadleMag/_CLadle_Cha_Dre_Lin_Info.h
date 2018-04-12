// �߼���CLadle_Cha_Dre_Lin_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Cha_Dre_Lin_Info :
	public CL3Object
{
public:
	CLadle_Cha_Dre_Lin_Info(void);
	virtual ~CLadle_Cha_Dre_Lin_Info(void);

	DECLARE_L3CLASS(CLadle_Cha_Dre_Lin_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Cha_Dre_Lin_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Number" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Number)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Ladle_ID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Cha_Slag_Line_Time" type="L3DATETIME">
	/// ������ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Cha_Slag_Line_Time)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Water_gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Bot_Wall_Rep_Mat_Fac" type="L3STRING">
	/// ���ױ��޲��ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Bot_Wall_Rep_Mat_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Bot_Wall_Rep_Mat_Wast" type="L3DOUBLE">
	/// �����޲���������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Bot_Wall_Rep_Mat_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Spi_Cast_Fac" type="L3STRING">
	/// �⾧ʯ�����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Spi_Cast_Fac)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Spi_Cast_Wast" type="L3DOUBLE">
	/// �⾧ʯ������������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Spi_Cast_Wast)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Seat_Bri_Installer" type="L3STRING">
	/// ��ש��װ
	/// </Property>
	DECLARE_L3PROP_STRING(Seat_Bri_Installer)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Buttom_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Buttom_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Wall_Builder" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Wall_Builder)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Rep_Ladle_Bot" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Bot)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Thr_Ladle_Time" type="L3DATETIME">
	/// ˦��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Thr_Ladle_Time)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Cha_Dre_Lin_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
