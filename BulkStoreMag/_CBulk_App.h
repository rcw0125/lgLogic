// �߼���CBulk_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CBulk_App :
	public CL3Object
{
public:
	CBulk_App(void);
	virtual ~CBulk_App(void);

	DECLARE_L3CLASS(CBulk_App,XGMESLogic\\BulkStoreMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CBulk_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CBulk_App" name="Bulk_Code" type="L3STRING">
	/// �Ͻ����
	/// </Property>
	DECLARE_L3PROP_STRING(Bulk_Code)

	/// <Property class="CBulk_App" name="Amount" type="L3DOUBLE">
	/// �������������Զ��ڸ־�Ȳ�����˵û��̫���ʵ�����壬��Ϊ1������������Һ�塢�ֹܡ���ʯ�����͵Ĳ�����˵�����������ˡ�������ϳ�Ϊ ���β��ϡ�
	/// </Property>
	DECLARE_L3PROP_DOUBLE(Amount)

	/// <Property class="CBulk_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CBulk_App" name="App_UnitID" type="L3STRING">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CBulk_App" name="App_Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CBulk_App" name="Confirm_Flag" type="L3LONG">
	/// </Property>
	DECLARE_L3PROP_LONG(Confirm_Flag)

	/// <Property class="CBulk_App" name="Confirm_Operator" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(Confirm_Operator)

	/// <Property class="CBulk_App" name="Confirm_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Confirm_Time)

};
