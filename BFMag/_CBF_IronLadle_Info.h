// �߼���CBF_IronLadle_Infoͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBF_IronLadle_Info :
	public CL3Object
{
public:
	CBF_IronLadle_Info(void);
	virtual ~CBF_IronLadle_Info(void);

	DECLARE_L3CLASS(CBF_IronLadle_Info,XGMESLogic\\BFMag, IDObject)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBF_IronLadle_Info)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBF_IronLadle_Info" name="IDObject" type="L3STRING">
	/// ����ID=�����+����˳���
	/// </Property>
	DECLARE_L3PROP_STRING(IDObject)

	/// <Property class="CBF_IronLadle_Info" name="TPC_No" type="L3STRING">
	/// �޺�
	/// </Property>
	DECLARE_L3PROP_STRING(TPC_No)

	/// <Property class="CBF_IronLadle_Info" name="GroupNo" type="L3STRING">
	/// �����
	/// </Property>
	DECLARE_L3PROP_STRING(GroupNo)

	/// <Property class="CBF_IronLadle_Info" name="OrderNo" type="L3LONG">
	/// ����˳���
	/// </Property>
	DECLARE_L3PROP_LONG(Order_No)

	/// <Property class="CBF_IronLadle_Info" name="ModifyTime" type="L3DATETIME">
	/// ���ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(ModifyTime)

	/// <Property class="CBF_IronLadle_Info" name="Operator" type="L3STRING">
	/// ����Ա
	/// </Property>
	DECLARE_L3PROP_STRING(Operator)

};
