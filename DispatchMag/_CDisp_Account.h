// �߼���CDisp_Accountͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_Account :
	public CL3Object
{
public:
	CDisp_Account(void);
	virtual ~CDisp_Account(void);

	DECLARE_L3CLASS(CDisp_Account,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_Account)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_Account" name="ProductDate" type="L3STRING">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_STRING(ProductDate)

	/// <Property class="CDisp_Account" name="UnitID" type="L3STRING">
	/// ����
	/// </Property>
	DECLARE_L3PROP_STRING(UnitID)

	/// <Property class="CDisp_Account" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	DECLARE_L3PROP_STRING(Team)

	/// <Property class="CDisp_Account" name="AccountType" type="L3STRING">
	/// ̨������
	/// </Property>
	DECLARE_L3PROP_STRING(AccountType)

	/// <Property class="CDisp_Account" name="AccountCount" type="L3LONG">
	/// ̨�ʼ���
	/// </Property>
	DECLARE_L3PROP_LONG(AccountCount)

	/// <Property class="CDisp_Account" name="AccountReason" type="L3STRING">
	/// ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(AccountReason)

	/// <Property class="CDisp_Account" name="Responsibility_Organ" type="L3STRING">
	/// ���ε�λ
	/// </Property>
	DECLARE_L3PROP_STRING(Responsibility_Organ)

	/// <Property class="CDisp_Account" name="CreateTime" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(CreateTime)

	/// <Property class="CDisp_Account" name="AccountAmount" type="L3DOUBLE">
	/// ̨������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(AccountAmount)

};
