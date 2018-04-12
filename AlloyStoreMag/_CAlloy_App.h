// �߼���CAlloy_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CAlloy_App :
	public CL3Object
{
public:
	CAlloy_App(void);
	virtual ~CAlloy_App(void);

	DECLARE_L3CLASS(CAlloy_App,XGMESLogic\\AlloyStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CAlloy_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CAlloy_App" name="Alloy_Code" type="L3STRING">
	/// �Ͻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Alloy_Code)

	/// <Property class="CAlloy_App" name="Amount" type="L3DOUBLE">
	/// ��������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CAlloy_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CAlloy_App" name="App_UnitID" type="L3STRING">
	/// ���빤��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CAlloy_App" name="App_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CAlloy_App" name="Confirm_Flag" type="L3STRING">
	/// ȷ�ϱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CAlloy_App" name="Confirm_Operator" type="L3STRING">
	/// ȷ����
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Operator)

	/// <Property class="CAlloy_App" name="Confirm_Time" type="L3DATETIME">
	/// ȷ��ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Confirm_Time)

};
