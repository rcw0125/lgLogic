// �߼���CLadle_Com_Lad_Rep_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Com_Lad_Rep_Info :
	public CL3Object
{
public:
	CLadle_Com_Lad_Rep_Info(void);
	virtual ~CLadle_Com_Lad_Rep_Info(void);

	DECLARE_L3CLASS(CLadle_Com_Lad_Rep_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Com_Lad_Rep_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Number" type="L3SHORT">
	/// ���
	/// </Property>
	DECLARE_L3PROP_SHORT(Number)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Ladle_ID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Water_gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Cast_Fac" type="L3STRING">
	/// �����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_Fac)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Cast_Wast" type="L3DOUBLE">
	/// ��ע��������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Rep_Ladle_Operator" type="L3STRING">
	/// �ް�������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Operator)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Com_Lad_Rep_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
