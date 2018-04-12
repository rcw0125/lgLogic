// �߼���CDisp_SteelTurn_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_SteelTurn_App :
	public CL3Object
{
public:
	CDisp_SteelTurn_App(void);
	virtual ~CDisp_SteelTurn_App(void);

	DECLARE_L3CLASS(CDisp_SteelTurn_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelTurn_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelTurn_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelTurn_App" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelTurn_App" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelTurn_App" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelTurn_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelTurn_App" name="App_UnitID" type="L3DATETIME">
	/// ���빤��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)


	/// <Property class="CDisp_SteelTurn_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelTurn_App" name="App_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelTurn_App" name="App_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Time" type="L3DATETIME">
	/// ��¯ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Turn_Time)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Operator" type="L3STRING">
	/// ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(Turn_Operator)

	/// <Property class="CDisp_SteelTurn_App" name="Turn_Flag" type="L3LONG">
	/// ��¯��־��0��δ��¯��1����¯
	/// </Property>
	DECLARE_L3PROP_LONG(Turn_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="All_Turn_Flag" type="L3LONG">
	/// ȫ��¯��־��0������ȫ��¯��1��ȫ��¯
	/// </Property>
	DECLARE_L3PROP_LONG(All_Turn_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="NC_Confirm_Flag" type="L3LONG">
	/// NCȷ�ϱ�־
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_LONG(NC_Confirm_Flag)

	/// <Property class="CDisp_SteelTurn_App" name="Shift" type="L3STRING">
	/// ���
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_STRING(Shift)

	/// <Property class="CDisp_SteelTurn_App" name="Team" type="L3STRING">
	/// ���
	/// </Property>
	///2009-03-22
	DECLARE_L3PROP_STRING(Team)

};
