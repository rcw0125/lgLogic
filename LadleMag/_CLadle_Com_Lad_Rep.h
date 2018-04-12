// �߼���CLadle_Com_Lad_Repͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Com_Lad_Rep :
	public CL3Object
{
public:
	CLadle_Com_Lad_Rep(void);
	virtual ~CLadle_Com_Lad_Rep(void);

	DECLARE_L3CLASS(CLadle_Com_Lad_Rep,XGMESLogic\\LadleMag, Object_ID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Com_Lad_Rep)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Com_Lad_Rep" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="RepID" type="L3LONG">
	/// ���
	/// </Property>
	DECLARE_L3PROP_LONG(RepID)

	/// <Property class="CLadle_Com_Lad_Rep" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Water_gap_Bri_Fac" type="L3STRING">
	/// ˮ����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Water_gap_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Water_gap_Bri_Wast" type="L3DOUBLE">
	/// ˮ����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Water_gap_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Breathe_Bri_Fac" type="L3STRING">
	/// ͸����ש����
	/// </Property>
	DECLARE_L3PROP_STRING(Breathe_Bri_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Breathe_Bri_Wast" type="L3DOUBLE">
	/// ͸����ש������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Breathe_Bri_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Cast_Fac" type="L3STRING">
	/// �����ϳ���
	/// </Property>
	DECLARE_L3PROP_STRING(Cast_Fac)

	/// <Property class="CLadle_Com_Lad_Rep" name="Cast_Wast" type="L3DOUBLE">
	/// ��ע��������[t]
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Cast_Wast)

	/// <Property class="CLadle_Com_Lad_Rep" name="Fire_Start_Time" type="L3DATETIME">
	/// �濾��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_Start_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="Fire_End_Time" type="L3DATETIME">
	/// �濾����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Fire_End_Time)

	/// <Property class="CLadle_Com_Lad_Rep" name="Rep_Ladle_Operator" type="L3STRING">
	/// �ް�������
	/// </Property>
	DECLARE_L3PROP_STRING(Rep_Ladle_Operator)

	/// <Property class="CLadle_Com_Lad_Rep" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Com_Lad_Rep" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Com_Lad_Rep" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Com_Lad_Rep" name="Rep_Date" type="L3DATETIME">
	/// �޲�����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Rep_Date)

	/// <Property class="CLadle_Com_Lad_Rep" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Com_Lad_Rep" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Com_Lad_Rep" name="Object_ID" type="L3STRING">
	/// ����[WorkID + RepID]
	/// </Property>
	DECLARE_L3PROP_STRING(Object_ID)

};
