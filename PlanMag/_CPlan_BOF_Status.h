// �߼���CPlan_BOF_Statusͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CPlan_BOF_Status :
	public CL3Object
{
public:
	CPlan_BOF_Status(void);
	virtual ~CPlan_BOF_Status(void);

	DECLARE_L3CLASS(CPlan_BOF_Status,XGMESLogic\\PlanMag, BOFID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CPlan_BOF_Status)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CPlan_BOF_Status" name="BOFID" type="L3STRING">
	/// ת¯¯��
	/// </Property>
	DECLARE_L3PROP_STRING(BOFID)

	/// <Property class="CPlan_BOF_Status" name="Status" type="L3STRING">
	/// ״̬
	/// </Property>
	DECLARE_L3PROP_STRING(Status)

	/// <Property class="CPlan_BOF_Status" name="New_BOF_Flag" type="L3SHORT">
	/// ��ת¯��־
	/// </Property>
	DECLARE_L3PROP_SHORT(New_BOF_Flag)

};
