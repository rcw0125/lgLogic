// �߼���CDeS_Lance_Logͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Lance_Log :
	public CL3Object
{
public:
	CDeS_Lance_Log(void);
	virtual ~CDeS_Lance_Log(void);

	DECLARE_L3CLASS(CDeS_Lance_Log,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Lance_Log)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();
	/// <Property class="CDeS_Lance_Log" name="LanceNo" type="L3STRING">
	/// ��ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Lance_Log" name="Status" type="L3LONG">
	/// ��ǹ״̬
	/// ����
	/// ����
	/// ����
	/// ����
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CDeS_Lance_Log" name="LanceAge" type="L3LONG">
	/// ��ǹǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Lance_Log" name="LanceVendor" type="L3STRING">
	/// ��ǹ����
	/// </Property>
	DECLARE_L3PROP_STRING(LanceVendor)

	/// <Property class="CDeS_Lance_Log" name="ProcessTime" type="L3LONG">
	/// ��ҵʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Lance_Log" name="ProcessAmount" type="L3DOUBLE">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ProcessAmount)

	/// <Property class="CDeS_Lance_Log" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Lance_Log" name="Action" type="L3STRING">
	/// ����˵��
	/// </Property>
	DECLARE_L3PROP_STRING(Action)

	/// <Property class="CDeS_Lance_Log" name="Time_Change" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Time_Change)

	/// <Property class="CDeS_Lance_Log" name="Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

	/// <Property class="CDeS_Lance_Log" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDeS_Lance_Log" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)
};
