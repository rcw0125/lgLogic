// �߼���CDisp_SteelBack_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_SteelBack_App :
	public CL3Object
{
public:
	CDisp_SteelBack_App(void);
	virtual ~CDisp_SteelBack_App(void);

	DECLARE_L3CLASS(CDisp_SteelBack_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelBack_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelBack_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelBack_App" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelBack_App" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelBack_App" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelBack_App" name="App_UnitID" type="L3STRING">
	/// ���빤��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CDisp_SteelBack_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelBack_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelBack_App" name="App_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelBack_App" name="App_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

	/// <Property class="CDisp_SteelBack_App" name="Back_UnitID" type="L3STRING">
	/// ���͹���
	/// </Property>
	DECLARE_L3PROP_STRING(Back_UnitID)

	/// <Property class="CDisp_SteelBack_App" name="Back_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Back_Time)

	/// <Property class="CDisp_SteelBack_App" name="Back_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(Back_Operator)

	/// <Property class="CDisp_SteelBack_App" name="Back_Flag" type="L3LONG">
	/// ���ͱ�־
	/// </Property>
	DECLARE_L3PROP_LONG(Back_Flag)

};
