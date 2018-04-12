// �߼���CDeS_Equipment_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDeS_Equipment_Status :
	public CL3Object
{
public:
	CDeS_Equipment_Status(void);
	virtual ~CDeS_Equipment_Status(void);

	DECLARE_L3CLASS(CDeS_Equipment_Status,XGMESLogic\\DeSMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDeS_Equipment_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDeS_Equipment_Status" name="DeSID" type="L3SHORT">
	/// 
	/// ����λ��(1:DeS1
	///            2:DeS2)
	/// </Property>
	DECLARE_L3PROP_SHORT(DeSID)

	/// <Property class="CDeS_Equipment_Status" name="Status" type="L3SHORT">
	/// 
	/// �豸״̬
	/// (1:����
	///  2:����
	///  3:�ȴ�
	///  4:����
	///  5:�罬
	///  6:����������
	///  7:����)
	/// </Property>
	DECLARE_L3PROP_SHORT(Status)

	/// <Property class="CDeS_Equipment_Status" name="Log_Time" type="L3DATETIME">
	/// ��¼ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Log_Time)

	/// <Property class="CDeS_Equipment_Status" name="Reason" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(Reason)
};
