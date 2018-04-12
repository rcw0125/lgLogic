// �߼���CDisp_SteelExchange_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_SteelExchange_App :
	public CL3Object
{
public:
	CDisp_SteelExchange_App(void);
	virtual ~CDisp_SteelExchange_App(void);

	DECLARE_L3CLASS(CDisp_SteelExchange_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelExchange_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelExchange_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelExchange_App" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelExchange_App" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelExchange_App" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelExchange_App" name="App_UnitID" type="L3STRING">
	/// ���빤��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CDisp_SteelExchange_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelExchange_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelExchange_App" name="App_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelExchange_App" name="App_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Time" type="L3DATETIME">
	/// �ĸ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Ex_Time)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Operator" type="L3STRING">
	/// �ĸ���
	/// </Property>
	DECLARE_L3PROP_STRING(Ex_Operator)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_Flag" type="L3LONG">
	/// �ĸֱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Ex_Flag)

	/// <Property class="CDisp_SteelExchange_App" name="Ex_SteelGradeIndex" type="L3STRING">
	/// �������ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(Ex_SteelGradeIndex)

};
