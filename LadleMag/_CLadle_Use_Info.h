// �߼���CLadle_Use_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CLadle_Use_Info :
	public CL3Object
{
public:
	CLadle_Use_Info(void);
	virtual ~CLadle_Use_Info(void);

	DECLARE_L3CLASS(CLadle_Use_Info,XGMESLogic\\LadleMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CLadle_Use_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CLadle_Use_Info" name="Input_Time" type="L3DATETIME">
	/// ¼��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Input_Time)

	/// <Property class="CLadle_Use_Info" name="Ladle_ID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_ID)

	/// <Property class="CLadle_Use_Info" name="Use_Date" type="L3DATETIME">
	/// ʹ������
	/// </Property>
	DECLARE_L3PROP_DATETIME(Use_Date)

	/// <Property class="CLadle_Use_Info" name="Ladle_Age" type="L3SHORT">
	/// ����
	/// </Property>
	DECLARE_L3PROP_SHORT(Ladle_Age)

	/// <Property class="CLadle_Use_Info" name="Bof_ID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Bof_ID)

	/// <Property class="CLadle_Use_Info" name="Steel_Grade" type="L3STRING">
	/// ���ּ���
	/// </Property>
	DECLARE_L3PROP_STRING(Steel_Grade)

	/// <Property class="CLadle_Use_Info" name="Seat_OK_Time" type="L3DATETIME">
	/// ���ð�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Seat_OK_Time)

	/// <Property class="CLadle_Use_Info" name="Tap_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Tap_Time)

	/// <Property class="CLadle_Use_Info" name="Irr_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Irr_Time)

	/// <Property class="CLadle_Use_Info" name="Off_Ladle_Time" type="L3DATETIME">
	/// �°�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Off_Ladle_Time)

	/// <Property class="CLadle_Use_Info" name="Arrive_Time" type="L3DATETIME">
	/// ���ϼ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Arrive_Time)

	/// <Property class="CLadle_Use_Info" name="Complete_Time" type="L3DATETIME">
	/// �Ϻü�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Complete_Time)

	/// <Property class="CLadle_Use_Info" name="Fire_Time_Len" type="L3DOUBLE">
	/// �濾ʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Fire_Time_Len)

	/// <Property class="CLadle_Use_Info" name="Stop_Time_Len" type="L3DOUBLE">
	/// ͣ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Stop_Time_Len)

	/// <Property class="CLadle_Use_Info" name="Ladle_Check" type="L3STRING">
	/// �ְ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Check)

	/// <Property class="CLadle_Use_Info" name="Off_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Off_Reason)

	/// <Property class="CLadle_Use_Info" name="Sk_Board_Keep" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(Sk_Board_Keep)

	/// <Property class="CLadle_Use_Info" name="Ladle_Grade" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Ladle_Grade)

	/// <Property class="CLadle_Use_Info" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CLadle_Use_Info" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CLadle_Use_Info" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CLadle_Use_Info" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
