// �߼���CLadle_Pour_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Pour_Info :
	public CL3Object
{
public:
	CLadle_Pour_Info(void);
	virtual ~CLadle_Pour_Info(void);

	DECLARE_L3CLASS(CLadle_Pour_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Pour_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Pour_Info" name="Input_Time" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Pour_Info" name="Steel_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Pour_Info" name="Out_Ladle_ID" type="L3STRING">
	/// �����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(Out_Ladle_ID)

	/// <Property class="CLadle_Pour_Info" name="In_Ladle_ID" type="L3STRING">
	/// ����ְ���
	/// </Property>
	DECLARE_L3PROP_STRING(In_Ladle_ID)

	/// <Property class="CLadle_Pour_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Pour_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Pour_Info" name="Operator" type="L3STRING">
	/// ����ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Pour_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
