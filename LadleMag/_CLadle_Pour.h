// �߼���CLadle_Pourͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Pour :
	public CL3Object
{
public:
	CLadle_Pour(void);
	virtual ~CLadle_Pour(void);

	DECLARE_L3CLASS(CLadle_Pour,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Pour)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Pour" name="Input_Time" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Pour" name="Steel_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Pour" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CLadle_Pour" name="Out_LadleID" type="L3STRING">
	/// �����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(Out_LadleID)

	/// <Property class="CLadle_Pour" name="In_LadleID" type="L3STRING">
	/// ����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(In_LadleID)

	/// <Property class="CLadle_Pour" name="Weight" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Weight)

	/// <Property class="CLadle_Pour" name="WorkID" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(WorkID)

	/// <Property class="CLadle_Pour" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Pour" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Pour" name="Operator" type="L3STRING">
	/// ����ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Pour" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CLadle_Pour" name="Confirm_Flag" type="L3LONG">
	/// ʵ��ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)


};
