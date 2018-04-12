// �߼���CLadle_Fireͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Fire :
	public CL3Object
{
public:
	CLadle_Fire(void);
	virtual ~CLadle_Fire(void);

	DECLARE_L3CLASS(CLadle_Fire,XGMESLogic\\LadleMag, FireID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Fire)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Fire" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Fire" name="Fire_Type" type="L3STRING">
	/// �濾���
	/// </Property>
	DECLARE_L3PROP_STRING(Fire_Type)

	/// <Property class="CLadle_Fire" name="Roaster_ID" type="L3STRING">
	/// �濾��̨��
	/// </Property>
	DECLARE_L3PROP_STRING(Roaster_ID)

	/// <Property class="CLadle_Fire" name="LadleID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(LadleID)

	/// <Property class="CLadle_Fire" name="Start_Time" type="L3DATETIME">
	/// ��ʼʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Start_Time)

	/// <Property class="CLadle_Fire" name="Start_Operator" type="L3STRING">
	/// ��ʼ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Start_Operator)

	/// <Property class="CLadle_Fire" name="Set_One_Time" type="L3DATETIME">
	/// ��һʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_One_Time)

	/// <Property class="CLadle_Fire" name="Set_One_Operator" type="L3STRING">
	/// ��һ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Set_One_Operator)

	/// <Property class="CLadle_Fire" name="Set_Two_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Two_Time)

	/// <Property class="CLadle_Fire" name="Set_Two_Operator" type="L3STRING">
	/// ��������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Two_Operator)

	/// <Property class="CLadle_Fire" name="Set_Three_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Three_Time)

	/// <Property class="CLadle_Fire" name="Set_Three_Operator" type="L3STRING">
	/// ��������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Three_Operator)

	/// <Property class="CLadle_Fire" name="Set_Four_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Set_Four_Time)

	/// <Property class="CLadle_Fire" name="Set_Four_Operator" type="L3STRING">
	/// ���Ĳ���Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Set_Four_Operator)

	/// <Property class="CLadle_Fire" name="End_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(End_Time)

	/// <Property class="CLadle_Fire" name="End_Operator" type="L3STRING">
	/// ��������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(End_Operator)

	/// <Property class="CLadle_Fire" name="Suspend_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Suspend_Time)

	/// <Property class="CLadle_Fire" name="Suspend_Operator" type="L3STRING">
	/// ��������Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Suspend_Operator)

	/// <Property class="CLadle_Fire" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Fire" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Fire" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Fire" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Fire" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Fire" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CLadle_Fire" name="FireNote" type="L3STRING">
	/// �濾��ע
	/// </Property>
	DECLARE_L3PROP_STRING(FireNote)

	/// <Property class="CLadle_Fire" name="FireID" type="L3STRING">
	/// �濾���[WorkID + Fire_Type + ���]
	/// </Property>
	DECLARE_L3PROP_STRING(FireID)

};
