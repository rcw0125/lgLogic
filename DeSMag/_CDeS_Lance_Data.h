// �߼���CDeS_Lance_Dataͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Lance_Data :
	public CL3Object
{
public:
	CDeS_Lance_Data(void);
	virtual ~CDeS_Lance_Data(void);

		// ��ǹ״̬ö��
	enum _LanceStatusEnum
	{
		lancePrepare = 1,			// ׼��
		lanceOnline = 2,			// ����
		lanceMaintain = 3,	        // ά��
		lanceOffline = 4,	        // ����
		lanceDeleted = 5,			// ����
	};

	DECLARE_L3CLASS(CDeS_Lance_Data,XGMESLogic\\DeSMag, LanceNo)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Lance_Data)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Lance_Data" name="LanceNo" type="L3STRING">
	/// ��ǹ��
	/// </Property>
	DECLARE_L3PROP_STRING(LanceNo)

	/// <Property class="CDeS_Lance_Data" name="Status" type="L3LONG">
	/// ��ǹ״̬
	/// ����
	/// ����
	/// ����
	/// ����
	/// </Property>
	DECLARE_L3PROP_LONG(Status)

	/// <Property class="CDeS_Lance_Data" name="LanceAge" type="L3LONG">
	/// ��ǹǹ��
	/// </Property>
	DECLARE_L3PROP_LONG(LanceAge)

	/// <Property class="CDeS_Lance_Data" name="LanceVendor" type="L3STRING">
	/// ��ǹ����
	/// </Property>
	DECLARE_L3PROP_STRING(LanceVendor)

	/// <Property class="CDeS_Lance_Data" name="ProcessTime" type="L3LONG">
	/// ��ҵʱ��
	/// </Property>
	DECLARE_L3PROP_LONG(ProcessTime)

	/// <Property class="CDeS_Lance_Data" name="ProcessAmount" type="L3DOUBLE">
	/// ������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(ProcessAmount)

	/// <Property class="CDeS_Lance_Data" name="Note" type="L3STRING">
	/// ��ע
	/// </Property>
	DECLARE_L3PROP_STRING(Note)

	/// <Property class="CDeS_Lance_Data" name="OpTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(OpTime)

};
