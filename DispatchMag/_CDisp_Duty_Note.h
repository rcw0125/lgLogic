// �߼���CDisp_Duty_Noteͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_Duty_Note :
	public CL3Object
{
public:
	CDisp_Duty_Note(void);
	virtual ~CDisp_Duty_Note(void);

	DECLARE_L3CLASS(CDisp_Duty_Note,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Duty_Note)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_Duty_Note" name="TeamID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(TeamID)

	/// <Property class="CDisp_Duty_Note" name="ShiftID" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(ShiftID)

	/// <Property class="CDisp_Duty_Note" name="CreateDate" type="L3DATETIME">
	/// ����
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateDate)

	/// <Property class="CDisp_Duty_Note" name="Note" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

};
