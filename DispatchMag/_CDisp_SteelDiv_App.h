// �߼���CDisp_SteelDiv_Appͷ�ļ�
// ���ļ�����L3���ɿ��������Զ����ɣ���û�г���˽Ȿ�ļ�������ǰ���벻Ҫ�����޸ı��ļ��е�����
// ������ܴ������غ����
#pragma once

class CDisp_SteelDiv_App :
	public CL3Object
{
public:
	CDisp_SteelDiv_App(void);
	virtual ~CDisp_SteelDiv_App(void);

	DECLARE_L3CLASS(CDisp_SteelDiv_App,XGMESLogic\\DispatchMag, GUID)
	DECLARE_L3PROPTABLE()
	DECLARE_L3METHODMAP(CDisp_SteelDiv_App)
	DECLARE_L3EVENTSINK_MAP()

	//������װ�ص�ϵͳ��ʱ��������
	virtual void OnLoaded();
	//������ж��ʱ��������
	virtual void OnUnloaded();

	/// <Property class="CDisp_SteelDiv_App" name="ObjectID" type="L3STRING">
	/// </Property>
	DECLARE_L3PROP_STRING(ObjectID)

	/// <Property class="CDisp_SteelDiv_App" name="PreHeatID" type="L3STRING">
	/// Ԥ��¯��
	/// </Property>
	DECLARE_L3PROP_STRING(PreHeatID)

	/// <Property class="CDisp_SteelDiv_App" name="SteelGradeIndex" type="L3STRING">
	/// ���ּǺ�
	/// </Property>
	DECLARE_L3PROP_STRING(SteelGradeIndex)

	/// <Property class="CDisp_SteelDiv_App" name="HeatID" type="L3STRING">
	/// ¯��
	/// </Property>
	DECLARE_L3PROP_STRING(HeatID)

	/// <Property class="CDisp_SteelDiv_App" name="App_Time" type="L3DATETIME">
	/// ����ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(App_Time)

	/// <Property class="CDisp_SteelDiv_App" name="App_Steel_Weight" type="L3DOUBLE">
	/// �������
	/// </Property>
	DECLARE_L3PROP_DOUBLE(App_Steel_Weight)

	/// <Property class="CDisp_SteelDiv_App" name="App_Operator" type="L3STRING">
	/// ������
	/// </Property>
	DECLARE_L3PROP_STRING(App_Operator)

	/// <Property class="CDisp_SteelDiv_App" name="App_UnitID" type="L3STRING">
	/// ���빤��
	/// </Property>
	DECLARE_L3PROP_STRING(App_UnitID)

	/// <Property class="CDisp_SteelDiv_App" name="Div_UnitID" type="L3STRING">
	/// �ָ��
	/// </Property>
	DECLARE_L3PROP_STRING(Div_UnitID)

	/// <Property class="CDisp_SteelDiv_App" name="Div_Time" type="L3DATETIME">
	/// �ָ�ʱ��
	/// </Property>
	DECLARE_L3PROP_DATETIME(Div_Time)

	/// <Property class="CDisp_SteelDiv_App" name="Div_Operator" type="L3STRING">
	/// �ָ���
	/// </Property>
	DECLARE_L3PROP_STRING(Div_Operator)

	/// <Property class="CDisp_SteelDiv_App" name="Div_Flag" type="L3LONG">
	/// �ָ��־
	/// </Property>
	DECLARE_L3PROP_LONG(Div_Flag)

	/// <Property class="CDisp_SteelDiv_App" name="App_Reason" type="L3STRING">
	/// ����ԭ��
	/// </Property>
	DECLARE_L3PROP_STRING(App_Reason)

};
